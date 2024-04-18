# Tarea 3

## Ejecución y visualización del código fuente
Debe ejecutar el código con el siguiente comando dentro de la carpeta **src**:
```
g++ -o main.exe .\main.cpp .\Funciones.cpp
```
Luego correr el ejecutable:
```
.\main.exe
```
Link del código fuente:
```

```

## Respuestas

1. ¿Qué es un algoritmo y cuáles son sus características principales?

>Es un conjunto de instrucciones bien definidas para resolver un problema particular. Toma un conjunto de entradas y produce el resultado deseado. Las características de un algoritmo son las siguientes: la entrada y la salida deben definirse con precisión, cada paso del algoritmo debe ser claro e inequívoco, los algoritmos deberían ser más eficaces entre muchas formas diferentes de resolver un problema, y finalmente, un algoritmo no debería incluir código informático. El algoritmo debe escribirse de tal manera que pueda usarse en diferentes lenguajes de  programación.

2. Explica la diferencia entre un algoritmo eficiente y uno ineficiente.

>Un algoritmo eficiente es aquel que realiza una tarea en la menor cantidad de tiempo y utilizando la menor cantidad de memoria posible, por consiguiente un algoritmo ineficiente no cumple con las características anteriores.

3. ¿Qué es una estructura de datos y por qué son importantes?

> Es un almacenamiento que se utiliza para almacenar y organizar datos, esto con el fin de acceder a ellos y actualizarlos de manera eficiente.

4. Describe las diferencias entre una estructura de datos estática y una dinámica.

 >**Estructura de datos estáticas**: son aquellas en las que el tamaño ocupado en memoria se define antes de que el programa se ejecute y no puede modificarse dicho tamaño durante la ejecución del programa
 
 >**Estructura de datos dinámica**: es aquella en la que el tamaño ocupado en memoria puede modificarse durante la ejecución del programa.

5. ¿Qué es la memoria dinámica y cómo se gestiona en lenguajes de programación como C++, explique las operaciones que se pueden realizar?

>En el caso de C++, la memoria dinámica es la memoria que ser reserva en el heap. Su principal ventaja frente  es que su tamaño puede variar durante la ejecución del programa. El uso de memoria dinámica es necesario cuando no se sabe el numero exacto de datos/elementos a tratar.

6. ¿Cuáles son las ventajas y desventajas de la memoria dinámica en comparación con la memoria estática? 

>Entre las ventajas se encuentran que su tamaño puede variar durante la ejecución del programa y es útil de utilizar cuando se desconoce la cantidad de elementos a tratar. En cuanto a las desventajas, destaca que la memoria dinámica se debe liberar de manera manual, ya que si no se libera, afecta el rendimiento.


7. Explique qué es un árbol binario y cuáles son sus principales características.

>Un árbol binario es una colección de elementos ordenandos de manera jerárquica, entre sus características está que los elementos se representan por nodos, cada nodo a excepción del nodo raiz, mantiene como referencia a un nodo padre, adicionalmente los nodos pueden tener a lo sumo dos noodos hijos.

8. ¿Qué es una cola (queue) y en qué situaciones se utiliza comúnmente?

>Es una estructura de datos que opera bajo el paradigma del **primero en entrar primero en salir**. Como se mencionó anteriormente, se utiliza en situaciones donde se necesita poder acceder al ultimo elemento que se añadió, como lo puede ser en aplicaciones de algoritmos de ordenaiento, buffer de comunicación de datos, entre otros más.

9. ¿Cuál es la diferencia entre una cola (queue) y una pila (stack)?

> **Queue**: opera bajo el **FIFO**, primero elemento en entrar será el primer elemento en salir.

>**Stack**: opra bajo el **LIFO**, primero elemento en entrar será el último elemento en salir.


10. Describe cómo funciona el algoritmo de inserción (insert) en una tabla hash.

>El algoritmo de inserción realiza los siguiente:
+ Crear el item a partir de un par **{key:value}**.
+ Genera el indice basado en la función hash.
+ Verificar si el indice existe o no, para ello compara el key.
    - Si no se encuentra ocupado se puede insertar en el indice directamente.
    - En caso de encontrarse ocupado, ocurre una colisión, donde el programador deberá encargarse de la lógica involucrada.

11. ¿Qué es la función de dispersión (hash function) y por qué es importante en las tablas hash?

>La funsión de dispersión "hash function", es una función de las tablas hash que permite generar indices para una determinado **key**.

12. ¿Cuál es la complejidad temporal promedio de búsqueda en una tabla hash bien implementada?

>La complejidad temporal promedio de búsqueda de una tabla hash es de **O(1)**.

13. Explica cómo se realiza la operación de inserción (push) en una pila (stack).

> La operación de inserción "push" en el stack, consiste en insertar un elemento dentro de la estructura stack, para ello se emplea la siguiente estructura lógica:
+ Verificar si el stack está lleno.
+ Si el stack está lleno, se le avisa al usuario que no se pudo insertar un nuevo elemento.
+ Si el stack no está lleno, incrementa el atributo **top** del stack en uno, para señalar al siguiente espacio vacio.
+ Añade el nuevo elemento al stack, donde lo indica **top**.
+ Se le indica al usuari que la operación de inserción fue exitosa.

