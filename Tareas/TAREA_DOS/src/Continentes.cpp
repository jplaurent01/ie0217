// Nombre del archivo: Continentes.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#include "Continentes.hpp"
#include <string>
#include <iostream>
#include <vector> 
using namespace std;

//constructor de la clase 
Continentes::Continentes(string _continente, int _totalPaises, int _totalPaisesDesarrollo, int _totalPaisesPrimerMundo) :
continente(_continente), totalPaises(_totalPaises), totalPaisesDesarrollo(_totalPaisesDesarrollo), totalPaisesPrimerMundo(_totalPaisesPrimerMundo){}

//Metodo void para mostrar datos de los continentes
void Continentes::mostrarDetalles() const {
    //ejemplo impresion America posee 7 paıses, 2 son de primer mundo y 5 son en desarrollo.
    cout << continente << " posee " << totalPaises << " paises, " << totalPaisesPrimerMundo << " son de primer mundo y " << totalPaisesDesarrollo << " son en desarrollo."<< endl;
}