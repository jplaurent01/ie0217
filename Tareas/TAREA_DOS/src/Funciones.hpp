// Nombre del archivo: Funciones.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include "Planeta.hpp"
#include "Continentes.hpp"
#include "PaisPrimerMundo.hpp"
#include "PaisEnDesarrollo.hpp"
#include "Pais.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_map>


//Envio un objeto planeta y una copia de un dicionario con instruciones para crear paises.
void imprimirPlaneta(Planeta tierra, unordered_map<std::string,
std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);
//Funcion determina si un numero es o no es primo.
bool isPrimo(int num);
//Funcion que me filtra la informacion de acuerdo al continente:
void filterByContinent(string keyWord, int &cantidadPaises0, int &primos0,
 int &noPrimos0, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,
  vector<PaisPrimerMundo> &paisesPrimerMundoContinente, vector<PaisEnDesarrollo> &paisesEnDesarrolloContinente);
//Convierto de string a booleano
bool stringToBool(const string& str);
//Funcion agrega un nuevo pais por continente al vector.
void agregarInformacion(string nombreContinente,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta);
 //Funcion determina se el id o pais está repetido
 bool idIsUnique(string num, string nombrePais,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);
 //convierto de booleano a string
 string boolToString(bool valor) ;
 //Elimina un pais del dicionario
 void eliminarId(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta);
 //Funcion determina se el id está repetido, Sobrecargo esta funcion
 bool idIsUnique(string num,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);
 //Funcion para comparar paises.
 void compararPaises(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);
//Funcion retorna un objeto de tipo Pais inicializado de acuerdo a un flitro
void retornarPais(string id, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta, vector<Pais> &paisesContinente);
#endif //FUNCIONES_HPP