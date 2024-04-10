#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Ingrese el total de estudiantes" << endl;
    cin >> num;
    float* ptr;

    // Se asigna memoria dinámicamente para un array de floats
    ptr = new float[num];

    cout << "Ingrese el GPA" << endl;
    // Se solicita el GPA de cada estudiante
    for (int i = 0; i < num; i++) {
        cout << "Estudiante " << i + 1 << ": ";
        cin >> *(ptr + i); // Se almacena el GPA en la memoria asignada
    }

    cout << "Despliegue del GPA" << endl;
    // Se muestra el GPA de cada estudiante
    for (int i = 0; i < num; i++) {
        cout << "Estudiante " << i + 1 << ": " << *(ptr + i) << endl;
    }

    // Se libera la memoria asignada para el array
    delete[] ptr;

    return 0;
}
