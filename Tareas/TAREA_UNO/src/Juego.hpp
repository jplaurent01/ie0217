// Nombre del archivo: juego.hpp
//
// Descripción:Este archivo contiene una estructura sin inicializar con atributos de una partida de ahorcado.
//
// Copyright (c) 2022 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <iostream>
#include <string>
#include <array>
using namespace std;

//Se crea tipo de dato tipo Contacto con atributos de nombre y telefono
/**
 * @brief Struct que representa un juego de ahorcado.
 * 
 * Esta Struct contiene informacion sobre la palabra aleatoria, un array que contiene la palabra letra por letra
 * la cantidad maxima de intentos y el conteo actual de los intentos realizados
 */
struct Juego{

    string palabra;///< La palabra a adivinar.
    string array[15];///< Estado actual de la palabra adivinada (letras adivinadas y letras aun no adivinadas).
    int max; ///< El numero maximo de intentos permitidos.
    int intentos; ///< El numero actual de intentos realizados.
};

#endif //JUEGO_HPP