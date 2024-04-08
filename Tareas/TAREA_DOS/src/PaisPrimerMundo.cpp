// Nombre del archivo: PaisPrimerMundo.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#include "PaisPrimerMundo.hpp"

//constructor de la clase 
PaisPrimerMundo::PaisPrimerMundo(string _name, int _id, int _habitantes, bool _tec5G, bool _aeropuerto, bool _investigacion) :
Pais(_name, _id, _habitantes), tec5G(_tec5G), aeropuerto(_aeropuerto){}


void PaisPrimerMundo::calcularTrabajo(int habitantes) {
    int habitantesConTrabajo = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, habitantes);

    habitantesConTrabajo = distrib(gen);

    std::cout << "Total de habitantes: " << habitantes << std::endl;
    std::cout << "Habitantes con trabajo: " << habitantesConTrabajo << std::endl;
    std::cout << "Habitantes sin trabajo: " << habitantes - habitantesConTrabajo << std::endl;

}

void PaisPrimerMundo::mostrarDetalles(){
    //calcularTrabajo(habitantes);
    //con boolalpha puedo imprimir booleanos
    double pib = calcularPib();
    cout << name << " -> id: " << id << ", habitantes: " << habitantes 
    << ", 5G: " << boolalpha <<tec5G << ", Aeropuerto: "<< boolalpha << aeropuerto 
    <<", Centro de investigacion: "<< boolalpha << investigacion <<", PIB:"<< pib << endl;
}