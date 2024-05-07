/**
 * @file main.cpp
 * @brief Se realiza el llamado a las funciones y menus del programa
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include "Matriz.hpp"
#include <memory> // Para std::unique_ptr
#include "OperacionesBasicas.hpp"

using namespace std;

//Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
enum Opciones {
    TAMANIO = 1,
    TIPO,
    OPERACION,
    BOTON1,
    BOTON2,
    BOTON3,
    SALIR
};

/**
 * @brief Ejecuta menus del programa y realiza el llamado a multiples funciones de Funciones.hpp.
 * 
 * @return 0 al terminar la ejecuación del programa.
 */
int main() {
        int opcion;
        int *ptrTipoDato = nullptr;
        int *ptrTipoOperacion = nullptr;
        //Punteros a matrices float
        unique_ptr<Matriz<int>> ptrMatrizUnoInt = nullptr;
        unique_ptr<Matriz<int>> ptrMatrizDosInt = nullptr;
        //Punteros a matrices float
        unique_ptr<Matriz<float>> ptrMatrizUnoFloat = nullptr;
        unique_ptr<Matriz<float>> ptrMatrizDosFloat = nullptr;
        //Punteros a matrices complejas
        unique_ptr<Matriz<complex<double>>> ptrMatrizUnoComplex = nullptr;
        unique_ptr<Matriz<complex<double>>> ptrMatrizDosComplex = nullptr;
        
        do {
            string opcion2;
            //Menu principal
            cout << "\nMenu:\n";
            cout << "1. Agregar tamanio de ambas matrices y sus valores.\n";
            cout << "2. Tipo de datos de las matrices.\n";
            cout << "3. Tipo de opereaciones matriciales.\n";
            cout << "4. Genearacion de datos aleatorios para las matrices.\n";
            cout << "5. Ver matrices.\n";
            cout << "6. Ejecutar operacion matricial.\n";
            cout << "7. Finalizacion del programa.\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion2;
            
        //Verifico que se ingrese una opcion valida
        if(all_of(opcion2.begin(), opcion2.end(), ::isdigit) && (opcion2 == "1" || opcion2 == "2" || opcion2 == "3" || opcion2 == "4" || opcion2 == "5" || opcion2 == "6" || opcion2 == "7")){
            opcion = stoi(opcion2);
            switch (opcion) {
            
           case TAMANIO:{
            
                string filas;
                string columnas;
                int fila;
                int columna;

                string filasTwo;
                string columnasTwo;
                int filaTwo;
                int columnaTwo;

                if (ptrTipoDato != nullptr){
                    cout << "Contenido de ptrTipoDato" << *ptrTipoDato << endl;
                    //Se establece que las matrices que se van a crear son de las mismas dimensiones
                    cout << "Ingrese un numero entero para las filas de la  matriz 1" << endl;
                    cin.ignore();
                    getline(cin, filas);

                    cout << "Ingrese un numero entero para las columnas de la  matriz 1" << endl;
                    
                    getline(cin, columnas);

                    cout << "Ingrese un numero entero para las filas de la  matriz 2" << endl;
                    getline(cin, filasTwo);

                    cout << "Ingrese un numero entero para las columnas de la  matriz 2" << endl;
                    getline(cin, columnasTwo);

                    if (all_of(filas.begin(), filas.end(), ::isdigit) && all_of(filasTwo.begin(), filasTwo.end(), ::isdigit)){

                        if (all_of(columnas.begin(), columnas.end(), ::isdigit) && all_of(columnasTwo.begin(), columnasTwo.end(), ::isdigit)){

                            try{
                                fila = stoi(filas);
                                columna = stoi(columnas);

                                cout << "fila 1: " << fila <<endl;
                                cout << "columna 1: " << columna <<endl;

                                filaTwo = stoi(filasTwo);
                                columnaTwo = stoi(columnasTwo);

                                cout << "fila 2: " << filaTwo <<endl;
                                cout << "columna 2: " << filaTwo <<endl;
                                
                                //Caso donde seleciono un tipo de dato entero
                                if (*ptrTipoDato == 1){
                                    cout << "Matriz enteros" << endl;
                                    //Si se cumplen condiciones de tamanios, se crean dos objetos de tipo matriz
                                    Matriz<int> matrizUno(fila,columna);
                                    Matriz<int> matrizDos(filaTwo,columnaTwo);

                                    cout << "Llenado de la matriz 1 ..." << endl;
                                    matrizUno.llenarMatriz();

                                    cout << "Llenado de la matriz 2 ..." << endl;
                                    matrizDos.llenarMatriz();
                                    //ptrMatrizUnoInt = &matrizUno;
                                    //ptrMatrizDosInt = &matrizDos;
                                    ptrMatrizUnoInt = make_unique<Matriz<int>>(matrizUno);
                                    ptrMatrizDosInt = make_unique<Matriz<int>>(matrizDos);

                                    ptrMatrizUnoFloat = nullptr;
                                    ptrMatrizDosFloat = nullptr;
                                    //Punteros a matrices complejas
                                    ptrMatrizUnoComplex = nullptr;
                                    ptrMatrizDosComplex = nullptr;

                                }else if(*ptrTipoDato == 2){

                                    cout << "Matriz flotantes" << endl;
                                    //Si se cumplen condiciones de tamanios, se crean dos objetos de tipo matriz
                                    Matriz<float> matrizUno(fila,columna);
                                    Matriz<float> matrizDos(filaTwo,columnaTwo);

                                    cout << "Llenado de la matriz 1 ..." << endl;
                                    matrizUno.llenarMatriz();

                                    cout << "Llenado de la matriz 2 ..." << endl;
                                    matrizDos.llenarMatriz();

                                    //ptrMatrizUnoFloat = &matrizUno;
                                    //ptrMatrizDosFloat = &matrizDos;
                                    ptrMatrizUnoFloat = make_unique<Matriz<float>>(matrizUno);
                                    ptrMatrizDosFloat = make_unique<Matriz<float>>(matrizDos);

                                    ptrMatrizUnoInt = nullptr;
                                    ptrMatrizDosInt = nullptr;

                                    ptrMatrizUnoComplex = nullptr;
                                    ptrMatrizDosComplex = nullptr;

                                }else if(*ptrTipoDato == 3){

                                    cout << "Matriz compleja" << endl;
                                    //Si se cumplen condiciones de tamanios, se crean dos objetos de tipo matriz
                                    Matriz<std::complex<double>> matrizUno(fila,columna);
                                    Matriz<std::complex<double>> matrizDos(filaTwo,columnaTwo);

                                    cout << "Llenado de la matriz 1 ..." << endl;
                                    matrizUno.llenarMatriz(0);

                                    cout << "Llenado de la matriz 2 ..." << endl;
                                    matrizDos.llenarMatriz(0);

                                    //ptrMatrizUnoComplex = &matrizUno;
                                    //ptrMatrizDosComplex = &matrizDos;
                                    ptrMatrizUnoComplex = make_unique<Matriz<complex<double>>>(matrizUno);
                                    ptrMatrizDosComplex = make_unique<Matriz<complex<double>>>(matrizDos);

                                    ptrMatrizUnoInt = nullptr;
                                    ptrMatrizDosInt = nullptr;
                                    ptrMatrizUnoFloat = nullptr;
                                    ptrMatrizDosFloat = nullptr;

                                    
                                }else{
                                    cout << "Se ingreso un tipo de dato NO valido" << endl;
                                }
                                
                            }
                            catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }
                            
                        }else{
                            cout << "Debe ingresar un numero entero para las columnas" << endl;
                        }
                        
                        
                    }else {
                        cout << "Debe ingresar un numero entero para las filas" << endl;
                    } 
                }else{
                    cout << "1ero debe selecionar un tipo de dato para las matrices" << endl;
                }
            }
            break;
                
            case TIPO:{
                string opcion3;
                int opt3;
                cout << "\nTipo de dato de las matrices:\n";
                cout << "1. Entero.\n";
                cout << "2. Floatante.\n";
                cout << "3. Complejo.\n";
                cout << "Ingrese una opcion: ";
                cin >> opcion3;

                if(all_of(opcion3.begin(), opcion3.end(), ::isdigit) && (opcion3 == "1" || opcion3 == "2" || opcion3 == "3")){
                    opt3 = stoi(opcion3);
                    //Puntero almacena el continido de la variable que contiene el tipo de dato
                    ptrTipoDato =  &opt3;
                }else{
                    cout << "Debe ingresar un numero entero entre 1,2 y 3 como opcion" << endl;
                }
            }
                break;

            case OPERACION:{

                string opcion4;
                int opt4;
                cout << "\nTipos de operaciones:\n";
                cout << "1. Suma.\n";
                cout << "2. Resta.\n";
                cout << "3. Multiplicacion.\n";
                cout << "Ingrese una opcion: ";
                cin >> opcion4;
                
                if(all_of(opcion4.begin(), opcion4.end(), ::isdigit) && (opcion4 == "1" || opcion4 == "2" || opcion4 == "3")){
                    opt4 = stoi(opcion4);
                    ptrTipoOperacion = &opt4;

                }else{
                    cout << "Debe ingresar un numero entero entre 1,2 y 3 como opcion" <<endl;
                }
                
                }

                break;
            //Datos aleatorios
            case BOTON1:{
                
                if (ptrTipoDato != nullptr){
               
                }else {
                    cout << "Debe ingresar el tipo de dato de las matrices" << endl;
                }
                
                }

                break;
            //Ver matrices
            case BOTON2:{
                
                if (ptrTipoDato != nullptr){

                    if (*ptrTipoDato == 1 && ptrMatrizUnoInt != nullptr && ptrMatrizDosInt != nullptr){

                        cout << "\nMatriz 1 Int..." << endl;
                        ptrMatrizUnoInt->imprimirMatriz();
                        cout << "\nMatriz 2 Int..." << endl;
                        ptrMatrizDosInt->imprimirMatriz();

                    }else if (*ptrTipoDato == 2 && ptrMatrizUnoFloat != nullptr && ptrMatrizDosFloat != nullptr){

                        cout << "\nMatriz 1 Float..." << endl;
                        ptrMatrizUnoFloat->imprimirMatriz();
                        cout << "\nMatriz 2 Float..." << endl;
                        ptrMatrizDosFloat->imprimirMatriz();
                        
                    }else if (*ptrTipoDato == 3 && ptrMatrizUnoComplex != nullptr && ptrMatrizDosComplex != nullptr){

                        cout << "\nMatriz 1 Complex..." << endl;
                        ptrMatrizUnoComplex->imprimirMatriz(0);
                        cout << "\nMatriz 2 Complex..." << endl;
                        ptrMatrizDosComplex->imprimirMatriz(0);
                        
                    }else{
                        cout << "No se pueden mostar las matrices" << endl;
                    }
       
                    
                }else{
                    cout << "1ero debe ingresar el tipo de dato de las matrices" << endl;
                }
                
                }

                break;
            //Operaciones de matrices
            case BOTON3:{

                if (ptrTipoDato != nullptr){
                    if (ptrTipoOperacion != nullptr){
                        
                         if (ptrMatrizUnoInt !=nullptr && ptrMatrizDosInt !=nullptr){
                            cout << "Esoy en caso de operacion Int" << endl;
                            try{    
                                if (*ptrTipoOperacion == 1){
                                    OperacionesBasicas<int>::validarSumaResta(*ptrMatrizUnoInt, *ptrMatrizDosInt);
                                    Matriz<int> resultado =  *ptrMatrizUnoInt + *ptrMatrizDosInt;
                                    cout << "Suma int ... " << endl;
                                    resultado.imprimirMatriz();

                                }else if(*ptrTipoOperacion == 2){
                                    OperacionesBasicas<int>::validarSumaResta(*ptrMatrizUnoInt, *ptrMatrizDosInt);
                                    Matriz<int> resultado =  *ptrMatrizUnoInt - *ptrMatrizDosInt;
                                    cout << "Resta int ... " << endl;
                                    resultado.imprimirMatriz();
                                }else if(*ptrTipoOperacion == 3){
                                    OperacionesBasicas<int>::validarMultiplicacion(*ptrMatrizUnoInt, *ptrMatrizDosInt);
                                    Matriz<int> resultado =  *ptrMatrizUnoInt * *ptrMatrizDosInt;
                                    cout << "Multiplicacion int ... " << endl;
                                    resultado.imprimirMatriz();
                                }else{
                                    cout << "No se pudo realizar la operacion" << endl;
                                }
                            }catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }
                            
                        }else if (ptrMatrizUnoFloat !=nullptr && ptrMatrizDosFloat !=nullptr){
                            cout << "Esoy en caso de operacion Float" << endl;
                            try{
                                if (*ptrTipoOperacion == 1){
                                    OperacionesBasicas<float>::validarSumaResta(*ptrMatrizUnoFloat, *ptrMatrizDosFloat);
                                    Matriz<float> resultado =  *ptrMatrizUnoFloat + *ptrMatrizDosFloat;
                                    cout << "Suma flotante ... " << endl;
                                    resultado.imprimirMatriz();
                                }else if(*ptrTipoOperacion == 2){
                                    OperacionesBasicas<float>::validarSumaResta(*ptrMatrizUnoFloat, *ptrMatrizDosFloat);
                                    Matriz<float> resultado =  *ptrMatrizUnoFloat - *ptrMatrizDosFloat;
                                    cout << "Resta flotante ... " << endl;
                                    resultado.imprimirMatriz();
                                }else if(*ptrTipoOperacion == 3){
                                    OperacionesBasicas<float>::validarMultiplicacion(*ptrMatrizUnoFloat, *ptrMatrizDosFloat);
                                    Matriz<float> resultado =  *ptrMatrizUnoFloat * *ptrMatrizDosFloat;
                                    cout << "Multiplicacion flotante ... " << endl;
                                    resultado.imprimirMatriz();
                                }else{
                                    cout << "No se pudo realizar la operacion" << endl;
                                }
                            }
                            catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }
                        
                        }else if (ptrMatrizUnoComplex !=nullptr && ptrMatrizDosComplex !=nullptr){
                            cout << "Esoy en caso de operacion Complex" << endl;
                           try{
                                if (*ptrTipoOperacion == 1){
                                    OperacionesBasicas<complex<double>>::validarSumaResta(*ptrMatrizUnoComplex, *ptrMatrizDosComplex);
                                    cout << "Algo pasa aqui..." << endl;
                                    Matriz<complex<double>> resultado =  *ptrMatrizUnoComplex + *ptrMatrizDosComplex;
                                    cout << "Suma compleja ... " << endl;
                                    resultado.imprimirMatriz(0);
                                }else if(*ptrTipoOperacion == 2){
                                    OperacionesBasicas<complex<double>>::validarSumaResta(*ptrMatrizUnoComplex, *ptrMatrizDosComplex);
                                    Matriz<complex<double>> resultado =  *ptrMatrizUnoComplex - *ptrMatrizDosComplex;
                                    cout << "Resta compleja ... " << endl;
                                    resultado.imprimirMatriz(0);
                                }else if(*ptrTipoOperacion == 3){
                                    OperacionesBasicas<complex<double>>::validarMultiplicacion(*ptrMatrizUnoComplex, *ptrMatrizDosComplex);
                                    Matriz<complex<double>> resultado =  *ptrMatrizUnoComplex * *ptrMatrizDosComplex;
                                    cout << "Multiplicacion compleja ... " << endl;
                                    resultado.imprimirMatriz(0);
                                }else{
                                    cout << "No se pudo realizar la operacion" << endl;
                                }
                           }
                           catch(const std::exception& e){
                            std::cerr << e.what() << '\n';
                           }
                           
                        }else{
                            cout << "No se agrego informacion a ninguna matriz para realizar la operacion" << endl;
                        }

                    }else{
                        cout << "Debe ingresar el tipo de operacion de las matrices" << endl;
                    }
                    
                }else {
                    cout << "Debe ingresar el tipo de dato de las matrices" << endl;
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