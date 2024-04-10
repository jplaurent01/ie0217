// Nombre del archivo: Pais.hpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "Pais.hpp"
 
//constructor de la clase 
//Constructor de la clase
/**
 * @brief Constructor de la clase.
 * 
 * @param _name Nombre del país.
 * @param _id ID del país.
 * @param _habitantes Número de habitantes del país.
 */
Pais::Pais(string _name, int _id, int _habitantes) :
name(_name), id(_id), habitantes(_habitantes){}

//Metodo double devuelve el Pib aleatoriamente
/**
 * @brief Método virtual para calcular el PIB del país.
 * 
 *Calcula PIB de manera aleatoria.
        * 
        * @return regreasa valor aleatorio PIB.
        */
double Pais::calcularPib() const {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> distrib(1000, 10000);
        return distrib(gen);
}

//Metodo publico que llama al metodo privado de sobrecarga

/**
 * @brief Método publico que hace el llamado al metodo privado para compar entre dos países.
 * 
 * @param pais0 Primer país a comparar.
 * @param pais1 Segundo país a comparar.
 */
void Pais::realizarComparacion(const Pais pais0, const Pais pais1) const{
        
        if (pais0 == pais1){
            cout << "Paises son del mismo tipo" << endl;
        }
        else{
            cout << "Paises No son del mismo tipo" << endl;
        }
        
}

//Metodo determina si un numero es o no es primo
/**
 * @brief Método para determinar si un número es primo.
 * 
 * @param num Número a verificar.
 * @return true si el número es primo, false en caso contrario.
 */
bool Pais::isPrimo(int num) const{
if (num <= 1) {
        return false;
}
for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
        return false;
        }
}
return true;
}

//Operador a sobrecargar es el "=="
// pais1 es un alias para un objeto Pais que no se puede modificar 
//dentro de la función operator==.const evita copias innecesarias de objetos y garantiza
// que el objeto pasado como argumento no se modificará accidentalmente dentro de la función.
/**
 * @brief Método comparador de países, sobrecargo operador ==.
 * 
 * @param pais1 País a comparar.
 * @return true si los ID de los países son primos entre sí, false en caso contrario.
 */
bool Pais::operator== (const Pais& pais1) const{
        bool resultado(
        isPrimo(this->id) && isPrimo(pais1.id)
        );
        return resultado;
}