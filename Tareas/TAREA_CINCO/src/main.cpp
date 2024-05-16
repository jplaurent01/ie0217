/**
 * @file main.cpp
 * @brief Se realiza el llamado a las funciones, clase ValidadorEmail.hpp y menus del programa
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
 * @brief Ejecuta menus del programa y realiza el llamado a multiples funciones de Funciones.hpp y clase ValidadorEmail.hpp.
 * 
 * @return 0 al terminar la ejecuacion del programa.
 */
int main() {
        int opcion;
        //siguiente vector almacena los correos creados
        std::vector<std::string> almacenCorreos;
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
                string opcion, opcionDos, opcionTres;
                cout << "\nIngrese un Nombre: ";
                //cin >> opcion;
                cin.ignore();
                getline(cin, opcion);

                cout << "\nIngrese un Dominio: ";
                getline(cin, opcionDos);

                cout << "\nIngrese una Extension: ";
                getline(cin, opcionTres);

                try{
                    //Creo objeto validador de Email
                    ValidadorEmail validar(opcion, opcionDos, opcionTres);
                    //Modifico el vector que ingresa como paramentro
                    validar.validarCorreo(almacenCorreos);
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

    /*
    */