14. ¿Cuál es la complejidad temporal de las operaciones de apilar (push) y desapilar (pop) en una pila?

> **Push** : En el mejor de los casos es **O(1)**, caso promedio **O(1)** y el peor de los casos **O(N)**, donde N son todos los elementos del stack.

> **Pop**: En el mejor de los casos es **O(1)**, caso promedio **O(1)** y el peor de los casos **O(1)**.

15. Describe cómo funciona una lista enlazada y cuáles son sus ventajas y desventajas.

>Una lista enlazada es una estructura de datos, constituida por nodos que contienen nformación y referencia al nodo siguiente. Si se compara una lista enlazada con un array, este permite de manera eiciente insertar y remover elementos de cualquier posición de la lista, además es una estructura de datos que no posee un tamaño fijo, por tal motivo se puede editar su tamaño durante la ejecución del programa. Entre sus desventajas es que las listas enlazadas se conforman por un único tipo de dato, en caso de iterar sobre la lista mediante un ciclo for no será del todo eficinete ya que los nodos no se encuetran almacenados contiguos en memoria.

16. ¿Qué es un nodo en una lista enlazada y qué contiene?

> Un nodo en una lista enlazada es un objeto que posee como atributos el tipo de información que se quiere almacenar en dicho objeto y una referencia a la dirección de memoria del siguiente nodo.

17. ¿Cuál es la diferencia entre una lista enlazada simple y una lista enlazada doblemente enlazada?

>Una lista enlazada simple, es un conjunto de nodos, donde cada nodo contiene un espacio para los datos y un enlace hacia el siguiente nodo. Por otro lado, una lista doblemente enlazada contiene un enlace adiccional hacia el nodo anterior, por tal motivo una lista doblemente enlazada apuntará hacia su elemento anterior y posterior. 


18. ¿Cómo se realiza la eliminación (delete) de un nodo en una lista enlazada?

>Si el nodo de la lista enlazada se crea reservando memoria en el heap mediante el uso de **new**, se debe realizar lo siguiente:

```c++
Node nodo1 = new Node;
nodo1->name = ptrContacto->nombre;
nodo1->number = ptrContacto->telefono;
```
Donde Node es un objeto de la siguiente clase:

```c++
class Node {
    public:
        string name;  //Nombre almacenado en el nodo
        string number; //Número almacenado en el nodo
        Node* last;   //Puntero al nodo anterior nodo en la lista
};
```

19. Explica cómo funciona el algoritmo de recorrido (transversal) en un árbol binario.

> Un algoritmo de recorrido transversal en un arbol binario, se utiliza para atravesar cada nodo del árbol exactamente una vez en un orden en específico. Existen tres maneras de recorrer el arbol binario estas son mediante recorridos de preorden, orden y postorden. Donde el recorrido de preorden busca visitar primero el nodo izquierdo, el actual y por último el nodo derecho. En cuanto al recorrido en orden, visita el nodo actual, el nodo izquierdo y finalmente el nodo derecho. Por último, el recorrido en postorden, vista primero el nodo izquierdo, luego el derecho y finaliza en el nodo actual.

20. ¿Cuál es la complejidad temporal del recorrido en preorden, en orden y en postorden en un árbol binario balanceado?

>La complejidad temporar para cada recorrido es de **O(n)**, ya que se reocorre cada uno de los nodos una vez.

21. Explique la diferencia entre la notación Big O (O) y la notación Omega () en el análisis de la complejidad temporal de los algoritmos. Proporciona un ejemplo de un algoritmo y determina su complejidad temporal utilizando ambas notaciones Big O y Omega.

>**Notación Big O**: Define tanto el límite superior como inferior del mayor tiempo requerido para su ejecución, es decir toma el peor de los casos de rendimiento.

>**Notación Omega**: Define tanto el límite superior como inferior del menor tiempo requerido para su ejecución , es decir el mejor de los casos de redimiento.

```c++
#include <iostream>
using namespace std;
//Ejecucion bubble sort
void bubbleSort(int array[], int size){

    //ciclo para acceder a cada elemento del array
    for (int step = 0; step < size; ++step){
        
        //ciclo para comparar cada elemento del array
        for (int i = 0; i < size - step; ++i){

            //comparar dos elementos adjacentes
            //cambiar > a < para ordenar descendentemente
            if (array[i] > array[i+1]){
                //cambiando elementos si los elementos no están ordenados
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }  
        }  
    }
};

//Imprimir array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
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
    //imprimo elementos ordenados
    printArray(data, size);

    return 0;
}
```

Se procede a analizar la complejidad temporal del algoritmo **bubbleSort**:
+ **Notación Big O (peor de los casos)**: En el peor de los casos, el array se encuentra completamente desordenado, donde el algoritmo debe realizar **n** iteraciones sobre cada uno de los **n** elementos del array, donde $n \cdot n = n^2$, dando como resultado una complejidad temporal del peor de los casos **O(n)**.
+ **Notación Omega (mejor de los casos)**: El mejor de los casos ocurre cuando el array está completamente ordenado, por tal motivo se debe recorrer el algoritmo solamente una vez, dando como resultado una complejidad temporal en el mejor de los casos de $\Omega(n)$.