#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(Producto* p, int cant) : producto(p), cantidad(cant) {}

Producto* ItemCarrito::getProducto() const { return producto; }
int ItemCarrito::getCantidad() const { return cantidad; }
double ItemCarrito::getSubtotal() const { return producto->getPrecio() * cantidad; }
void ItemCarrito::setCantidad(int cant) { cantidad = cant; }
