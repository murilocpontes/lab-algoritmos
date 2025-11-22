#include <iostream>
#include <vector>


void encontrarSubconjuntos(int n, long long S, std::vector<int> numeros, int &contador_de_subconjuntos,
	 int indice, long long soma_atual) {
    if (indice == n) {
        if (soma_atual == S) {
            contador_de_subconjuntos++;
        }
        return;
    }

    if (soma_atual > S) {
        return;
    }

    encontrarSubconjuntos(n, S, numeros, contador_de_subconjuntos, indice + 1, soma_atual);

    encontrarSubconjuntos(n, S, numeros, contador_de_subconjuntos, indice + 1, soma_atual + numeros[indice]);
}

int main() {

	int n;
	long long S;
	std::vector<int> numeros;
	int contador_de_subconjuntos = 0;

    // Leitura da entrada
    std::cin >> n >> S;
    numeros.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
    }
    encontrarSubconjuntos(n, S, numeros, contador_de_subconjuntos, 0, 0);

    if (contador_de_subconjuntos > 0) {
        std::cout << contador_de_subconjuntos << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}