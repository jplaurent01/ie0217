// Nombre del archivo: Funciones.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "Funciones.hpp"

//Convierto de string a booleano
bool stringToBool(const string& str) {
    string lowerStr;
    // Convertir la cadena a minúsculas
    for (char c : str) {
        lowerStr += tolower(c);
    }
    if (lowerStr == "true") {
        return true;
    } else {
        return false;
    }
}

//Funcion que me filtra la informacion de acuerdo al continente:
void filterByContinent(string keyWord, int &cantidadPaises0, int &primos0, int &noPrimos0, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,  vector<PaisPrimerMundo> &paisesPrimerMundoContinente){

    if (keyWord == "Oceania" || keyWord == "Asia" || keyWord == "Africa" || keyWord == "Europa" || keyWord == "America"){
        //Busco en el dicionario de acuerdo a la palabra clave, en relacion con el continente
        if (instrucionesPlaneta.find(keyWord) != instrucionesPlaneta.end()) {
            cantidadPaises0 = instrucionesPlaneta[keyWord].size();
            //itero sobre el dicionario de acuerdo al contienente selecionado
            for (const auto& par : instrucionesPlaneta[keyWord]) {
                //accedo al identificador unico par.second[indice], accedo a los valores del dicionario anidado
                //con esto puedo recolectar los valores del pais para generar objetos de tipo pais
                int id = std::stoi(par.second[3]);

                //Caso de encontrar pais desarrollado
                if (isPrimo(id)) {
                    //agrego contructor de paises de primer mundo
                    //Nombre, id, habitantes, 5g, aeropuerto, investigacion
                    paisesPrimerMundoContinente.push_back(PaisPrimerMundo(par.first, stoi(par.second[3]), stoi(par.second[4]), stringToBool(par.second[0]), stringToBool(par.second[1]), stringToBool(par.second[2])));
                    primos0++;
                } else {
                    noPrimos0++;
                }
            }

        } else {
            std::cout << "No se encontró el continente " << keyWord << std::endl;
        }
        
    }
    else{
        cout <<"OCURRIO EN ERROR EN keyWord"<<endl;
    }
}

//Funcion determina si el numero es o no es primo
bool isPrimo(int num){
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void imprimirPlaneta(Planeta tierra, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta) {
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

    //varaibles con contenidos del filtro de acuerdo al continente:
    int cantidadPaises0, cantidadPaises1, cantidadPaises2;
    int primos0 = 0, noPrimos0 = 0;
    int primos1 = 0, noPrimos1 = 0;
    int primos2 = 0, noPrimos2 = 0;
    //Vector de constructores paises de primer mundo
    vector<PaisPrimerMundo> paisesPrimerMundoContinente1;
    vector<PaisPrimerMundo> paisesPrimerMundoContinente2;
    vector<PaisPrimerMundo> paisesPrimerMundoContinente3;

    //Caso para el 1er continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[0], cantidadPaises0, primos0, noPrimos0, instrucionesPlaneta, paisesPrimerMundoContinente1);
    //Caso para el 2do continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[1], cantidadPaises1, primos1, noPrimos1, instrucionesPlaneta, paisesPrimerMundoContinente2);
    //Caso para el 3er continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[2], cantidadPaises2, primos2, noPrimos2, instrucionesPlaneta, paisesPrimerMundoContinente3);

    //se crean los tres objetos de los continentes por donde pasa el avion.
    Continentes continente1(tierra.selectedContinents[0], cantidadPaises0, noPrimos0, primos0);
    Continentes continente2(tierra.selectedContinents[1], cantidadPaises1, noPrimos1, primos1);
    Continentes continente3(tierra.selectedContinents[2], cantidadPaises1, noPrimos2, primos2);

    //Muestro la informacion de los continentes llamando a sus repectivos medotos de mostrarDetalles()
    continente1.mostrarDetalles();
    continente2.mostrarDetalles();
    continente3.mostrarDetalles();
    
    //Informacion paises de primer mundo, la idea es crear un vector de paises de 1er mundo y en desarrollo
    //el vector lo que guarda son los constructrores de los paises.
    cout <<"\nInformacion sobre los paises de primer mundo: \n";
    cout <<"\n Paises desarrollados de " << tierra.selectedContinents[0] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente1) {
            pais.mostrarDetalles();
        }
    cout <<"\n Paises desarrollados de " << tierra.selectedContinents[1] << ":" <<endl;
                // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente2) {
            pais.mostrarDetalles();
        }
    cout <<"\n Paises desarrollados de " << tierra.selectedContinents[2] << ":" <<endl;
                // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente3) {
            pais.mostrarDetalles();
        }
}


