#include "Usuario.h"
#include <iostream>

UsuarioShop::UsuarioShop(std::string n, std::string e) : nombre(n), email(e) {}

std::string UsuarioShop::getNombre() const { return nombre; }

void UsuarioShop::agregarAlHistorial(const std::string& detalleCompra) {
    historialCompras.push_back(detalleCompra);
}

void UsuarioShop::verHistorial() const {
    std::cout << "--- Historial de Compras de " << nombre << " ---\n";
    if (historialCompras.empty()) {
        std::cout << "No hay compras registradas.\n";
        return;
    }
    for (const auto& compra : historialCompras) {
        std::cout << "[Compra] " << compra << std::endl;
    }
}
