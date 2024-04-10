#include <iostream>
using namespace std;

int main() {
    float *ptr, *new_ptr;

    // Se asigna memoria para un array de 5 floats
    ptr = (float*) malloc(5 * sizeof(float));

    // Se verifica si la asignación de memoria fue exitosa
    if (ptr == NULL) {
        cout << "Fallo en la asignacion de memoria" << endl;
        exit(1);
    }

    // Se inicializan los valores del array
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 1.5;
    }

    // Se reasigna memoria para un array de 10 floats
    new_ptr = (float*) realloc(ptr, 10 * sizeof(float));

    // Se verifica si la reasignación de memoria fue exitosa
    if (new_ptr == NULL) {
        cout << "Fallo en la RE-asignacion de memoria" << endl;
        exit(1);
    }

    // Se inicializan los valores del array reasignado
    for (int i = 5; i < 10; i++) {
        new_ptr[i] = i * 2.5;
    }

    cout << "Imprimiendo valores" << endl;

    // Se imprime el array reasignado
    for (int i = 0; i < 10; i++) {
        cout << new_ptr[i] << endl;
    }

    // Se libera la memoria asignada dinámicamente
    free(new_ptr);

    return 0;
}
