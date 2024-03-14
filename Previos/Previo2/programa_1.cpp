#include <iostream>
using namespace std;

int count;
//Funcion que ha sido definida en otro archivo
extern void write_extern();
int main(){

    count =5;
    write_extern();
    return 0;
}