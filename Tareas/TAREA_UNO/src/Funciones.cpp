#include "Funciones.hpp"
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <cstring>
#include <algorithm> // Para usar la función std::transform
#include <cctype>    // Para usar la función std::tolower
#include<map> //Dicionrio de c++
#include <unordered_map>
#include <vector>

using namespace std;

//Envio un puntero de tipo Juego y un array con palabras pre cargadas
void Inicializar(Juego* play1, vector<string> array){

    //Array tipo string con 10 elementos
    //array<string, 10> array = {"perro", "gato", "casa", "arbol", "libro", "manzana", "rojo", "verde", "curso", "sol"};
    // Inicializar el generador de números aleatorios
    mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> distribucion(0, 9);

    // Obtiene un índice aleatorio
    int indice = distribucion(rng);
    // Puntero acceder a la palabra seleccionada aleatoriamente y almacena el valor
    play1->palabra = array[indice];
    //itero en las letras de palabra
    for (int i = 0; i < play1->palabra.length(); ++i) {
        //asigno convierto la palabra en caracteres y asigno los caracteres en cada posicion del arreglo
        //substr(i, 1) extraer una subcadena de longitud 1 de una cadena más grande, comenzando en la posición i
        play1->array[i] = play1->palabra.substr(i, 1);
    }
    //maximo de intentos permitidos
    play1->max = 10;
    //numero actual de intentos realizados.
    play1->intentos = 0;

}
//Anadir robustez como ingresar solo una letra, no numeros ni espacios vacios
void Adivinar(Juego* play1){
    //int count = 0;
    //dicionario key int, value char
    map<int, char> dict;
    //varrable de tipo array que contiene inidces de letras repetidas
    bool indicesRepetidos = letrasRepetidas(play1->palabra);
    do{
        char letra;
        std ::cout << "\n Ingrese una letra: ";
        cin >> letra;
        std ::cout << endl;
        if (isLetra(letra)){
        //Se corrobora que el caracter sea en minuscula
        letra = tolower(letra);
        //Contador para imprimir correctamente la posición de la letra
        int print_count = 0;
        int rep_count = 0;
        //Bandera para indicar si se encntro la letra en la palabra
        bool flag_1 = false;
        
        //Notar que poseo memoria en el dict
        //Itero sobre cada uno de los elementos del array
        if (!indicesRepetidos){
            for (const string& str: play1->array){
                //Caracter temporal que eventualmente sera transformado en minuscula
                string temp = str;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                //En caso de encontrar una letra en la palabra, se covierte el char en string
                    if (temp == string(1, letra)){
                    flag_1 = true;
                    //Pueblo el dicionario, este dicionario se ordena solo
                    dict.insert(make_pair(print_count, letra));
                    break;
                }
                //Empiezo posicion 0,1,2,3,...
                print_count += 1;
            }
        }
        //Caso para palabras con letras repetidas
        else{
            for (const string& str: play1->array){
                //Caracter temporal que eventualmente sera transformado en minuscula
                string temp2 = str;
                transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
                //En caso de encontrar una letra en la palabra, se covierte el char en string
                    if (temp2 == string(1, letra)){
                    flag_1 = true;
                    dict.insert(make_pair(print_count, letra));
                    //No utilizo el break
                    //break;
                }
                print_count += 1;
            }
        }

        //Caso de encontrar una letra en palabra, procedo a imprimir
        if (flag_1){
            //Desde cero hasta la longitude de palabra -1
            //Se supone que aqui puedo almcenar las letras que hacen match de acuerdo a la posicion
            for (int i = 0; i < play1->palabra.size(); i++){
                //Si el inice es distinto a la posicion donde hubo match
                if (i != print_count){
                        //Antes debo chequear si existe algo en el diccionario
                        //SI en el diccionario exste un key igual a inex
                        auto iterador = dict.find(i);
                        //Carga valor previamente guardado
                        if (iterador != dict.end()){
                            std ::cout << dict[i] <<"\t";
                           }
                        //si no, imprimo espacio nada mas
                        else{
                            std ::cout << "_\t";
                        }
                        
                    }
                    //Caso de match
                    else {
                        //Inserto valores en el diccionario
                        dict.insert(make_pair(print_count, letra));
                        std ::cout << letra <<"\t";
                    }
            }
             std ::cout << "\nIntento Fallido" << std ::endl;   
        }

        //Se ejecuta el else cuando no hay match
        else{
            std ::cout << "Intento Fallido" << std ::endl;
        }
        //itera hasta la cantidad maxima de ejecuciones del programa
        //count += 1; 
        }
        
        
    } while ( !Verificar(dict, play1));
    
}

//Retorna un boleano con las posiciones de la letras repetidas en caso de haber
bool letrasRepetidas(const std::string& palabra) {
    //Dicionario sin ordenado automatico guarda un char con un integer
    std::unordered_map<char, int> contador;
    //Declara array de enteros
    std::vector<int> indicesRepetidos;
    //Recorre todas las letras de la palabra
    for (int i = 0; i < palabra.length(); i++) {
        char letra = palabra[i];
        //Verifico si en el dicinario contengo indices repetidos, en daado caso se repetiran las letras
        if (contador.find(letra) != contador.end()) {
            //Agrego el indice al arreglo
            indicesRepetidos.push_back(i);
            return true;
        } else {
            contador[letra] = 1;

        }
    }

    return false;
}

//Retorna un boleano cuando es true; termino el do while, false continuo el ciclo
//Puedo acceder al valor de la variable play1->intentos i modificarlo con &intentos
//OJO EMPLEAR ESTO POR PUNTEROS
bool Verificar(map<int, char> dict, Juego* play1){
    string var;
    string tex_concat;
    //Formo una palabra de acuerdo a lo que voy llenando en el dicionario
    for (const auto& par : dict) {
        //accedo al value del diccionario
        tex_concat += par.second;
    }

    play1->intentos+=1;
    cout<< "\nIntentos: " << (play1->max - play1->intentos) << endl;

    //Caso donde se agota la cantidad de intentos
    if (play1->intentos == play1->max){
        if ( tex_concat == play1->palabra){
        cout << "Ha GANADO" << endl;
        return true;
        }

        else{
            //Ultima oportunidad del jugador
            cout << "Ultimo intento (ingrese toda la palabra): ";
            cin >> var;
            cout << endl;
            //Convierto cada letra a minuscula
            for (char &c:var){
                c = std::tolower(c);
            }
            //caso ganador, donde acierto la palabra
            if (var == play1->palabra){
                cout << "Ha GANADO" << endl;
                return true;
            }
            
            
        }
        
        cout << "GAME OVER, palabra correcta: " << play1->palabra;
        return true;
    } 

    if ( tex_concat == play1->palabra){
        cout << "Ha GANADO" << endl;
        return true;
    }

    return false;
}

//La siguiente funcion verifica si el caracter ingresado es una letra, de esa manera verifico que no se ingreso un numero
bool isLetra(char letra){
    //Verifica si se ingresa una letra y si el tamano del caracter es de logitud 1, no esta vacio
    if (isalpha(letra) && sizeof(letra) == 1) {
        return true;
    } 
    else  {
        if (sizeof(letra) > 1){
        cout << "Ingrese unicamente un caracter";
        return false;
        }
        else if (!isalpha(letra)){
        cout << "Debe ingresar una letra";
        return false;
        }
    
    }
    return false;
}


