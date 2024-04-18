/**
 * @file Funcciones.hpp
 * @brief Encabezado con las funciones del progarma que se llaman desde el main y desde el archivo Funciones.cpp
 * 
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <tuple>
#include "List.hpp"
#include "Contacto.hpp"
using namespace std;

enum Opciones2 {
    ELIMINAR1 =1,
    ELIMINAR2,
    SALIR2
};

//Paso como parametro por referencia un puntero tipo nodo y un dicionario
//Funcion agregarContactos recibe como parametros un nodo, un hastable que almacena el nodo, nodeDir que almacena la direccion del nodo,  contactoDir almacena la direccion de memoria de los objetos de tipo contact0
//Recibe un contador que cuenta la cantidad de nodos.

/**
 * @brief Agrega un nuevo contacto.
 * 
 * @param nodo1 Objeto de tipo nodo, aun si reservar memoria.
 * @param hashTable Hashtable que almacena el nodo e informacion del contacto.
 * @param nodeDir Vector que almacena la dirección de memoria de los nodos.
 * @param contactoDir Vector que almacena la dirección de memoria de los objetos de tipo Contacto.
 * @param count Contador que cuenta la cantidad de nodos.
 */
void agregarContactos(Node* nodo1, unordered_map<Contacto*, Node*> &hashTable, vector<tuple<Node*, int>> &nodeDir, vector<Contacto*> &contactoDir, int &count);

//Funcion eliminarContacto recibe hashTable donde se elimina el nodo, contactoDir posee la memoria interna del celular, nodeDir contiene la ubicacion de los nodos acomodarlos 
//luego de su eliminacón


/**
 * @brief Elimina un contacto.
 * 
 * @param hashTable Hashtable que contiene el nodo a eliminar.
 * @param contactoDir Vector que posee la memoria interna del celular.
 * @param nodeDir Vector que contiene la ubicación de los nodos para acomodarlos luego de su eliminación.
 */

void eliminarContacto(unordered_map<Contacto*, Node*> &hashTable, vector<Contacto*> &contactoDir, vector<tuple<Node*, int>> &nodeDir);

//Funcion contactoExistHashTable retorna un booleano si el nombre ingresado se encuentra en el almacenaiento-cloud.

/**
 * @brief Verifica si un contacto existe en el Hashtable.
 * 
 * @param name Nombre del contacto a buscar.
 * @param hashTable Hashtable donde se busca el contacto.
 * @return true Si el contacto existe en el Hashtable.
 * @return false Si el contacto no existe en el Hashtable.
 */

bool contactoExistHashTable(string name, unordered_map<Contacto*, Node*> hashTable);

//Funcion contactoExistMemoInterna retorna un booleano si el nombre se encuentra en el almacenamiento interno.
/**
 * @brief Verifica si un contacto existe en la memoria interna.
 * 
 * @param name Nombre del contacto a buscar.
 * @param contactoDir Vector que contiene la memoria interna.
 * @return true Si el contacto existe en la memoria interna.
 * @return false Si el contacto no existe en la memoria interna.
 */

bool contactoExistMemoInterna(string name, vector<Contacto*> contactoDir);

//Funcion imprimir muestra el contenido de la tabla hash
/**
 * @brief Imprime el contenido de la Hashtable.
 * 
 * @param hashTable Hashtable que se va a imprimir (almacenamiento-cloud).
 */

void imprimir(unordered_map<Contacto*, Node*> hashTable);

//Funcion mostrar muestra el contenido de la memoria interna
/**
 * @brief Muestra el contenido de la memoria interna.
 * 
 * @param contactoDir Vector que contiene la memoria interna del celular.
 */

void mostrar(vector<Contacto*> contactoDir);

//Funcion sortLinkeList ordena la lista enlazada luego de la eiliminacion de alguno de los nodos.
/**
 * @brief Ordena la lista enlazada luego de la eliminación de un nodo.
 * 
 * @param nodoAEliminar Nodo que se ha eliminado.
 * @param nodeDir Vector que contiene la ubicación de los nodos para acomodarlos después de su eliminación.
 */

void sortLinkeList(const Node* nodoAEliminar, vector<tuple<Node*, int>> &nodeDir);

//Función bubbleSort ordena el vector de contactos de manera alfabetica
/**
 * @brief Ordena un vector de contactos de manera alfabética.
 * 
 * @param arr Vector de contactos que se va a ordenar.
 */

void bubbleSort(vector<Contacto*> &arr);

#endif //FUNCIONES_HPP