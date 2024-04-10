#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Se reserva memoria para un array de 5 enteros usando calloc
    int* ptr;
    ptr = (int*)calloc(5, sizeof(int));

    // Se verifica si la asignación de memoria fue exitosa
    if (!ptr) {
        cout << "Asignacion de memoria fallida" << endl;
        exit(1);
    }

    // Se inicializan los valores del array
    cout << "Inicializando valores..." << endl;
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1;
    }

    // Se imprime el array
    cout << "Imprimiendo valores..." << endl;
    for (int i = 0; i < 5; i++) {
        // Se imprime el valor del elemento i (ptr[i] y *(ptr + i) son equivalentes)
        cout << *(ptr + i) << endl;
    }

    // Se libera la memoria asignada dinámicamente
    free(ptr);

    return 0;
}
