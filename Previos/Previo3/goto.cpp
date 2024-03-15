#include <iostream>
using namespace std;


int main(){
    float num, average, sum = 0.0;
    int i, n;
    cout << "Maximo numero de entrdas" << endl;
    cin >>n;
     for (int i = 0; i < n; i++)
     {
        cout << "Enter n" << i <<": " <<endl;
        cin >>num;

        if (n < 0.0){
            //La expresion goto provoca saltos de linea, hace que la ejecucion del programa no sea lineal
            //No es una practica recomendada
            goto jump;
        }
        sum+=num;
     }
     

    jump:
        average = sum/(i-1);
        cout <<"\n Promedio: " << average;
        return 0;
}


