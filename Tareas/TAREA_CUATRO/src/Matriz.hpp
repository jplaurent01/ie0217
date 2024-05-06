#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "ValidadorDeEntrada.hpp"

template <typename T>
class Matriz{

    private:
       std::vector<std::vector<std::complex<double>>> matrizComplex; 
    protected:
        int filas;
        int columnas;
        std::vector<std::vector<T>> matriz;

    public:
        
        Matriz(int filas, int columnas) :  filas(filas), columnas(columnas) {

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

        void setDimensiones(const int filas, const int columnas) {
             ValidadorDeEntrada<T> validadorEntrada;
            try{
                validadorEntrada.validarDimensiones(filas);
                validadorEntrada.validarDimensiones(columnas);
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
            
            //if (filas <= 0 ){
              //  throw std::invalid_argument("Fila invalida");

            //} else if (columnas <= 0){
              //  throw std::invalid_argument("Columna invalida");     
           // }
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
       
        Matriz<T> operator+(const Matriz<T>& matriz1){
            if (filas != matriz1.filas || columnas != matriz1.columnas) {
                throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para sumarse.");
            }

            Matriz<T> resultado(filas, columnas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    resultado.matriz[i][j] = matriz[i][j] + matriz1.matriz[i][j];
                }
            }

            return resultado;
        };

        Matriz<T> operator-(const Matriz<T>& matriz1){
            if (filas != matriz1.filas || columnas != matriz1.columnas) {
                throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para sumarse.");
            }

            Matriz<T> resultado(filas, columnas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    resultado.matriz[i][j] = matriz[i][j] - matriz1.matriz[i][j];
                }
            }

            return resultado;
        };

        Matriz<T> operator*(const Matriz<T>& matriz2){
            if (columnas != matriz2.filas) {
                throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarlas.");
            }

            Matriz<T> resultado(filas, matriz2.columnas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < matriz2.columnas; j++) {
                    T sum = T();
                    for (int k = 0; k < columnas; k++) {
                        sum += matriz[i][k] * matriz2.matriz[k][j];
                    }
                    resultado.matriz[i][j] = sum;
                }
            }

            return resultado;
            };
        
        


};


#endif //MATRIZ_HPP

/*
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
                    matriz.push_back(tempVector);
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
*/


/*
       void llenarMatriz(int complexFlag = -1) {
                    
                    if (complexFlag == 0){

                        ValidadorDeEntrada<std::complex<double>> validadorEntrada;

                        for (int i = 0; i < filas; i++) {

                            std::vector<std::complex<double>> tempVector;

                            for (int j = 0; j < columnas; j++) {
                                bool flag = false;
                                std::complex<double> value
                                std::string strValue;
                                float realValue, imagValue;
                                std::string realPart, imagPart, result;

                                do {
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
                        
                        }
                        
                            tempVector.push_back(value);
                        }
                        matriz.push_back(tempVector);
                
                    }else{

                        ValidadorDeEntrada<T> validadorEntrada;

                        for (int i = 0; i < filas; i++) {

                            std::vector<T> tempVector;

                            for (int j = 0; j < columnas; j++) {
                                bool flag = false;
                                T value;
                                std::string strValue;

                                do {
                                    std::cout << "matriz[" << i << "][" << j << "] : " ;
                                    getline(std::cin, strValue);
                                    flag = validadorEntrada.validarTipoDato(strValue, typeid(T).name(), value);
                                    if (!flag) {
                                        std::cout << "Dato agregado no es valido, vuelva a introducirlo..." << std::endl;
                                    }
                                } while (!flag);


                            }
                        
                            tempVector.push_back(value);
                        }
                        matriz.push_back(tempVector);
            }
        
        }
*/


/*
 void llenarMatriz(int complexFlag = -1) {
            ValidadorDeEntrada<T> validadorEntrada;

            for (int i = 0; i < filas; i++) {

                std::vector<T> tempVector;

                for (int j = 0; j < columnas; j++) {
                    bool flag = false;
                    T value;
                    std::string strValue;
                    
                    if (complexFlag == 0){
                        float realValue, imagValue;
                        std::string realPart, imagPart, result;

                        do {
                            std::cout << "matriz[" << i << "][" << j << "] - Parte real: ";
                            getline(std::cin, realPart);
                            std::cout << "\nParte imaginaria: ";
                            getline(std::cin, imagPart);
                            result = realPart + "," + imagPart;
                        } while (!validadorEntrada.validarTipoDato(result, typeid(T).name(), value));

                        //do {
                          //  std::cout << "matriz[" << i << "][" << j << "] - Parte imaginaria: ";
                           // getline(std::cin, imagPart);
                        //} while (!validadorEntrada.validarTipoDato(imagPart, typeid(float).name(), imagValue));

                        //value = std::complex<float>(realValue, imagValue);
                        
                        std::istringstream is('(' + result + ')');
                        std::complex<double> c;
                        is >> c;
                        //value = c;
                        std::cout << "the number is " << c << "\n";
                        std::cout << typeid(c).name() << '\n';
                        std::cout << typeid(value).name() << '\n';
                    }else{
                        do {
                            std::cout << "matriz[" << i << "][" << j << "] : " ;
                            getline(std::cin, strValue);
                            flag = validadorEntrada.validarTipoDato(strValue, typeid(T).name(), value);
                            if (!flag) {
                                std::cout << "Dato agregado no es valido, vuelva a introducirlo..." << std::endl;
                            }
                        } while (!flag);
                    }
                    
                    tempVector.push_back(value);
                }
                matriz.push_back(tempVector);
                
            }
        
        }
*/