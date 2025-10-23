#include <bits/stdc++.h>

int main() {
    std::string line;
    int ans = 0;
    while (getline(std::cin, line)) {
        // get game id
        size_t l = 0;
        size_t r = 0;
        int game_id = 0;
        while(game_id == 0) {
            if (line[r] == ':'){
                std::string game = line.substr(l, r-l+1);
                game_id = std::stoi(game);
            }
            if (line[r] == ' ') {
                l = r +1;
            }
            r++;
        }

        int count;
        bool valid = 1;
        while(l < line.size()){
            if (std::isdigit(line[l])) {
                r = l;
                while (std::isdigit(line[r])) {
                    r++;
                }
                count = std::stoi(line.substr(l, r-l));
                switch (line[r+1]) {
                case 'r':
                    if (count > 12) {
                        valid = 0;
                    }
                    break;
                case 'g':
                    if (count > 13) {
                        valid = 0;
                    }
                    break;
                case 'b':
                    if (count > 14) {
                        valid = 0;
                    }
                    break;
                }
            }
            l++;
        }
        if (valid) {
            ans += game_id;
        }
    }
    std::cout << ans << "\n";
}
