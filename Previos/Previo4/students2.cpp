#include <iostream>
using namespace std;

class Student {

    public:
        double marks1, marks2;
};

//Esta funcion de tipo student retorna un Student
//Basicamente esta función sustituye el concepto de constructor
Student createStudent(){
    //Aparentemente aqui se logra inicializar el objeto
    Student student1;
    student1.marks1 = 90;
    student1.marks2 = 100;

    cout << "Marks 1: " << student1.marks1 << endl;
    cout << "Marks 2: " << student1.marks2 << endl;

    return student1;
}
int main(){
    //Se crea una variable de tipo student para poder retornar un objeto de tipo student
    Student stuedent;
    //Se llama a la funcion que instancia un objeto tipo student
    stuedent = createStudent();
    return 0;
}
