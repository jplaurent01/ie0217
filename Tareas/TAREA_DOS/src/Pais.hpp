// Nombre del archivo: Pais.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef PAIS_HPP
#define PAIS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Pais{
    protected:
        int id;
        int habitantes;
        double pib;
        //Constructor de la clase
        Pais(int _id, int _habitantes);
    
    public:
        virtual double calcularPib() const;
    


};

#endif //PAIS_HPP