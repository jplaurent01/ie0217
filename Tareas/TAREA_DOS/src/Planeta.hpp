// Nombre del archivo: Planeta.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <string>
#include <iostream>
#include <vector> 
using namespace std;

//Clase Planeta como atributos tiene los continentes y la cantidad de estos
class Planeta{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    public:
        vector<string> continets;
        int number_continets;
        vector<string> selectedContinents;
        //Constructor
        Planeta(vector<string> _continets, int _number_continets, vector<string> _selectedContinents);

};

#endif //PLANETA_HPP