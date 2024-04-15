#include <iostream>
using namespace std;
//Ejecucion bubble sort
void bubbleSort(int array[], int size){

    //ciclo para acceder a cada elemento del array
    for (int step = 0; step < size; ++step){
        
        //ciclo para comparar cada elemento del array
        for (int i = 0; i < size - step; ++i){

            //comparar dos elementos adjacentes
            //cambiar > a < para ordenar descendentemente
            if (array[i] > array[i+1]){
                //cambiando elementos si los elementos no están ordenados
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }  
        }  
    }
};

//Imprimir array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << " " << array[i];
    }
    cout << "\n";
};


int main() {
    int data[] = {-2,45,0,11,-9};

    //encontrar la longitud del array
    int size = sizeof(data)/sizeof(data[0]);
    bubbleSort(data, size);

    cout << "Array ordenado ascendentemente" << endl;
    printArray(data, size);

    return 0;
}