#include <iostream>
#include <cstring>
#include <list>

int main(){
	int n = 0;
	int anagramas = 0;
	std::list<void*> anagram_list;

	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::string entry;
		std::cin >> entry;
		for(auto string : anagram_list){
			if(dynamic_cast<std::string*>(string))
		}

	}

}