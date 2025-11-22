#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(){
	int n;
	std::cin >> n;

	std::vector<int> dp(n+1, std::numeric_limits<int>::max());

	dp[0] = 0;

	for(int i = 0; i <= n; i++){
		std::string s = std::to_string(i);
		for(char c : s){
			int digit = c - '0';
			if(digit == 0)
				continue;

			if(i-digit >= 0){
				dp[i] = std::min(dp[i], 1 + dp[i-digit]);
			}
		}
	}

	std::cout << dp[n] << std::endl;

	return 0;
}