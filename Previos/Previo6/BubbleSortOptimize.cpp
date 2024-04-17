//Bubble sort optimizado en C++
#include <iostream>
using namespace std;

//Ejecucion bubble sort
void bubbleSort(int array[], int size){

    //ciclo para acceder a cada elemento del array
    for (int step = 0; step < (size-1); ++step){
        
        //Verificar siocurrio un intercambio
        int swapped = 0;

        //ciclo para comparar cada elemento del array
        for (int i = 0; i < (size - step-1); ++i){

            //comparar dos elementos adjacentes
            //cambiar > a < para ordenar descendentemente
            if (array[i] > array[i+1]){

                //cambiando elementos si los elementos no están ordenados
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;

                swapped = 1;
            }  
        } 
        //No intercambiar significa que el array ya está ordenado
        //no se necesitan más comparaciones
        if(swapped == 0)
            break;
    }   
};

//Imprimir array
void printArray(int array[], int size){
    for (int i = 0; i < size; ++i){
        cout << " " << array[i];
    }
    cout << "\n";
};


int main() {
    int data[] = {-2,45,0,11,-9};

    //encontrar la longitud del array
    int size = sizeof(data)/sizeof(data[0]);
    //ordeno elementos
    bubbleSort(data, size);

    cout << "Array ordenado ascendentemente" << endl;
    //Imprimo elementos ordenados
    printArray(data, size);

    return 0;
}