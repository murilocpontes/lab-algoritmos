#include <iostream>
#include <vector>

#define MAXN 10000000

void sieve(std::vector<int>& smallestPrimeFactor){
	for(int i = 0; i <= MAXN; i++){
		smallestPrimeFactor[i] = i;
	}

	for(int i = 4; i <= MAXN; i += 2){
		smallestPrimeFactor[i] = 2;
	}

	for(int i = 3; i * i <= MAXN; i++){
		if(smallestPrimeFactor[i] == i){
			for(int j = i * i; j <= MAXN; j += i){
				if (smallestPrimeFactor[j] == j) {
                    smallestPrimeFactor[j] = i;
				}
			}
		}
	}
}

void solve(std::vector<int>& smallestPrimeFactor){
	int n;
	std::cin >> n;

	bool firstFactor = true;

	while(n != 1){
		int p = smallestPrimeFactor[n];
		int divisionByP = 0;

		while(n > 0 && n % p == 0){
			divisionByP++;
			n /= p;
		}
		if(!firstFactor){
			std::cout << ",";
		}
		std::cout << "(" << p << "," << divisionByP << ")";
		firstFactor = false;
	}
	std::cout << std::endl;
}

int main(){
	int t;
	std::vector<int> smallestPrimeFactor(MAXN + 1);
	std::cin >> t;

	sieve(smallestPrimeFactor);

	for(; t > 0; t--){
		solve(smallestPrimeFactor);
	}
	return 0;
}