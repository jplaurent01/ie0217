/**
 * @file PaisPrimerMundo.hpp
 * @brief Encabezado de la clase PaisPrimerMundo
 *
 * Archivo que contiene la definición de la clase PaisPrimerMundo, que representa un país de primer mundo
 * con su nombre, ID, número de habitantes, si tiene tecnología 5G, un aeropuerto y si realiza investigaciones.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Pais.hpp"

using namespace std;

/**
 * @brief Clase de un país de primer mundo, hereda de clase país.
 */
class PaisPrimerMundo : public Pais{
    private:
        bool tec5G;
        bool aeropuerto;
        bool investigacion;
    public:
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
        PaisPrimerMundo(string _name, int _id, int _habitantes, bool tec5G, bool aeropuerto, bool investigacion);
        /**
         * @brief Método para mostrar los detalles del país .
         * 
         * Imprimie informacion del pais.
         */
        void mostrarDetalles();
    private:
        //Metodo calcular cuanta gente trabaja y no de forma aleatoria
        /**
         * @brief Método para calcular cuánta gente trabaja y no de forma aleatoria.
         * 
         * @return El resultado del cálculo de manera porcentual en relacion a la cantidad de habitantes.
         */
        string calcularTrabajo();
    
};

#endif //PAISPRIMERMUNDO_HPP