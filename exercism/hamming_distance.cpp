#include <string>
#include <stdexcept>

namespace hamming {
    int compute(const std::string& a, const std::string& b) {
        if (a.length() != b.length()) {
            throw std::domain_error("DNA strands must be of equal length.");
        }
        int distance = 0;
        for (size_t i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                distance++;
            }
        }
        return distance;
    }
}
