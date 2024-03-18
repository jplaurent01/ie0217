#include <iostream>
using namespace std;

class Animal{

    public: 
        void setEdad(int age){
            edad = age;
        };

        int getEdad(){
            return edad;
        };
    
    //Puedo acceder a este atributo a traves de la clase perro
    protected:
        string nombre;
    
    //Solo en esta clase puedo acceder a este atributo
    private:
        int edad;
};

//La clase perro posee herencia de la clase animal
class Perro : public Animal{
    public:
        void setNombre(string n){
            nombre = n;
        };

        string getNombre(){
            return nombre;
        };

    
};

int main(){

    Perro miPerro;
    miPerro.setNombre("Hugo");
    miPerro.setEdad(3);
    //Metodo de la clase perro
    cout << "El nombre de mi perro es: " << miPerro.getNombre() << endl;
    //Metodo de la clase animal
    cout << "Edad: " << miPerro.getEdad() << endl;
    return 0;
}
