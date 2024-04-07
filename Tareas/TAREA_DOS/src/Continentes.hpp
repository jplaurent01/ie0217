// Nombre del archivo: Continentes.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#ifndef CONTINENTES_HPP
#define CONTINENTES_HPP


#include <string>
#include <iostream>
#include <vector> 
using namespace std;

class Continentes{
    public:
        string continente;
        int totalPaises;
        int totalPaisesDesarrollo;
        int totalPaisesPrimerMundo;
        //Constructor de la clase
        Continentes( string _continente, int _totalPaises, int _totalPaisesDesarrollo, int _totalPaisesPrimerMundo);

        virtual void mostrarDetalles() const;

};

#endif //CONTINENTES_HPP