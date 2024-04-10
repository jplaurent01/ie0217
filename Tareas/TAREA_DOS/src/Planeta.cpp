// Nombre del archivo: Planeta.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT
#include "Planeta.hpp"
#include <string>
#include <iostream>
#include <vector> 
using namespace std;

//constructor de la clase
/**
 * @brief Constructor de la clase.
 * 
 * @param _continets Vector que contiene los nombres de los continentes.
 * @param _number_continets Cantidad de continentes en el planeta.
 * @param _selectedContinents Vector que contiene los continentes seleccionados.
 */
Planeta::Planeta(vector<string> _continets, int _number_continets, vector<string> _selectedContinents) :
    continets(_continets), number_continets(_number_continets), selectedContinents(_selectedContinents){}

