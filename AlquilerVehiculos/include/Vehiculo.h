#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(std::string m, std::string mod, std::string p);
    virtual ~Vehiculo() = default;

    std::string getMarca() const;
    std::string getModelo() const;
    std::string getPlaca() const;
    bool isDisponible() const;

    void setDisponible(bool estado);
    virtual void mostrarInformacion() const = 0; // Método virtual puro
};

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(std::string m, std::string mod, std::string p, int pasajeros);
    void mostrarInformacion() const override;
};

class Bicicleta : public Vehiculo {
private:
    std::string tipo; // montaña, ruta, urbana

public:
    Bicicleta(std::string m, std::string mod, std::string p, std::string t);
    void mostrarInformacion() const override;
};

#endif
