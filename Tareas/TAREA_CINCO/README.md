# Tarea 5


## Instrucciones de ejecución


Dentro de la carpeta **.\src** se encuentran los archivos **.cpp** y **.hpp** y dentro de la carpeta **.\bin** se encuentran los archivos ejecutables creados a partir de los archivos contenidos en **.\src**. Utilizando el sistema operativo Windows, ejecute:


> mingw32-make all


Con ello llenará la carpeta  **.\bin** de archivos **.exe**, creará un target llamado **tarea5**, que se encargará de correr el ejecutable y todas sus dependencias.


Si desea eliminar el contenido de la carpeta **.\bin**, ejecute:


> mingw32-make clean


De manera adicional puede ejecutar el código dentro de la carpeta **\.src** de la siguiente manera:


> g++ -o main.exe main.cpp .\ValidadorEmail.cpp .\Funciones.cpp


Donde se creará un ejecutable **.\main.exe** donde se podrá correr el código.

Enlace del código fuente:

> 

## Parte Teórica


1. ¿Qué es una expresión regular y cual es su propósito en programación?


    > + Las expresiones regulares son un mini lenguaje, utilizado para mejorar la búsqueda de patrones en un string. Su propósito dentro de la programación yace en validar, buscar, extraer y remplazar un determinado texto de acuerdo a un patrón en específico.


2. ¿Qué significan los caracteres especiales . y * en una expresión regular?


    > + ".": Busca coincidencias con cualquier caracter a excepción de un salto de línea.
    > + "*": Representa cero o más veces la aparición del elemento anterior.


3. ¿Cómo se pueden agrupar subexpresiones en una expresión regular?


    > + Se pueden agrupar subexpresiones mediante **()**, donde es posible crear subexpresiones de coincidencia, coincidencia con nombre, grupos de compensación, grupos sin captura, entre otros más.


4. ¿Qué función cumple la barra invertida \ en una expresión regular?


    > + Se utiliza cuando se desea buscar un carácter en específico, por lo que \ trata dicho carácter como literal.


5. Explique cómo se pueden capturar coincidencias usando paréntesis en una expresión
regular.


    > + Los paréntesis, tal y como se explicó anteriormente, se pueden utilizar para agrupar subexpresiones, donde la coincidencia resultante se guardará en un grupo de captura, permitiendo acceder a la parte específica de de la cadena de texto que coincidió con la subexpresión.


6. ¿Cuál es la diferencia entre \d y \D en una expresión regular?


    > + **\d**: Busca coincidencias con un dígito.
    > + **\D**: Busca coincidencias con un no dígito.


7. ¿Cómo se representa una clase de caracteres en una expresión regular?


    > + Una clase característica en una expresión regular se representa mediante **[]**, donde su contenido define un conjunto de caracteres válidos dentro de la cadena de texto, ejemplo **[a-zA-Z]** busca letras mayúsculas y minúsculas.


8. ¿Cuál es el propósito del modificador $ en una expresión regular?


    > + El propósito del modificador **$** consiste en indicar que la coincidencia debe terminar al final de la cadena de texto.


9. Describa cómo validar una dirección de correo electrónico usando expresiones regulares
en C++.


     ```c++
    std::regex pattern("^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$");
    ```
    > + Para validar una dirección de correo electrónico se puede utilizar una expresión regular como la anterior donde:


        + Con relación al nombres se utiliza la expresión "^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?", esta se encarga de realizar un subgrupo donde el primer y último elemento del subgrupo debe ser una letra o número y los elementos intermedios deben se letrass, numeros o caracteres especiales como ".-_" con una extensión máxima de 14 caracteres.


        + Con respecto al dominio "+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?", la expresión anterior realiza un subgrupo donde el dominio se destaca por contener un "@", luego el primer y último elemento del subgrupo deben ser letras y sus caracteres intermedios deben ser letras o "." con una extensión de entre 3 y  30 caracteres.


        + Con relación a la extensión "(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$", la expresión anterior indica que el dominio destaca por contener un "." al inicio del subgrupo, posteriormente al punto, el primer y último elemento del subgrupo debe ser una letra, siendo sus caracteres intermedios letras con extensiones de entre 2 y 6 elementos.


    > Finalmente se compara la expresión regular con un determinado string haciendo uso de "std::regex_match(nombre, pattern)" donde se obtiene un verdadero si el string nombre se coincide con la secuencia establecida para validar un correo electrónico.
     
   


10. Discuta las implicaciones de rendimiento de utilizar expresiones regulares en aplicaciones de software. ¿Qué técnicas se pueden aplicar para optimizar una expresión regular
compleja, especialmente en contextos donde el tiempo de ejecución es crítico?


    > + El uso de expresiones regulares puede tiene implicaciones en cuanto al rendimiento, entre algunas de las técnicas que se pueden emplear para optimizar una expresión regular compleja destacan descomponer el patrón en partes más simples, evitar utilizar retrocesos, utilizar "^" y "$" para indicar el inicio y final de la cadena de manera respectiva y evitar el uso de grupos innecesarios.


