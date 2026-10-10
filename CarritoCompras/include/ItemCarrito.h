#ifndef ITEM_CARRITO_H
#define ITEM_CARRITO_H

#include "Producto.h"

class ItemCarrito {
private:
    Producto* producto;
    int cantidad;

public:
    ItemCarrito(Producto* p, int cant);

    Producto* getProducto() const;
    int getCantidad() const;
    double getSubtotal() const;
    void setCantidad(int cant);
};

#endif
