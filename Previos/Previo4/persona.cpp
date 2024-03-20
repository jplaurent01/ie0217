#include "persona.hpp"
using namespace std;

//constructor que recibe un nombre y una edad para inicializar los atributos de la clase.
//El constructor Persona::Persona(string nombre, string edad) asigna los valores recibidos
// a los atributos nombre y edad de la instancia actual (this).
Persona::Persona(string nombre, int edad){
// La notación this-> se utiliza en C++ para acceder a los miembros de un objeto dentro de la propia clase.
//this->nombre = nombre; asigna el valor de nombre que se pasa al constructor al atributo nombre de la instancia actual (this).
    this->nombre = nombre;
    this->edad = edad;
}

/*En C++, el operador :: se utiliza para acceder a miembros estáticos de una clase,
 a miembros de una clase desde fuera de la clase misma (para evitar ambigüedades)
  y para definir o implementar miembros de una clase fuera de la declaración de la clase.*/
string Persona::getName(){
    return nombre;
}

int Persona::getEdad(){
 return edad;
}

//Esta función actualiza el valor de edad
void Persona::setEdad(int edad){
    // Usando this->edad = edad;, 
    //se asigna el valor recibido al atributo edad de la instancia de Persona en la que se llama a la función
    this->edad = edad;
}



