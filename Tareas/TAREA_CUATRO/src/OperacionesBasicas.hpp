/**
 * @file OperacionesBasicas.hpp
 * @brief Valida las dimensiones de la matriz para sus operaciones de suma, resta y multiplicacion
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <complex>

template <typename T>
class OperacionesBasicas : public Matriz<T>{

    public:
    //Verifica dimensiones para la suma y resta es static para no tener que inicializar
        /**
         * @brief Valida las dimensiones de las matrices para la suma y resta.
         * @param matriz1 Primera matriz.
         * @param matriz2 Segunda matriz.
         * @throw std::invalid_argument Si las dimensiones no son compatibles.
         */
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
        //Verifica dimensiones para la multiplicacion es static para no tener que inicializar
        /**
         * @brief Valida las dimensiones de las matrices para la multiplicación.
         * @param matriz1 Primera matriz.
         * @param matriz2 Segunda matriz.
         * @throw std::invalid_argument Si las dimensiones no son compatibles.
         */
        static void validarMultiplicacion(const Matriz<T>&matriz1, const Matriz<T>&matriz2){
            if (matriz1.columnas != matriz2.filas){
                throw std::invalid_argument("El numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2.");
            }else{
                std::cout << "Dimensiones aptas para la MULTIPLICACION." << std::endl;
            }
        }


};


#endif //OPERACIONESBASICAS_HPP
