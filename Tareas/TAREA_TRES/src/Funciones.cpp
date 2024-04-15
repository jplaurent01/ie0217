#include "Funciones.hpp"

void agregarContactos(Node* nodo1, unordered_map<string*, unordered_map<string*, Node*>> &hashTable,  vector<Node*> &nodeDir){

    //Variables para el cin
    string name;
    string number;

    cout << "Ingrese el nombre del contacto" << endl;
    //getline abarca espacios del strign ejemplo costa rica, agarra toda el string
    //si no agrego esto tengo un error con los cin
    cin.ignore();
    //desreferencio el puntero para acceder al contenido de la direccion de memoria
    getline(cin, name);

    cout << "Ingrese el numero del contacto" << endl;
    //desreferencio el puntero para acceder al contenido de la direccion de memoria
    getline(cin, number);

    //Verifico que usuario no ingrese entradas vacias, debo verificar que el  usuario no agrege informacion 
    //repetida
    if (!name.empty() && !number.empty()){
        cout << "Verifico que los datos no esten vacios" << endl;
        if (!contactoExist(name, hashTable)){
            cout << "Verifico que el contacto no este en la tabla hash" << endl;
            //Recorro todo el string de number para ver si esta compuesto de numeros enteros
            if (all_of(number.begin(), number.end(), ::isdigit)){
                cout << "Verifico el el numero sea numero" << endl;
                //elimino todos los espacios en blanco del numero
                number.erase(remove_if(number.begin(), number.end(), ::isspace), number.end());
                //Reservo espacio de memoria de tipo string
                cout << "Reservo memoria" << endl;
                string* ptrName = (string*) malloc(sizeof(string));
                string* ptrNumber = (string*) malloc(sizeof(string));

                //Asigno a los punteros el contenido de las variables name y number
                *ptrName = name;
                *ptrNumber = number;
                cout << "Verifico tamano del vector de direciones" << endl;
                if (nodeDir.size() <= 0){

                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = *ptrName;
                    nodo1->number = *ptrNumber;
                    //el primer elemento punta a nullptr para indicar que ya termine la lista
                    nodo1->last = nullptr;
                    nodeDir.push_back(nodo1);

                }//En este caso ya tengo al menos un elemento guardado en la lista enlazada
                else{
                    
                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = *ptrName;
                    nodo1->number = *ptrNumber;
                    //Nodos distintos al primer elemento, apuntan al nodo anterior de la lista
                    nodo1->last = nodeDir.back();
                    nodeDir.push_back(nodo1);

                }
                

                //Accedo a la direccion de memoria del key, luego accedo al 2do key de la direcion de memoria de number
                //Finalmente para esas 2 keys inserto la direccioón de memoria del nodo
                hashTable[ptrName][ptrNumber] = nodo1;
                //free(name);
                //free(number);
                cout << "Contacto guardado" << endl;

            }else{
                cout << "Debe ingresar un numero entero sin espacios"<< endl;
            }

            
        }else{
            cout << "Se encontro una cuenta asociada a este nombre" << endl;
        }
        
    }else{
        cout << "Se ha detectado un espacio vacio" << endl;
    }
    

    
};

void eliminarContacto( unordered_map<string*, unordered_map<string*, Node*>> &hashTable){
    //Variables para el cin
    string name;

    cout << "Ingrese el nombre del contacto a eliminar" << endl;
    //getline abarca espacios del strign ejemplo costa rica, agarra toda el string
    //si no agrego esto tengo un error con los cin
    cin.ignore();
    //desreferencio el puntero para acceder al contenido de la direccion de memoria
    getline(cin, name);

    if (!name.empty()){
        //Caso de existir el contacto, debo verificar si el cantacto existe en el celular o en el cloud
        if (contactoExist(name, hashTable)){
            //Menu principal
            int opcion;
            cout << "\nEliminar Memoria:\n";
            cout << "1. Eliminar memoria del celular\n";
            cout << "2. Eliminar en la memoria del almacenamiento - cloud.\n";
            cout << "3. Salir del programa\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion;
        
            switch (opcion) {
            
            //Caso donde elimino memoria del celular
            //Aqui se le debe hacer un free al malloc de los bloques de memoria de punteros tipo strings
            case ELIMINAR1:{
            
            for (const auto& nombres : hashTable){
                //desreferencio el contenido de la direccion de memoria y lo comparo con el string
                //caso donde encuentro una coincidencia
                if (*nombres.first == name){
                    //Libero el bloque de memora correspondiente al nombre para este contacto en particular
                    free(nombres.first);
                    
                    for (const auto& numeros : nombres.second) {
                        //Libero el bloque de memora correspondiente al numeros para este contacto en particular
                        free(numeros.first);
                    }
                }
            }
        }
                break;
            //Caso donde elimino memoria del almacenamiento - cloud    
            case ELIMINAR2:{

                for (const auto& nombres : hashTable){
                //desreferencio el contenido de la direccion de memoria y lo comparo con el string
                //caso donde encuentro una coincidencia
                if (*nombres.first == name){
                    //Libero el bloque de memora correspondiente al nombre para este contacto en particular
                    free(nombres.first);
                    
                    for (const auto& numeros : nombres.second) {
                        //Libero el bloque de memora correspondiente al numeros para este contacto en particular
                        free(numeros.first);
                        //Elimino el bloque de memoria del nodo correspondiente
                        delete numeros.second;
                    }
                }
             }
             //Elimino el hashTable con el key del punteror de tipo de string que apunta al nombre del contacto
              for (const auto& nombres : hashTable){
                 if (*nombres.first == name){
                    hashTable.erase(nombres.first);
                    break;
                 }
              }

            }
                break;

            //salgo del 2do menu
            case SALIR2:
                cout << "Saliendo...\n";
                break;

            //Caso por defecto   
            default:
                cout << "Opción no valida\n";
                break;
            }

        }else{
             cout <<"Contacto NO encontrado" << endl;
        }
        
    }else{
        cout <<"Se detecto un espacio vacio" << endl;
    }

    

};

bool contactoExist(string name, unordered_map<string*, unordered_map<string*, Node*>> hashTable){
    // Verificar si el ID es único
    bool nameUnico = false;
    //iter sobre cada uno de los key:name del hashTable
    for (const auto& nombres : hashTable){
        //desreferencio el contenido de la direccion de memoria y lo comparo con el string
        //caso donde encuentro una coincidencia
        if (*nombres.first == name){
            nameUnico = true;
            break;
        }
    }
    return nameUnico;

};

void imprimir(unordered_map<string*, unordered_map<string*, Node*>> hashTable){
    if(hashTable.size() > 0){
        // Imprimir el contenido de hashTable
        for (const auto& nombres : hashTable) {
            cout << "Key1: " << *(nombres.first) << endl;
            for (const auto& innerEntry : nombres.second) {
                cout << "  Key2: " << *(innerEntry.first) << endl;
                cout << "  Nodo: "<< endl;
                cout << "   -Nombre: " << (innerEntry.second)->name << endl;
                cout << "   -Numero: " << (innerEntry.second)->number << endl;
                cout << "   -Direccion apunta: " << (innerEntry.second)->last << endl;
                cout << "   -Direccion actual: " << (innerEntry.second) << endl;
                // Imprimir otros miembros de Node si es necesario
            }
        }
    }else{
        cout << "HashTable vacia" << endl;
    }


};