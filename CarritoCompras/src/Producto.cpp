#include "Producto.h"
#include <iostream>

Producto::Producto(std::string n, double p, int s)
    : nombre(n), precio(p), stock(s) {}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

void Producto::reducirStock(int cantidad) {
    if (stock >= cantidad) {
        stock -= cantidad;
    }
}

void Producto::mostrarInformacion() const {
    std::cout << "[Producto] " << nombre << " - $" << precio << " | Stock disponible: " << stock << std::endl;
}
