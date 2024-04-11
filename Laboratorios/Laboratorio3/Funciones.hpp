#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include "Libro.hpp"

//Agrego libros
void agregarLibro(Libro*& lista);
//Muestro los libros creados
void mostrarLibro(Libro* lista);
//Libero memoria del programa 
void liberarMemoria(Libro* &lista);
#endif //FUNCIONES_HPP