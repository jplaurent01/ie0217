#include <iostream>
using namespace std;

//atributos -> similar a variables.
//Metodo -> sinonimo de acción, verbo infinitivo espanol, similar a una funcion
//Objeto -> Instancia de una clase.
/*
Estructura de una clase:
Class Class_Name{
   Acces specifier //Publico, privado, protegido (se puede acceder mediante la herencia)
   Data members //Variables a usar
   Member Functions {} //Metodos
}
*/
class Molde{

   //Atributos de la clase
   public:
      double largo;
      double ancho;
      double altura;

   //Constructor de la clase, lleva los parametros
   //inicializador de todo los necesario
   /*
      Molde(){
      largo = 10;
      ancho = 20;
      altura = 30;
      cout << "Esto se ejecuta en cada instancia" << endl;
      cout << "Inicia objeto de la clase molde" << endl;
   }
   */

   //Otra forma de inicializar el constructor
   Molde(double largo_p, double ancho_p, double altura_p): largo(largo_p), ancho(ancho_p), altura(altura_p){}
   //lo mismo que esto:
   /*
      Molde(double largo_p, double ancho_p, double altura_p){
      largo = largo_p;
      ancho = ancho_p;
      altura = altura_p;
   }
   */

   //Destructor -> Sirve para cerrar archivos, Limpia todo, su nomenclaturaa utiliza ~
   //Lo ultimo que se ejecuta es el destructor
  ~Molde(){
    cout << "Saludos desde el destructor";
  }

   //Metodos
   double calcularArea(){
      return largo*ancho;
   }

   double calcularVolumen(){
      return largo*ancho*altura;
   }
};

int main(){

   //Instancia de la clase molde;
   //Ejecuta el constructor
   //Molde pared; //Se puede utilizar este constructor cuando los atributos se inicializan dentro del el.
   Molde pared (1,2,3); //Ahora este constructor requiere parametros

   //Asignar valores al objeto pared
   cout << pared.altura << endl;
   pared.altura = 400;
   cout << pared.altura << endl;

   cout << pared.ancho << endl;
   pared.ancho = 500;
   cout << pared.ancho << endl;

   cout << pared.largo << endl;
   pared.largo = 20;
   cout << pared.largo << endl;

   //Calculos del objeto
   cout << "Area: " << pared.calcularArea() << endl;
   cout << "Volumen: " << pared.calcularVolumen() << endl;

   return 0;
}

