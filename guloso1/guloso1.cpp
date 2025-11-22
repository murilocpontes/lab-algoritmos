#include <iostream>
#include <vector>

int find_begin(std::vector<std::pair<int, int>>& entry){
	long int fuel = 0;
	int begin = 0;

	for(int i = 0; i < entry.size(); i ++){
		fuel += entry[i].first - entry[i].second;
		if(fuel < 0){
			begin = i + 2;
			fuel = 0;
		}
	}
	return begin;
}

int main(){
	int n, qSum = 0, cSum = 0;
	std::cin >> n;
	std::vector<std::pair<int, int>> entry;
	
	for(int i = 0; i < n; i++){
		int q, c;
		std::cin >> q >> c;
		qSum += q;
		cSum += c;
		entry.push_back({q, c});
	}

	if(qSum < cSum){
		std::cout << (-1) << std::endl;
		return 0;
	}
	
	int res = find_begin(entry);

	if(res == 0){
		std::cout << (-1) << std::endl;
	} else {
		std::cout << res << std::endl;
	}

	return 0;
}