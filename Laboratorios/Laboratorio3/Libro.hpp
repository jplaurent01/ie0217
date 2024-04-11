#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <iostream>
#include <string>
using namespace std;

//Estrucutura de tipo libro
struct Libro{
    string titulo;
    string autor;
    string genero;
    //Punto de tipo libor, eventualmente apunt a la siguiente dir. memoria con un nuevo objeto libro
    Libro* siguiente;
};
#endif //LIBRO_HPP