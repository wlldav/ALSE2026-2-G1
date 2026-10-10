#include "Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado exitosamente: " << libro.getTitulo() << std::endl;
}

void Biblioteca::eliminarLibro(const std::string& isbn) {
    auto it = std::remove_if(libros.begin(), libros.end(), [&isbn](const Libro& l) {
        return l.getIsbn() == isbn;
    });
    if (it != libros.end()) {
        libros.erase(it, libros.end());
        std::cout << "Libro con ISBN " << isbn << " eliminado." << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }
}

void Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::cout << "--- Resultados busqueda por titulo: '" << titulo << "' ---" << std::endl;
    for (const auto& l : libros) {
        if (l.getTitulo().find(titulo) != std::string::npos) {
            l.mostrarInformacion();
        }
    }
}

void Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::cout << "--- Resultados busqueda por autor: '" << autor << "' ---" << std::endl;
    for (const auto& l : libros) {
        if (l.getAutor().find(autor) != std::string::npos) {
            l.mostrarInformacion();
        }
    }
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "--- Libros Disponibles en Biblioteca ---" << std::endl;
    for (const auto& l : libros) {
        if (l.isDisponible()) {
            l.mostrarInformacion();
        }
    }
}

void Biblioteca::registrarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
    std::cout << "Usuario registrado: " << usuario->getNombre() << std::endl;
}

bool Biblioteca::prestarLibro(const std::string& isbn, const std::string& idUsuario) {
    for (auto& l : libros) {
        if (l.getIsbn() == isbn) {
            if (l.isDisponible()) {
                l.setDisponible(false);
                std::cout << "Libro '" << l.getTitulo() << "' prestado con exito." << std::endl;
                return true;
            } else {
                std::cout << "El libro ya se encuentra prestado." << std::endl;
                return false;
            }
        }
    }
    std::cout << "Libro no encontrado." << std::endl;
    return false;
}

bool Biblioteca::devolverLibro(const std::string& isbn) {
    for (auto& l : libros) {
        if (l.getIsbn() == isbn) {
            l.setDisponible(true);
            std::cout << "Libro '" << l.getTitulo() << "' devuelto exitosamente." << std::endl;
            return true;
        }
    }
    std::cout << "Libro no encontrado." << std::endl;
    return false;
}

