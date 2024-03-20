#include <iostream>
using namespace std;

class Student {

    public:
        double marks;

    //Constructor de la clase
    Student(double m){
        marks = m;
    }
};

void CalculateAverage(Student s1, Student s2){
    double avrg = (s1.marks + s2.marks)/2;
    cout << "Average marks: " << avrg << endl;
}
int main(){
    //Se inicializa los constructores 
    Student student1(90), student2(100);
    //Funcion que recibe objetos de una clase como parametros
    CalculateAverage(student1, student2);
    return 0;
}
