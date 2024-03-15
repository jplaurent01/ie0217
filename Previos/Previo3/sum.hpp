//Este es un archivo de encabezado.
#ifndef SUM_H //Si no existe una varibale SUM_H
#define SUM_H //Se proede a dfinir SUM_H

//Prototipo de la funcion
int sum(int a, int b);

#endif

/* Cuando 2 archivos pretenden importar ".hpp",
   el primero en importar el archivo define SUM_H,
   debido a que ya existe el 2do archivo no lo lee, se ahorra el codigo debido al if
   debido a que ya está definido, esto ahorra tiempo y espacio en memoria.
*/