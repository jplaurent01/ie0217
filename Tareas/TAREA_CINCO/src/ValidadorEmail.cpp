#include "ValidadorEmail.hpp"
#include <regex>
#include <iostream>
#include <stdexcept>
#include "Funciones.hpp"

ValidadorEmail::ValidadorEmail(std::string _email) :
    email(_email) {}

void ValidadorEmail::validarCorreo(){
    
    //std::regex pattern("([[^.-_]a-zA-Z0-9]{1,15}+@[[^.]a-zA-Z[$.]]{3,30}+\\.[a-zA-Z]{2,6})");
    //std::regex pattern("/^[a-zA-Z0-9.-_]+@[a-zA-Z0-9]+.[a-zA-Z]{2,6})*$/");
    //std::regex pattern("^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$");
    
    if (!email.empty()){
        //Expresion regular
        std::regex pattern("^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$");
        //std::regex pattern("^[a-zA-Z0-9](?:[a-zA-Z0-9](?:[.-_](?![.-_])[a-zA-Z0-9])?{0,14}[a-zA-Z0-9])?+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$");

        if (std::regex_match(email, pattern)) {

            //std::cout << "Direccion de correo VALIDA" << std::endl;
            validarNombre(email);

        } else {

            throw std::invalid_argument("Direccion de correo no valida, vuelva a intentar..."); 
            //std::cout << "Direccion de correo no valida" << std::endl;
        }
        
    }else{
        throw std::invalid_argument("Se agrego un correo vacio, vuelva a intentar...");     
    }
    
    
    
}


