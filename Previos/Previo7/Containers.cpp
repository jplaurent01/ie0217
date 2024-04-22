#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

int main(){
    
    //Se inicializa el vector
    //Vector unicamente almacena elementos de un mismo tipo de dato, en este caso son enteros.

    vector<int> numbers = {1,100,10,70,100};

    //se imprime contenido del vector
    cout << " Numeros: ";
    //Itero sobre cada uno de los elementos almacenados en el vector
    //si se desea se puede modificar el contenido del num al ser una referencia de los contenidos del vector
    for (auto &num: numbers){
        cout << num << ", ";
    }

    //Contenedor que ordena automaticamente elementos y en caso se existir duplicados los elimina
    set<int> numberSet = {1,100,10,70,100};

    //se imprime contenido de set
    cout << " Numeros: ";
    for (auto &num: numberSet){
        cout << num << ", ";
    }

    //Contenedor que NO ordena elementos y en caso se existir duplicados los elimina
    //La ventaja principal de std::unordered_set es su eficiencia en operaciones como la insercion,
    // la eliminacion y la búsqueda de elementos, que tienen complejidad O(1) en promedio, 
    //en lugar de O(log n) como en std::set.
    unordered_set<int> numberUnorderedSet = {1,100,10,70,100};

    //se imprime contenido de set
    cout << " Numeros: ";
    for (auto &num: numberUnorderedSet){
        cout << num << ", ";
    }
    
    //Contenedor ordenado almacena elementos en forma de par, donde el key: integer y value:String.
    map<int, string> student;

    //Se usa el operdador para agregar elementos por indice[]
    student[1] = "Jaqueline";
    student[2] = "Blake";

    //se utiliza el metodo insert para agregar el par
    student.insert(make_pair(3, "Dennise"));
    student.insert(make_pair(4, "Blake"));

    // Se agregan elementos con keys duplicados, se sustituye "Timoty" por "Jose"
    student[5] = "Timoty";
    student[5] = "Jose";

    for (int i = 1; i <= student.size(); i++){
        cout << " Student["<< i << "] :" << student[i] << endl;
    }
    

    return 0;
}