#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nombre;
    std::string id;

public:
    Usuario(std::string n, std::string i);
    virtual ~Usuario() = default;

    std::string getNombre() const;
    std::string getId() const;
    virtual int getLimitePrestamos() const = 0; // Método virtual puro
};

class Estudiante : public Usuario {
public:
    Estudiante(std::string n, std::string i);
    int getLimitePrestamos() const override;
};

class Profesor : public Usuario {
public:
    Profesor(std::string n, std::string i);
    int getLimitePrestamos() const override;
};

#endif
