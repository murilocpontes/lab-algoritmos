#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Pos {
	int r, c;
	bool operator==(const Pos& other) const {
        return r == other.r && c == other.c;
    }
    bool operator!=(const Pos& other) const {
        return !(*this == other);
    }
};

int main(){
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> grid(n, std::string());
	Pos start, end;
	for(int i = 0; i < n; i++){
		std::cin >> grid[i];
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'A'){
				start = {i, j};
			}
			if(grid[i][j] == 'B'){
				end = {i, j};
			}
		}
	}

	std::queue<Pos> q;
	std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
	std::vector<std::vector<char>> parent_move(n, std::vector<char>(m, '\0'));

	q.push(start);
	dist[start.r][start.c] = 0;

	int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
	char moves[4] = {'U', 'D', 'L', 'R'};

	bool found = false;

	while(!q.empty()){
		Pos cur = q.front();
		q.pop();

		if(cur == end){
			found = true;
			break;
		}

		for(int i = 0; i < 4; i++){
			int next_r =cur.r + dr[i];
			int next_c =cur.c + dc[i];
			char move = moves[i];
			
			if(next_r < 0 || next_r >= n ||
				next_c < 0 || next_c >= m)
				continue;

			if (grid[next_r][next_c] == '#') 
				continue;
        
            if (dist[next_r][next_c] != -1) 
				continue;
			
			dist[next_r][next_c] = dist[cur.r][cur.c] + 1;
            parent_move[next_r][next_c] = move;
            q.push({next_r, next_c});
		}
	}

	if(!found){
		std::cout << "Nao" << std::endl;

	} else {
		std::cout << dist[end.r][end.c] << " ";
		std::string path = std::string();
		Pos cur = end;
		while(cur != start) {
			char move = parent_move[cur.r][cur.c];
			path += move;

			if(move == 'U')
				cur.r++;
            else if(move == 'D') 
				cur.r--;
            else if(move == 'L')
				cur.c++;
            else if(move == 'R')
				cur.c--;
		}
		std::reverse(path.begin(), path.end());
		std::cout << path << std::endl;
	}
	return 0;
}