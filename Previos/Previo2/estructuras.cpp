#include <iostream>
#include <cstring>
using namespace std;

//Una estructura es similar a una clase
struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

struct Persona{
    char nombre[50];
    int edad;
    float salario;
};

int main(){
    //Se crean 2 estructuras de tipo Books
    struct Books Book1;
    struct Books Book2;

    /*
    La función strcpy() en C se utiliza para copiar una cadena de caracteres (string) a otra.
    La función toma dos argumentos: el destino (donde se copiará la cadena) y la fuente 
    (la cadena que se copiará). 
    */
    //Se inicializan 2 objetos tipo Books
    std::strcpy(Book1.title, "Herlock Holmes");
    std::strcpy(Book1.author, "Artur conan doyle");
    std::strcpy(Book1.subject, "Ingles");
    Book1.book_id = 12345;

    std::strcpy(Book2.title, "El principe");
    std::strcpy(Book2.author, "Maquiavelo");
    std::strcpy(Book2.subject, "Ciencias sociales");
    Book2.book_id = 135676;

    cout<<"Book1.title : "<< Book1.title <<endl;
    cout<<"Book1.author : "<< Book1.author <<endl;
    cout<<"Book1.subject : "<< Book1.subject <<endl;
    cout<<"Book1.book_id"<< Book1.book_id<<endl;

    cout<<"Book2.title : "<< Book2.title <<endl;
    cout<<"Book2.author : "<< Book2.author <<endl;
    cout<<"Book2.subject : "<< Book2.subject <<endl;
    cout<<"Book2.book_id"<< Book2.book_id<<endl;

    Persona p1;

    cout <<"Nombre :";
     cin.get(p1.nombre, 50);

    cout <<"Edad :";
     cin >> p1.edad;

     cout << "Salario :";
      cin >> p1.salario;

    cout <<p1.nombre <<endl;
    cout <<p1.edad <<endl;
    cout << p1.salario<<endl;
    return 0;
}