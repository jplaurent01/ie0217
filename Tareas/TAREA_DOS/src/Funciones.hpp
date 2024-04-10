/**
 * @file Funciones.hpp
 * @brief Archivo que contiene los header files
 * Este archivo contiene el prototipo de las funciones para el funcionamiento del programa
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @see Planeta, Continentes, PaisPrimerMundo, PaisEnDesarrollo, Pais
 * @license MIT
 */

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
/**
 * @brief Imprime la información de un planeta y sus países.
 * 
 * @param tierra Objeto de tipo Planeta a imprimir.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void imprimirPlaneta(Planeta tierra, unordered_map<std::string,
std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);

//Funcion determina si un numero es o no es primo.
/**
 * @brief Determina si un número es primo.
 * 
 * @param num Número a verificar.
 * @return true Si el número es primo.
 * @return false Si el número no es primo.
 */
bool isPrimo(int num);


//Funcion que me filtra la informacion de acuerdo al continente:
/**
 * @brief Filtra la información de los países por continente.
 * 
 * @param keyWord Palabra clave de dicionario para filtrar.
 * @param cantidadPaises0 Cantidad de países filtrados.
 * @param primos0 Cantidad de países con id primo.
 * @param noPrimos0 Cantidad de países con id no primo.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @param paisesPrimerMundoContinente Vector de países de primer mundo del continente.
 * @param paisesEnDesarrolloContinente Vector de países en desarrollo del continente.
 */
void filterByContinent(string keyWord, int &cantidadPaises0, int &primos0,
 int &noPrimos0, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,
  vector<PaisPrimerMundo> &paisesPrimerMundoContinente, vector<PaisEnDesarrollo> &paisesEnDesarrolloContinente);

//Convierto de string a booleano
/**
 * @brief Convierte un string a bool.
 * 
 * @param str String a convertir.
 * @return true Si el string es "true".
 * @return false caso contrario.
 */
bool stringToBool(const string& str);

//Funcion agrega un nuevo pais por continente al vector.
/**
 * @brief Agrega un nuevo país por continente al vector.
 * 
 * @param nombreContinente Nombre del continente.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void agregarInformacion(string nombreContinente,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta);

 //Funcion determina se el id o pais está repetido
 /**
 * @brief Determina si el ID de un país está repetido.
 * 
 * @param num ID del país a verificar.
 * @param nombrePais Nombre del país.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @return true Si el ID está repetido.
 * @return false Si el ID no está repetido.
 */
 bool idIsUnique(string num, string nombrePais,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);
 
 //convierto de booleano a string
 /**
 * @brief Convierte un booleano a string.
 * 
 * @param valor Valor bool a convertir.
 * @return std::string "true" si el valor es true, "false" si es false.
 */
 string boolToString(bool valor) ;


 //Elimina un pais del dicionario
 /**
 * @brief Elimina un país del diccionario.
 * 
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
 void eliminarId(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta);
 
 //Funcion determina se el id está repetido, Sobrecargo esta funcion
 /**
 * @brief Funcion determina se el id está repetido, Sobrecargo esta funcion.
 * 
 * @param num ID del país a verificar.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @return true Si el ID está repetido.
 * @return false Si el ID no está repetido.
 */
 bool idIsUnique(string num,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);

 //Funcion para comparar paises.
 /**
 * @brief Funcion para comparar paises.
 * 
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
 void compararPaises(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta);

//Funcion edita el contenido del vector paisesContinente para insertar su respectivo constructor con la informacion del diccionario
 /**
 * @brief Funcion edita el contenido del vector paisesContinente para insertar su respectivo constructor con la informacion del diccionario
 * 
 * @param id Id del pais.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @param paisesContinente Vector que alberga el constructor con el que posterior mente se  comparan 2 paises.
 */
void retornarPais(string id, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta, vector<Pais> &paisesContinente);
#endif //FUNCIONES_HPP