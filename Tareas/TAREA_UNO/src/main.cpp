// Nombre del archivo: main.cpp
//
// Descripción: Este archivo realiza el llamado a las inicializar, adivinar, por otro lado tiene dos menus
//el primero se encarga de elegir un nivel de dificultad (por defecto 10 intentos), iniciar una partida,
//agregar una nueva palabra a un array pre inicializado, ver las palabras del array y salir, por ultimo,
//el ultimo menu seleciona los niveles de dificultad alterando la cantidad de intetnos establecida por defecto.
//
// Copyright (c) 2022 Jose Pablo Laurent Chaves
// Licencia: MIT
    
    #include <iostream>
    #include "Juego.hpp"
    #include "Funciones.hpp"
    #include <algorithm> 

    //Contenido de defines contenidos en 1, solo tiene valores numericos y se llaman atraves de variables
    enum Opciones {
        ELEGIR = 1,
        INICIAR,
        AGREGAR,
        VER,
        SALIR
    };
    //enum con niveles de dificultad, empezando por 1
    enum Niveles {
        FACIL = 1,
        INTERMEDIO ,
        DIFICIL  
    };
    /**
     * @brief Se realiza el llamado a funciones y contiene la logica del programa.
     * 
     * Esta funciones de inicializar y adivinar, contiene menus para la interacion del usuario.
     * 
     * 
     * @return 0 cuando el programa se ha terminado de ejecutar.
     */
    int main() {
        int opcion;
        Juego *ptr, play;
        //ptr apunta direccion memoria de play
        ptr = &play;
        //Array que contiene los niveles de dificultad del programa
        vector<int> program_memory;
        //array con palabras
        vector<string> words = {"perro", "gato", "casa", "arbol", "libro", "manzana", "rojo", "verde", "curso", "sol"};
        do {
            //Dejo la funcion inicializar en este punto para poder selecionar una palabra aleatoria
            //Estando fuera del do-while el programa se queda con una unica palabra y no varia
            inicializar(ptr, words);
            //En caso de que el array con los niveles de dificultad tenga un tamaño mayor a cero, es decir
            //No esta vacio
            //Agarro la ultima posicion del arreglo, cambiando el valor de max objeto tipo juego
            if(program_memory.size()>0){
                int ultimoValor = program_memory.back();
                //modifico el atributo maz del objeto tipo juego
                ptr->max = ultimoValor;
            }
            std::cout << "\nMenu:\n";
            std::cout << "1. Elegir la dificultad del juego\n";
            std::cout << "2. Iniciar el juego\n";
            std::cout << "3. Agregar palabras al arreglo de palabras que se escogen aleatoriamente\n";
            std::cout << "4. Ver diccionario de palabras\n";
            std::cout << "5. Salir del programa\n";
            std::cout << "Ingrese una opcion: ";
            std::cin >> opcion;
        
        //Variable que almacena una palabra introducida por el usuario
        string intro_palabra;
        //Pregunta sobre los valores del enum
        switch (opcion) {

            case ELEGIR:
                int level;
                //Eligo el nivel de dificultad
                std::cout << "1. Facil\n";
                std::cout << "2. Intermedio\n";
                std::cout << "3. Dificil\n";
                std::cout << "Ingrese una opcion: ";
                std::cin >> level;

                switch (level){
                case FACIL:
                    ptr->max =7;
                    std::cout << "Intentos maximos: " << play.max <<endl;
                    //guardo el nivel de dificultad
                    program_memory.push_back(play.max);
                    break;
                case INTERMEDIO:
                    ptr->max =5;
                    std::cout << "Intentos maximos: " << play.max <<endl;
                    //guardo el nivel de dificultad
                    program_memory.push_back(play.max);
                    break;
                case DIFICIL:
                    ptr->max =3;
                    std::cout << "Intentos maximos: " << play.max <<endl;
                    //guardo el nivel de dificultad
                    program_memory.push_back(play.max);
                    break;
                default:
                    std::cout << "Opcion no valida\n";
                    break;
                }

                break;

            case INICIAR:
                std::cout << "Intentos maximos: " << ptr->max <<endl;
                std::cout << "Ingrese una palabra: " <<endl;
                //Imprimo la palabra en guiones
                for (int i = 0; i < play.palabra.size(); i++){
                    cout << "_\t";
                }
                adivinar(&play);
                break;

            case AGREGAR:
                std::cout << "Ingrese una palabra: ";
                std::cin >> intro_palabra;
                stdd:cout << endl;
                //Pregunto por la extension del array, el el struct hay un array qe contiene todas las letras
                //De la palabra y es de longitud 15
                if(intro_palabra.size()>0 && intro_palabra.size()<=15){
                //Usando std::transform junto con std::tolower para convertir a minúsculas
                transform(intro_palabra.begin(), intro_palabra.end(), intro_palabra.begin(),[](unsigned char c) { return tolower(c); });
                cout << intro_palabra << endl;

                //Inserto palabra en el array
                words.push_back(intro_palabra);
                cout << "La palabra: " << intro_palabra << " ha sido agregada exitosamente";
                //}
                //else{cout << "La palabra NO debe contener caracteres en espanol" << endl;}
                
                }
                else{
                    cout<< "Debe ingresar al menos un caracter";
                }
                break;

            case VER:
                // Imprimir dicionario
                //itero sobra cada uno de los elementos
                cout << "{";
                for (int i = 0; i < words.size(); ++i) {
                    if(i==(words.size()-1)){cout <<  words[i];}
                    else{cout <<  words[i] << ",";}
                    
                }
                cout << "}"<< endl;
                break;
            case SALIR:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no valida\n";
                break;
            }

        } while(opcion != SALIR);

        return 0;
    }





