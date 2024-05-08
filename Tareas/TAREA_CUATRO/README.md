# Tarea 4


## Ejecucion del codigo
Ejecute el código de la carpeta **src** mediante el siguiente comando:


    >g++ -o main.exe .\main.cpp


Donde se generar un archivo ejecutable **.\main.cpp**


Link del código en linea:


    >https://tare4-josepablolaurent.netlify.app/


## Respuestas


### Templates


1. Definición de Templates: Explique el concepto de templates en C++ y
proporcione un ejemplo simple.
    >Un template es una plantilla que permite generar generar funciones y clase de una manera genérica


    ```c++
    // Función template que devuelve el valor máximo entre dos valores del mismo tipo
    template <typename T>
    T maximo(T a, T b) {
        return (a > b) ? a : b;
    }


    int main() {
        int a = 5, b = 10;
        std::cout << "El máximo entre " << a << " y " << b << " es: " << maximo(a, b) << std::endl;


        double c = 3.14, d = 2.71;
        std::cout << "El máximo entre " << c << " y " << d << " es: " << maximo(c, d) << std::endl;


        return 0;
    }
    ```


2. Sobrecarga de Plantillas: ¿Cómo se realiza la sobrecarga de funciones con
plantillas en C++?
    >Este proceso se realiza al llamar al nombre de una plantilla de función sobrecargada, el compilador intentará adivinar los argumentos de la plantilla y comprobar los argumentos de la plantilla de manera explícita, si esto se puede lograr se crea una instancia de una especialización de la plantilla, añadiendo esta especialización al conjunto de funciones candidatas utilizadas en la resolución de la sobrecarga. Por lo tanto el compilador continúa realizando la resolución de la sobrecarga, eligiendo a aquellas funciones del conjunto de funciones más adecuadas.


3. Plantillas de Clases: Explique cómo se pueden utilizar plantillas en la definición de clases en C++.
    >C++ permite definir plantillas de clases que funcione con distintos tipos de datos, a continuación se muestra un ejemplo:
    ```c++
    //Clase generica usando template
    template <typename T>
    class MiClase {
    public:
        T dato;
        void asignarDato(T nuevoDato) {
            dato = nuevoDato;
        }
        T obtenerDato() {
            return dato;
        }
    };
    ```
    Aquí se crea una clase generica para un determinado tipo de dato, estos pueden ser **int**, **float**, **char**, entre otros más.


    ```c++
    MiClase<int> intClase;
    intClase.asignarDato(5);
    std::cout << intClase.obtenerDato() << std::endl; // Imprime 5


    MiClase<std::string> stringClase;
    stringClase.asignarDato("Hola");
    std::cout << stringClase.obtenerDato() << std::endl; // Imprime Hola
    ```
    Del código anterior se observa que se han creado dos instancias de la clase MiClase que reciben un tipo de dato distinto.




### Excepciones


4. Manejo de Excepciones: Describa los bloques try, catch y throw y cómo se utilizan para el manejo de excepciones en C++.
    >+ try: se posiciona alrededor del código que puede causar una excepción.
    >+ catch: se utiliza para capturar la excepción generada dentro del bloque try.
    >+ throw: Es un bloque de código que se utiliza para lanzar una excepción desde cualquier punto del programa.


5. Excepciones Estándar: Nombre al menos tres excepciones estándar proporcionadas por C++ y proporciona ejemplos de situaciones en las que podrían ser útiles.
    >**std::invalid_argument**, **std::out_of_range** y **std::runtime_error**.


    > Ejemplos:
    Se puede utilizar **std::invalid_argument** cuando se quiere dividir entre 0, como se muestra a continuación:
     ```c++
        void dividir(int a, int b) {
            if (b == 0) {
                throw std::invalid_argument("Divisor no puede ser cero");
            }
        }
     ```
    > **std::out_of_range** Se puede utilizar cuando se quiere acceder a un índice fuera del rango de un vector.
     ```c++
        std::vector<int> vec = {1, 2, 3};
        try {
            int valor = vec.at(5); // Se produce un std::out_of_range
        } catch (std::out_of_range &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
     ```
     >**std::runtime_error** Se puede utilizar para errores que ocurren en ejecución y no se pueden detectar en tiempo de compilación.
     ```c++
        void funcion() {
        throw std::runtime_error("Ocurrió un error durante la ejecución");
    }
    ```
6. Política de Manejo de Excepciones: ¿Qué es una política de manejo de excepciones y por qué es importante considerar al diseñar software?
    >Una política de excepciones es un conjunto de reglas establecidas para manejar las excepciones de un programa. Son importantes porque añaden seguridad, robustez y estabilidad al programa, facilitando su mantenimiento.


