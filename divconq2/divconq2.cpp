#include <iostream>
#include <set>

bool isValid(long long M, long H, std::multiset<long>& trees){
	long long m = 0;
	auto deb = trees.upper_bound(H);
	auto deb2 = *trees.upper_bound(H);
	for(auto it = trees.upper_bound(H); it != trees.end(); it = std::next(it)){
		m += *it - H;
	}
	return (m >= M);
}

long getMaxHeight(long long M, long h, std::multiset<long>& trees){
	if(!isValid(M, h, trees)){
		return -1;
	}
	long retVal = getMaxHeight(M, (*trees.rbegin() + h)/2, trees);

	if(retVal == -1){
		return h;
	}
	return retVal;
}

int main(){
	int n;
	long long M;
	std::multiset<long> trees;

	std::cin >> n >> M;


	for(int i =0; i < n; i++){
		long tree;
		std::cin >> tree;
		trees.insert(tree);
	}

	std::cout << getMaxHeight(M, 0, trees) << std::endl;

	return 0;
}