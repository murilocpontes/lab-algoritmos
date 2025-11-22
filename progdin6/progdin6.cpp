#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n, 0));

	for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> cost[row][col];
        }
    }

	vector<int> result(1 << n,  numeric_limits<int>::max());
	result[0] = 0;
	
	for(int mask = 1; mask < (1<<n); mask++){
		int number_of_tasks = __builtin_popcount(mask);
		int next_person = number_of_tasks - 1;

		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				int prev_mask = mask ^ (1 << i);
				if(prev_mask != numeric_limits<int>::max())
				result[mask] = std::min(result[mask], result[prev_mask] + cost[next_person][i]);
			}
		}
	}

	int final_mask = (1 << n) - 1;
	cout << result[final_mask] << std::endl;

	return 0;
}