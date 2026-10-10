#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(std::string m, std::string mod, std::string p)
    : marca(m), modelo(mod), placa(p), disponible(true) {}

std::string Vehiculo::getMarca() const { return marca; }
std::string Vehiculo::getModelo() const { return modelo; }
std::string Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::isDisponible() const { return disponible; }

void Vehiculo::setDisponible(bool estado) { disponible = estado; }

// --- Auto ---
Auto::Auto(std::string m, std::string mod, std::string p, int pasajeros)
    : Vehiculo(m, mod, p), capacidadPasajeros(pasajeros) {}

void Auto::mostrarInformacion() const {
    std::cout << "[Auto] Placa: " << placa << " | " << marca << " " << modelo 
              << " | Pasajeros: " << capacidadPasajeros 
              << " | Estado: " << (disponible ? "Disponible" : "Alquilado") << std::endl;
}

// --- Bicicleta ---
Bicicleta::Bicicleta(std::string m, std::string mod, std::string p, std::string t)
    : Vehiculo(m, mod, p), tipo(t) {}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[Bicicleta] Placa/ID: " << placa << " | " << marca << " " << modelo 
              << " | Tipo: " << tipo 
              << " | Estado: " << (disponible ? "Disponible" : "Alquilada") << std::endl;
}
