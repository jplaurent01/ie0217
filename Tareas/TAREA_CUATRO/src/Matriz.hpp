#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <complex>
#include <algorithm>
#include <numeric>
#include "ValidadorDeEntrada.hpp"
#include <random>
//#include "OperacionesBasicas.hpp"

// Declaración adelantada de la clase OperacionesBasicas

template <typename T>
class Matriz{

    public:
        std::vector<std::vector<T>> matriz;
        std::vector<std::vector<std::complex<double>>> matrizComplex;
       
    public:
        int filas;
        int columnas;
 
    public:
        
        Matriz(int _filas, int _columnas) :  filas(_filas), columnas(_columnas) {

            //Verifico se las filas y columnas son positivas y mayores a cero
            setDimensiones(filas, columnas);
            
            this->filas = filas;
            this->columnas = columnas;
            
        }

        //No tengo recursos que liberar
        ~Matriz(){};
        /*Establece las dimensiones de la matriz y
        verifica su validez (no negativas, no cero). Lanza una excepcion si las dimensiones
        son invalidas.*/

        void setDimensiones(const int& filas, const int& columnas) {
            ValidadorDeEntrada<T> validadorEntrada;
            validadorEntrada.validarDimensiones(filas);
            validadorEntrada.validarDimensiones(columnas);            
            std::cout << "Matriz exitosamente creada" << std::endl;

        }

        void llenarMatriz(int complexFlag = -1) {
            if (complexFlag == 0) {
                ValidadorDeEntrada<std::complex<double>> validadorEntrada;

                for (int i = 0; i < filas; i++) {
                    std::vector<std::complex<double>> tempVector;

                    for (int j = 0; j < columnas; j++) {
                        bool flag = false;
                        std::complex<double> value;
                        std::string strValue;
                        float realValue, imagValue;
                        std::string realPart, imagPart, result;

                        do {
                            //dEBO EVITAR QUE EL USUARIO AGREGUE COMAS
                            std::cout << "matriz[" << i << "][" << j << "] - Parte real: ";
                            getline(std::cin, realPart);
                            std::cout << "\nParte imaginaria: ";
                            getline(std::cin, imagPart);
                            result = realPart + "," + imagPart;
                        } while (!validadorEntrada.validarTipoDato(result, typeid(T).name(), value));

                        std::istringstream is('(' + result + ')');
                        std::complex<double> c;
                        is >> c;
                        value = c;
                        std::cout << "the number is " << c << "\n";
                        std::cout << typeid(c).name() << '\n';
                        std::cout << typeid(value).name() << '\n';

                        tempVector.push_back(value);
                    }
                    matrizComplex.push_back(tempVector);
                }
            } else {
                ValidadorDeEntrada<T> validadorEntrada;

                for (int i = 0; i < filas; i++) {
                    std::vector<T> tempVector;

                    for (int j = 0; j < columnas; j++) {
                        bool flag = false;
                        T value;
                        std::string strValue;

                        do {
                            std::cout << "matriz[" << i << "][" << j << "] : ";
                            getline(std::cin, strValue);
                            flag = validadorEntrada.validarTipoDato(strValue, typeid(T).name(), value);
                            if (!flag) {
                                std::cout << "Dato agregado no es valido, vuelva a introducirlo..." << std::endl;
                            }
                        } while (!flag);

                        tempVector.push_back(value);
                    }
                    matriz.push_back(tempVector);
                }
            }
        }

 
        void imprimirMatriz(int complexFlag = -1){
            if (complexFlag == 0){ 
                for (int i = 0; i < filas; ++i) {
                    for (int j = 0; j < columnas; ++j) {
                        std::cout << matrizComplex[i][j] << "\t";
                    }
                    std::cout << std::endl;
                }
            }
            else{
                for (int i = 0; i < filas; ++i) {
                    for (int j = 0; j < columnas; ++j) {
                        std::cout << matriz[i][j] << "\t";
                    }
                    std::cout << std::endl;
                }
            }

   
        }
        //Se agregó esta funcion nueva
        void generarDatosAleatorios(int complexFlag = -1){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double>dis(0.0,1.0);
            if (complexFlag == 0) {
                for ( auto& fila: matrizComplex){
                    for ( auto& columna: matrizComplex){
                        double real = dis(gen)*100.0;
                        double img = dis(gen)*100.0;
                        columna  = std::complex<double>(real, img);
                    }
                    
                }
                
            }else{

                for ( auto& fila: matriz){
                    for ( auto& columna: matriz){
                        if(std::is_same<T,int>::value){
                            columna = static_cast<T>(dis(gen) * 100);
                        }else if(std::is_same<T,float>::value){
                            columna = static_cast<T>(dis(gen) * 100.0f);
                        }
                        else{
                            std::cout << "No encontre dato para convertir" << std::endl;
                        }

                    }
                    
                }

            }
        }


