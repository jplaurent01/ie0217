// Nombre del archivo: Funciones.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "Funciones.hpp"


void imprimirPlaneta(Planeta tierra) {
    cout << "Informacion General: \n";
    cout << "Planeta posee " << tierra.number_continets <<" continentes: ";
    for(auto it = tierra.continets.begin(); it != tierra.continets.end(); ++it) {

    // Check if it's not the last element before adding a tab
    if (it != tierra.continets.end() - 1) {
        if(it != tierra.continets.end() - 2){
            cout << *it; // Print current continent
            cout << ", "; // Add tab if not the last element
        }
        else{
            cout << *it; // Print current continent
        }
        
    }else{
         cout <<" y "<<*it <<"."; // Print current continent
        }
    }

     // Crear un nuevo vector para almacenar los 3 strings aleatorios
    
    // Usar un generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, tierra.continets.size() - 1);

    // Obtener 3 índices aleatorios únicos
    while (tierra.selectedContinents.size() < 3) {
        int index = distrib(gen);
        string continent = tierra.continets[index];
        if (find(tierra.selectedContinents.begin(), tierra.selectedContinents.end(), continent) == tierra.selectedContinents.end()) {
            tierra.selectedContinents.push_back(continent);
        }
    }
    // Print the selected random continents
    //cout << "Selected random continents:" << endl;
    //for (const auto& continent : tierra.selectedContinents) {
    //    cout << continent << endl;
    //}
    cout <<"\nDe estos continentes, el avion pasa por los siguientes: ";
    for(auto it = tierra.selectedContinents.begin(); it != tierra.selectedContinents.end(); ++it) {

    // Check if it's not the last element before adding a tab
    if (it != tierra.selectedContinents.end() - 1) {
        if(it != tierra.selectedContinents.end() - 2){
            cout << *it; // Print current continent
            cout << ", "; // Add tab if not the last element
        }
        else{
            cout << *it; // Print current continent
        }
        
    }else{
         cout <<" y "<<*it <<".\n"; // Print current continent
        }
    }

    cout <<"\nInformacion sobre los paises: \n";
    //Objetos de continentes, se establece un total de 3 continentes por los cuales pasa el avion
    Continentes continente1(tierra.selectedContinents[0], 7, 5, 2);//Para el continente 1 crear 7 paises
    Continentes continente2(tierra.selectedContinents[1], 4, 3, 1);//Para el continente 2 crear 4 paises
    Continentes continente3(tierra.selectedContinents[2], 3, 2, 1);//Para el continente 3 crear 3 paises

    //Muestro la informacion de los continentes llamando a sus repectivos medotos de mostrarDetalles()
    continente1.mostrarDetalles();
    continente2.mostrarDetalles();
    continente3.mostrarDetalles();
    
}