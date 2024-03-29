#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <iostream>
#include <string>
#include <array>
using namespace std;
//#define MAX_CONTACTOS 15
//Se crea tipo de dato tipo Contacto con atributos de nombre y telefono
struct Juego{

    string palabra;
    string array[15];
    int max;
    int intentos;
};

#endif //JUEGO_HPP