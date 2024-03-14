#include <iostream>
// se evita escribir escribir std:: para imprimir
using namespace std;

//ejemplo donde las variables del main existen unicamente en el main
int main(){
    int a,b;
    int c;
     a = 10;
     b = 20;
     c = a + b;
    cout <<c;
    return 0;
}