#include <iostream>
using namespace std;

//Funcion que imprime el array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
};

void insertionSort(int array[], int size){
    for (int step = 1; step < size; step++){
        int key = array[step];
        int j = step - 1 ;

        //Compara el key con cada elemento a la izquierda hasta encontrar un elemento más pequeno
        //si lo encuentra, para orden descendente  cambiar key<array[j] a key>array[j]
        while (key  < array[j] && j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
        
    }
    
};


//Ejecucion de codigo
int main() {
    int data[] = {9,5,1,4,3};

    //encontrar la longitud del array
    int size = sizeof(data)/sizeof(data[0]);
    //Ordeno elementos
    insertionSort(data, size);
    cout << "Array ordenado ascendentemente" << endl;
    //Imprimo elementos ordenados
    printArray(data, size);

    return 0;
}