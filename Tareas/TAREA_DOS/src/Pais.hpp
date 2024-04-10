/**
 * @file Pais.hpp
 * @brief Encabezado de la clase Pais
 *
 * Archivo que contiene la definición de la clase Pais, que representa un país con su nombre, ID, número de habitantes y PIB.
 * También incluye métodos para calcular el PIB, comparar países y verificar si un número es primo.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef PAIS_HPP
#define PAIS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
/**
 * @brief Clase paid.
 */
class Pais{
    protected:
        string name;
        int id;
        int habitantes;
        double pib;
        
    
    public:
        //Constructor de la clase
        /**
         * @brief Constructor de la clase.
         * 
         * @param _name Nombre del país.
         * @param _id ID del país.
         * @param _habitantes Número de habitantes del país.
         */
        Pais(string _name, int _id, int _habitantes);

        /**
         * @brief Método virtual para calcular el PIB del país.
         * 
         *Calcula PIB de manera aleatoria.
         * 
         * @return regreasa valor aleatorio PIB.
         */
        virtual double calcularPib() const;

        /**
         * @brief Método publico que hace el llamado al metodo privado para compar entre dos países.
         * 
         * @param pais0 Primer país a comparar.
         * @param pais1 Segundo país a comparar.
         */
        void realizarComparacion(const Pais pais0, const Pais pais1) const;

         /**
         * @brief Método para determinar si un número es primo.
         * 
         * @param num Número a verificar.
         * @return true si el número es primo, false en caso contrario.
         */
        bool isPrimo(int num) const;

    private:

        //metodo comparador de paises, retorna un boleano en caso de que sus ID sean o no primos
        /**
         * @brief Método comparador de países, sobrecargo operador ==.
         * 
         * @param pais1 País a comparar.
         * @return true si los ID de los países son primos entre sí, false en caso contrario.
         */
        bool operator== (const Pais& pais1) const;

};

#endif //PAIS_HPP