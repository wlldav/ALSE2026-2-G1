#include <iostream>
#include "Producto.h"
#include "ItemCarrito.h"
#include "CarritoCompras.h"
#include "Usuario.h"

int main() {
    // Crear productos
    Producto p1("Laptop", 2500.0, 5);
    Producto p2("Mouse Inalambrico", 50.0, 20);
    Producto p3("Teclado Mecanico", 120.0, 10);

    // Crear usuario
    UsuarioShop cliente("Wilinton Asencio", "wilinton@escuelaing.edu.co");

    CarritoCompras carrito;

    std::cout << "\n";
    p1.mostrarInformacion();
    p2.mostrarInformacion();

    std::cout << "\n--- Operaciones de Carrito ---\n";
    carrito.agregarProducto(&p1, 1);
    carrito.agregarProducto(&p2, 2);

    std::cout << "\n";
    carrito.mostrarCarrito();

    std::cout << "\n--- Procesando Compra ---\n";
    // Descontar stock y registrar en historial
    for (auto& item : carrito.getItems()) {
        item.getProducto()->reducirStock(item.getCantidad());
    }
    cliente.agregarAlHistorial("Compra de Laptop (1) y Mouse Inalambrico (2) - Total: $2600.0");
    carrito.limpiarCarrito();

    std::cout << "\n";
    cliente.verHistorial();

    std::cout << "\n";
    p1.mostrarInformacion(); // Mostrar stock actualizado

    return 0;
}
