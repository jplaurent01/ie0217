#include <iostream>
using namespace std;

//La recursividad se puede seguir cuando hay patrones como series numericas por ejemplo
int factorial(int n){

    if (n != 0){
        //Una funcion recursiva como esta tiene la ventaja de no gasta memoria, ya que se vuelve a llamar a si misma
        return n*factorial(n-1);
    }

    else{
        return 1;
    }
    
}

int fibonacci(int n){
    if (n == 0){
        return 0;
    }

    else if (n==1)
    {
        return 1 + fibonacci(n-1);
    }

    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
    
    
}

int main(){
    int n, result, fibo;
    cout << "Ingrese un numero >= 0:";
    cin >> n;
    if (n < 0){
        cout << "Ingrese un numero positivo";
    }
    
    else{
        result = factorial(n);
        fibo = fibonacci(n);
        cout << "Factorial de "<< n << " es :" << result <<endl;
        cout << "Finocacci de "<< n << " es :" << fibo <<endl;
    }
   
    return 0;
}


