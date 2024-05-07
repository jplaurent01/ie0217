#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <complex>

template <typename T>
class OperacionesBasicas : public Matriz<T>{

    public:
        static void validarSumaResta(const Matriz<T>& matriz1, const Matriz<T>& matriz2){
            if (matriz1.filas != matriz2.filas){
                 throw std::invalid_argument("Filas de las dos matrices son distintas.");
            }else if (matriz1.columnas != matriz2.columnas){
                 throw std::invalid_argument("Columnas de las dos matrices son distintas.");
            }
            else {
                std::cout << "Dimensiones aptas para la SUMA y RESTA." << std::endl;
            }

        }

        static void validarMultiplicacion(const Matriz<T>&matriz1, const Matriz<T>&matriz2){
            if (matriz1.columnas != matriz2.filas){
                throw std::invalid_argument("El numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2.");
            }else{
                std::cout << "Dimensiones aptas para la MULTIPLICACION." << std::endl;
            }
        }


};


#endif //OPERACIONESBASICAS_HPP
