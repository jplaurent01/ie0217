/**
 * @file Validadro de entrada.hpp
 * @brief Valida los datos ingreados por el usuario en la matriz
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef VALIDADORDEENTRADA_HPP
#define VALIDADORDEENTRADA_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <complex>
#include <sstream>


template <typename T>
class ValidadorDeEntrada {

    public:
        /**
         * @brief Valida el tipo de dato ingresado por el usuario.
         * @param input Cadena de entrada del usuario.
         * @param tName Nombre del tipo de dato a validar ("i" para entero, "f" para flotante).
         * @param value Referencia al valor donde se almacenará el dato validado.
         * @return Verdadero si el dato es válido, falso en caso contrario.
         */
        bool validarTipoDato(std::string input, std::string tName, T &value){
            //Csso entero
            if ( !input.empty() && all_of(input.begin(), input.end(), esDigit) && tName == "i"){
                try{
                    value = stoi(input);
                    std::cout << "\nDato int valido" << std::endl;
                    return true;
                }
                catch(...){
                    std::cout << "Imposible convertir a int" << std::endl;
                    return false;
                }
                
            }
            //Caso flotante
            if (!input.empty() && all_of(input.begin(), input.end(), isfloat) && tName == "f"){

                try{

                    value = stof(input);
                    std::cout << "\nDato float valido" << std::endl;
                    return true;
                }
                catch(...){
                    std::cout << "Imposible convertir a float" << std::endl;
                    return false;
                }
                
            }
            //Caso  complejo
            if(std::is_same<T, std::complex<double>>::value && !input.empty()){ 
            
                std::string result = input; 
                //Crear un stringstream a partir del string result
                std::stringstream ss(result);
                //Vector para almacenar las partes separadas
                std::vector<std::string> partes;
                //Variable temporal para almacenar cada parte
                std::string parte;
                // Leer partes del stringstream hasta encontrar el delimitador ","
                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte); // Agregar la parte al vector
                }

                //verifica cantidad de comas encontradas y que los datos no sean vacios
                if (partes.size()>2 || partes[0].empty() || partes[1].empty()){
                    std::cout << "Se agrego un caracter invalido, digite de nuevo..." << std::endl;
                    return false;
                }else {
                    //verifico que se ingrese un numero
                    if (all_of(partes[0].begin(), partes[0].end(), isfloat)){
                        if (all_of(partes[1].begin(), partes[1].end(), isfloat)){
                            try {
                                std::cout << "\nDato float valido" << std::endl;
                                return true;

                            } catch (...) {
                                std::cout << "Imposible convertir a complex" << std::endl;
                                return false;
                            }
                        }else{
                            std::cout << "La parte imaginaria no es un numero" << std::endl; 
                        }
                    }else{
                        std::cout << "La parte real no es un numero" << std::endl; 
                    }
                }
            }
            
            return false;

        };

        /**
         * @brief Valida el tamaño de la matriz ingresado por el usuario.
         * @param tamanio Tamaño de la matriz a validar.
         * @throw std::invalid_argument Si el tamaño es inválido.
         */
        
        void validarDimensiones(const int tamanio){
            std::cout << tamanio << std::endl;
            if (tamanio > 0){
                std::cout << "Dimension valida" << std::endl;
            }else {
                throw std::invalid_argument("Dimension invalida debe ingresar de nuevo las matrices");
            }
            
        };

    private:
        //metodos me indican s agregue un numero son estaticos para no inicializar
        static bool isfloat(const char& c) {
            return std::isdigit(c) || c == '.' || c == '-';
        };

        static bool esDigit(const char& c) {
            return std::isdigit(c) || c == '-';
        };


};

#endif //VALIDADORDEENTRADA_HPP