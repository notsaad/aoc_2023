#include <bits/stdc++.h>
#define ROWS board.size()
#define COLS board[0].size()

// basic template for reading input in c++
bool inBounds(int r, int c, std::vector<std::vector<char>> &board);

int main() {
    int ans = 0;
    std::string line;
    std::vector<std::vector<char>> board;
    std::vector<std::vector<int>> boolBoard;
    std::unordered_map<int, std::vector<int>> m;
    while (getline(std::cin, line)) {
        std::vector<char> row;
        std::vector<int> boolRow;
        for (char c : line) {
            row.push_back(c);
            boolRow.push_back(0);
        }
        board.push_back(row);
        boolBoard.push_back(boolRow);
    }

    std::vector<std::pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,1}, {-1,-1}, {1,-1}, {1,1}};

    // every time a symbol is seen (non-number or .) check adjacent cells (diagonals included)
    for (int r=0; r < ROWS; r++) {
        for (int c=0; c < COLS; c++) {
            if (board[r][c] != '.' && !std::isdigit(board[r][c])) {
                std::vector<std::string> nums;
                std::set<std::pair<int, int>> visited;
                for (std::pair<int, int> p : directions) {
                    int row = r + p.first;
                    int col = c + p.second;
                    std::string num = "";

                    if (inBounds(row, col, board) && std::isdigit(board[row][col]) && visited.find({row, col}) == visited.end()) {
                        int l = col - 1;
                        int r = col + 1;

                        while (l >= 0 && std::isdigit(board[row][l])){
                            l--;
                        }

                        while (r < COLS && std::isdigit(board[row][r])){
                            r++;
                        }

                        for (int x = l+1; x < r; x++) {
                            num += board[row][x];
                            visited.insert({row, x});
                        }

                        nums.push_back(num);
                    }
                }

                if (nums.size() == 2) {
                    ans += (std::stoi(nums[0]) * std::stoi(nums[1]));
                }
            }
        }
    }

    std::cout << ans << "\n";
}

bool inBounds(int r, int c, std::vector<std::vector<char>> &board){
    return (r >= 0 && c >= 0 and r < ROWS && c < COLS);
}
