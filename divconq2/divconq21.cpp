#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(long long M, long H, std::vector<long>& trees){
	long long m = 0;
	for(auto it = std::upper_bound(trees.begin(), trees.end(), H); it != trees.end(); ++it){
		m += *it - H;
	}
	return (m >= M);
}

long getMaxHeight(long long M, long h, std::vector<long>& trees){
	long lowerBound = 0;
	long upperBound = trees.back();
	long optimalHeight = -1;

	while(lowerBound <= upperBound){
		long middle = lowerBound + (upperBound - lowerBound)/2;
		if(isValid(M, middle, trees)){
			optimalHeight = middle;
			lowerBound = middle + 1;
		} else {
			upperBound = middle - 1;
		}
	}
	return optimalHeight;
}

int main(){
	int n;
	long long M;
	std::vector<long> trees;

	std::cin >> n >> M;


	for(int i =0; i < n; i++){
		long tree;
		std::cin >> tree;
		trees.push_back(tree);
	}

	std::sort(trees.begin(), trees.end());

	std::cout << getMaxHeight(M, 0, trees) << std::endl;

	return 0;
}