11. ¿Qué es un Makefile y cuál es su función en un proyecto de C++?


    > + Makefile es una herramienta aplicable a C/C++ que permite decidir que partes de un largo programa necesitan ser recompiladas mediante un conjunto de reglas.


12. ¿Cuál es la diferencia entre una regla implícita y una regla explícita en un Makefile?


    > + Una regla implícita indica a **make** cómo construir un archivo a partir de otro archivo sin necesidad de especificar explícitamente cada archivo. Por otro lado, una regla explícita indica de manera explícita cómo construir un archivo a partir de otros.


13. Explique el propósito de las macros (variables) en un Makefile.


    > + El propósito de los macros en un Makefile radica en reutilizar valores en varias partes del Makefile, lo que facilita la actualización de valores en común en un solo lugar y además evita que se repitan valores. De manera adicional, hace que el Makefile sea legible, mantenible y portable.


14. ¿Qué es un objetivo (target) en un Makefile y cómo se define?
    > + Un **target** representa un archivo que debe ser ejecutada.
    Su sintaxis es la siguiente:


     ```Makefile
        target: dependencias
        receta
    ```
    Donde el **target** el es el archivo que se desea construir, este podría llamarse como **Tarea**, las dependencias son aquellos archivos necesarios para construir el **target**, en este caso pueden ser **archivo1.cpp** y **archivo2.cpp** y finalmente la receta es el comando que se debe ejecutar para construir el **target**, ejemplo:
    ```Makefile
        tarea: archivo1.cpp archivo2.cpp
        g++ -o tarea archivo1.cpp archivo2.cpp
    ```






15. ¿Por qué es útil dividir un proyecto de C++ en múltiples archivos fuente y cómo ayuda el uso de Makefiles en este enfoque?
    > + Es útil debido a que si se realizan cambios a un único archivo fuente, solamente es necesario recompilar dicho archivo y sus dependencias sin necesidad de recompilar todo el proyecto, además cuando se tienen archivos fuente, estos pueden depender de otros archivos fuentes y de archivos de encabezado, por tales motivos el uso de Makefiles permite compilar dichos archivos de manera correcta y que cuando se realice un cambio en un archivo de encabezado, los archivos se vuelvan a compilar.


16. ¿Cómo se pueden definir dependencias entre los archivos fuente en un Makefile?
    > + Las dependencias indican que archivos son necesarios para la construcción de archivo target. A continuación se vuelve a exponer el ejemplo anteriormente mencionado.
    Su sintaxis es la siguiente:


     ```Makefile
        target: dependencias
        receta
    ```
    Donde el **target** el es el archivo que se desea construir, este podría llamarse como **Tarea**, las dependencias son aquellos archivos necesarios para construir el **target**, en este caso pueden ser **archivo1.cpp** y **archivo2.cpp** y finalmente la receta es el comando que se debe ejecutar para construir el **target**, ejemplo:
    ```Makefile
        tarea: archivo1.cpp archivo2.cpp
        g++ -o tarea archivo1.cpp archivo2.cpp
    ```


17. Explique cómo se puede compilar un proyecto en diferentes sistemas operativos usando
un solo Makefile.
    > + Se pueden utilizar condicionales dentro del **Makefile** que pregunten por el sistema operativos del usuario, mediante el uso de **ifeq**, **else** y **endif**, a continuación se muestra un ejemplo de un **Makefile** que pregunta por el sistema operativo.
     ```Makefile
        #Define una variable OSFLAG para almacenar los flags del sistema operativo
        OSFLAG :=


        #Comprueba si el sistema operativo es Windows
        ifeq ($(OS),Windows_NT)
            # Añade el flag WIN32 si es Windows
            OSFLAG += -D WIN32
            #Comprueba la arquitectura del procesador
            ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
                #Añade el flag AMD64 si la arquitectura es AMD64
                OSFLAG += -D AMD64
            endif
            ifeq ($(PROCESSOR_ARCHITECTURE),x86)
                #Añade el flag IA32 si la arquitectura es x86
                OSFLAG += -D IA32
            endif
        else
            #Si no es Windows, obtiene el nombre del sistema operativo
            UNAME_S := $(shell uname -s)
            #Añade el flag correspondiente al sistema operativo
            ifeq ($(UNAME_S),Linux)
                OSFLAG += -D LINUX
            endif
            ifeq ($(UNAME_S),Darwin)
                OSFLAG += -D OSX
            endif
            #Obtiene la arquitectura del procesador en sistemas no Windows
            UNAME_P := $(shell uname -p)
            #Añade el flag AMD64 si la arquitectura es x86_64
            ifeq ($(UNAME_P),x86_64)
                OSFLAG += -D AMD64
            endif
            #Añade el flag IA32 si la arquitectura es x86
            ifneq ($(filter %86,$(UNAME_P)),)
                OSFLAG += -D IA32
            endif
            #Añade el flag ARM si la arquitectura es ARM
            ifneq ($(filter arm%,$(UNAME_P)),)
                OSFLAG += -D ARM
            endif
        endif


        #Regla por defecto, muestra los flags del sistema operativo
        all:
            @echo $(OSFLAG)


    ```


