#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isVowel(char c){
	return (c == 'a' || c == 'e' || c == 'i' ||
		 c == 'o' || c == 'u');
}



int main(){
	std::string s1;
	std::string s2;
	
	std::cin >> s1;
	std::cin >> s2;

	int size1 = s1.size();
	int size2 = s2.size();

	std::vector<std::vector<int>> edit(size1 + 1, std::vector<int>(size2 + 1, 0));

	for(int i = 1; i <= size1; i++){
		edit[i][0] = 2*i;
	}
	for(int i = 1; i <= size2; i++){
		edit[0][i] = 2*i;
	}
	
	for(int i = 1; i <= size1; i++){
		for(int j = 1; j <= size2; j++){
			int ins = edit[i][j-1] + 2;
			int del = edit[i-1][j] + 2;
			int rep = edit[i-1][j-1];
			if(s1[i-1] != s2[j-1]){
				if(!(isVowel(s1[i-1]) ^ isVowel(s2[j-1])))
					rep += 1;
				else 
					rep += 3;
			}
			edit[i][j] = std::min({ins, del, rep});
		}
	}

	std::cout << edit[size1][size2] << std::endl;
	
	return 0;
}