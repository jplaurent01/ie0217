#include <string>
#include <iostream>
#include <unordered_map> // Diccionario posee la estructura key-value
#include <vector>
#include "List.hpp"
#include "Contacto.hpp"
#include "Funciones.hpp"

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
        // Hash-Table,guarda direciion memoria objeto contacto y dir del nodo
        unordered_map<Contacto*, Node*> hashTable;
        //unordered_map<string*, unordered_map<string*, Node*>> hashTable;
        //Vector con las direcciones de memoria de de los nodos
        vector<Node*> nodeDir;
        //Vector con las direcciones de memoria de los objetos tipo contacto
        vector<Contacto*> contactoDir;

        
        do {
            //Menu principal
            std::cout << "\nMenu:\n";
            std::cout << "1. Agregar un contacto\n";
            std::cout << "2. Eliminar un contacto\n";
            std::cout << "3. Imprimir Hash-Table y Listas Enlazadas:\n";
            std::cout << "4. Mostrar todos los contactos\n";
            std::cout << "5. Salir del programa\n";
            std::cout << "Ingrese una opcion: ";
            std::cin >> opcion;
        
        switch (opcion) {
            
           case AGREGAR:{
                //Siempre que entro aqui creo un nuevo nodo
                //Node* nodo1;
                //Creo objeto de tipo nodo puntero
                Node* nodo1;
                //nodeDir.push_back(nodo1);
                //Envio como parametros la dicreccion de memoria del nodo y el dicionario
                agregarContactos(nodo1, hashTable, nodeDir, contactoDir);
            }
            break;
                
            case ELIMINAR:{
                eliminarContacto(hashTable, contactoDir);
            }
                break;

            case IMPRIMIR:{
                imprimir(hashTable);
                }

                break;

            case MOSTRAR:{

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

        // Liberar memoria utilizada por los contactos
        //for (auto& pair : hashTable) {
            // Liberar memoria del nombre y el número
          //  free(pair.first);
           // for (auto& innerPair : pair.second) {
             //   free(innerPair.first);
                // Liberar memoria del nodo
               // free(innerPair.second);
           // }
        //}

            // Liberar memoria utilizada por los contactos
            for (auto& pair : hashTable) {
                //Libero memoria del puntero tipo string name
                free(pair.first);
                delete pair.second;
                //for (auto& innerPair : pair.second) {
                    //Libero memoria del puntero tipo string number
                  //  free(innerPair.first);
                    //Libero memoria del puntero de clase nodo
                    //free(innerPair.second);
                   // delete innerPair.second;
                //}
            }
        return 0;
    }