/**
 * @file Main.cpp
 * @brief Se realiza el llamado a las funciones y menus del programa
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */

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

enum Opciones2 {
    CONTINENTE1 = 1,
    CONTINENTE2,
    CONTINENTE3,
    CONTINENTE4,
    CONTINENTE5,
    OUT
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
            {"Estados Unidos", {"true", "true", "true", "2", "331"}},
            {"Mexico", {"false", "false", "true", "4", "126"}},
        }},
        {"Europa", {
            {"Alemania", {"true", "true", "true", "3", "837"}},
            {"Espana", {"true", "true", "true", "5", "473"}},
        }},
        {"Africa", {
            {"Sudafrica", {"true", "true", "true", "41", "600"}},
            {"Kenia", {"false", "false", "true", "24", "580"}},
        }},
        {"Asia", {
            {"China", {"true", "true", "true", "53", "144"}},
            {"India", {"false", "true", "true", "25", "139"}},
        }},
        {"Oceania", {
            {"Australia", {"true", "true", "true", "73", "256"}},
            {"Nueva Zelanda", {"true", "true", "true", "79", "512"}},
        }}
        };

        //Vector con los key values del primer dicionario, contiene los continentes
        std::vector<std::string> continentes;
        for (const auto& continente : instrucionesPlaneta) {
            //Lleno el vector
            continentes.push_back(continente.first);
            }

        do {
            //Menu principal
            std::cout << "\nMenu:\n";
            std::cout << "1. Imprimir la informacion de todos los paises\n";
            std::cout << "2. Comparar paises\n";
            std::cout << "3. Agregar un nuevo pais\n";
            std::cout << "4. Eliminar un pais\n";
            std::cout << "5. Salir del programa\n";
            std::cout << "Ingrese una opcion: ";
            std::cin >> opcion;
        
        switch (opcion) {
            //Imprimo contenido del planeta
           case IMPRIMIR:{
            //inicializo el constructor de la clase planeta
            Planeta tierra(continentes, continentes.size(),{});
            //Envio un objeto Planeta y una copia del dicionario para crear los objetos paises, etc...
            imprimirPlaneta(tierra, instrucionesPlaneta);

            }
            break;
                

            case COMPARAR:{
            //Pide 2 id, compara si los dos son primos, utliza sobrecarga de operadores
            compararPaises(instrucionesPlaneta);
            }
                break;

            //Agrego contenido al dicionario
            case AGREGAR:
                int opcion2;
                std::cout << "\nSelecione un continente:\n";
                std::cout << "1. America\n";
                std::cout << "2. Europa\n";
                std::cout << "3. Africa\n";
                std::cout << "4. Asia\n";
                std::cout << "5. Oceania\n";
                std::cout << "6. Salir\n";
                std::cout << "Ingrese una opcion: ";
                std::cin >> opcion2;

                switch (opcion2)
                {
                case CONTINENTE1:{
                    agregarInformacion("America", instrucionesPlaneta);
                    }
                    
                    break;

                case CONTINENTE2:{
                    agregarInformacion("Europa", instrucionesPlaneta);
                    }
                    
                    break;
                
                case CONTINENTE3:{
                    agregarInformacion("Africa", instrucionesPlaneta);
                }
                    
                    break;

                case CONTINENTE4:{
                    agregarInformacion("Asia", instrucionesPlaneta);
                }
                    
                    break;

                case CONTINENTE5:{
                    agregarInformacion("Oceania", instrucionesPlaneta);
                }
                    
                    break;

                case OUT:
                    std::cout << "Saliendo...\n";
                    break;
                
                default:
                    std::cout << "Opción no valida\n";
                    break;
                }
                break;

            case ELIMINAR:{
                eliminarId(instrucionesPlaneta);
                }

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
