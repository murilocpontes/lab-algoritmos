#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> adj_orig, adj_scc;
vector<long long> k_values, scc_value;
vector<int> scc_id, in_degree_scc;
vector<int> disc_time, low_link; 
stack<int> s;
vector<bool> on_stack;
int timer, scc_count;


void find_scc(int u) {
    disc_time[u] = low_link[u] = ++timer;
    s.push(u);
    on_stack[u] = true;

    for (int v : adj_orig[u]) {
        if (disc_time[v] == -1) { // Nó 'v' não visitado
            find_scc(v);
            low_link[u] = min(low_link[u], low_link[v]);
        } else if (on_stack[v]) { // Nó 'v' está na stack (back-edge)
            low_link[u] = min(low_link[u], disc_time[v]);
        }
    }

    // Se u é a raiz de um SCC
    if (low_link[u] == disc_time[u]) {
        while (true) {
            int v = s.top();
            s.pop();
            on_stack[v] = false;
            scc_id[v] = scc_count;
            scc_value[scc_count] += k_values[v]; // Acumula o valor no super-nó
            if (u == v) break;
        }
        scc_count++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // --- 1. Leitura ---
    k_values.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k_values[i];
    }
    adj_orig.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj_orig[a].push_back(b);
    }

    // --- 2. Encontrar SCCs ---
    disc_time.assign(n + 1, -1);
    low_link.assign(n + 1, -1);
    scc_id.resize(n + 1);
    on_stack.assign(n + 1, false);
    scc_value.resize(n + 1, 0); 
    timer = 0;
    scc_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (disc_time[i] == -1) {
            find_scc(i);
        }
    }

    // --- 3. Grafo de Condensação ---
    adj_scc.resize(scc_count);
    in_degree_scc.assign(scc_count, 0);

    for (int u = 1; u <= n; ++u) {
        for (int v : adj_orig[u]) {
            // Se a aresta conecta dois SCCs diferentes
            if (scc_id[u] != scc_id[v]) {
                adj_scc[scc_id[u]].push_back(scc_id[v]);
                in_degree_scc[scc_id[v]]++;
            }
        }
    }

    // --- 4. Programação Dinâmica no DAG de SCCs ---
    vector<long long> dp = scc_value; // dp[i] = valor do super-nó i
    queue<int> q;
    long long max_loot = 0;

    for (int i = 0; i < scc_count; ++i) {
        if (in_degree_scc[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u_scc = q.front();
        q.pop();

        // Atualiza a resposta global
        max_loot = max(max_loot, dp[u_scc]);

        for (int v_scc : adj_scc[u_scc]) {
            // Aplica a transição da PD
            dp[v_scc] = max(dp[v_scc], dp[u_scc] + scc_value[v_scc]);
            
            in_degree_scc[v_scc]--;
            if (in_degree_scc[v_scc] == 0) {
                q.push(v_scc);
            }
        }
    }

    cout << max_loot << "\n";

    return 0;
}