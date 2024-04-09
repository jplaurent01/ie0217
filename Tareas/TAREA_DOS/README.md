# Tarea 2


Debe ejecutar el código con el siguiente comando dentro de la carpeta **src**:
```
g++ -o main.exe .\main.cpp .\Planeta.cpp .\Funciones.cpp .\Continentes.cpp .\Pais.cpp .\PaisPrimerMundo.cpp .\PaisEnDesarrollo.cpp
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

5. ¿Qué significa el término encapsulamiento en el contexto de la OOP?
6. ¿Cuál es el propósito del constructor y el destructor en una clase de C++?
7. ¿Investigue cómo se define una clase abstracta en C++ y cuál es su función?
8. ¿Investigue qué es un constructor de copia y para qué se utiliza en C++?
9. ¿Investigue qué es el polimorfismo estático y dinámico en C++ y cómo se diferencian?
10. ¿Qué son las clases anidadas y cuál es su utilidad en C++?
11. En el contexto de la programación orientada a objetos en C++, ¿cómo se pueden
utilizar los punteros para trabajar con objetos y clases? Explique también por qué los
punteros a objetos son útiles en la programación orientada a objetos.
12. ¿Qué es una función prototipo?
13. ¿Explique los diferentes tipos de miembros que existen en la OOP?
14. ¿Qué es un memory leak?

>Un memory leak, es una fuga de memoria, esto ocurre cuando se asigna memoria a un determinado proceso, pero esta no se libera una vez ejecutada la labor. Cuando esto ocurre la memoria asignada se pierde, por tal motivo el programa intentará solventar dicha carencia con un uso excesivo de la memoria. En el caso de c++ se recomienda que cada vez que se utilice el comando **new** para asignar memoria, se debe posteriormente utilizar **delete** ,una vez ejecutada la labor, con el fin de evitar estas fugas.

15. ¿Qué es y cuál es la importancia de la Herencia multinivel, múltiple y jerárquica de
C+?

>**Herencia multinivel**: Se da cuando una clase derivada hereda una clase base, teniendo la la clase derivada la oportunidad como clase base para otra clase.

>**Herencia múltiple**: Se da cuando una clase hereda características de multiples clases.

>**Herencia jerárquica** : Se da cuando una clase sirve como clase base para otras clases.

>En terminos generales, la herencia permite reutilizar código ya que permite definir nuevas clases a partir de clases pre existentes.

16. ¿Qué es la composición y cómo se implementa en C++?
17. ¿Qué es la sobreescritura de funciones en C++ y cuando es bueno usarla?
18. ¿Qué es un método y un atributo y cuál es la diferencia entre ellos?
19. ¿Qué es el constructor y el destructor en una clase?
20. ¿Qué es la sobrecarga de operadores en C++ y cómo se utiliza?

