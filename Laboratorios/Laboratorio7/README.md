# Laboratorio 6

## Ejecución del código:

Debe ejecutar los códigos dentro de la carpeta **.\Laboratorio7**.

A continuación se procede a explicar un poco de los código dentro de la carpeta **.\Laboratorio7\src**:

+ Main.cpp : realiza el llamado a al encabezado de la clase **TextProcessor**.
+ text_procesor.hpp : Encabezado de la clase **TextProcessor**.
+ text_procesor.cpp : Contiene la declaración del constructor de la clase **TextProcessor** y contiene el método **replace** encargado de leer 2 archivo de text, siendo el primero el archivo de entrada un documento que se leera en busca de palabras claves para sustituir y el segundo archivo de texto contendrá el archivo de texto con las ediciones realizadas del archivo de entrada a partir de la sustitución de las palabras claves.

Ejecute el **Makefile** utilizando el siguiente comando:

    > mingw32

Para ello debe crear una carpeta **src** que contengan los archivos de extensión **.cpp** y **.hpp**, también debe crear una carpeta **data** que contendrá los archivos de entrada y salida de extensión **.txt** y por último agregar una carpeta **bin** que contendrá los archivos **.exe** generados por el **Makefile**.

Si se desea eliminar los ejecutables creados ejecutar el siguiente comando:

> mingw32-make clea

Finalmente para ejecutar los código creados, ejecute el siguiente comando:

> .\bin\textprocessor.exe -f .\data\input.txt -o .\data\output.txt -search "foo" -replace "bar"

El comando anterior lo que hace es leer el ejecutable **textprocessor.exe** dentro de la carpeta **bin** posteriormente se reciben como parámetros los archivos dentro de la carpeta **data** y se sustituye aquellas palabras que contengan **foo** por **bar**.

A continuación se muestra el archivo **input.txt**:

```txt
    hola mundo
    foo
    bar
    food comida fooooooo
    foofooooo
```
y su resultado luego de ser editado en **output.txt**:

```txt
    hola mundo
    bar
    bar
    bard comida barooooo
    barbarooo
```