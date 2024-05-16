#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iostream>
#include <regex>
#include <algorithm>

/**
 * @brief Valida que el nombre cumpla con ciertas reglas.
 * 
 * @param nombre El nombre a validar.
 * @throw std::invalid_argument Si el nombre no cumple con las reglas.
 */
void validarNombre(const std::string &nombre);

/**
 * @brief Divide una cadena en un vector de cadenas.
 * 
 * @param nombre La cadena a dividir.
 * @return std::vector<std::string> El vector de cadenas resultante.
 */
std::vector<std::string> splitString(const std::string &nombre);

/**
 * @brief Valida que el dominio cumpla con ciertas reglas.
 * 
 * @param dominio El dominio a validar.
 * @throw std::invalid_argument Si el dominio no cumple con las reglas.
 */
void validarDominio(const std::string &dominio);

/**
 * @brief Valida que la extension cumpla con ciertas reglas.
 * 
 * @param extension La extension a validar.
 * @throw std::invalid_argument Si la extension no cumple con las reglas.
 */
void validarExtension(const std::string &extension);

/**
 * @brief Calcula el tamaño del nombre.
 * 
 * @param nombre El nombre del archivo.
 * @param Flag Un indicador para especificar el tamaño deseado.
 * @return int El tamaño del nombre.
 */
int nombreTamanio(const std::string &nombre, int Flag);

/**
 * @brief Cuenta el numero de arrobas en una cadena.
 * 
 * @param text La cadena en la que contar las arrobas.
 * @return int El numero de arrobas.
 */
int contarArrobas(const std::string &text);

#endif //FUNCIONES_HPP