        Matriz<T> operator+(const Matriz<T>& matriz1){
                if (std::is_same<T, std::complex<double>>::value) {
                    std::cout << "matriz.size(): " << matrizComplex.size()<<std::endl;
                    std::cout << "matriz[0].size(): " << matrizComplex[0].size()<<std::endl;
                    Matriz<T> resultado(matrizComplex.size(),matrizComplex[0].size());

                //std::cout << "Se crea constructor: " << matrizComplex[0].size()<<std::endl;
                 for (int i = 0; i < filas; i++) {
                    std::vector<std::complex<double>> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        std::complex<double> c2 = {0.0, 0.0};
                        tempVector.push_back(c2);
                    }
                    resultado.matrizComplex.push_back(tempVector);
                    }
                //std::cout << "Itero bucle: " <<std::endl;
                for (int i = 0; i < matrizComplex.size(); ++i) {
                    std::transform(matrizComplex[i].begin(), matrizComplex[i].end(),
                                matriz1.matrizComplex[i].begin(), resultado.matrizComplex[i].begin(),
                                std::plus<std::complex<double>>());
                }

                return resultado;

                }else{
                     Matriz<T> resultado(matriz.size(),matriz[0].size());
                
                 for (int i = 0; i < filas; i++) {
                    std::vector<T> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        tempVector.push_back(0);
                    }
                    resultado.matriz.push_back(tempVector);
                    }
                
                for (int i = 0; i < matriz.size(); i++) {
                    std::transform(matriz[i].begin(), matriz[i].end(), matriz1.matriz[i].begin(), resultado.matriz[i].begin(), std::plus<T>());
                }

                return resultado;
                }

        };
       

        Matriz<T> operator-(const Matriz<T>& matriz1){

            if (std::is_same<T, std::complex<double>>::value) {
                    std::cout << "matriz.size(): " << matrizComplex.size()<<std::endl;
                    std::cout << "matriz[0].size(): " << matrizComplex[0].size()<<std::endl;
                    Matriz<T> resultado(matrizComplex.size(),matrizComplex[0].size());

                //std::cout << "Se crea constructor: " << matrizComplex[0].size()<<std::endl;
                 for (int i = 0; i < filas; i++) {
                    std::vector<std::complex<double>> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        std::complex<double> c2 = {0.0, 0.0};
                        tempVector.push_back(c2);
                    }
                    resultado.matrizComplex.push_back(tempVector);
                    }
                //std::cout << "Itero bucle: " <<std::endl;
                for (int i = 0; i < matrizComplex.size(); ++i) {
                    std::transform(matrizComplex[i].begin(), matrizComplex[i].end(), matriz1.matrizComplex[i].begin(), resultado.matrizComplex[i].begin(),
                   [](std::complex<double> a, std::complex<double> b) { return a - b; });
                    //std::transform(matrizComplex[i].begin(), matrizComplex[i].end(),
                      //          matriz1.matrizComplex[i].begin(), resultado.matrizComplex[i].begin(),
                        //        std::plus<std::complex<double>>());
                }

                return resultado;

                }else{

                Matriz<T> resultado(matriz.size(),matriz[0].size());
                
                 for (int i = 0; i < filas; i++) {
                    std::vector<T> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        tempVector.push_back(0);
                    }
                    resultado.matriz.push_back(tempVector);
                    }

                for ( int i = 0; i < matriz.size(); i++){
                    std::transform(matriz[i].begin(), matriz[i].end(), matriz1.matriz[i].begin(), resultado.matriz[i].begin(),
                   [](T a, T b) { return a - b; });
                }
                
                return resultado;
            }
            
        };

        //Revisar multiplicacion
        Matriz<T> operator*(const Matriz<T>& matriz2){

                if (std::is_same<T, std::complex<double>>::value) {

                    std::cout << "matriz.size(): " << matrizComplex.size()<<std::endl;
                    std::cout << "matriz[0].size(): " << matrizComplex[0].size()<<std::endl;
                    Matriz<T> resultado(matrizComplex.size(), matriz2.columnas);

                    for (int i = 0; i < filas; i++) {
                        std::vector<std::complex<double>> tempVector;
                        for (int j = 0; j < columnas; j++) {
                            std::complex<double> c2 = {0.0, 0.0};
                            tempVector.push_back(c2);
                        }
                        resultado.matrizComplex.push_back(tempVector);
                    }
                    return resultado;
                }
                else{
                    Matriz<T> resultado(matriz.size(), matriz2.columnas);

                        for (int i = 0; i < filas; i++) {
                            std::vector<T> tempVector;
                            for (int j = 0; j < columnas; j++) {
                                tempVector.push_back(0);
                            }
                            resultado.matriz.push_back(tempVector);
                        }

                        //for ( int i = 0; i < matriz.size(); i++){
                            //  std::transform(matriz[i].begin(), matriz[i].end(), matriz2.matriz[i].begin(), resultado.matriz[i].begin(),
                            // []( T a, T b) { return a * b; });
                        //}


                        for (int i = 0; i < filas; ++i) {
                            for (int j = 0; j < matriz2.columnas; ++j) {
                                for (int k = 0; k < columnas; ++k) {
                                    resultado.matriz[i][j] += matriz[i][k] * matriz2.matriz[k][j];
                                }
                            }
                        }

                    return resultado;
                }
 
            };

};



