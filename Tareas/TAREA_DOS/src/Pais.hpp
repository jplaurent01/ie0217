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
        string name;
        int id;
        int habitantes;
        double pib;
        
    
    public:
        //Constructor de la clase
        Pais(string _name, int _id, int _habitantes);
        virtual double calcularPib() const;
        void realizarComparacion(const Pais pais0, const Pais pais1) const;
        bool isPrimo(int num) const;
    private:
        //metodo comparador de paises, retorna un boleano en caso de que sus ID sean o no primos
        bool operator== (const Pais& pais1) const;

};

#endif //PAIS_HPP