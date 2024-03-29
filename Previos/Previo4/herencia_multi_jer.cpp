#include <iostream>
using namespace std;

//ejemplo de herencia multinivel
class A {
    public:
        void display(){
            cout <<"Base class content.\n";
        }
};

//Clase b heredada de A
class B: public A {};
//Clase C heredada de A
class C: public B {}; //Puedo acceder a A gracias a laherencia e B

//ejemplo de herencia multiple una clase puede tener herencia de multiples clases
class Mammal {
    public:
        Mammal(){
            cout << "Los mamiferos tienen mamas y pelo\n";
        }
};

class WingedAnimal {
    public:
        WingedAnimal(){
            cout << "Las aves puden volar\n";
        };
};

//Ejemplo de jerarquía
class Animal{
    public:
        void info(){cout << "Soy un animal"<< endl;}
};

class Dog: public Animal{
    public:
        void Bark(){cout << "Soy un perro y ladro" << endl;}
};

class Cat: public Animal {
    public:
        void meow(){cout << "Soy un gato y maullo" << endl;}
};

class Bat: public Mammal, public WingedAnimal {};
int main(){

    C obj;
    //Objeto de tipo clse C
    obj.display();

    //Objeto de tipo murcielago con caracteristicas de mamifero y ave
    //El constructor no necesita inicializar, no tiene parametros
    Bat b1;

    //Creacion de objeto tipo Dog
    Dog dog1;
    dog1.info(); //Funcion clase padre
    dog1.Bark();

    //Creacion clase cat
    Cat cat1;
    cat1.info();
    cat1.meow();

    return 0;
}
