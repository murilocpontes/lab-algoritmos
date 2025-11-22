#include <iostream>
#include <vector>
#include <string>

void longest_palindromic_subsequence(std::string s){
	int length = s.length();
	std::vector<std::vector<int>> dp(length, std::vector<int>(length, 0));

	for(int i = 0; i < length; i++){
		dp[i][i] = 1;
	}
	for(int len = 2; len <= length; len++){
		for (int i = 0; i <= length - len; i++){
			int j = i + len - 1;
			if(s[i] == s[j]){
				if(len == 2){
					dp[i][j] = 2;
				} else {
					dp[i][j] = 2 + dp[i+1][j-1];
				}
			} else {
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	std::cout << dp[0][length - 1] << std::endl;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<std::string> vec;
	for(int i = 0; i < n; i++){
		std::string str;
		std::cin >> str;
		vec.push_back(str);
	}
	for(auto s : vec){
		longest_palindromic_subsequence(s);
	}
	return 0;
}