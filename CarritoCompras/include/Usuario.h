#ifndef USUARIO_SHOP_H
#define USUARIO_SHOP_H

#include <string>
#include <vector>

class UsuarioShop {
private:
    std::string nombre;
    std::string email;
    std::vector<std::string> historialCompras;

public:
    UsuarioShop(std::string n, std::string e);

    std::string getNombre() const;
    void agregarAlHistorial(const std::string& detalleCompra);
    void verHistorial() const;
};

#endif
