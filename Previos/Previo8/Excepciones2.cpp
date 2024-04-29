#include <iostream>
#include <stdexcept>//Libreria manipulacion de excepciones
using namespace std;

int main(){
    double numerator, denominator, divide;
    //Se pregunta al usuario por numeros a ingresar
    cout << "Ingrese un numerador ";
    cin >> numerator;

    cout << "Ingrese un denominador ";
    cin >> denominator;

    try{
        if (denominator == 0){
            throw runtime_error("Error: el denominador no puede ser  0");
        }

        divide = numerator/denominator;
        cout <<" El resultado es:  " << divide << endl;
    
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
    
    return 0;
}