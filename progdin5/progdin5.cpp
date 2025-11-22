#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> dist(n, vector<int>(n, 0));

	for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> dist[row][col];
        }
    }

	vector<vector<int>> result(1 << n, vector<int>(n, numeric_limits<int>::max()));
	for(int i = 0; i < n; i++){
		result[1<<i][i] = 0;
	}
	
	for(int mask = 1; mask < (1<<n); mask++){
		for(int i = 0; i < n; i++){
			// se a cidade i está na mask, significa que vamos avaliar os caminhos das outras cidades na mask com ela
			if(mask & (1<<i)){
				for(int j = 0; j < n; j++){
					// para as outras cidades contidas na mask
					if(j != i && (mask & (1 << j))){
						// mask das outras cidades que formam o caminho até ela
						int prev_mask = mask ^ (1 << i);
						// se o caminho pelas outras cidades terminando em j já foi avaliado
						if(result[prev_mask][j] != numeric_limits<int>::max()){
							result[mask][i] = min(result[mask][i], result[prev_mask][j] + dist[j][i]);
						}
					}
				}
			}
		}
	}

	int final_mask = (1 << n) - 1;
    int min_cost = numeric_limits<int>::max();
	// percorre a mask final (passou por todas as cidades)
	for(int i = 0; i < n; i++){
		// avalia em qual cidade final o custo foi menor
		min_cost = min(min_cost, result[final_mask][i]);
	}
	cout << min_cost << std::endl;

	return 0;
}