// Nombre del archivo: Pais.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "Pais.hpp"
 
//constructor de la clase 
Pais::Pais(int _id, int _habitantes) :
id(_id), habitantes(_habitantes){}

//Metodo double devuelve el Pib
double Pais::calcularPib() const {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> distrib(1000, 10000);
        return distrib(gen);
}