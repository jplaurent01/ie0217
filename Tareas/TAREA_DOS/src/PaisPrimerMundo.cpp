// Nombre del archivo: PaisPrimerMundo.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#include "PaisPrimerMundo.hpp"

//constructor de la clase 
PaisPrimerMundo::PaisPrimerMundo(string _name, int _id, int _habitantes, bool _tec5G, bool _aeropuerto, bool _investigacion) :
Pais(_name, _id, _habitantes), tec5G(_tec5G), aeropuerto(_aeropuerto), investigacion(_investigacion){}


string PaisPrimerMundo::calcularTrabajo(int habitantes) {
    int habitantesConTrabajo = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, habitantes);

    habitantesConTrabajo = distrib(gen);
    double result1 = (habitantesConTrabajo /habitantes)*100;
    double result2 = ((habitantes - habitantesConTrabajo)/habitantes)*100;

    string result = ", Habitantes con trabajo: " + to_string(result1) +
     "% Habitantes sin trabajo:" + to_string(result2) +"%";

    return result;
}

void PaisPrimerMundo::mostrarDetalles(){
    //calcularTrabajo(habitantes);
    //con boolalpha puedo imprimir booleanos
    double pib = calcularPib();
    string habitantesConTrabajo = calcularTrabajo(habitantes);
    cout << name << " -> id: " << id << ", habitantes: " << habitantes 
    << ", 5G: " << boolalpha <<tec5G << ", Aeropuerto: "<< boolalpha << aeropuerto 
    <<", Centro de investigacion: "<< boolalpha << investigacion <<", PIB:"<< pib << habitantesConTrabajo << endl;
}