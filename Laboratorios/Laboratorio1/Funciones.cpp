#include "Funciones.hpp"

//int &numContactos por referencia, puedo modificar varible original
void agregarContacto(Contacto listaContactos[], int &numContactos) {
    Contacto nuevoContacto;
    std::cout << "Ingrese el nombre del contacto: "<< "\n";
    std::cin >> nuevoContacto.nombre;
    std::cout << "Ingrese el nombre de telefono: "<< "\n";
    std::cin >> nuevoContacto.telefono;

    listaContactos[numContactos++] = nuevoContacto;
}

void mostrarContacto(const Contacto listaContactos[], int numContactos){
    std::cout << "Lista de contactos: " << "\n";
    for (int i = 0; i < numContactos; i++)
    {
        std::cout << "Nombre: "  << listaContactos[i].nombre << " telefono:  " << listaContactos[i].telefono << "\n";
    }
    
}

void buscarContacto(const Contacto listaContactos[], int numContactos){

    std::string nombreBusqueda;
    std::cout << "Ingrese nombre a buscar"<< "\n";
    std::cin >> nombreBusqueda;
    //Bandera para encontrar resultado
    bool encontrado = false;

    for (int i = 0; i < numContactos; i++){

        if (listaContactos[i].nombre == nombreBusqueda){
        std::cout << "Nombre: "  << listaContactos[i].nombre << " telefono:  " << listaContactos[i].telefono << "\n";
        //Bandera para encontrar resultado, encuentro resultado y rompo ciclo
        encontrado = true;
        break;
        }
    }

    //Caso de nunca encontrar un contacto
    if (!encontrado){
        std::cout << "Contacto no encontrado"<< "\n";
    }
    
    
}
