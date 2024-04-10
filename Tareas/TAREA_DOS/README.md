# Tarea 2


Debe ejecutar el código con el siguiente comando dentro de la carpeta **src**:
```
g++ -o main.exe .\main.cpp .\Planeta.cpp .\Funciones.cpp .\Continentes.cpp .\Pais.cpp .\PaisPrimerMundo.cpp .\PaisEnDesarrollo.cpp
```

Link del código fuente:
```
https://tarea2jplaurent.netlify.app/
```
1. ¿Qué es la programación orientada a objetos y cuáles son sus principales principios?
>La programación orientada a objetos es un paradigma de la programación que busca crear clases, con el objetivo de crear objetos de estas. Dichas clases sirven como molde para la estructuración de los objetos ya que permiten estructurar los datos y coportamientos de los objetos.

>Los prinipales principios de la POO radican en **reutilización**, **organización** y **mantenimiento** del código.

2. Explique el concepto de ocultamiento de datos y cómo se logra en C++.

>El ocultamiento de datos consiste en la protección o aislameinto de los atributos o métodos de una clase.
>Los niveles de ocultamiento se logran mediante los modificadores de acceso conocidos como: **public**, **private** y **protected**.

3. ¿Cuál es la diferencia entre una clase y un objeto en C++?
>En terminos generales una clase es un **molde** que contiene todas las instruciones necesarias para elaborar un objeto. Por otro lado un objeto es una **instancia** de una clase.

4. ¿Qué es el polimorfismo y cómo se logra en C++?

>En c++ el poliformismo es hacer que una funcion se comporte diferente en relación con la cantidad de argumentos y tipos de datos que tiene comoargumentos, para lograrlo se recurre a la **sobre carga** de funciones, es basicamente un grupo de funciones con el **mismo** nombre, pero con diferencias en la cantidad de argumentos y los tipos de datos de los argumentos.

5. ¿Qué significa el término encapsulamiento en el contexto de la OOP?

>El encapsulamiento hace referencia al ocultamiento de de datos, ya sean metodos o atributos de una clase, con el fin de evitar su manipulación de manera directa.

6. ¿Cuál es el propósito del constructor y el destructor en una clase de C++?

>Constructor es el elemento que contiene todas las instruciones necesarias para la creación de un objeto. Su propósito es brindar todos los recursos para inicializar una clase, mediante un objeto. Estos pueden recibir argumentos.

>Destructor es el encargado de destuir un objeto, a diferencia del constructor, este no recibe como parametro ningun tipo de elemento.

7. ¿Investigue cómo se define una clase abstracta en C++ y cuál es su función?

    >Una clase abstracta es en terminos generales uns expresión de conceptos, sobre los cuales se pueden derivar clases más complejas.Para declara una clase abstracta se debe declar una función virtual pura, por consiguiente las clases derivadas de dicha clase, deben implementar la función virtual pura. Para concluir, su funcón radica en la definición de una interfaz común, para la posterior creación de clases genéricas.

8. ¿Investigue qué es un constructor de copia y para qué se utiliza en C++?

    >Un constructor de copia en C++ es una herramineta que se utiliza para copiar los datos de un objeto a otro objeto, es decir sirve para inicializar un objeto igual a otro objeto pre existente.

9. ¿Investigue qué es el polimorfismo estático y dinámico en C++ y cómo se diferencian?

>**polimorfismo estático**: ocurre cuando la ejecución de la función a llamar ocurre en tiempo de compilación. Para lograrlo se utilizan tanto funciones como clase.

>**polimorfismo dinámico**: ocurre cuando un objeto se comporta de manera distinta de acuerdo a su tiempo de ejecución. Para lograrlo se utilizan tanto funciones virtuales como punteros.

10. ¿Qué son las clases anidadas y cuál es su utilidad en C++?

>En terminos generales, es la declaración de una clase dentro de otra clase. Su utilidad radica en el encapsulamiento, acceso a miembros privados y reducción de complejidad.

