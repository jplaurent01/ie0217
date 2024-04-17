#include <iostream>
using namespace std;

//Funcion para intercambiar posicion entre dos elementos
//Parametro por referencia usando punteros
void swap(int* a, int* b){
    int temp = *a;
    //desreferencio contenido de punteros y guardo valor de variables intercambiadas
    *a = *b;
    *b = temp;
};

//Funcion que imprime el array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
};

void selectionSort(int array[], int size){

    for (int step = 0; step < size - 1; step++){
        int min_idx = step;
        for (int i = step + 1; i < size; i++){
            
            //Para ordenar de manera descendente, cambiar > a < en esta linea
            //selecione el elemento mas pequeno de cada ciclo
            if (array[i] < array[min_idx]){
                min_idx = i;
            }

        //poner min en la posicion correcta
        swap(&array[min_idx], &array[step]);  
        }  
    }

};

//Ejecucion de codigo
int main() {
    int data[] = {9,5,1,4,3};

    //encontrar la longitud del array
    int size = sizeof(data)/sizeof(data[0]);
    //Ordeno elementos
    selectionSort(data, size);
    cout << "Array ordenado ascendentemente" << endl;
    //Imprimo elementos ordenados
    printArray(data, size);

    return 0;
}