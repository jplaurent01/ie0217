// Nombre del archivo: PaisPrimerMundo.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Pais.hpp"

using namespace std;

class PaisPrimerMundo : public Pais{
    private:
        bool tec5G;
        bool aeropuerto;
        bool investigacion;
    public:
        PaisPrimerMundo(string _name, int _id, int _habitantes, bool tec5G, bool aeropuerto, bool investigacion);
        void mostrarDetalles();
    private:
        //Metodo calcular cuanta gente trabaja y no de forma aleatoria
        void calcularTrabajo(int habitantes);
    
};

#endif //PAISPRIMERMUNDO_HPP