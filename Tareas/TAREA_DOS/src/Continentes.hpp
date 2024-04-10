/**
 * @file Continentes.hpp
 * @brief Cuerpo de la clase Continentes
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef CONTINENTES_HPP
#define CONTINENTES_HPP


#include <string>
#include <iostream>
#include <vector> 
using namespace std;

/**
 * @brief Clase que representa un continente.
 */
class Continentes{
    public:
        string continente;
        int totalPaises;
        int totalPaisesDesarrollo;
        int totalPaisesPrimerMundo;
        //Constructor de la clase
        /**
         * @brief Constructor de la clase Continentes.
         * 
         * @param _continente Nombre del continente.
         * @param _totalPaises Total de países en el continente.
         * @param _totalPaisesDesarrollo Total de países en desarrollo en el continente.
         * @param _totalPaisesPrimerMundo Total de países de primer mundo en el continente.
         */
        Continentes( string _continente, int _totalPaises, int _totalPaisesDesarrollo, int _totalPaisesPrimerMundo);

        /**
         * @brief Método virtual para mostrar los detalles del continente.
         * 
         * Este método debe ser implementado para imprimir informacion del continente.
         */
        virtual void mostrarDetalles() const;

};

#endif //CONTINENTES_HPP