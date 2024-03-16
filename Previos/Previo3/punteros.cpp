#include <iostream>
using namespace std;

struct Distance{
    int feed;
    float inch;
};

//Funcion toma 2 referencias de enteros
//una referencia es un alias, es decir, otro nombre para un objeto existente.
// Proporciona una forma de acceder a un objeto utilizando un nombre diferente.
// Las referencias se utilizan principalmente en dos contextos:
/*Parámetros de funciones: Se utilizan para pasar argumentos a funciones de manera que la función
 pueda modificar el valor de la variable original. Esto se logra pasando la referencia del objeto
 en lugar de una copia del objeto.*/

 /*
 Devolución de valores de funciones: Las funciones también pueden devolver referencias. 
 Esto permite que una función devuelva un valor que se puede modificar directamente.
 */
void swap(int &n1, int &n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap_2(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

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
    
    //Paso de parametros de referencia sin punteros
    int a =1, b =2;

    cout << "Antes de cambiar" << endl;
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;

    //Parametros por referencia
    swap(a,b);
    cout << "Despues de cambiar" << endl;
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;

    //Parametros por referencia con punteros

    int c =3, e =4;

    cout << "Antes de cambiar" << endl;
    cout << "c = " << c <<endl;
    cout << "e = " << e <<endl;

    cout << "Antes de cambiar" << endl;
    cout << "&c = " << &c <<endl;
    cout << "&e = " << &e <<endl;
    
    //Parametros por referencia
    //Altera el valor de las variables originales mediante punteros, sin necesidad de enviar una copia.
    swap_2(&c,&e);
    cout << "Despues de cambiar" << endl;
    cout << "c = " << c <<endl;
    cout << "e = " << e <<endl;

    //Punteros dobule
    int result_init = 2905;
    int* ptr_1;
    //Referencio el puntero con la direccion en memoria de result_init
    ptr_1 = &result_init;

    cout <<"Direccion memoria de result_init: " << &result_init<< endl;
    cout <<"Direccion memoria de ptr_1: " << ptr_1<< endl;

    //Se crea un puntero que apunta al valor de memoria de ptr1

    int** ptr_ptr_1;
    ptr_ptr_1 = &ptr_1 ;

    cout <<" ptr_2: " << ptr_ptr_1<< endl;
    cout << "Direcion de &ptr_1: " << &ptr_1<<endl;
    cout << "Direccion de &ptr_2: " << &ptr_ptr_1<<endl;
    return 0;
}


