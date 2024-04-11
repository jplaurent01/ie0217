#include <iostream>
#include <string>
#include "Libro.hpp"
#include "Funciones.hpp"

using namespace std;

enum opciones{
    AGREGAR_LIBRO = 1,
    MOSTRAR_LIBRO,
    SALIR,
    //Se agrega ultimo miembro para saber cuantas opciones tengo
    OPCIONES_MAX
};

//Siempre es necesario que se llame main, es por donde entramos el progrma
int main() {
    //Al inicio no apunto a nada
    Libro* listaLibros = nullptr;
    int opcion;
    do
    {
        cout << "Selecione su opcion " << endl;
        cout << "1. Agregar un libro " << endl;
        cout << "2. Mostrar todos los libros " << endl;
        cout << "3.Salir " << endl;
        cin >> opcion;

        //Menu de opciones
        switch (opcion){
        case AGREGAR_LIBRO:
            agregarLibro(listaLibros);
            break;
        case MOSTRAR_LIBRO:
            mostrarLibro(listaLibros);
            break;
        case SALIR:
           cout << "Saliendo del programa ..." << endl;
            break;
        default:
            cout << "Opcion no permitida" << endl;
            break;
        }


    } while (opcion != SALIR);
    
    //Cuando se sale del programa se libera memoria
    liberarMemoria(listaLibros);

    return 0;
}
//No es necesario que el nombre del archivo sea main.cpp

//Estrucutura de tipo libro
/*
struct Libro{
    string titulo;
    string autor;
    string genero;
    //Punto de tipo libor, eventualmente apunt a la siguiente dir. memoria con un nuevo objeto libro
    Libro* siguiente;
};
*/



/*
//Parametro por referencia de un objeto de tipo puntero Libro, el puntero que se recibe
//como argumento modifica al puntero original
void agregarLibro(Libro*& lista){
    //Reserva tamano memoria dinamica del tamano de Libro struct
    Libro* nuevoLibro = new Libro;

    cout << "Ingrese el titulo del libro" << endl;
    //getline abarca espacios del strign ejemplo costa rica, agarra toda el string
    //si no agrego esto tengo un error con los cin
    cin.ignore();
    getline(cin, nuevoLibro->titulo);

    cout << "Ingrese el autor del libro" << endl;
    getline(cin, nuevoLibro->autor);

    cout << "Ingrese el genero del libro" << endl;
    getline(cin, nuevoLibro->genero);

    //indico donde esta el siguiente libro
    nuevoLibro->siguiente = lista;

    lista = nuevoLibro;

    cout <<"Libro agregado correctamente" << endl;
};

void mostrarLibro(Libro* lista){
//me encuentro ultimo elemento de la lista
 if (lista == nullptr){
    cout << "La libreria no tiene libros" << endl;
    //me salgo de la funcion tipo void
    return;
 }

 cout << "Lista de libros: " << endl;
 //No he llegado al ultimo elemento de la lista
 while (lista != nullptr){
    cout << "Titulo: " << lista->titulo << endl;
    cout << "Autor: " << lista->autor << endl;
    cout << "Genero: " << lista->genero << endl << endl;
    //apunto al siguiente elemento de la lista
    lista = lista->siguiente;
 }
 
 
};

void liberarMemoria(Libro* &lista){
    while(lista != nullptr){
        Libro* temp = lista;
        //indico donde esta el siuiente
        lista = lista->siguiente;
        delete temp;
    }
};
*/







