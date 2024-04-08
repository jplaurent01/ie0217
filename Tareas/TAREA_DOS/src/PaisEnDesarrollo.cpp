// Nombre del archivo: PaisEnDesarrollo.Cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "PaisEnDesarrollo.hpp"

PaisEnDesarrollo::PaisEnDesarrollo(string _name, int _id, int _habitantes, bool _aeropuerto) :
Pais(_name, _id, _habitantes), aeropuerto(_aeropuerto){}

void PaisEnDesarrollo::mostrarDetalles(){
    //calcularTrabajo(habitantes);
    //con boolalpha puedo imprimir booleanos
    //double pib = calcularPib();
    //string habitantesConTrabajo = calcularTrabajo(habitantes);
    cout << name << " -> id: " << id << ", habitantes: " << habitantes 
    << ", Aeropuerto: "<< boolalpha << aeropuerto <<", PIB:"<< pib  << endl;
}

