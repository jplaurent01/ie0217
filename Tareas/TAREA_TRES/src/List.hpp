/**
 * @file Lista.hpp
 * @brief Encabezado con la clase de la lista enlazada
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>

using namespace std;

// Se crea una clase para representar un nodo de la lista enlazada
/**
 * @brief Clase para representar un nodo de la lista enlazada.
 * Esta clase contiene tres atributos: nombre, telefono y un puntero que apunta hacia el bloque de memoria anterior al nodo actual.
 */
class Node {
    public:
        //Nombre almacenado en el nodo
        string name;
        //Numero almacenado en el nodo  
        string number;
        //Puntero al nodo anterior nodo en la lista
        //hago esto porque no se cual es el siguiente bloque de memoria, pero si se cual es el bloque
        //de memoria anterior porque lo guardo en un vector.
        Node* last;   
};

#endif //LIST_HPP
