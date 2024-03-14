#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;

//Prototipo de la funcion
//variable no puede ser modificado después de su inicialización
//referencia a una variable de tipo string
bool isNumber(const string& s);

int main(){
    //Declara variable tipo string
    string x;
     cout <<"Ingrese un numero: ";
     cin >> x;
    
    //Si se optiene un valor numerico se imprime el numero si no, ejecuta else
     if (isNumber(x)) {
        cout <<"Numero ingresado: " <<x;
     }

     else {
        cout <<"Debe ingrese un valor numerico";
     }
     
    return 0;
}

//Funcion returno un valor boleano
bool isNumber(const string& s){
    for (char element: s){
        /*
        funcion isdidgit() determina si por lo menos uno de los caracteres del string no es un valor numerico
        rompe el ciclo en caso de encontrar algo distinto a un numero
        */
        if (!isdigit(element)){
            return false;
        }
    }
    return true;
}