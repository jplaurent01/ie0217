#include <iostream>
using namespace std;
#include "persona.hpp"

int main(){

    Persona persona1("Jose pablo", 26);
    cout << "Nombre: " << persona1.getName()<<endl;
    cout << "Edad: " << persona1.getEdad()<<endl;

    persona1.setEdad(12);
    cout << "Edad biologica: " << persona1.getEdad()<<endl;
    return 0;
}
