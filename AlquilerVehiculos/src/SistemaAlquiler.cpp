#include "SistemaAlquiler.h"
#include <iostream>

SistemaAlquiler::~SistemaAlquiler() {
    for (auto v : vehiculos) {
        delete v;
    }
}

void SistemaAlquiler::registrarVehiculo(Vehiculo* vehiculo) {
    vehiculos.push_back(vehiculo);
    std::cout << "Vehiculo registrado exitosamente.\n";
}

void SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            if (v->isDisponible()) {
                v->setDisponible(false);
                std::cout << "Vehiculo con placa " << placa << " alquilado con exito.\n";
            } else {
                std::cout << "El vehiculo ya se encuentra alquilado.\n";
            }
            return;
        }
    }
    std::cout << "Vehiculo no encontrado.\n";
}

void SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    for (auto& v : vehiculos) {
        if (v->getPlaca() == placa) {
            v->setDisponible(true);
            std::cout << "Vehiculo con placa " << placa << " devuelto exitosamente.\n";
            return;
        }
    }
    std::cout << "Vehiculo no encontrado.\n";
}

void SistemaAlquiler::mostrarVehiculosDisponibles() const {
    std::cout << "--- Vehiculos Disponibles para Alquiler ---\n";
    for (const auto& v : vehiculos) {
        if (v->isDisponible()) {
            v->mostrarInformacion();
        }
    }
}
