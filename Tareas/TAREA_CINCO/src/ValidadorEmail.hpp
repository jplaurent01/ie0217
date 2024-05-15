#ifndef VALIDADOREMAIL_HPP
#define VALIDADOREMAIL_HPP
#include <regex>
#include <iostream>
#include <stdexcept>
#include "Funciones.hpp"

#include <string>
class ValidadorEmail{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    protected:
        std::string nombre;
        std::string dominio;
        std::string extension;
 
    public:
        ValidadorEmail(const std::string& _nombre, const std::string& _dominio, const std::string& _extension);
        void validarCorreo(std::vector<std::string>& almacenCorreos);

};

#endif //VALIDADOREMAIL_HPP