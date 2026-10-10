#include <iostream>
#include "Vehiculo.h"
#include "SistemaAlquiler.h"

int main() {
    SistemaAlquiler sistema;

    // Registrar vehículos (Autos y Bicicletas)
    sistema.registrarVehiculo(new Auto("Renault", "Logan", "ABC-123", 5));
    sistema.registrarVehiculo(new Auto("Mazda", "CX-30", "XYZ-789", 5));
    sistema.registrarVehiculo(new Bicicleta("Trek", "Marlin 5", "BIC-01", "montaña"));

    std::cout << "\n";
    sistema.mostrarVehiculosDisponibles();

    std::cout << "\n--- Simulacion de Alquiler ---\n";
    sistema.alquilarVehiculo("ABC-123");

    std::cout << "\n";
    sistema.mostrarVehiculosDisponibles();

    std::cout << "\n--- Simulacion de Devolucion ---\n";
    sistema.devolverVehiculo("ABC-123");

    return 0;
}
