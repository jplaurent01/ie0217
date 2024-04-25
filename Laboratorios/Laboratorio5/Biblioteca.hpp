#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "Libro.hpp"

//Clase biblioteca
class Biblioteca  {
//Atributo privado, vector de libros
private:
    //Vector de objetos de tipo libro
    std::vector<Libro> libros;

public:

    //Mediante el método de tipo void, tengo acceso al atributo privado del vector de libros
    void agregarLibro(const Libro& libro) {
        //Inserto un nuevo libro en el vector
        libros.push_back(libro);
    }

    //Itero sobre todo el vector de libros, sin editarlos para poder imprimirlos
    void mostrarLibros() {
        for (const auto& libro : libros) {
            std::cout << libro.titulo << ", " << libro.autor << ", " << libro.anioPublicacion << std::endl;
        }
    }

    //Se ordenan los libros por anio
    void ordenarLibrosPorAnio() {
        //Sort rebibe como argumento un puntero al inicio y final del vector
        //son iteradores
        std::sort(libros.begin(), libros.end());
    }

   //Funcion que retorna un iterador, recibe como parametro la referencia del string original, pero este no puede
   //modificarse
    std::vector<Libro>::iterator buscarLibroPorTitulo(const std::string& titulo) {
        //se busca un elemento dentro del rango inicial y final del vector de libros
        return std::find_if(libros.begin(), libros.end(), [&titulo](const Libro& l) {
            //Si el titulo del libro es igual al titulo buscado, la funcion devuelve true
            return l.titulo == titulo;
        });
    }

    //Esta función end() devuelve un iterador que apunta al final del vector libros. 
    std::vector<Libro>::iterator end() {
        return libros.end();
    }
};
#endif //BIBLIOTECA_HPP