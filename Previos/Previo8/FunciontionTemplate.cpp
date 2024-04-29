#include <iostream>
using namespace std;

template <typename T>
T add( T num1, T num2){
    return (num1 + num2);
}

int main(){
    int result1;
    double result2;

    //Llamando con parametos int
    result1 = add<int>(2,3);
    cout << "2 + 3: " << result1 << endl;

    //Llamando con parametros double
    result2 = add<double>(2.2, 2.3);
    cout << "2.2 + 2.3: " <<result2 << endl;

    return 0;

}