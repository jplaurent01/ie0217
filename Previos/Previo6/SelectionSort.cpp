#include <iostream>
using namespace std;

//Funcion para intercambiar posicion entre dos elementos
void swap(int* a, int* b){
    int temp = *a;
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

    for (int step = 0; step < size; step++){
        int min_idx = step;
        for (int i = step + 1; i < size; i++){
            
            //Para ordenar de manera descendente, cambiar > a < en esta linea
            //selecione el elemento mas pequeno de cada ciclo
            if (array[i] < array[min_idx]){
                min_idx = 1;
            }

        //poner min en la posicion correcta
        swap(&array[min_idx], &array[step]);  
        }  
    }

};

//Ejecucion de codigo
int main() {
    int data[] = {20, 12,10, 15, 2};

    //encontrar la longitud del array
    int size = sizeof(data)/sizeof(data[0]);
    selectionSort(data, size);
    cout << "Array ordenado ascendentemente" << endl;
    printArray(data, size);

    return 0;
}