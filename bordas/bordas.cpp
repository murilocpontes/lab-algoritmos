#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main(){
	std::string s;
	std::cin >> s;
	int n = s.length();

	std::vector<int> pi(n, 0);

	for(int i = 1; i < n; i++){
		int j = pi[i-1];

		while(j > 0 && s[i] != s[j]){
			j = pi[j-1];
		}
		if(s[i] == s[j]){
			j++;
		}
		pi[i] = j;
	}

	std::vector<int> borders;
	int k = pi[n-1];

	while(k > 0){
		borders.push_back(k);
		k = pi[k-1];
	}

	std::sort(borders.begin(), borders.end());

	for(int i = 0; i < borders.size(); i++){
		std::cout << borders[i] << (i == borders.size() - 1 ? "" : " ");
	}
	if(!borders.empty())
		std::cout << std::endl;

	return 0;
}