#include <string>
#include <iostream>
#include <unordered_map> // Diccionario posee la estructura key-value
#include <vector>
#include "List.hpp"
#include "Contacto.hpp"
#include "Funciones.hpp"
#include <tuple>

using namespace std;

//Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
enum Opciones {
    AGREGAR = 1,
    ELIMINAR,
    IMPRIMIR,
    MOSTRAR,
    SALIR
};

int main() {
        int opcion;
        //hashTable,guarda direciion memoria objeto contacto y dir del nodo
        unordered_map<Contacto*, Node*> hashTable;
        //Vector de tuplas, tiene la direcion en memoria del nodo y su unicacion
        vector<tuple<Node*, int>> nodeDir;
        //Contador de las posiciones de las memorias
        int count = 0;
        //Vector con las direcciones de memoria de los objetos tipo contacto (memoria interna)
        vector<Contacto*> contactoDir;

        
        do {
            //Menu principal
            cout << "\nMenu:\n";
            cout << "1. Agregar un contacto\n";
            cout << "2. Eliminar un contacto\n";
            cout << "3. Imprimir Hash-Table y Listas Enlazadas:\n";
            cout << "4. Mostrar todos los contactos\n";
            cout << "5. Salir del programa\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion;
        
        switch (opcion) {
            
           case AGREGAR:{
                //Siempre que entro aqui creo un nuevo nodo
                //Creo objeto de tipo nodo puntero
                Node* nodo1;
                //nodeDir.push_back(nodo1);
                //Envio como parametros la dicreccion de memoria del nodo y el dicionario
                agregarContactos(nodo1, hashTable, nodeDir, contactoDir, count);
            }
            break;
                
            case ELIMINAR:{
                eliminarContacto(hashTable, contactoDir, nodeDir);
            }
                break;

            case IMPRIMIR:{
                imprimir(hashTable);
                }

                break;

            case MOSTRAR:{
                mostrar(contactoDir);
                }

                break;
            case SALIR:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no valida\n";
                break;
            }

        } while(opcion != SALIR);


            if (hashTable.size() > 0){
                //Libero memoria restante asignada para el amacenamiento cloud
                //elimino la memoria asignada a los nodos
                for (auto& pair : hashTable) {
                    //Libero memoria del puntero tipo string name
                    //free(pair.first);
                    delete pair.second;
                }
            }
            
            if (contactoDir.size() > 0){
                //Libero memoria restante asignada a los objetos contactos (memoria intern)
                for (auto& element : contactoDir) {
                    //Libero memoria del puntero tipo string name
                    free(element);
                }
            }
            
            
        return 0;
    }