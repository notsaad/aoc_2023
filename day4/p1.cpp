#include <bits/stdc++.h>

int main() {
    std::string line;
    int ans = 0;
    while (getline(std::cin, line)) {
        bool lineSeen = false;
        std::string num = "";
        std::unordered_set<std::string> seen;
        int score = 0;

        for(int i = 9; i < line.size(); i++){
            if (std::isdigit(line[i])) {
                num += line[i];
            } else {
                if (line[i] == '|') {
                    lineSeen = true;
                    continue;
                }
                if (lineSeen) {
                    if (seen.find(num) != seen.end()) {
                        if (score == 0) {
                            score++;
                        } else {
                            score <<= 1;
                        }
                    }
                } else if (num != "") {
                    seen.insert(num);
                }
                num = "";
            }
        }
        if (num != "" && seen.find(num) != seen.end()) {
            if (score == 0) {
                score++;
            } else {
                score <<= 1;
            }
        }
        ans += score;
    }
    std::cout << ans << "\n";
}
