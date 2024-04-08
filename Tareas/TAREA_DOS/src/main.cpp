// Nombre del archivo: main.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include <iostream>
#include <algorithm>
#include "Planeta.hpp"
#include "Funciones.hpp" 
#include <unordered_map>

//Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
enum Opciones {
    IMPRIMIR = 1,
    COMPARAR,
    AGREGAR,
    ELIMINAR,
    SALIR
};

/**
     * @brief Se realiza el llamado a funciones y contiene la logica del programa.
     * 
     * Se muestra el menu del progrma
     * 
     * 
     * @return 0 cuando el programa se ha terminado de ejecutar.
     */
    int main() {
        int opcion;

        //Este diccionario contiene las instruciones para crear un planeta con n continentes y n pais por contienete
        //informacion ordenada en 5G, AEROPUERTO, CENTRO INVESTIGACION, ID Y HABITANTES.
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta = {
        {"America", {
            {"Estados Unidos", {"true", "true", "true", "2", "331449281"}},
            {"Mexico", {"false", "false", "true", "4", "126190788"}},
            {"Canada", {"true", "true", "true", "7", "38005238"}},
            {"Brasil", {"false", "true", "true", "6", "213993437"}},
            {"Argentina", {"false", "false", "true", "8", "45195777"}},
        }},
        {"Europa", {
            {"Alemania", {"true", "true", "true", "3", "83783942"}},
            {"Espana", {"true", "true", "true", "5", "47351567"}},
            {"Francia", {"true", "true", "true", "19", "65273511"}},
            {"Italia", {"true", "true", "true", "23", "60243439"}},
            {"Reino Unido", {"true", "true", "true", "29", "67886011"}},
        }},
        {"Africa", {
            {"Nigeria", {"false", "false", "true", "20", "206139587"}},
            {"Egipto", {"false", "true", "true", "21", "104258327"}},
            {"Sudafrica", {"true", "true", "true", "41", "60041989"}},
            {"Etiopia", {"false", "false", "true", "22", "118118000"}},
            {"Kenia", {"false", "false", "true", "24", "58036725"}},
        }},
        {"Asia", {
            {"China", {"true", "true", "true", "53", "1444216107"}},
            {"India", {"false", "true", "true", "25", "1393409038"}},
            {"Japon", {"true", "true", "true", "61", "126476461"}},
            {"Corea del Sur", {"true", "true", "true", "67", "51780579"}},
            {"Indonesia", {"false", "false", "true", "26", "276361783"}},
        }},
        {"Oceania", {
            {"Australia", {"true", "true", "true", "73", "25687041"}},
            {"Nueva Zelanda", {"true", "true", "true", "79", "5129262"}},
            {"Fiyi", {"false", "false", "true", "27", "896444"}},
            {"Papua Nueva Guinea", {"false", "false", "true", "28", "9579746"}},
            {"Samoa", {"false", "false", "true", "30", "199133"}},
        }}
        };

        //Vector con los key values del primer dicionario, contiene los continentes
        std::vector<std::string> continentes;
        for (const auto& continente : instrucionesPlaneta) {
            //Lleno el vector
            continentes.push_back(continente.first);
            }

        do {
    
            std::cout << "\nMenu:\n";
            std::cout << "1. Imprimir la informacion de todos los paises\n";
            std::cout << "2. Comparar paises\n";
            std::cout << "3. Agregar un nuevo pais\n";
            std::cout << "4. Eliminar un pais\n";
            std::cout << "5. Salir del programa\n";
            std::cout << "Ingrese una opcion: ";
            std::cin >> opcion;
        
        switch (opcion) {

           case IMPRIMIR:{
            //inicializo el constructor de la clase planeta
            Planeta tierra(continentes, continentes.size(),{});
            //Envio un objeto Planeta y una copia del dicionario para crear los objetos paises, etc...
            imprimirPlaneta(tierra, instrucionesPlaneta);

            }
            break;
                

            case COMPARAR:
                
                break;

            case AGREGAR:
                
                break;

            case ELIMINAR:

                break;
            case SALIR:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no valida\n";
                break;
            }

        } while(opcion != SALIR);

        return 0;
    }
