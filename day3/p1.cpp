#include <bits/stdc++.h>
#define ROWS board.size()
#define COLS board[0].size()

// basic template for reading input in c++
bool inBounds(int r, int c, std::vector<std::vector<char>> &board);

int main() {
    int ans = 0;
    std::string line;
    std::vector<std::vector<char>> board;
    std::vector<std::vector<bool>> boolBoard;
    while (getline(std::cin, line)) {
        std::vector<char> row;
        std::vector<bool> boolRow;
        for (char c : line) {
            row.push_back(c);
            boolRow.push_back(false);
        }
        board.push_back(row);
        boolBoard.push_back(boolRow);
    }

    std::vector<std::pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,1}, {-1,-1}, {1,-1}, {1,1}};

    // every time a symbol is seen (non-number or .) check adjacent cells (diagonals included)
    for (int r=0; r < ROWS; r++) {
        for (int c=0; c < COLS; c++) {
            if (board[r][c] != '.' && !std::isdigit(board[r][c])) {
                for (std::pair<int, int> p : directions) {
                    int x = p.first;
                    int y = p.second;

                    int row = r + x;
                    int col = c + y;

                    if (inBounds(row, col, board) && std::isdigit(board[row][col])) {
                        boolBoard[row][col] = true;
                    }
                }
            }
        }
    }

    for (int r=0; r < ROWS; r++) {
        int c = 0;
        std::string num = "";
        bool valid = false;
        while (c < COLS){
            while (c < COLS && std::isdigit(board[r][c])) {
                num += board[r][c];
                if (boolBoard[r][c]) {
                    valid = true;
                }
                c++;
            }
            if (num != ""){
                if (valid) {
                    ans += std::stoi(num);
                }
                num = "";
                valid = false;
            }
            c++;
        }
    }
    
    std::cout << ans << "\n";
}

bool inBounds(int r, int c, std::vector<std::vector<char>> &board){
    return (r >= 0 && c >= 0 and r < ROWS && c < COLS);
}
