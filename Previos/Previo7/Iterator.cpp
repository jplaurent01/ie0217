#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    //Creo un vector de tipo string
    vector <string> lenguajes = {"Python", "C++", "Java"};

    //Creo un iterador, que es un que representa la posción de un elemento del vector
    vector<string>::iterator itr;

    //Voy a recorrer todo el contenido del vector
    //Apunto al primer elemento del vecotr lenguajes.begin()
    //Apunto al elemento final del vector lenguajes.end()
    //Apunto al siguiente elemento del vector itr++
    for ( itr= lenguajes.begin(); itr != lenguajes.end(); itr++){
        //Desreferencio el contenido de memoria del iterador actual
        cout <<*itr<<", ";
    }
    
    return 0;
}