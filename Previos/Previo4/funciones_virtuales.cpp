#include <iostream>
using namespace std;

/*Una función virtual es una función miembro en la clase base
 que esperamos redefinir en clases derivadas. Básicamente, se usa una 
función virtual en la clase base para garantizar que la función se invalide. 
Esto se aplica especialmente a los casos en los que un 
puntero de la clase base apunta a un objeto de una clase derivada*/

class Base{
    public:
    //funcion virtual
        virtual void print(){
            cout << "Funcion base" << endl;
        }
};

//Clase padre clase Base
class Derived: public Base{
    public:
        void print(){
            cout << "Funcion derivada" << endl;
        }
};

int main(){
    Derived derived1;
    //puntero de tipo base apunta a la direccion de memoria del objeto derived1
    Base* base1 = &derived1;

    //imprimo contenido clase
    base1->print();


    
    return 0;
}
