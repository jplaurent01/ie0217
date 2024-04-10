#include <iostream>

//Se almacena en el segmento de data
int globalVariable = 42;

int main(){

    //Se almacena en el stack
    int stackVariable = 10;

    //Se almacena en el heap
    int* heapVariable  = new int(20);

    std::cout << "Valor globalVariable: " << globalVariable << std::endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std::endl;
    std::cout << "Valor de heapVariable: " << heapVariable << std::endl;

    //Si no lo hago pierdo recursos de memoria de la computadora, la hago mas lenta
    //evito fugas de memoria
    delete heapVariable;
   
    return 0;
}