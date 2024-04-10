/**
 * @file Continentes.cpp
 * @brief Cuerpo de la clase Continentes
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#include "Continentes.hpp"
#include <string>
#include <iostream>
#include <vector> 
using namespace std;

//constructor de la clase 
/**
 * @brief Constructor de la clase Continentes.
 * 
 * @param _continente Nombre del continente.
 * @param _totalPaises Total de países en el continente.
 * @param _totalPaisesDesarrollo Total de países en desarrollo en el continente.
 * @param _totalPaisesPrimerMundo Total de países de primer mundo en el continente.
 */
Continentes::Continentes(string _continente, int _totalPaises, int _totalPaisesDesarrollo, int _totalPaisesPrimerMundo) :
continente(_continente), totalPaises(_totalPaises), totalPaisesDesarrollo(_totalPaisesDesarrollo), totalPaisesPrimerMundo(_totalPaisesPrimerMundo){}

//Metodo void para mostrar datos de los continentes
/**
 * @brief Método virtual para mostrar los detalles del continente.
 * 
 * Este método debe ser implementado para imprimir informacion del continente.
 */
void Continentes::mostrarDetalles() const {
    //ejemplo impresion America posee 7 paıses, 2 son de primer mundo y 5 son en desarrollo.
    cout << continente << " posee " << totalPaises << " paises, " << totalPaisesPrimerMundo << " son de primer mundo y " << totalPaisesDesarrollo << " son en desarrollo."<< endl;
}