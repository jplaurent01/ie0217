#include "Funciones.hpp"
#include <sstream>
#include <iostream>
#include <regex>

void validarNombre(const std::string &nombre){
    std::vector<std::string> result = splitString(nombre);
    //std::cout << "Nombre: " << result[0] << std::endl;
    //std::cout << "Nombre: " << result[1] << std::endl;
    if (result[0].size() <= 15){

        std::regex pattern("[.-_]{2,}");

        if (!std::regex_search(result[0], pattern)){

            std::regex patternTwo("[.-_]");

            if(std::regex_search(result[0], patternTwo)){

                std::cout << "Nombre valido" << std::endl;

            }else{

            throw std::invalid_argument("Nombre debe contener alguno de los caracteres .-_, vuelva a intentar...");                
            
            }
           
        }else {
            throw std::invalid_argument("Nombre contiene los caracteres .-_ consecutivos, vuelva a intentar...");
        }
        

    }else{
         throw std::invalid_argument("La extension del nombre supera los 15 caracteres, vuelva a intentar...");
    }
    
    
};

std::vector<std::string> splitString(const std::string &nombre){
     
    //Crear un stringstream a partir del string result
    std::stringstream ss(nombre);
    //Vector para almacenar las partes separadas
    std::vector<std::string> partes;
    //Variable temporal para almacenar cada parte
    std::string parte;
    // Leer partes del stringstream hasta encontrar el delimitador ","
    while (std::getline(ss, parte, '@')) {
        partes.push_back(parte); // Agregar la parte al vector
    }

    if (partes.size() > 2){
        throw std::invalid_argument("Se ha ingresado multiplies veces el caracter @, vuelva a intentar...");
    }else if (partes.size() == 0){
        throw std::invalid_argument("No se ha detectado el caracter @, vuelva a intentar...");
    }
    
    return partes;
    
};