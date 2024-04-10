#include <iostream>
using namespace std;

// Definición de la clase Student
class Student {
private:
    int age;

public:
    // Constructor que inicializa la edad en 12
    Student(): age(12) {}

    // Método para obtener la edad
    void getAge() {
        cout << "Age = " << age << endl;
    }
};

int main() {
    // Se declara dinámicamente un objeto de la clase Student
    Student* ptr = new Student;

    // Se llama al método getAge del objeto
    ptr->getAge();

    // Se libera la memoria asignada dinámicamente
    delete ptr;

    return 0;
}
