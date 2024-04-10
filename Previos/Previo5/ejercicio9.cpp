#include <bits/stdc++.h> // Incluye todas las bibliotecas estándar de C++
#include <iostream>
using namespace std;

// Se crea una clase para representar un nodo de la lista enlazada
class Node {
public:
    int value;  // Valor almacenado en el nodo
    Node* next; // Puntero al siguiente nodo en la lista
};

int main() {

    // Se crean punteros para los nodos de la lista
    Node* head;  // Puntero al primer nodo
    Node* one = NULL;   // Puntero al segundo nodo
    Node* two = NULL;   // Puntero al tercer nodo
    Node* three = NULL; // Puntero al cuarto nodo

    // Se asigna memoria para los nodos en el heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Se asignan valores a los nodos
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Se conectan los nodos enlazando los punteros 'next'
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Se imprime la lista enlazada
    head = one; // Se establece el puntero 'head' al primer nodo
    while (head != NULL) { // Mientras el puntero 'head' no sea NULL (fin de la lista)
        cout << head->value; // Se imprime el valor del nodo actual
        head = head->next; // Se mueve el puntero 'head' al siguiente nodo
    }

    // Liberar memoria
    delete one;
    delete two;
    delete three;
    
    return 0;
}
