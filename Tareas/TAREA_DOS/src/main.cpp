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
        vector<string> continentes = {"America", "Europa", "Africa", "Oceania", "Asia"};
        int sizeContinents = continentes.size();

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
            Planeta tierra(continentes, sizeContinents,{});
            imprimirPlaneta(tierra);

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
