#include "queen_attack.h"
#include <cmath>

namespace queen_attack {

chess_board::chess_board() : white_{0, 3}, black_{7, 3} {}

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) 
    : white_{white}, black_{black} {
    
    if (white.first < 0 || white.first > 7 || white.second < 0 || white.second > 7 ||
        black.first < 0 || black.first > 7 || black.second < 0 || black.second > 7) {
        throw std::domain_error("Las posiciones deben estar dentro del tablero.");
    }

    if (white == black) {
        throw std::domain_error("Las reinas no pueden ocupar la misma posicion.");
    }
}

std::pair<int, int> chess_board::white() const {
    return white_;
}

std::pair<int, int> chess_board::black() const {
    return black_;
}

bool chess_board::can_attack() const {
    if (white_.first == black_.first || white_.second == black_.second) {
        return true;
    }

    if (std::abs(white_.first - black_.first) == std::abs(white_.second - black_.second)) {
        return true;
    }

    return false;
}

}  // namespace queen_attack
