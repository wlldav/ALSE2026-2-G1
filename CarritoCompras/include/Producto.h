#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    int stock;

public:
    Producto(std::string n, double p, int s);

    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    void reducirStock(int cantidad);
    void mostrarInformacion() const;
};

#endif
