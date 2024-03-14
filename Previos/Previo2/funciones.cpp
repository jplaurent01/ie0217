#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;

/*La principal diferencia entre la variable local y la variable estática es 
que el valor de la variable estática persiste al final del programa.
*/
void test(){
    /*Una variable local estática existe solo dentro de una función donde 
    se declara (similar a una variable local), pero su vida comienza cuando 
s   e llama a la función y finaliza solo cuando finaliza el programa
    */
    static int var = 0;
    //equivalente var+=1, contador
    ++var;
    cout<< var << endl;
}
//funcion con parametros por defecto
//LO RARO DE ESTA FUNCION ES QUE NO RETORNA LA SUMA DE LOS PARAMETRSO CON C Y D EN LA SUMA
void add2(int a, int b, int c = 30, int d = 10){
    //return (a+b+c+d);
    cout<< "Imprime valro de una funcion que tiene parametros por defecto de c=30 y d=10, sin embargo no se toman en cuenta" << endl;
    cout<< (a+b+c+d) << endl;

}

//prototipo de la funcion, si no declaro el prototipo de la funcion, obtendré un error en el scoop
int add(int, int);

//Funcion de tipo void, no retrna nada
void greet(){

    cout <<"Esta funcion no retorna nada"<< endl;

}
/*
Argumentos de referencia: En lugar de pasar una copia del valor de la variable al parámetro de la función, los argumentos de 
referencia pasan una referencia a la variable. Esto significa que cualquier modificación realizada dentro de la función afectará la 
variable original en el programa principal.
*/
void displayNum(int n1, double n2){
    cout << n1 << endl;
    cout << n2 << endl;
}   


/*En C++, dos funciones pueden tener el mismo nombre si el
número y/o tipo de argumentos pasados es diferente.
Estas funciones que tienen el mismo nombre pero diferentes
argumentos se conocen como funciones sobrecargadas
*/
void display(int a){
    cout << a << endl;
}

void display(double b){
    cout << b << endl;
}

void display(int a, double b){
    cout << a << endl;
    cout << b << endl;
}
 
//argumentos funcion main primer argumento intica la cantidad de argumentos que se ingresan a la terminal
//Segundo argumento puede imprimir cada uno de los argumentos ingresados.
int main(int argc, char* argv[]){
    cout << "Numero de argumentos" <<argc<< endl;
    cout << "Nombre del programa" <<argv[0]<< endl;

    if (argc > 1){
        cout << "Argumentos adicionales" << endl;
        for (int i = 1; i < argc; i++){
            cout << "argv[" <<i<<"] : " << argv[i] <<endl;
        }
        
    }

    greet();

    int num1 = 5;
    double num2 = 5.5;
    displayNum(num1, num2);

    //Esta funcion retorna un entero
    int sum = add(100, 50);
    cout<< sum << endl;

    add2(100, 50, 0, 0);
    

    add2(100, 50);
    


    display(num1);
    display(num2);
    display(num1, num2);

    test();
    test();
    
    return 0;
}

int add(int a, int b){
    return (a+b);
}
