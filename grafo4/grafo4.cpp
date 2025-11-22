#include <iostream>
#include <vector>

int main(){
	int n, q;
	std::cin >> n >> q;
	std::vector<std::vector<int>> bin_lift(31, std::vector<int>(n+1, 0));
	
	// teleportes unitarios
	for(int i = 1; i < n+1; i++){
		std::cin >> bin_lift[0][i];
	}
	for(int i = 1; i < 31; i++){ // p/ cada 2^i teleportes
		for(int j = 1; j < n+1; j++){ // p/ cada planeta
			// partindo do planeta j e fazendo s^i pulos
			bin_lift[i][j] = bin_lift[i-1][bin_lift[i-1][j]];
		}
	}

	int x, k;
	for(int i = 0; i < q; i++){
		std::cin >> x >> k;

		for(int j = 0; j < 31; j++){
			if(k & (1 << j)){
				x = bin_lift[j][x];
			}
		}
		std::cout << x << std::endl;
	}
	return 0;
}