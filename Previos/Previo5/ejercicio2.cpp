#include <iostream>
using namespace std;

int main() {
    // Se declaran dos punteros, uno para int y otro para float
    int* pointInt;
    float* pointFloat;

    // Se reserva memoria dinámicamente para los punteros
    pointInt = new int;
    pointFloat = new float;

    // Se asignan valores a la memoria reservada
    *pointInt = 45;
    *pointFloat = 45.45f;

    // Se imprime el valor de la memoria asignada
    cout << *pointInt << endl;
    cout << *pointFloat << endl;

    // Se libera la memoria asignada dinámicamente
    delete pointInt;
    delete pointFloat;

    return 0;
}
