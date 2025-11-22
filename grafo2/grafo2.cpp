#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits> 

using namespace std;


using State = tuple<long long, int, int>; 

int main(){
    int n, m;
    cin >> n >> m;

    // lista de adjacência (grafo direcionado)
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); 
    }

    // dist[i][0] = min p chegar em i sem usar cupom
    // dist[i][1] = min p chegar em i usando cupom
    const long long INF = numeric_limits<long long>::max();
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));

    // fila de prioridade p o Dijkstra
    priority_queue<State, vector<State>, greater<State>> prio_queue;

    // caso base - primeira cidade s/ cupom
    dist[1][0] = 0;
    prio_queue.push({0, 1, 0});

    while (!prio_queue.empty()){
        auto [cost, depart_city, state] = prio_queue.top();
        prio_queue.pop();

        // ignorar caminhos piores
        if (cost > dist[depart_city][state]){
            continue;
        }

        for (auto& edge : adj[depart_city]){
            int dest_city = edge.first;
            int w = edge.second;

            // voo sem cupom
            long long new_cost_normal = cost + w;
            if (new_cost_normal < dist[dest_city][state]){
                dist[dest_city][state] = new_cost_normal;
                prio_queue.push({new_cost_normal, dest_city, state});
            }

            // usar cupom se possivel 
            if (state == 0){
                long long new_cost_cupom = cost + (w / 2);
                
                if (new_cost_cupom < dist[dest_city][1]){
                    dist[dest_city][1] = new_cost_cupom;
                    prio_queue.push({new_cost_cupom, dest_city, 1});
                }
            }
        }
    }
	// valida se a cidade de partida é a mesma de chegada 
    long long final_cost = min(dist[n][0], dist[n][1]);

    cout << final_cost << "\n";

    return 0;
}