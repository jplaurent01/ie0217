#include <iostream>
#include <stack>
using namespace std;

int main(){
    
   //Se crea un stack de numeros enteros
   stack<int> numbers;
    
    //Se utiliza la peracion push del stack
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);

    cout << "Numeros: " << endl;

    //Se puede acceder a los numeros, obteniedo el top y utilizando la operacion pop
    //Hasta que el satck quede vacio
    while (!numbers.empty()){
        //Se imprime el elemento en la posición top
        cout << numbers.top() << ", ";

        //Se elimina el elemnto del stack mediante pop()
        numbers.pop();
    }
    

    return 0;
}