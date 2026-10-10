#include "Usuario.h"

Usuario::Usuario(std::string n, std::string i) : nombre(n), id(i) {}

std::string Usuario::getNombre() const { return nombre; }
std::string Usuario::getId() const { return id; }

Estudiante::Estudiante(std::string n, std::string i) : Usuario(n, i) {}
int Estudiante::getLimitePrestamos() const { return 3; }

Profesor::Profesor(std::string n, std::string i) : Usuario(n, i) {}
int Profesor::getLimitePrestamos() const { return 5; }
