#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;



int main(){
    //Declara variable tipo string
    int x;
     cout <<"Ingrese un numero: ";
     cin >> x;
    
    //Si se optiene un valor numerico distinto de cero se imprime el numero si no, ejecuta else
     if (x != 0) {

        if (x > 0){
            cout <<"Numero posotivo";
        }
        else{
            cout <<"Numero negativo";
        }
     }

     else {
        cout <<"Debe ingrese valor distinto de cero";
     }
     
    return 0;
}

