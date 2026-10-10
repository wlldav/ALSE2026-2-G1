#include "Libro.h"
#include <iostream>

Libro::Libro(std::string t, std::string a, std::string i)
    : titulo(t), autor(a), isbn(i), disponible(true) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getIsbn() const { return isbn; }
bool Libro::isDisponible() const { return disponible; }

void Libro::setDisponible(bool estado) { disponible = estado; }

void Libro::mostrarInformacion() const {
    std::cout << "[ISBN: " << isbn << "] " << titulo << " - " << autor 
              << " | Estado: " << (disponible ? "Disponible" : "Prestado") << std::endl;
}
