#include "crypto_square.h"
#include <cctype>
#include <cmath>

namespace crypto_square {

cipher::cipher(const std::string& text) {
    for (char c : text) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            text_ += std::tolower(static_cast<unsigned char>(c));
        }
    }
}

std::string cipher::normalize_plain_text() const {
    return text_;
}

std::vector<std::string> cipher::plain_text_segments() const {
    std::vector<std::string> segments;
    if (text_.empty()) return segments;

    size_t c = std::ceil(std::sqrt(text_.length()));
    
    for (size_t i = 0; i < text_.length(); i += c) {
        segments.push_back(text_.substr(i, c));
    }
    return segments;
}

std::string cipher::normalized_cipher_text() const { 
    if (text_.empty()) return "";

    size_t c = std::ceil(std::sqrt(text_.length()));
    size_t r = std::ceil(static_cast<double>(text_.length()) / c);

    std::string result;
    for (size_t i = 0; i < c; ++i) {
        for (size_t j = 0; j < r; ++j) {
            size_t index = j * c + i;
            if (index < text_.length()) {
                result += text_[index];
            } else {
                result += " "; 
            }
        }
        if (i < c - 1) {
            result += " ";
        }
    }
    return result;
}

}  // namespace crypto_square

