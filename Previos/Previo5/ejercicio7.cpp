//Implementacion de Stack en C++
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10 // Tamaño máximo del stack
int size = 0; // Variable global para el tamaño actual del stack

// Estructura para representar el stack
struct stack {
   int items[MAX]; // Array para almacenar los elementos del stack
   int top; // Índice del elemento en la cima del stack
};
typedef struct stack st;

// Función para crear un stack vacío
void createEmptyStack(st *s){
    s->top = -1; // Inicializa el índice de la cima en -1 para indicar que el stack está vacío
}

// Función para verificar si el stack está lleno
int isfull(st *s){
    if (s->top == MAX - 1) // Si el índice de la cima es igual al tamaño máximo - 1, entonces el stack está lleno
        return 1;
    else
        return 0;
}

// Función para verificar si el stack está vacío
int isempty(st *s){
    if (s->top == -1) // Si el índice de la cima es -1, entonces el stack está vacío
        return 1;
    else
        return 0;
}

// Función para agregar elementos al stack
void push(st *s, int newitem){
    if(isfull(s)){ // Verifica si el stack está lleno
        cout << "STACK FULL";
    }else {
        s->top++; // Incrementa el índice de la cima
        s->items[s->top] = newitem; // Agrega el nuevo elemento en la posición de la cima
    }
    size++; // Incrementa el tamaño del stack
}

// Función para eliminar elemento del stack
void pop(st *s){
    if (isempty(s)){ // Verifica si el stack está vacío
        cout << "STACK VACIO" << endl;
    } else {
        cout << "Item eliminado= " << s->items[s->top]; // Imprime el elemento eliminado
        s->top--; // Decrementa el índice de la cima
    }
    size--; // Decrementa el tamaño del stack
    cout <<endl;
}

// Función para imprimir el stack
void printStack(st *s){
    printf("Stack: ");
    for (int i = 0; i < size; i++){
        cout << s->items[i] << " "; // Imprime cada elemento del stack
    }
    cout << endl;
}

// Función principal
int main() {
   
    int ch;
    st *s = (st *)malloc(sizeof(st)); // Se reserva memoria para la estructura del stack

    createEmptyStack(s); // Se crea un stack vacío

    // Se agregan elementos al stack
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s); // Se imprime el stack
    pop(s); // Se elimina un elemento del stack

    cout << "Despues de eliminar" << endl;
    printStack(s); // Se imprime el stack después de eliminar un elemento

    //libero memoria
    free(s);
    return 0;
}
