#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <stdexcept>
#include <vector>

void validarNombre(const std::string &nombre);
std::vector<std::string> splitString(const std::string &nombre);
void validarDominio(const std::string &nombre);

#endif //FUNCIONES_HPP