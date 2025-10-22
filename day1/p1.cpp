#include <bits/stdc++.h>

int main() {
    std::string line;
    int ans = 0;
    while (getline(std::cin, line)) {
        std::string digits = "";
        for (char c : line) {
            if (std::isdigit(c)) {
                if (digits.size() == 0) {
                    digits += c;
                    digits += c;
                } else {
                    digits[1] = c;
                }
            }
        }
        int num = std::stoi(digits);
        ans += num;
    };
    std::cout << ans << "\n";
}
