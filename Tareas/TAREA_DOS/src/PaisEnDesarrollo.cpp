/**
 * @file PaisEnDesarrollo.cpp
 * @brief Cuerpo clase PaisEnDesarrollo.hpp
 *
 * Archivo que contiene la definición de la clase PaisEnDesarrollo, que representa un país en desarrollo
 * con su nombre, ID, número de habitantes, y si tiene o no un aeropuerto.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#include "PaisEnDesarrollo.hpp"

/**
 * @brief Constructor de la clase.
 * 
 * @param _name Nombre del país en desarrollo.
 * @param _id ID del país en desarrollo.
 * @param _habitantes Número de habitantes del país en desarrollo.
 * @param aeropuerto Indica si el país en desarrollo tiene un aeropuerto.
 */
PaisEnDesarrollo::PaisEnDesarrollo(string _name, int _id, int _habitantes, bool _aeropuerto) :
Pais(_name, _id, _habitantes), aeropuerto(_aeropuerto){}

/**
 * @brief Método para mostrar los detalles del país .
 * 
 * Se imprime informacion.
 */
void PaisEnDesarrollo::mostrarDetalles(){
    //calcularTrabajo(habitantes);
    //con boolalpha puedo imprimir booleanos
    //double pib = calcularPib();
    //string habitantesConTrabajo = calcularTrabajo(habitantes);
    cout << name << " -> id: " << id << ", habitantes: " << habitantes 
    << ", Aeropuerto: "<< boolalpha << aeropuerto <<", PIB:"<< pib  << endl;
}

