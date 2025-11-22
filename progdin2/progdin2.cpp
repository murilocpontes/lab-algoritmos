#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n, x;
	std::cin >> n >> x;
	std::vector<int> coins;

	for(int i = 0; i < n; i++){
		int d;
		std::cin >> d;
		coins.push_back(d);
	}

	const int mod = 1e9 + 7;

	std::vector<int> dp(x + 1, 0);
	dp[0] = 1;

	for(int coin : coins){
		for(int i = coin; i <= x; i++){
			dp[i] = (dp[i] + dp[i - coin]) % mod;
		}
	}
	std::cout << dp[x] << std::endl;

	return 0;
}