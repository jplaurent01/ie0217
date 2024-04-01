#ifndef FUNCIONES_HPP
#define FUNCIONES_HP
#include <vector>
#include <iostream>
#include <string>
#include "Juego.hpp"
#include<map> //Dicionrio de c++

//Envio un puntero de tipo Juego
void inicializar(Juego* play1, vector<string> array);
void adivinar(Juego* play1);
//retorna un boleano indicando si hay letras repetidas en la palabra
bool letrasRepetidas(const std::string& palabra);
//Funcion verifica la cantdad de intentos y si la palabra se ha encontrado
//Cambio el valor de la variable intentos
bool verificar(map<int, char> dict, Juego* play1);
//Funcion determina si un caracter es una letra o no
bool isLetra(char letra);


#endif //FUNCIONES_HPP