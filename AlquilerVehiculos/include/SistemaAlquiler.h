#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include <vector>
#include <string>
#include "Vehiculo.h"

class SistemaAlquiler {
private:
    std::vector<Vehiculo*> vehiculos;

public:
    ~SistemaAlquiler();
    void registrarVehiculo(Vehiculo* vehiculo);
    void alquilarVehiculo(const std::string& placa);
    void devolverVehiculo(const std::string& placa);
    void mostrarVehiculosDisponibles() const;
};

#endif

