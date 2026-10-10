#include "CarritoCompras.h"
#include <iostream>
#include <algorithm>

void CarritoCompras::agregarProducto(Producto* producto, int cantidad) {
    if (producto->getStock() < cantidad) {
        std::cout << "Stock insuficiente para agregar " << producto->getNombre() << std::endl;
        return;
    }

    for (auto& item : items) {
        if (item.getProducto()->getNombre() == producto->getNombre()) {
            item.setCantidad(item.getCantidad() + cantidad);
            std::cout << "Cantidad actualizada en el carrito para: " << producto->getNombre() << std::endl;
            return;
        }
    }

    items.push_back(ItemCarrito(producto, cantidad));
    std::cout << producto->getNombre() << " agregado al carrito." << std::endl;
}

void CarritoCompras::eliminarProducto(const std::string& nombreProducto) {
    auto it = std::remove_if(items.begin(), items.end(), [&nombreProducto](const ItemCarrito& item) {
        return item.getProducto()->getNombre() == nombreProducto;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "Producto eliminado del carrito." << std::endl;
    } else {
        std::cout << "El producto no se encuentra en el carrito." << std::endl;
    }
}

double CarritoCompras::calcularTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getSubtotal();
    }
    return total;
}

void CarritoCompras::mostrarCarrito() const {
    std::cout << "--- Contenido del Carrito de Compras ---\n";
    if (items.empty()) {
        std::cout << "El carrito esta vacio.\n";
        return;
    }
    for (const auto& item : items) {
        std::cout << "- " << item.getProducto()->getNombre() 
                  << " | Cantidad: " << item.getCantidad() 
                  << " | Subtotal: $" << item.getSubtotal() << std::endl;
    }
    std::cout << "Total a pagar: $" << calcularTotal() << "\n";
}

std::vector<ItemCarrito>& CarritoCompras::getItems() {
    return items;
}

void CarritoCompras::limpiarCarrito() {
    items.clear();
}
