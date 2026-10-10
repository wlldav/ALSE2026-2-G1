#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "Libro.h"
#include "Usuario.h"

class Biblioteca {
private:
    std::vector<Libro> libros;
    std::vector<Usuario*> usuarios;

public:
    void agregarLibro(const Libro& libro);
    void eliminarLibro(const std::string& isbn);
    void buscarPorTitulo(const std::string& titulo) const;
    void buscarPorAutor(const std::string& autor) const;
    void mostrarLibrosDisponibles() const;
    
    void registrarUsuario(Usuario* usuario);
    bool prestarLibro(const std::string& isbn, const std::string& idUsuario);
    bool devolverLibro(const std::string& isbn);
};

#endif
