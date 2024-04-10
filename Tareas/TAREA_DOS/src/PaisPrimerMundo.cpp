// Nombre del archivo: PaisPrimerMundo.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#include "PaisPrimerMundo.hpp"

//constructor de la clase 
/**
 * @brief Constructor de la clase.
 * 
 * @param _name Nombre del país de primer mundo.
 * @param _id ID del país de primer mundo.
 * @param _habitantes Número de habitantes del país de primer mundo.
 * @param tec5G Indica si el país de primer mundo tiene tecnología 5G.
 * @param aeropuerto Indica si el país de primer mundo tiene un aeropuerto.
 * @param investigacion Indica si el país de primer mundo realiza investigaciones.
 */
PaisPrimerMundo::PaisPrimerMundo(string _name, int _id, int _habitantes, bool _tec5G, bool _aeropuerto, bool _investigacion) :
Pais(_name, _id, _habitantes), tec5G(_tec5G), aeropuerto(_aeropuerto), investigacion(_investigacion){}

//Metodo calcular cuanta gente trabaja y no de forma aleatoria
/**
 * @brief Método para calcular cuánta gente trabaja y no de forma aleatoria.
 * 
 * @return El resultado del cálculo de manera porcentual en relacion a la cantidad de habitantes.
 */
string PaisPrimerMundo::calcularTrabajo() {
    int habitantesConTrabajo = 0;

    //Generador numeros aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, habitantes);

    habitantesConTrabajo = distrib(gen);
    double result1 = (static_cast<double>(habitantesConTrabajo) /habitantes)*100;
    double result2 = ((habitantes - habitantesConTrabajo)/static_cast<double>(habitantes))*100;

    string result = ", Habitantes con trabajo: " + to_string(result1) +
     "% Habitantes sin trabajo:" + to_string(result2) +"%";

    return result;
}

//Desde este metodo publico hago el llamado al metodo privado para acceder a sus valores
/**
 * @brief Método para mostrar los detalles del país .
 * 
 * Imprimie informacion del pais.
 */
void PaisPrimerMundo::mostrarDetalles(){
    //calcularTrabajo(habitantes);
    //con boolalpha puedo imprimir booleanos
    double pib = calcularPib();
    string habitantesConTrabajo = calcularTrabajo();
    cout << name << " -> id: " << id << ", habitantes: " << habitantes 
    << ", 5G: " << boolalpha <<tec5G << ", Aeropuerto: "<< boolalpha << aeropuerto 
    <<", Centro de investigacion: "<< boolalpha << investigacion <<", PIB:"<< pib << habitantesConTrabajo << endl;
}