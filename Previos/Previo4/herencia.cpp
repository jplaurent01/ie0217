#include <iostream>
using namespace std;

class Animal{

    public: 
        void eat(){
            cout << "Comer" << endl;
        };

        void sleep(){
            cout << "Dormir" << endl;
        }
        
};

//La clase perro posee herencia de la clase animal
/*La herencia es una de las características clave de la programación
orientada a objetos en C++. Nos permite crear una nueva clase (clase 
derivada) a partir de una clase existente (clase base). La clase derivada
 hereda las características de la clase base y puede tener 
características adicionales propias
*/
class Perro : public Animal{
    public:
        void bark(){
            cout << "Ladrar" << endl;
        };
    
};

int main(){

    Perro miPerro;

    miPerro.eat();
    miPerro.sleep();
    miPerro.bark();
    
    return 0;
}
