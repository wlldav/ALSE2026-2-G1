#include <cmath>
#include <string>

namespace armstrong_numbers {
    bool is_armstrong_number(int number) {
        if (number < 0) return false;
        std::string s = std::to_string(number);
        int length = s.length();
        long long sum = 0;
        for (char c : s) {
            int digit = c - '0';
            sum += std::pow(digit, length);
        }
        return sum == number;
    }
}