11. En el contexto de la programación orientada a objetos en C++, ¿cómo se pueden
utilizar los punteros para trabajar con objetos y clases? Explique también por qué los
punteros a objetos son útiles en la programación orientada a objetos.

>Los punteros son útiles debido a la capacidad de apuntar a la dirección de memoria de un determinado tipo de dato, objeto o clase, esto permite realizar operaciones de acceso y manipulación del contenido de un objeto o clase, sin la necesidad de trabajar con el propio objeto o clase como tal.


12. ¿Qué es una función prototipo?

>En terminos generales, es la declaración de una función, es decir una función que por el momento de se ha desarrollado de manera lógica.

13. ¿Explique los diferentes tipos de miembros que existen en la OOP?

    >**Atributos**: Son las variables que tiene una clase.
    >**Métodos**: Son las funciones que definen el comportamiento de una clase.
    >**Constructores**: Es la estructura encargada de inicializar un objeto.
    >**Destructores**: Es la estructura encargada de destruir un objeto.
    >**Miembros públicos, protegidos y privados**: Los miembros publicos son aquellos accesibles desde fuera de la clase, miembros protegidos solo son accesibles desde la clase y sus clases derivadas y por último los miembros privados son solamente accesibles desde la clase.

14. ¿Qué es un memory leak?

>Un memory leak, es una fuga de memoria, esto ocurre cuando se asigna memoria a un determinado proceso, pero esta no se libera una vez ejecutada la labor. Cuando esto ocurre la memoria asignada se pierde, por tal motivo el programa intentará solventar dicha carencia con un uso excesivo de la memoria. En el caso de c++ se recomienda que cada vez que se utilice el comando **new** para asignar memoria, se debe posteriormente utilizar **delete** ,una vez ejecutada la labor, con el fin de evitar estas fugas.

15. ¿Qué es y cuál es la importancia de la Herencia multinivel, múltiple y jerárquica de
C+?

>**Herencia multinivel**: Se da cuando una clase derivada hereda una clase base, teniendo la la clase derivada la oportunidad como clase base para otra clase.

>**Herencia múltiple**: Se da cuando una clase hereda características de multiples clases.

>**Herencia jerárquica** : Se da cuando una clase sirve como clase base para otras clases.

>En terminos generales, la herencia permite reutilizar código ya que permite definir nuevas clases a partir de clases pre existentes.

16. ¿Qué es la composición y cómo se implementa en C++?

>La composición se da cuando se quiere crear objetos complejos a partir de objetos más simples. En C++ es posible implementar dicho concepto mediante la implementacíon de clases anidadas, es decir la inclusión de un objeto de una clase dentro de otro clase. 

17. ¿Qué es la sobreescritura de funciones en C++ y cuando es bueno usarla?

>Son dos o más funciones con el mismo nombre, pero difieren en el tipo y cantidad de argumentos. Es buena idea utilizar dicho concepto cuando se quiere reutilizar código, ahorrar memoria e incremenetar la legibilidad del código.


18. ¿Qué es un método y un atributo y cuál es la diferencia entre ellos?

>**Atributo** son las variables dentro de una clase y un **método** es basicamente, las acciones que realiza dicha clase, es posible que el método implemente atributos de la clase.

19. ¿Qué es el constructor y el destructor en una clase?

>Constructor es el elemento que contiene todas las instruciones necesarias para la creación de un objeto. Su propósito es brindar todos los recursos para inicializar una clase, mediante un objeto. Estos pueden recibir argumentos.

>Destructor es el encargado de destuir un objeto, a diferencia del constructor, este no recibe como parametro ningun tipo de elemento.

20. ¿Qué es la sobrecarga de operadores en C++ y cómo se utiliza?

>Es una herramienta de POO qué permite establecer el comportamiento de los operadores al trabajar como objetos. La sobre escritura se puede implementar cunado se tiene la necesidad ya sea de sumar, restar, multiplicar, dividir y comparar cobjetos, por tal motivo se define dentro de la clase la manaera de interactura de distintos operadores con los objetos.

