#include <iostream>
#include <vector>

int find_stop_number(std::vector<std::pair<int, int>>& gas_stations, int t, int k){
	int stops = 0;
	int current_position = 0;

	for(int i = 0; i < (gas_stations.size() - 2); i ++){
		if(gas_stations[i+1].first - gas_stations[i].first > t){
			return -1;
		}		
	}

	for(int i = 0; i < gas_stations.size(); i ++){
		int next_stop = current_position;
		for(int j = i + 1; j < gas_stations.size(); j++){
			if(gas_stations[j].first <= current_position + t){
				next_stop = gas_stations[j].first;
			}
		}
		if(next_stop == current_position)
			return -1;
		if(next_stop < k)
			stops++;
		current_position = next_stop;
	}
	return stops;
}

int main(){
	int n, k, t;
	std::vector<std::pair<int, int>> gas_stations;

	std::cin >> k >> t;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		int d_o, d_d;
		std::cin >> d_o >> d_d;

		gas_stations.push_back({d_o, d_d});
	}

	gas_stations.insert(gas_stations.begin(), {0, k});
	gas_stations.insert(gas_stations.end(), {k, 0});

	std::cout << find_stop_number(gas_stations, t, k) << std::endl;

	return 0;
}