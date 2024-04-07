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
Planeta::Planeta(vector<string> _continets, int _number_continets, vector<string> _selectedContinents) :
    continets(_continets), number_continets(_number_continets), selectedContinents(_selectedContinents){}

