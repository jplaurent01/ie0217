# Tarea 5

## Instrucciones de ejecución

Dentro de la carpeta **.\src** se encuentran los archivos **.cpp** y **.hpp** y dentro de la carpeta **.\bin** se encuentran los archivos ejecutables crreados a partir de los archivos contenidos en **.\src**. Utilizando el sitema operativo Windows, ejecute:

> mingw32-make all 

Con ello llenará la carpeta  **.\bin** de archivos **.exe**, creará un target llamado **tarea5**, que se encargará de correr el ejecutable y todas sus dependencias.

Si desea eliminar el contenido de la carpeta **.\bin**, ejecute:

> mingw32-make clean

De manera adicional puede ejecutar el código dentro de la carpeta **\.src** de la siguiente manera:

> g++ -o main.exe main.cpp .\ValidadorEmail.cpp .\Funciones.cpp

Donde se creará un ejecutable **.\main.exe** donde se podrá correr el código.

## Parte Teórica

1. ¿Qué es una expresión regular y cual es su propósito en programación?

    > + Las expresiones regulares son un mini lenguaje, utilizado para mejorar la bucqueda de patrones en un string. Su proposito dentro de la programación yace en validar, buscar, extraer y remplazar un determinado texto de acuerdo a un patrón en específico.

2. ¿Qué significan los caracteres especiales . y * en una expresión regular?

    > + ".": Busca coincidencias con cualquier caracter a excepción de un salto de línea.
    > + "*": Representa cero o más veces la aparición del elemento anterior.

3. ¿Cómo se pueden agrupar subexpresiones en una expresión regular?

    > + Se pueden agrupar subexpresiones meiante **()**, donde es psible crear subexpresiones de coincidencia, coincidencia con nombre, grupos de compensación, grupos sin captura, entre otros más.

4. ¿Qué función cumple la barra invertida \ en una expresión regular?

    > + Se utiliza cuando se desea buscar un caracter en específico, por lo que "\" trata dicho carácter como literal.

5. Explique cómo se pueden capturar coincidencias usando paréntesis en una expresión
regular.

    > + Los parentesis, tal y como se explicó anteriormente, se pueden utilizar para agrupar subexpresiones, donde la coincidencia resultante se guardará en un grupo de captura, permitiendo acceder a la parte específica de de la cadena de texto que coincidió con la subexpresión.

6. ¿Cuál es la diferencia entre \d y \D en una expresión regular?

    > + **\d**: Busca coincidencias con un dígito.
    > + **\D**: Busca coincidencias con un no dígito.

7. ¿Cómo se representa una clase de caracteres en una expresión regular?

    > + Una clase característica en una expresión regular se representa mediante **[]**, donde su contenido define un conjunto de caracteres válidos dentro de la cadena de texto.

8. ¿Cuál es el propósito del modificador $ en una expresión regular?

    > + El proposito del modificador **$** consiste en indicar que la coincidencia debe terminar al final de la cadena de texto.

9. Describa cómo validar una dirección de correo electrónico usando expresiones regulares
en C++.

     ```c++
    std::regex pattern("^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$");
    ```
    > + Para validar una dirección de correo electrónico se puede utiliar una expresión regular como la anterior donde:

        + Con relación al nombres se utiliza la expresión "^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?", esta se encarga de realizar un subgrupo donde el primer y ultimo elemento del subgrupo debe ser una letra o número y los elementos intermedios deben se letrass, numeros o caracteres especiales como ".-_" con una extensión máxima de 14 caracteres.

        + Con respecto al dominio "+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?", la expresión anterior realiza un subgrupo donde el dominio se destaca por contener un "@", luego el primer y ultimo elemento del subgrupo deben ser letras y sus caracteres intermedios deben ser letras o "." con una extensión de entre 3 y  30 caracteres.

        + Con relación a la extensión "(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$", laexpresión anterior indica que el dominio destaca por contener un "." al inicio del subgrupo, posteriormente al punto, el primer y último elemento del subgrupo debe ser una letra, siendo sus caracteres intermedios letras con extensiones de entre 2 y 6 elementos.

    > Finalemte se compara la expresión regular con un determinado string haciando uso de "std::regex_match(nombre, pattern)" donde se obtiene un verdadero si el string nombre se coincide con la secuencia establecidad para validar un correo electrónico.
      
    

10. Discuta las implicaciones de rendimiento de utilizar expresiones regulares en aplicaciones de software. ¿Qué técnicas se pueden aplicar para optimizar una expresión regular
compleja, especialmente en contextos donde el tiempo de ejecución es crítico?

    > + El uso de expresiones regulares puede tiene implicaciones en cuanto al rendimiento, entre algunas de las técnicas que se pueden emplear para optimizar una expresión regular compleja destancan descomponer el patrón en partes más simples, evitar utilizar retrocesos, utilizar "^" y "$" para indicar el inicio y final de la cadena de manera respectiva y evitar el uso de grupos innecesarios.

11. ¿Qué es un Makefile y cuál es su función en un proyecto de C++?

    > + Makefile es una herramienta aplicable a C/C++ que permite decidir que partes de un largo programa necesitan ser recompiladas mediante un conjunto de reglas.

12. ¿Cuál es la diferencia entre una regla implícita y una regla explícita en un Makefile?

    > + Una regla implicita inida a **make** cómo construir un archivo a partir de otro archivo sin necesidad de especificar explicitamente cada archivo. Por otro lado, una regla explícita indica de manera explicita cómo construir un archivo a partir de otros.

13. Explique el propósito de las macros (variables) en un Makefile.

14. ¿Qué es un objetivo (target) en un Makefile y cómo se define?
15. ¿Por qué es útil dividir un proyecto de C++ en múltiples archivos fuente y cómo ayuda el uso de Makefiles en este enfoque?
16. ¿Cómo se pueden definir dependencias entre los archivos fuente en un Makefile?
17. Explique cómo se puede compilar un proyecto en diferentes sistemas operativos usando
un solo Makefile.
18. ¿Cuál es el propósito de los comandos clean y all en un Makefile?
19. Describa cómo se pueden pasar argumentos desde la línea de comandos a un Makefile.
20. Proporcione un ejemplo de una regla en un Makefile que compile un archivo fuente
.cpp a un archivo objeto .o.

## Parte teórica - Makefile

1. ¿Qué suelen contener las variables CC, CFLAGS, CXXFLAGS y LDFLAGS en un
makefile?
2. ¿De qué se compone una regla en un Makefile?
3. Defina qué es un target y cómo se relaciona con sus prerrequisitos.
4. ¿Para qué se utiliza la bandera -I, -c y -o del compilador gcc?
5. ¿Cómo se definen y se utilizan las variables en un Makefile? ¿Qué utilidad tienen?
6. ¿Qué utilidad tiene un @ en un Makefile?
7. ¿Para qué se utiliza .PHONY en un Makefile?

