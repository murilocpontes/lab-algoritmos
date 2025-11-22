#include <iostream>
#include <vector>
#include <queue>

#define MAXN 200005

std::pair<int, int> bfs(int start, int n, std::vector<std::vector<int>> &adj){
	std::vector<int> distance(n+1, -1);
	std::queue<int> queue;

	queue.push(start);
	distance[start] = 0;

	int farthest_node = start;
	int max_distance = 0;

	while(!queue.empty()){
		int u = queue.front();
		queue.pop();

		for(int v : adj[u]){
			if(distance[v] == -1) {
				distance[v] = distance[u] + 1;
				queue.push(v);

				if(distance[v] > max_distance){
					max_distance = distance[v];
					farthest_node = v;
				}
			}
		}
	}
	return {farthest_node, max_distance};
}

int main(){
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n+1, std::vector<int>());

	for(int i = 0; i < n-1; i++){
		int a, b;
		std::cin >> a >> b;

		adj[a].push_back(b);
        adj[b].push_back(a);
	}

	std::pair<int, int> res1 = bfs(1, n, adj);
	int endpoint1 = res1.first;
	
	std::pair<int, int> res2 = bfs(endpoint1, n, adj);
	int diameter = res2.second;

	std::cout << diameter << std::endl;

	return 0;
}