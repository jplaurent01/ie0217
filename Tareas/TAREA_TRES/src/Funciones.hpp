#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include <iostream>
#include "List.hpp"
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

enum Opciones2 {
    ELIMINAR1 =1,
    ELIMINAR2,
    SALIR2
};

//Paso como parametro por referencia un puntero tipo nodo y un dicionario
void agregarContactos(Node* nodo1, unordered_map<string*, unordered_map<string*, Node*>> &hashTable, vector<Node*> &nodeDir);
void eliminarContacto( unordered_map<string*, unordered_map<string*, Node*>> &hashTable);
bool contactoExist(string name, unordered_map<string*, unordered_map<string*, Node*>> hashTable);
void imprimir(unordered_map<string*, unordered_map<string*, Node*>> hashTable);
#endif //FUNCIONES_HPP