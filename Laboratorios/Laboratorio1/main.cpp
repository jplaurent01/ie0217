#include <iostream>
#include "Contacto.hpp"
#include "Funciones.hpp"

//No ejecuta esta codigo
//Sustituye todas las variables MAX_CONTACTOS les pone 100 yluego ejecuta
#define MAX_CONTACTOS 100

//Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
enum Opciones {
    AGREGAR = 1,
    MOSTRAR,
    BUSCAR,
    SALIR
};

int main() {
    Contacto listaContactos[MAX_CONTACTOS];

    int numContactos = 0;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar contacto\n";
        std::cout << "2. Mostrar contacto\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;
    
    //Pregunta sobre los valores del enum
    switch (opcion) {
    case AGREGAR:
        //Modifico variable original de numContactos, por parametros por referencia
        agregarContacto(listaContactos, numContactos);
        break;
    case MOSTRAR:
        mostrarContacto(listaContactos, numContactos);
        break;
    case BUSCAR:
        buscarContacto(listaContactos, numContactos);
        break;
    case SALIR:
        std::cout << "Saliendo...\n";
        break;
    default:
        std::cout << "Opción no válida\n";
        break;
    }
    } while(opcion != SALIR);



    return 0;
}