#endif //MATRIZ_HPP

        //Caso de la suma
        /*
                Matriz<T> operator+(const Matriz<T>& matriz1){
                
                Matriz<T> resultado(matriz.size(),matriz[0].size());
                
                 for (int i = 0; i < filas; i++) {
                    std::vector<T> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        tempVector.push_back(0);
                    }
                    resultado.matriz.push_back(tempVector);
                    }
                
                for (int i = 0; i < matriz.size(); i++) {
                    std::transform(matriz[i].begin(), matriz[i].end(), matriz1.matriz[i].begin(), resultado.matriz[i].begin(), std::plus<T>());
                }

                return resultado;
            
        };
        */

       //Caso de la resta
       /*
               Matriz<T> operator-(const Matriz<T>& matriz1){
            
                Matriz<T> resultado(matriz.size(),matriz[0].size());
                
                 for (int i = 0; i < filas; i++) {
                    std::vector<T> tempVector;
                    for (int j = 0; j < columnas; j++) {
                        tempVector.push_back(0);
                    }
                    resultado.matriz.push_back(tempVector);
                    }

                for ( int i = 0; i < matriz.size(); i++){
                    std::transform(matriz[i].begin(), matriz[i].end(), matriz1.matriz[i].begin(), resultado.matriz[i].begin(),
                   [](T a, T b) { return a - b; });
                }
                
                return resultado;
            
        };

       */

      //Caso de la multiplicacion
      /*
      Matriz<T> operator*(const Matriz<T>& matriz2){
            
                Matriz<T> resultado(matriz.size(), matriz2.columnas);

                    for (int i = 0; i < filas; i++) {
                        std::vector<T> tempVector;
                        for (int j = 0; j < columnas; j++) {
                            tempVector.push_back(0);
                        }
                        resultado.matriz.push_back(tempVector);
                    }

                    //for ( int i = 0; i < matriz.size(); i++){
                      //  std::transform(matriz[i].begin(), matriz[i].end(), matriz2.matriz[i].begin(), resultado.matriz[i].begin(),
                       // []( T a, T b) { return a * b; });
                    //}


                    for (int i = 0; i < filas; ++i) {
                        for (int j = 0; j < matriz2.columnas; ++j) {
                            for (int k = 0; k < columnas; ++k) {
                                resultado.matriz[i][j] += matriz[i][k] * matriz2.matriz[k][j];
                            }
                        }
                    }

                return resultado;
            };
      */