18. ¿Cuál es el propósito de los comandos clean y all en un Makefile?


    > + **clean**: Este comando sirve para eliminar los archivos generados durante el proceso de compilación.
    > + **all**: Este comando sirve para realizar el compilado de todo el proyecto.


19. Describa cómo se pueden pasar argumentos desde la línea de comandos a un Makefile.
    >Existen varias maneras de realizarlo.


    > - Desde el entorno: Aquí cada variable de entorno se transforma a una variable del make con el mismo nombre y valor. Para ello se recomienda utilizar **?=** de la siguiente manera: **FOO?=default_value_if_not_set_in_environment**.


    > - Desde la línea de comandos: make puede tomar argumentos mezclados con targets de la siguiente forma:
    **make target FOO=bar**.


    > - Exportar desde el Make principal: Al exportar una variable la convierte en el entorno de cada invocación del Shell y Make llama desde estos comandos y recoge estas variables de entorno.
     ```Makefile
        CFLAGS=-g
        export CFLAGS
        target:
                $(MAKE) -C target
     ```
    > También puede exportar todas las variables utilizando **export** sin argumentos.
20. Proporcione un ejemplo de una regla en un Makefile que compile un archivo fuente
.cpp a un archivo objeto .o.

    > Ejemplo:
    ```Makefile
        CXX = g++
        CXXFLAGS = -Wall -std=c++11

        # Regla para compilar un archivo .cpp a un archivo .o
        %.o: %.cpp
            $(CXX) $(CXXFLAGS) -c $< -o $@
        clean:
            rm -f *.o
     ```
    > Donde la regla **%o: %.cpp** que para cualquier archivo de extensión **.cpp** se debe construir un archivo de extensión **.o** utilizando el compilador **g++** con las opciones **-Wall -std=c++11** donde **$<** indica que que el archivo de origen debe ser **.cpp** y **$@** indica que el archivo de destino debe ser **.o**.

## Parte teórica - Makefile

1. ¿Qué suelen contener las variables CC, CFLAGS, CXXFLAGS y LDFLAGS en un
makefile?
    > + CC : Indica el compilador que se va a utilizar.


    > + CFLAGS: Contiene las opciones de compilación para los archivos C, donde **-Wall** indica que se deben activar todas las advertencias.


    > + CXXFLAGS: Contiene las opciones de compilación específicas para los archivos de C++.


    > + LDFLAGS: Contiene las opciones de enlace para el linker.


2. ¿De qué se compone una regla en un Makefile?


    > + Una regla se compone de un target, dependencias y una receta. Ejemplo:
    ```Makefile
        tarea: archivo1.cpp archivo2.cpp
        g++ -o tarea archivo1.cpp archivo2.cpp
    ```
    >Donde el target es el archivo tarea, con dependencias de los archivos de extensión **.cpp**, finalmente la receta es **g++ -o tarea archivo1.cpp archivo2.cpp** que contiene las instrucciones necesarias para crear el target.


3. Defina qué es un target y cómo se relaciona con sus prerrequisitos.


    >+ Un target es un archivo que se desea realizar. En sus pre requisitos son los archivos necesarios para su creación en el ejemplo anterior los prerrequisitos son los archivos de extensión **.cpp**.


4. ¿Para qué se utiliza la bandera -I, -c y -o del compilador gcc?


    >+ **-I**: Se utiliza para agregar al path de búsqueda de archivos de encabezado.
    >+ **-c**: Se utiliza para indicar al compilador que compile los archivos .c y .cpp.
    >+ **-o**: Se utiliza para indicar el nombre del archivo de salida del compilador.
   
5. ¿Cómo se definen y se utilizan las variables en un Makefile? ¿Qué utilidad tienen?
   
    >+ En un Makefile las variables se definen y utilizan de la siguiente manera: NOMBRE = valor o NOMBRE := valor, ejemplo **CC= gcc**. Esto tiene como utilidad facilitar la modificación de los valores de las variables así como facilitar su legibilidad.


6. ¿Qué utilidad tiene un @ en un Makefile?


    >+ Se utiliza para ejecutar comandos sin imprimir la regla.


7. ¿Para qué se utiliza .PHONY en un Makefile?


    >+ Son targets especiales que le indican a make que un target no es un archivo.











