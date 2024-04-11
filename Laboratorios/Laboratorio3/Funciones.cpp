#include "Funciones.hpp"

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
