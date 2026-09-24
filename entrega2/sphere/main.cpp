#include <iostream>
#include "sphere.h"

int main() {
    try {
        Sphere s1;
        std::cout << "--- Esfera por defecto ---" << std::endl;
        std::cout << "Radio: " << s1.get_radius() << std::endl;
        std::cout << "Area de Superficie: " << s1.surface_area() << std::endl;
        std::cout << "Volumen: " << s1.volume() << std::endl;

        Sphere s2(5.0);
        std::cout << "\n--- Esfera R = 5.0 ---" << std::endl;
        std::cout << "Radio: " << s2.get_radius() << std::endl;
        std::cout << "Area de Superficie: " << s2.surface_area() << std::endl;
        std::cout << "Volumen: " << s2.volume() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
