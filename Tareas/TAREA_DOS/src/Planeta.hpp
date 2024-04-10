/**
 * @file Planeta.hpp
 * @brief Definición de la clase Planeta
 *
 * Archivo que contiene la definición de la clase Planeta, que representa un planeta con sus continentes y la cantidad de estos.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <string>
#include <iostream>
#include <vector> 
using namespace std;

//Clase Planeta como atributos tiene los continentes y la cantidad de estos
/**
 * @brief Clase Planeta que representa un planeta con sus continentes y la cantidad de estos.
 */
class Planeta{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    public:
        vector<string> continets;
        int number_continets;
        vector<string> selectedContinents;
        //Constructor
        /**
         * @brief Constructor de la clase.
         * 
         * @param _continets Vector que contiene los nombres de los continentes.
         * @param _number_continets Cantidad de continentes en el planeta.
         * @param _selectedContinents Vector que contiene los continentes seleccionados.
         */
        Planeta(vector<string> _continets, int _number_continets, vector<string> _selectedContinents);

};

#endif //PLANETA_HPP