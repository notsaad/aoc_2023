#include <bits/stdc++.h>

int main() {
    std::string line;
    int ans = 0;

    std::unordered_map<std::string, char> valid_numbers = {{"one", '1'}, {"two", '2'}, 
        {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};

    while (getline(std::cin, line)) {
        std::string digits = "";
        std::pair<char, size_t> digit_one = {'0', SIZE_MAX};
        std::pair<char, size_t> digit_two = {'0', 0};

        for (auto const& [key, value] : valid_numbers){
            size_t pos = line.find(key);
            size_t r_pos = line.rfind(key);

            if (pos != std::string::npos) {
                if (pos < digit_one.second) {
                    digit_one = {value, pos};
                }
            }
            if (r_pos != std::string::npos) {
                if (r_pos >= digit_two.second) {
                    digit_two = {value, r_pos};
                }
            }
        }

        for(size_t i=0; i < line.size(); i++){
            if (std::isdigit(line[i])) {
                if (i < digit_one.second) {
                    digit_one.first = line[i];
                    digit_one.second = i;
                }

                if (i >= digit_two.second) {
                    digit_two.first = line[i];
                    digit_two.second = i;
                }
            }
        }
        digits += digit_one.first;
        digits += digit_two.first;
        int num = std::stoi(digits);
        ans += num;
    };
    std::cout << ans << "\n";
}
