/**
 * @file PaisEnDesarrollo.hpp
 * @brief Encabezado clase PaisEnDesarrollo.hpp
 *
 * Archivo que contiene la definición de la clase PaisEnDesarrollo, que representa un país en desarrollo
 * con su nombre, ID, número de habitantes, y si tiene o no un aeropuerto.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef PAISENDESARROLLO_HPP
#define PAISENDESARROLLO_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Pais.hpp"

using namespace std;

/**
 * @brief Clase que representa un país en desarrollo, que es un tipo de país.
 */
class PaisEnDesarrollo : public Pais{
    private:
        //bool tec5G;
        bool aeropuerto;
        //bool investigacion;
    public:
        /**
         * @brief Constructor de la clase.
         * 
         * @param _name Nombre del país en desarrollo.
         * @param _id ID del país en desarrollo.
         * @param _habitantes Número de habitantes del país en desarrollo.
         * @param aeropuerto Indica si el país en desarrollo tiene un aeropuerto.
         */
        PaisEnDesarrollo(string _name, int _id, int _habitantes,  bool aeropuerto);
        /**
         * @brief Método para mostrar los detalles del país .
         * 
         * Se imprime informacion.
         */
        void mostrarDetalles();
    
    
};

#endif //PAISENDESARROLLO_HPP