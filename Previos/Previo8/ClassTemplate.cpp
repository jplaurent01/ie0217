#include <iostream>
using namespace std;

//Teplate de una clase
template <class T>
class Number {
    private:
    //Variable de tipo T
    T num;

    public: 
    Number(T n) : num(n){}//Constructor de la clase

    T getNum(){
        return num;
    }

};

//Template con multiples parametros, char por defecto
template <class T, class U, class V = char>
class ClassTemplate{
    private:
        T var1;
        U var2;
        V var3;

    public:
        //Cnstructor
        ClassTemplate(T v1, U v2, V v3): var1(v1), var2(v2), var3(v3) {}

        //metodo publico para imprimir contenido
        void printVar(){
            cout << "var1 = " << var1 << endl;
            cout << "var2 = " << var2 << endl;
            cout << "var3 = " << var3 << endl;
        }

};





int main(){

    //Se inicializan los objetos
    //Se crea un objeto de tipo entero
    Number<int> numberInt(7);

    //Se crea un objeto tipo double
    Number<double> numberDouble(7.7);

    //Llamado a métdos
    cout << "Numero int: " << numberInt.getNum() << endl;
    cout << "Numero double: " << numberDouble.getNum() << endl;

    //Se crea un objeto que recibe como paramentrso un entero, double y char, se inicializa
    //Como no paso V internamente utiliza un char por defecto
    ClassTemplate<int, double> obj1(7, 7.7,'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    //Se crea un objeto con tipos int, double y bool
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    return 0;

}