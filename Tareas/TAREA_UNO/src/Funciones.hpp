// Nombre del archivo: funciones.hpp
//
// Descripción:Este archivo contiene el encabezado de las funciones inicializar, adivinar, isLetra y verificar.
//
// Copyright (c) 2022 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef FUNCIONES_HPP
#define FUNCIONES_HP
#include <vector>
#include <iostream>
#include <string>
#include "Juego.hpp"
#include<map> //Dicionrio de c++

//Envio un puntero de tipo Juego y un array de palabras
/**
 * @brief Inicializa un objeto Juego con un array de strings.
 * 
 * Esta función inicializa un objeto Juego con un array de strings, incializa por defecto en 10 la cantidad 
 * maxima de intentos, escoge una palabra aleatoria del array para inicializar la palabra del struct.
 * 
 * @param play1 Puntero al objeto Juego que se inicializará.
 * @param array Vector de strings que se utilizará para inicializar objeto de tipo Juego.
 */

void inicializar(Juego* play1, vector<string> array);

/**
 * @brief Se llama a esta funcion cuando se pretende iniciar el juego y adivinar una palabra.
 * 
 * Esta funcion permite iniciar el juego, recibe un objeto de tipo juego ya inicializado con una palabra 
 * aleatoria, cantidad maxima de intentos, durante su ejecucion se altera el atributos intentos del objeto
 * Juego.
 * 
 * @param play1  Puntero al objeto Juego.
 */

void adivinar(Juego* play1);

//retorna un boleano indicando si hay letras repetidas en la palabra
/**
 * @brief Verifica si una palabra tiene letras repetidas.
 * 
 * Esta función verifica si una palabra tiene letras repetidas.
 * 
 * @param palabra Parametro por referencia de la palabra a verificar, esta no se puede modificar por const.
 * @return true si la palabra tiene letras repetidas, false en caso contrario.
 */

bool letrasRepetidas(const std::string& palabra);

//Funcion verifica la cantdad de intentos y si la palabra se ha encontrado
//Cambio el valor de la variable intentos
/**
 * @brief Funcion que chequea si se ha encontrado la palabra o se han agotado los intentos.
 * 
 * Esta funcion verifica si se ha encontrado la palabra o se han agotado los intentos,
 * y actualiza la variable de intentos.
 * 
 * @param dict Diccionario que contiene las letras adivinadas.
 * @param play1 Puntero al objeto Juego, este puntero se modifica con la cantidad de intentos.
 * @return true si se ha encontrado la palabra o se han agotado los intentos, false en caso contrario.
 */

bool verificar(map<int, char> dict, Juego* play1);

//Funcion determina si un caracter es una letra o no
/**
 * @brief Determina si un caracter es una letra o no.
 * 
 * Esta función determina si un caracter es una letra o no.
 * 
 * @param letra El caracter a verificar.
 * @return true si el caracter es una letra, false en caso contrario.
 */

bool isLetra(char letra);


#endif //FUNCIONES_HPP