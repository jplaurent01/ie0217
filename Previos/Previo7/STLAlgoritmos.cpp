#include <iostream> //cout
#include <algorithm> //sort
#include <vector> //vector


//funcion retorna true i<j caso contrario retorna false
bool myfunction (int i, int j){return (i<j);}

//Structura tipo clase, 
struct myclass{
    bool operator() (int i, int j) {return (i<j);}
}myobject;

int main(){
    //areglo de enteros
    int myints[] = {32,71, 12, 45, 26, 80, 53, 33};
    //Vector de enteros
    //En este caso, myints apunta al primer elemento del arreglo myints y myints+8
    //apunta al elemento después del último elemento del arreglo myints, lo que significa
    //que el rango incluye todos los elementos del arreglo.
    std::vector<int> myvector (myints, myints+8); //32,71, 12, 45, 26, 80, 53, 33

    //Ordeno del inico del vector hasat el 4to elemento del vector
    //Utilizo < como comparador
    std::sort(myvector.begin(), myvector.begin()+4); //(12,32,45,71), 26, 80, 53, 33

    //Ordeno del 5to elemento del vector hasta el final del vector
    //Uso function como comparador
    std::sort(myvector.begin()+4, myvector.end(), myfunction); //12,32,45,71, (26, 33, 53, 80)

    //Utilizo objeto como comparador
    std::sort(myvector.begin(), myvector.end(), myobject); //(12,32,45,71, 26, 33, 53, 80)

    //se imprime el contenido

    std:: cout <<"Contenido del vector...   ";
    //Itero sobre el vector
    for (std::vector<int>::iterator it=myvector.begin();it!=myvector.end();++it){
        //Desreferencio del vector
        std::cout << " " <<*it;
        std::cout << "\n";
    }
    

    return 0;
}