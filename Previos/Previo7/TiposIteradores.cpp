#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
using namespace std;

int main(){

    /*std::forward_list es un contenedor en C++ que representa una lista enlazada
     de un solo sentido. Es similar a std::list, pero a diferencia de std::list,
    std::forward_list solo permite el recorrido en una dirección (de principio a fin)
    y no admite acceso aleatorio a los elementos. Cada elemento en un std::forward_list contiene
     un valor y un enlace al siguiente elemento en la lista.
    La ventaja principal de std::forward_list es su menor consumo de memoria y mayor eficiencia
    en la inserción y eliminación de elementos en comparación con std::list, ya que no necesita
    almacenar enlaces inversos. Sin embargo, debido a su naturaleza de un solo sentido,
    no es posible acceder directamente a un elemento por su índice, lo que limita su uso en algunas
    situaciones.
    */
    forward_list<int> nums{1,2,3,4};

    /****************** Iterador hacia delante ********************************/
    //Se inicializa el iterador al inicio de la lista
    forward_list<int>::iterator itr = nums.begin();

    //duplico el contenido de la lista
    while (itr != nums.end()){
        //Se accede al valor del iterador utilizando operador indirecto
        //desreferencia el contenido del puntero
        int original_value = *itr;

        //Se le asigna un nuevo valor al puntero utilizando operadores indirectos
        *itr = original_value *2;

        //Me muevo al siguiente elemento de la lista
        itr++;
    }
    
    
    //Imprimo el contenido de la lista
    for (int num : nums){
        cout << num << ", ";
    }

    /****************** Iterador bi-direcional ********************************/
    //Contendor lista de tipo entero, es bidireccionaln iterar tanto hacia adelante 
    //como hacia atrás. Se puede iterar hacia adelante usando ++, hacia atrás 
    //usando --, y leer y escribir valores usando * o leer y escribir valores de 
    //miembros usando ->.
    list<int> numb{1,2,3,4,5,6};

    //Se inicializa el iterador al inicio de la lista
    list<int>::iterator itr2 = numb.begin();

    cout << "\nHacia delante..." << endl;
    //Se imprime el contenido de la lista hacia adelante
    while (itr2 != numb.end()){
        cout << *itr2 << ", ";
        //Me muevo al siguiente elemento
        itr2++;
    }
    
    cout << "\nHacia atras..." << endl;
    //Se imprime el contenido de la lista hacia atras
    while (itr2 != numb.begin()){
        if (itr2 != numb.end()){
            cout << *itr2 << ", ";
        }
        
        //me muevo haca atras
        itr2--;
    }

    cout << *itr2 << endl;

    /****************** Iterador acceso aleatorio ********************************/
    //Tiene las mismas propiedades ierador de acceso bidirecional junto con acceso aleatorio

    //Se crea un vector de enteros
    vector<int> vec{1,2,3,4,5};

    //Se crean iteradores al inicio y final del vector
    vector<int>:: iterator itr_first = vec.begin();
    vector<int>:: iterator itr_last = vec.end() - 1;

    //Se muestra el contenido del vector
    cout << "1er elemento: " << *itr_first << endl;
    cout << "2do elemento: " << itr_first[1] << endl;

    cout << "Penultimo: " << *(itr_last - 1) << endl;
    cout << "Ultimo: " << *(itr_last) << endl;


    return 0; 
}