#include <iostream>
#include <vector>

int dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<int>& subordinates_count){
    int subtree_size = 1;

    for (int v : adj[u]){
        subtree_size += dfs(v, adj, subordinates_count);
    }

    subordinates_count[u] = subtree_size - 1;
    return subtree_size;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> subordinates_count(n + 1, 0);

    for (int i = 2; i <= n; ++i){
        int boss;
        std::cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1, adj, subordinates_count);

    for (int i = 1; i <= n; ++i) {
        std::cout << subordinates_count[i];
        if (i < n) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}