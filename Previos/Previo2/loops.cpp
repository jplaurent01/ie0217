#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;


int main(){
    //ciclo for
    for (int i = 1; i<=5; i++){
        cout<< i <<" ";
    }

    //se crea un array de enteros
    int num_array[] = {10,20,30,40};
    //Se itera sobre cada uno de los elementos del array no sus indices
    for (int element:num_array){
         cout<< element <<" ";
    }

    int index = 0;
    //Ciclo while itera de 0 a 5
    while(index <= 5){
        cout<< index <<" ";
        //aumento el indice
        index ++;
    }

    //ciclo do-while, ejecuto el codigo por lo menos una vez antes de evaluar la condicion
    //ejecuto el coodigo nada mas una vez, siguiente itneracion se se vera que i es mayor a 5
    int i = 5;
    do {
    cout<< i <<" ";
    i ++;
    } while (i < 5);
    
    /*sentencias tipo break; rompen los ciclos esto puede ser implementado bajo cierta condicion
      continue  es un equivalente a pass en python
    */
    return 0;
}

