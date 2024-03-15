#include <iostream>
using namespace std;

struct Distance{
    int feed;
    float inch;
};


int main(){

    //&var accedo a la direccion de memoria, referencio
    //*var accedo a la direccion de memoria, Des-referencio
    int var1 = 3;
    //cout << "Direccion de memoria de var1: " << &var1 <<endl;
    //cout << "Direccion de memoria de var2: " << &var2 <<endl;
    //cout << "Direccion de memoria de var3: " << &var3 <<endl;

    //Puntero de tipo entero
    int* pointer;
    //Puntero apunta hacia la direccion de memoria de var1
    pointer = &var1;

    cout << "Contenido de var1: " << var1 <<endl;
    cout << "Direccion de memoria de var1: " << &var1 <<endl;

    cout << "Direccion de memoria de senalada por pointer: " << pointer <<endl;
    //Des referencio el puntero
    cout << "Contenido de pointer " << *pointer <<endl;

    cout << "Cambiando el valor de var1 a 7 " <<endl;

    var1 = 7;
     
    cout << "Contenido de var1: " << var1 <<endl;
    cout << "Contenido de pointer " << *pointer <<endl;

    //De des referenciando el valor al que apunta pointer, puedo modificar el valor de var1
    cout << "Cambiando el valor de *pointer a 16 " <<endl;
    *pointer = 16;
    cout << "Contenido de var1: " << var1 <<endl;
    cout << "Contenido de pointer " << *pointer <<endl;

    //Se crea un puntero de tipo Distance y una variable de tipo distace
    Distance *ptr, d;
    //Ptr apunta hacia la dir memoria de d
    ptr =&d;

    /*, (*ptr).inch y d.inch son equivalentes. Del mismo modo, (*ptr).feet y 
    d.feet son equivalentes.*/

    cout << "Enter feet" <<endl;
    cin >>(*ptr).feed;

    cout << "Enter inch" <<endl;
    cin >>d.inch;

    cout << "Despliegue de informacion" <<endl;
    //de manera analoga ptr->inch y ptr->feed son equiv. a (*ptr).feed y (*ptr).inch
    cout << "Distancia " << ptr->feed << " feet, " <<  (*ptr).inch << " inch" << endl;

    /*Al crear un puntero hacia un arreglo, este almacenará la dirección de donde 
    inicia el arreglo, es decir, la dirección donde está ubicado 
    el primer elemento del arreglo.*/

    /*ptr=arr mismo que &arr[0]*/
    /* ... ptr+1 = &arr[1], ptr+2 = &arr[2], ptr+3 = &arr[3], etc....*/
    int *ptr_2;
    int arr[4] = {20,30,40,50} ;
    ptr_2 = arr;

    cout << "ptr + 1 es equiv. a &arr[1] : " <<ptr_2 +1 <<endl;
    cout << "ptr + 1 es equiv. a &arr[1] : " <<&arr[1]<<endl;
    cout << "ptr + 2 es equiv. a &arr[2] : " <<ptr_2 + 2 <<endl;
    cout << "ptr + 2 es equiv. a &arr[2] : " <<&arr[2] <<endl;
    cout << "ptr + 3 es equiv. a &arr[3] : " <<ptr_2 + 3 <<endl;
    cout << "ptr + 3 es equiv. a &arr[3] : " <<&arr[3] <<endl;

    cout << "desreferenciar"<<endl;
    cout << "*(ptr + 1) es equiv. a arr[1] : " << *(ptr_2 + 1) <<endl;
    cout << "*(ptr + 2) es equiv. a arr[2] : " << *(ptr_2 + 2) <<endl;
    cout << "*(ptr + 3) es equiv. a arr[3] : " << *(ptr_2 + 3) <<endl;

    return 0;
}


