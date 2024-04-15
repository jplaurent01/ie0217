#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>

using namespace std;

// Se crea una clase para representar un nodo de la lista enlazada
class Node {
    public:
        string name;  // Nombre almacenado en el nodo
        string number; // Número almacenado en el nodo
        Node* last;   // Puntero al nodo anterior nodo en la lista
};

#endif //LIST_HPP
