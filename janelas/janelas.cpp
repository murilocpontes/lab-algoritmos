#include <iostream>
#include <vector>
#include <set>

/* função que distribui os elementos da janela baseado em:
	a arvore low tem que ter tamanho(low) = tamanho(high) ou tamanho(high)+1
*/
void balance(std::multiset<int>& low, std::multiset<int>& high){
	while(low.size() > high.size() + 1){
		int v = *low.rbegin();
		high.insert(v);
		low.erase(prev(low.end()));
	}
	while(high.size() > low.size()){
		int v = *high.begin();
		high.erase(high.begin());
		low.insert(v);
	}
}


/* função para adicionar no conjunto correto:
		se menor que o maior low, adiciona em low
		se maior que menor high, adiciona em maior
*/
void add(int v, std::multiset<int>& low, std::multiset<int>& high){
	if(low.empty() || v <= *low.rbegin()){
		low.insert(v);

	} else {
		high.insert(v);
	}
	balance(low, high);
}
// função para remover o elemento no conjunto

void remove(int v,std::multiset<int>& low, std::multiset<int>& high){
	auto it = low.find(v);
	if(it != low.end()){
		low.erase(it);
	} else {
		it = high.find(v);
		if(it != high.end()){
			high.erase(it);
		}
	}
	balance(low, high);
}

int main(){
	int n, k;
	std::cin >> n >> k;
	std::vector<int> congress(n);
	
	for(int i = 0; i < n; i++){
		std::cin >> congress[i];
	}
	std::multiset<int> low, high;

	// processa a primeira janela
	for(int i = 0; i < k; i++){
		add(congress[i], low, high);
	}
	std::cout << *low.rbegin();
	// move a janela
	for(int i = k; i < n; i++){
		remove(congress[i-k], low, high);
		add(congress[i], low, high);
		// a mediana buscada é sempre o maior da arvore dos menores
		std::cout << " " << *low.rbegin();
	}
	std::cout << std::endl;
	return 0;
}