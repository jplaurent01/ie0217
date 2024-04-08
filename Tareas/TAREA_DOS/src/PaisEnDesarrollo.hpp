// Nombre del archivo: PaisEnDesarrollo.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef PAISENDESARROLLO_HPP
#define PAISENDESARROLLO_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Pais.hpp"

using namespace std;

class PaisEnDesarrollo : public Pais{
    private:
        //bool tec5G;
        bool aeropuerto;
        //bool investigacion;
    public:
        PaisEnDesarrollo(string _name, int _id, int _habitantes,  bool aeropuerto);
        void mostrarDetalles();
    
    
};

#endif //PAISENDESARROLLO_HPP