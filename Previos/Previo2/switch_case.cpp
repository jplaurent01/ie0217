#include <iostream>
#include <string>
// se evita escribir escribir std:: para imprimir
using namespace std;

int main(){
    //Declara variable tipo string
    char oper;
    float num1, num2;
     cout <<"Ingrese un operador (+, -, *, /): ";
     cin >> oper;
     cout <<"Ingrese 2 numeros: "<< endl;
     cin >> num1 >> num2;
    
    //Si se optiene un valor numerico se imprime el numero si no, ejecuta else
     
     switch (oper)
     {
    //Multiplicacion
     case '*':
        cout <<num1 * num2 ;
        break;
    //Resta
    case '-':
         cout <<num1 - num2 ;
        break;
    //Suma
    case '+':
         cout <<num1 + num2 ;
        break;
    //Division
    case '/':
         cout <<num1 / num2 ;
        break;
        
     default:
        cout <<"No ingreso ningun operador habilitado";
        break;
     }
    return 0;
}

