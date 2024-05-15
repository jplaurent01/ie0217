#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iostream>
#include <regex>
#include <algorithm>

void validarNombre(const std::string &nombre);
std::vector<std::string> splitString(const std::string &nombre);
void validarDominio(const std::string &dominio);
void validarExtensión(const std::string &extension);
int nombreTamanio(const std::string &nombre, int Flag);
int contarArrobas(const std::string &text);
//std::pair<std::string, std::string> splitDominioExtension(const std::string &nombre);
//void getreverse(std::string &str, int i);
#endif //FUNCIONES_HPP