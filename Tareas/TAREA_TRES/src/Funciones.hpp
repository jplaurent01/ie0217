#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "List.hpp"
#include "Contacto.hpp"
using namespace std;

enum Opciones2 {
    ELIMINAR1 =1,
    ELIMINAR2,
    SALIR2
};

//Paso como parametro por referencia un puntero tipo nodo y un dicionario
void agregarContactos(Node* nodo1, unordered_map<Contacto*, Node*> &hashTable, vector<Node*> &nodeDir, vector<Contacto*> &contactoDir);
void eliminarContacto(unordered_map<Contacto*, Node*> &hashTable, vector<Contacto*> &contactoDir);
bool contactoExistHashTable(string name, unordered_map<Contacto*, Node*> hashTable);
bool contactoExistMemoInterna(string name, vector<Contacto*> contactoDir);
void imprimir(unordered_map<Contacto*, Node*> hashTable);
#endif //FUNCIONES_HPP