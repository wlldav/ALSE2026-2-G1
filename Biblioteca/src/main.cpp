#include <iostream>
#include "Libro.h"
#include "Usuario.h"
#include "Biblioteca.h"

int main() {
    Biblioteca miBiblioteca;

    // Agregar libros
    miBiblioteca.agregarLibro(Libro("Cien anos de soledad", "Gabriel Garcia Marquez", "978-0307474728"));
    miBiblioteca.agregarLibro(Libro("El amor en los tiempos del colera", "Gabriel Garcia Marquez", "978-0307389732"));
    miBiblioteca.agregarLibro(Libro("Clean Code", "Robert C. Martin", "978-0132350884"));

    // Registrar usuarios (Bonus POO: Herencia)
    Estudiante est1("Wilinton Asencio", "E001");
    Profesor prof1("Daniel Palomino}", "P001");
    miBiblioteca.registrarUsuario(&est1);
    miBiblioteca.registrarUsuario(&prof1);

    std::cout << "\n";
    miBiblioteca.mostrarLibrosDisponibles();

    std::cout << "\n--- Simulacion de Prestamo ---" << std::endl;
    miBiblioteca.prestarLibro("978-0307474728", "E001");

    std::cout << "\n";
    miBiblioteca.mostrarLibrosDisponibles();

    std::cout << "\n--- Simulacion de Devolucion ---" << std::endl;
    miBiblioteca.devolverLibro("978-0307474728");

    return 0;
}
