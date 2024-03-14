#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;


int main(){
    //Inicializa array tamano 6, espacios restantes se rellenan con valor de cero.
    int array[6] = {1,3};
    // Obtener el tamaño total del array
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    //se inicializa dos matrices de enteros 
    //cada 3 indices se agrega una nueva fila
    int test0 [2][3] = {2,4,5,9,0,19};
     //Lo mismo nada mas que en forma de par ordenado
    int test1 [2][3] = {{2,4,5},{9,0,19}};

        for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "(" << i << "," << j << "): " << test1[i][j] << endl;
        }
    }




    return 0;
}

