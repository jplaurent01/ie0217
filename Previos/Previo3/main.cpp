#include <iostream>
//Archivo de encabezado
/*
La diferencia entre utilizar < > y " " es que < > se utiliza para incluir 
archivos de encabezado estándar del sistema, mientras que " " se utiliza 
para incluir archivos de encabezado que están específicamente 
relacionados con el proyecto y que se encuentran en el directorio 
actual o en otros directorios específicos definidos por el usuario.
*/
#include "sum.hpp"
using namespace std;


int main(){

   int num1 = 1;
   int num2 = 2;
   int result = sum(num1,num2);
   cout << "Resultado de la suma es: " << result << endl;

   return 0;
}

