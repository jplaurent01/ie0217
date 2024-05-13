/**
 * @file main.cpp
 * @brief Se realiza el llamado a las funciones y menus del programa
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#include <string>
#include <iostream>
#include <algorithm>
#include "ValidadorEmail.hpp"

using namespace std;

//Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
enum Opciones {
    AGREGAR = 1,
    SALIR
};

/**
 * @brief Ejecuta menus del programa y realiza el llamado a multiples funciones de Funciones.hpp.
 * 
 * @return 0 al terminar la ejecuación del programa.
 */
int main() {
        int opcion;

        do {
            string opcion2;
            //Menu principal
            cout << "\nMenu:\n";
            cout << "1. Agregar un correo electronico\n";
            cout << "2. Salir del programa\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion2;
        //Verifico que se ingrese una opcion valida
        if(all_of(opcion2.begin(), opcion2.end(), ::isdigit) && (opcion2 == "1" || opcion2 == "2")){
            opcion = stoi(opcion2);
            switch (opcion) {
            
           case AGREGAR:{
                string opcion;
                cout << "\nIngrese una direccion de correo: ";
                //cin >> opcion;
                cin.ignore();
                getline(cin, opcion);
                try{
                    ValidadorEmail validar(opcion);
                    validar.validarCorreo();
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
                
            }
            break;

            case SALIR:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
            }
        }else{
            cout << "Se ingreso una opcion no valida" << endl;
        }
        
        } while(opcion != SALIR);
        return 0;
    }