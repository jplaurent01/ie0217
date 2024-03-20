#include <iostream>
using namespace std;

/*La sobrecarga de operadores permite a los desarrolladores 
definir el comportamiento de los operadores para trabajar con objetos de una clase personalizada. 
Esto significa que los operadores como +, -, *, /, entre otros, pueden ser utilizados
con objetos de una clase personalizada, y los resultados de estas 
operaciones pueden ser definidos por quien programe.
*/
class Fraccion {
    int numerador, denominador;

    //Constructor de la clase
    public:
        Fraccion(int n, int d): numerador(n), denominador(d){};

        //Operador a sobrecargar es el "+"
        //const Fraccion &f significa: f es un alias para un objeto Fraccion que no se puede modificar 
        //dentro de la función operator+.Usar una referencia constante en la sobrecarga de operadores
        // es una buena práctica porque evita copias innecesarias de objetos grandes y también garantiza
        // que el objeto pasado como argumento no se modificará accidentalmente dentro de la función.
        Fraccion operator+ (const Fraccion &f){
            Fraccion resultado(
                numerador * f.denominador + f.numerador * denominador,
                denominador * f.denominador
            );
            return resultado;
        }

        void imprimir(){
            cout << numerador << "/" << denominador << endl;    
        }
        
};

int main(){
    //Instancia de objetos tipo fracion
    Fraccion f1(1,2), f2(3,4);

    Fraccion f3 = f1 + f2;

    f3.imprimir();
    return 0;
}
