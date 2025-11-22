#include <iostream>
#include <vector>
#include <numeric>


class Board {
public:
	Board(){}
	bool canPlace(int row, int col, int h, int w);
	void updateBoard(int row, int col, int h, int w, bool is_placing);
	bool solve();

	int board_H, board_W, num_pieces;
	std::vector<std::pair<int, int>> pieces;
	std::vector<std::vector<bool>> board; 
	std::vector<bool> used_pieces;
};


bool Board::canPlace(int row, int col, int h, int w) {
    if (row + h > board_H || col + w > board_W) {
        return false;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[row + i][col + j]) {
                return false; 
            }
        }
    }
    return true;
}


void Board::updateBoard(int row, int col, int h, int w, bool is_placing) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            board[row + i][col + j] = is_placing;
        }
    }
}


bool Board::solve() {
    int r = -1, c = -1;
    for (int i = 0; i < board_H; ++i) {
        for (int j = 0; j < board_W; ++j) {
            if (!board[i][j]) {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1){
			break;
		}
    }
    if (r == -1) {
        return true;
    }

    for (int i = 0; i < num_pieces; ++i) {
        if (!used_pieces[i]) {
            int h = pieces[i].first;
            int w = pieces[i].second;

            if (canPlace(r, c, h, w)) {
                updateBoard(r, c, h, w, true); 
                used_pieces[i] = true;
                
                if (solve()) {
					return true;
				} 
                
                updateBoard(r, c, h, w, false);
                used_pieces[i] = false;
            }

            if (h != w) {
                if (canPlace(r, c, w, h)) {
                    updateBoard(r, c, w, h, true); 
                    used_pieces[i] = true;

                    if (solve()){
					return true;
					}
                    updateBoard(r, c, w, h, false);
                    used_pieces[i] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    Board b;
    std::cin >> b.board_H >> b.board_W;
    std::cin >> b.num_pieces;

    b.pieces.resize(b.num_pieces);
    long long total_piece_area = 0;
    for (int i = 0; i < b.num_pieces; ++i) {
        std::cin >> b.pieces[i].first >> b.pieces[i].second;
        total_piece_area += (long long)b.pieces[i].first * b.pieces[i].second;
    }

    if (total_piece_area != (long long)b.board_H * b.board_W) {
        std::cout << "cha" << std::endl;
        return 0;
    }

    b.board.assign(b.board_H, std::vector<bool>(b.board_W, false));
    b.used_pieces.assign(b.num_pieces, false);

    if (b.solve()) {
        std::cout << "yebo" << std::endl;
    } else {
        std::cout << "cha" << std::endl;
    }

    return 0;
}