#include <iostream>
using namespace std;


int main(){
    //Variable tipo entero
    int num1 = 9;
    //variable tipo double
    double num2;

    //Asigno variable tipo entero a un double
    num2 = num1;
    cout << "El valor de num2 es: " << num2 << endl;

    double num_double = 3.556;
    //Se convierte a numero entero
    int num_init1 = (int) num_double;
    cout << "num_init1: " << num_init1 << endl;
    //Se convierte a numero entero
    int num_init2 = int(num_double);
    cout << "num_init2: " << num_init2 << endl;
    return 0;
}

/*PS C:\Users\Administrador\Documents\Estructuras_de_Datos_y_Algoritmos\repos\ie0217\Previos\Previo3> g++ -o main.exe type_casting.cpp
C:/TDM-GCC-64/bin/../lib/gcc/x86_64-w64-mingw32/10.3.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:/TDM-GCC-64/bin/../lib/gcc/x86_64-w64-mingw32/10.3.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o): in function `main':
C:/crossdev/src/mingw-w64-v8-git/mingw-w64-crt/crt/crt0_c.c:18: undefined reference to `WinMain'
collect2.exe: error: ld returned 1 exit status*/ 
