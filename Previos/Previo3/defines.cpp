#include <iostream>
using namespace std;

#define BOOK_ID_MAX 10
enum {CASA_BADILLA, CASA_ALVARADO, CASA_SOLANO, CASA_MAX};

int main(){
   /*El valor de BOOK_ID_MAX es preprocesado*/
   /*No existe en tiempo de ejecucion*/
    cout << "El valor de BOOK_ID_MAX es: " << BOOK_ID_MAX <<endl;
    cout << "Cantidad de casas es: " <<  CASA_MAX <<endl;
    return 0;
}