7. Noexcept: Explica el propósito de la palabra clave noexcept y cómo se utiliza en C++.


    >Es un tipo de especificación de excepción. El operador condicional unitario noexcept(constant_expression), cuando constant_expression produce true, y su equivalente incondicional noexcept, especifican que la función no arrojará excepciones. En otras palabras, la función está diseñada para no generar ni permitir que las excepciones se propaguen fuera de su ámbito. Por otro lado, el operador noexcept(constant_expression) cuando constant_expression produce false o no hay una especificación de excepción (excepto para destructores o funciones de desasignación), indica que la función podría arrojar cualquier tipo de excepción.


8. Explique la diferencia entre las excepciones std::logic error y std::runtime error.
    >+ std::logic error: La clase logic error define el tipo de objetos lanzados como excepciones para informar errores presumiblemente detectables antes de que se ejecute el programa, como violaciones de condiciones previas lógicas o invariantes de clase.
    >+ std::runtime error: La clase runtime_error define el tipo de objetos lanzados como excepciones para informar errores presumiblemente detectables sólo cuando se ejecuta el programa.


9. Explique qué ocurre cuando una excepción no es capturada.
    >El programa termina abruptamente y muestra un mensaje de error indicando que se produjo una excepción no capturada.


### STL (Standard Template Library):


10. Contenedores STL: Nombre cinco contenedores diferentes de la STL y explique brevemente en que situaciones sería apropiado usar cada uno.
    >+ std::vector: Contenedor de tamaño variable que permite un acceso rápido a los elementos mediante índices, permite que sus elementos crezcan o disminuyan su tamaño de manera dinámica, todos los elementos deben ser iguales.
    >+ std::list: Contenedor se utiliza como una lista doblemente enlazada, permite insertar o eliminar elementos con frecuencia en cualquier posición de la lista,puede almacenar elementos de distinto tipo.
    >+ std::map: Se utilizó para crear diccionarios, almacena información de manera de pares key-value ordenada por clave.
    >+ std::set: Contenedor permite ordenar un conjunto de elementos, eliminando los duplicados.
    >+ std::queue: Contenedor permite procesar elementos en el mismo orden en que se insertaron, opera bajo el paradigma FIFO, donde el primero en entrar es el primero en salir.


11. Iteradores en STL: Explique el concepto de iteradores en la STL y cómo se utilizan para acceder a elementos en contenedores.
    > Los iteradores STL permiten recorrer de forma secuencial los elementos dentro de un contenedor, estos operan como puntero donde apunta al primer y último elemento del vector, posteriormente iteran sobre cada una de las posiciones de memoria del contenedor para acceder a sus elementos.
    A continuación se muestra un ejemplo de cómo accede a cada uno de los elementos del contenedor.
    ```c++
    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};


        // Utilizando un iterador para recorrer el vector
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;


        return 0;
    }
    ```
    Note que para acceder a cada elemento guardado en **vec** el iterador **it**, se debe des referenciar.
   


12. Algoritmos STL: Proporciona ejemplos de al menos tres algoritmos de la STL y describa sus funciones básicas.
    > + std::transform: Realiza una operación a cada elemento en un rango y guarda el resultado en otro rango.
    ```c++
    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::vector<int> result;


        // Duplica cada elemento del vector original y lo guarda en 'result'
        std::transform(vec.begin(), vec.end(), std::back_inserter(result),
                    [](int x) { return x * 2; });


        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;


        return 0;
    }
    ```
    >+ std::copy: Copia los elementos de un rango a otro.
    ```c++
    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::vector<int> copyVec(vec.size());


        // Copia los elementos de 'vec' a 'copyVec'
        std::copy(vec.begin(), vec.end(), copyVec.begin());


        for (int num : copyVec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;


        return 0;
    }
    ```
    >+ std::reverse: Invierte el orden de los elementos.
     ```c++
        int main() {
            std::vector<int> vec = {1, 2, 3, 4, 5};
            // Invierte el orden de los elementos en 'vec'
            std::reverse(vec.begin(), vec.end());


            for (int num : vec) {
                std::cout << num << " ";
            }
            std::cout << std::endl;


            return 0;
            }
    ```


13. Algoritmos Personalizados: ¿Como podrıa utilizar un algoritmo personalizado con la STL?
    >A continuación se muestra un ejemplo:
    ```c++
    template <typename T>
    int contarMayoresQue(const std::vector<T>& vec, const T& value) {
        return std::count_if(vec.begin(), vec.end(), [&](const T& elem) {
            return elem > value;
        });
    }
    ```
    Del código anterior se crea una función personalizada que recibe como parámetro un std::vector, cuyo tipo de dato es genérico. Posteriormente se hace el llamado a esta función desde un main.
    ```c++
    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int valor = 5;


        int cantidad = contarMayoresQue(vec, valor);


        std::cout << "Cantidad de elementos mayores que " << valor << ": " << cantidad << std::endl;


        return 0;
    }
    ```
    Del main se realiza el llamado a la función **contarMayoresQue** que recibe como parámetro un vector de tipo **int** y dentro de la función se determina utilizando iteradores si algún elemento de este es mayor a 5.





