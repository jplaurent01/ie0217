// Nombre del archivo: funciones.cpp
//
// Descripción: Este archivo contiene la logica de las funciones inicializar, adivinar, isLetra y verificar
//
// Copyright (c) 2022 Jose Pablo Laurent Chaves
// Licencia: MIT
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

/**
 * @brief Inicializa un objeto Juego con un array de strings.
 * 
 * Esta función inicializa un objeto Juego con un array de strings, incializa por defecto en 10 la cantidad 
 * maxima de intentos, escoge una palabra aleatoria del array para inicializar la palabra del struct.
 * 
 * @param play1 Puntero al objeto Juego que se inicializará.
 * @param array Vector de strings que se utilizará para inicializar objeto de tipo Juego.
 */

void inicializar(Juego* play1, vector<string> array){

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
/**
 * @brief Se llama a esta funcion cuando se pretende iniciar el juego y adivinar una palabra.
 * 
 * Esta funcion permite iniciar el juego, recibe un objeto de tipo juego ya inicializado con una palabra 
 * aleatoria, cantidad maxima de intentos, durante su ejecucion se altera el atributos intentos del objeto
 * Juego.
 * 
 * @param play1  Puntero al objeto Juego.
 */
void adivinar(Juego* play1){
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


        //anado robustez, debido a problema de insertar en el dicionario letras incorrectas
        // y letras repetidas mal
        //Nuevo dicionario, sirve de filtro
        std::map<int, char> nuevoDict;
        //se utiliza para acceder a cada par clave-valor en un std::map de forma segura
        // y eficiente, sin permitir que el contenido de los pares se modifique accidentalmente
        // durante la iteración.
        for (const auto& par : dict) {
            //se cumple si el caracter par.second está presente en la cadena palabra,
            // es decir, si find() devuelve un valor diferente a std::string::npos.
            if (play1->palabra.find(par.second) != std::string::npos) {
                //inserto en el nuevo dicionario
                nuevoDict.insert(par);
            }
        }
        //Actualizo el dicionario con el filtro
        dict = nuevoDict;

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
             std ::cout << "\nIntento Acertado" << std ::endl;   
        }

        //Se ejecuta el else cuando no hay match
        else{
            std ::cout << "Intento Fallido" << std ::endl;
        }
        //itera hasta la cantidad maxima de ejecuciones del programa
        //count += 1; 
        }
        
        
    } while ( !verificar(dict, play1));
    
}

//Retorna un boleano con las posiciones de la letras repetidas en caso de haber
/**
 * @brief Verifica si una palabra tiene letras repetidas.
 * 
 * Esta función verifica si una palabra tiene letras repetidas.
 * 
 * @param palabra Parametro por referencia de la palabra a verificar, esta no se puede modificar por const.
 * @return true si la palabra tiene letras repetidas, false en caso contrario.
 */
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
/**
 * @brief Funcion que chequea si se ha encontrado la palabra o se han agotado los intentos.
 * 
 * Esta funcion verifica si se ha encontrado la palabra o se han agotado los intentos,
 * y actualiza la variable de intentos.
 * 
 * @param dict Diccionario que contiene las letras adivinadas.
 * @param play1 Puntero al objeto Juego, este puntero se modifica con la cantidad de intentos.
 * @return true si se ha encontrado la palabra o se han agotado los intentos, false en caso contrario.
 */
bool verificar(map<int, char> dict, Juego* play1){
    string var;
    string tex_concat;
    //Formo una palabra de acuerdo a lo que voy llenando en el dicionario
    for (const auto& par : dict) {
        //accedo al value del diccionario
        tex_concat += par.second;
    }
    //Puede que se agrege una o más letras de más sobre todo si son letras repetidas en el dicionario
    //y que la palabra ingresada ya se haya completado, por tal razon el juego no termina, por eso se 
    //agregan las siguientes lineas de codigo para solventar dicho problema.
    //en este escenario ya se ingreso la palabra correcta, pero por defecto esta palabra contiene algun caracter
    //erroneo, ejemplo rojoo, se ingresan dos o al final y la palabra correcta nada más tiene una
    if (tex_concat.size() > play1->palabra.size()){
        tex_concat = play1->palabra;
    }
    
    play1->intentos+=1;
    cout<< "\nIntentos: " << (play1->max - play1->intentos) << endl;

    //Caso donde se acierta toda la palabra
    if ( tex_concat == play1->palabra){
    cout << "Ha GANADO" << endl;
    return true;
    }

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

    return false;
}

//La siguiente funcion verifica si el caracter ingresado es una letra, de esa manera verifico que no se
// ingreso un numero

/**
 * @brief Determina si un caracter es una letra o no.
 * 
 * Esta función determina si un caracter es una letra o no.
 * 
 * @param letra El caracter a verificar.
 * @return true si el caracter es una letra, false en caso contrario.
 */
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


