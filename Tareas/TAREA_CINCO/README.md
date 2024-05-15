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

1. ¿Que es una expresión regular y cual es su propósito en programación?
2. ¿Qué significan los caracteres especiales? y * en una expresión regular?
3. ¿Cómo se pueden agrupar subexpresiones en una expresión regular?
4. ¿Qué función cumple la barra invertida \ en una expresión regular?
5. Explique cómo se pueden capturar coincidencias usando paréntesis en una expresión
regular.
6. ¿Cuál es la diferencia entre \d y \D en una expresión regular?
7. ¿Cómo se representa una clase de caracteres en una expresión regular?
8. ¿Cuál es el propósito del modificador $ en una expresión regular?
9. Describa cómo validar una dirección de correo electrónico usando expresiones regulares
en C++.
10. Discuta las implicaciones de rendimiento de utilizar expresiones regulares en aplicaciones de software. ¿Qué Técnicas se pueden aplicar para optimizar una expresi´on regular
compleja, especialmente en contextos donde el tiempo de ejecución es crítico?
11. ¿Qué es un Makefile y cuál es su función en un proyecto de C++?
12. ¿Cuál es la diferencia entre una regla implícita y una regla explícita en un Makefile?
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

