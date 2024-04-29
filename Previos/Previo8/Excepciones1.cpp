#include <iostream>
using namespace std;

int main(){
    double numerator, denominator, divide;
    //Se pregunta al usuario por numeros a ingresar

    cout << "Ingrese un numerador ";
    cin >> numerator;

    cout << "Ingrese un denominador ";
    cin >> denominator;

    try{

        //Arroja una excepcion si el denominador es 0
        if (denominator == 0)
            throw 0;

            //No se ejecuta si el denominador es 0
            divide = numerator/denominator;
            cout << numerator << " / " << denominator << " = " << divide << endl;
    }
    catch(int num_exception){
        cout << "Error: no se puede dividir entre " << num_exception << endl;
    }
    return 0;
}