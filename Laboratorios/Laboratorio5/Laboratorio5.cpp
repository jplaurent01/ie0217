#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
#include "Biblioteca.hpp"
using namespace std;


int main() {
    //se crea objeto de tipo biblioteca
    Biblioteca miBiblioteca;
    //Inserto objetos de tipo libro en un vector privado de la clase miBilioteca
    miBiblioteca.agregarLibro({"Cien anios de soledad", "Gabriel Garcia Marquez", 1967});
    miBiblioteca.agregarLibro({"1984", "George Orwell", 1949});
    miBiblioteca.agregarLibro({"El senor de los anillos", "J.R.R. Tolkien", 1954});

    //miBiblioteca.mostrarLibros();

    cout << "Antes de Ordenar por Anio de publicacion..." << endl;
    miBiblioteca.mostrarLibros();
    cout << "\nDespues de Ordenar por Anio de publicacion..." << endl;
    miBiblioteca.ordenarLibrosPorAnio();
    miBiblioteca.mostrarLibros();


    /*La expresion auto libro = miBiblioteca.buscarLibroPorTitulo("1984"); 
    declara una variable libro e inicializa su valor con el resultado de la
    búsqueda del libro con el título "1984" en la biblioteca miBiblioteca.
    Si el libro se encuentra, libro sera un iterador que apunta al libro en el vector de
    libros de la biblioteca; de lo contrario, sera igual a miBiblioteca.end().
    */
    cout << "\nSe busca libro 1984..." << endl;
    auto libro = miBiblioteca.buscarLibroPorTitulo("1984");
    //En caso de que el libro se encuentre dentro de la iteracion de lasposciones de memoria destinadas
    // a cada uno
    //de los elementos del vector
    if (libro != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    cout << "\nSe busca libro Star Wars..." << endl;
    auto libro2 = miBiblioteca.buscarLibroPorTitulo("Star Wars");
    //En caso de que el libro se encuentre dentro de la iteracion de lasposciones de memoria destinadas
    // a cada uno
    //de los elementos del vector
    if (libro2 != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro2->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    return 0;
}
