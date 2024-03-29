#include <iostream>
using namespace std;

/*Las funciones y clases permiten acceder a funciones miembro 
desde fuera de la clase*/

class Distance{
    private:
        //Atributo privado
        int meter;

        //funcion amiga Note la palabra "friend"
        friend int addfive(Distance);

    //Se inicializa constructor en 0 metros    
    public:
        Distance(): meter(0) {};

};

class classB; 
class classA {
    public:
        //Constructor inicializadoen 12
        classA(): numA(12) {}

    private:
        int numA;

        //funcion Amiga
        friend int add(classA, classB);
        //Clase amiga
        friend class classC;
};

class classB{
    public:
        //inicializo contructor
        classB():numB(1){}
    private:
        int numB;
        //funcion Amiga
        friend int add(classA, classB);
};

class classC{
    private:
        int numC;
    public:
        //inicializo contructor
        classC  ():numC(20){}
    
        int add(){
            //Puedo acceder a los atributos privados de la classA DEBIDO a que es amiga
            classA objectA;
            return objectA.numA + numC;
        }
};


//Funcion amiga accedo atributos privados ambas clases
int add(classA objectA, classB objectB){
    return (objectA.numA + objectB.numB);
}

//Funcion amiga accede al atributo privado de la clase Dsitance
int addfive(Distance d){
    //modifico atributo privado
    d.meter+=5;
    return d.meter;
};


int main(){
    Distance d1;
    cout << "Distancia: " << addfive(d1) << endl;

    classA objectA;
    classB objectB;
    classC objectC;
    //Sumo atributos privados de las clases A y B entre funciones amigas
    cout << "SUMA: " << add(objectA, objectB) << endl;

    //Sumo atributos privados de las clases A y B entre clases amigas
    cout << "SUMA: " << objectC.add() << endl;




    return 0;
}
