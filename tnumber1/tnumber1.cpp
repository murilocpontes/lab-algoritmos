#include <iostream>
#include <vector>

#define MAXN 1000000

void sieve(std::vector<bool>& isPrime){
	isPrime.assign(MAXN + 1, true);
	isPrime[0] = isPrime[1] = false;

	for(int p = 2; p*p <= MAXN; p++){
		if(isPrime[p]){
			for(int i = p * p; i <= MAXN; i += p){
				isPrime[i] = false;
			}
		}
	}
}

void solve(std::vector<bool> isPrime){
	int n;
	std::cin >> n;
	for(int p1 = 2; p1 < n; p1++){
		if(isPrime[p1]){
			int p2= n-p1;
			if(isPrime[p2]){
				std::cout << p1 << " " << p2 << std::endl;
				return;
			}
		}
	}
}

int main(){
	int t;
	std::vector<bool> isPrime(MAXN + 1);
	std::cin >> t;

	sieve(isPrime);

	for(int i = t; i > 0; i--){
		solve(isPrime);
	}
	return 0;
}