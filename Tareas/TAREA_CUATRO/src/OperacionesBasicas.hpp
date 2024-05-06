#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Matriz.hpp"

template <typename T>
class OperacionesBasicas : protected Matriz{

    public:
        void validarSumaResta(const Matriz<T>& matriz1, const Matriz<T>& matriz2, int option){
            if (matriz1.filas != matriz2.filas){
                 throw std::invalid_argument("Filas de las dos matrices son distintas.");
            }else if (matriz1.columnas != matriz2.columnas){
                 throw std::invalid_argument("Columnas de las dos matrices son distintas.");
            }
            else {
                cout << "Dimensiones aptas para la SUMA y RESTA."
            }
            if 
        }

        void validarMultiplicacion(const Matriz<T>&matriz1, const Matriz<T>&matriz2){
            if (matriz1.columnas != matriz2.filas){
                throw std::invalid_argument("El numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2.");
            }else{
                cout << "Dimensiones aptas para la MULTIPLICACION."
            }
        }


        /*DEBO USAR STD::TRANSFORM*/
        void realizarSuma(const Matriz<T>& matriz1, const Matriz<T>& matriz2){
            std::vector<std::vector<T>> resultado = matriz1 + matriz2 ;
        }

        void realizarResta(const Matriz<T>& matriz1, const Matriz<T>& matriz2){
            std::vector<std::vector<T>> resultado = matriz1 - matriz2 ;
        }

        void realizarMultiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2){
            std::vector<std::vector<T>> resultado = matriz1 * matriz2;
        }
};


#endif //OPERACIONESBASICAS_HPP
