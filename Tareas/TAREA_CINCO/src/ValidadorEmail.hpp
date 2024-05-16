#ifndef VALIDADOREMAIL_HPP
#define VALIDADOREMAIL_HPP
#include <regex>
#include <iostream>
#include <stdexcept>
#include "Funciones.hpp"

#include <string>

/**
 * @brief Clase para validar correos electronicos.
 */
class ValidadorEmail{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    protected:
        std::string nombre;
        std::string dominio;
        std::string extension;
 
    public:
        /**
         * @brief Constructor de la clase ValidadorEmail.
         * 
         * @param _nombre El nombre del correo electronico.
         * @param _dominio El dominio del correo electronico.
         * @param _extension La extension del correo electronico.
         */
        ValidadorEmail(const std::string& _nombre, const std::string& _dominio, const std::string& _extension);
        
        /**
         * @brief Valida el correo electronico y lo almacena en un vector.
         * 
         * @param almacenCorreos El vector donde se almacenaran los correos validos.
         */
        void validarCorreo(std::vector<std::string>& almacenCorreos);

};

#endif //VALIDADOREMAIL_HPP