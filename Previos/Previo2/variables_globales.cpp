#include <iostream>
// se evita escribir escribir std:: para imprimir
using namespace std;

//variable que se puede utilizar fuera del main, es una variable global
//Se puede utilizar en el main
int g;

int main(){
    int a,b;
     a = 10;
     b = 20;
     g = a + b;
    cout <<g;
    return 0;
}