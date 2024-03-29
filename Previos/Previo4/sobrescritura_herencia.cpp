#include <iostream>
using namespace std;

class Base{

    public: 
        void print(){
            cout << "Base Function" << endl;
        };
        
};

class Derived : public Base{
    public:
    //sobre escribo en el nombre de la funcion print
        void print(){
            cout << "Derived Function" << endl;
        };
};


int main(){

    Derived derived1, derived2;
    //imprimoprint de clase Derived
    derived1.print();

    //accedo al print de la clase base
    derived2.Base::print();

    
    return 0;
}
