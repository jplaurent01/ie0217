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