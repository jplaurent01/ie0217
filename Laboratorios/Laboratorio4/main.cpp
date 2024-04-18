#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Funciones.hpp"

using namespace std;
using namespace std::chrono;

//Siempre es necesario que se llame main, es por donde entramos el progrma
int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    //Desordeno el array
    generateRandomArray(arr, SIZE);
    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort");
    //Desordeno el array
    generateRandomArray(arr, SIZE);
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");
    //Desordeno el array
    generateRandomArray(arr, SIZE);
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");
    //Desordeno el array
    generateRandomArray(arr, SIZE);
    measurinQuickSortTime(quickSort, arr, 0, SIZE - 1, "Quick sort");
    return 0;
}

/*
//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Puedo modificar arr sin referencia por puntero ni puntero, siempre se manda referencia primer elemento del arreglo
void generateRandomArray(int arr[], int n){
    srand(time(0));
    for (int i = 0; i < n; ++i){
        arr[i] = rand() % 1000;
    }
    
};
//Parametro tipo void que se casteo como puntero de tipo algoritmo ordenamiento
//Recibo punetoero de una función que recibe 2 parametros, arreglo de enteros y un numero entero
//Atraves de esta funcion puedo enviar multiples funciones como parametros
void measuringSortingTime(void (*sortingAlgorithm)(int [], int), int arr[], int n, string algorithmName){

    //Mido tiempos de ejecución
    high_resolution_clock::time_point start = high_resolution_clock::now();
    //ejemplo BubbleSort(arr,n), insert(arr, n)
    //Puntero de lla funcion
    sortingAlgorithm(arr,n);
    //Mido tiempos de ejecución
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //Vaersiones modernas se puede usar auto, hace el asteo automatico
    //auto duration = duration_cast<microseconds>(stop -start);

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << "microseundos" << endl;
}

//Funcio que se utiliza para llamar quicksort
void measurinQuickSortTime(void (*sortingAlgorithm)(int [], int, int), int arr[], int low, int high, string algorithmName){
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortingAlgorithm(arr, low, high);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop -start);
    cout << "Tiempo de " << algorithmName << ": " << duration.count() << "microseundos" << endl;
};

*/





