#include <iostream>
#include "crypto_square.h"

int main() {
    crypto_square::cipher c("This is fun!");
    std::cout << "Texto cifrado: '" << c.normalized_cipher_text() << "'" << std::endl;
    return 0;
}

