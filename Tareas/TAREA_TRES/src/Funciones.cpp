#include "Funciones.hpp"

void agregarContactos(Node* nodo1, unordered_map<Contacto*, Node*> &hashTable, vector<Node*> &nodeDir,
 vector<Contacto*> &contactoDir){

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
        
        //VERIFICAR ESTO DEBO HACER CASO TABLA HASH Y VECTOR DE CONTACTOS
        if (!contactoExistHashTable(name, hashTable) && !contactoExistMemoInterna(name, contactoDir)){
            
            //Recorro todo el string de number para ver si esta compuesto de numeros enteros
            if (all_of(number.begin(), number.end(), ::isdigit)){
                
                //elimino todos los espacios en blanco del numero
                number.erase(remove_if(number.begin(), number.end(), ::isspace), number.end());
                //Reservo espacio de memoria de un puntero de tipo contacto
                Contacto* ptrContacto = (Contacto*) malloc(sizeof(Contacto));
 
                //Asigno al puntero tipo contacto el contenido de las variables name y number
                 ptrContacto->nombre = name;
                 ptrContacto->telefono= number;

                 //Guardo en la memoria del celular el la direcion de memoria del nuevo contacto
                contactoDir.push_back(ptrContacto);

                //Cuando la tabla hash esta vacia
                if (nodeDir.size() <= 0){

                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = ptrContacto->nombre;
                    nodo1->number = ptrContacto->telefono;
                    //el primer elemento punta a nullptr para indicar que ya termine la lista
                    nodo1->last = nullptr;
                    nodeDir.push_back(nodo1);

                }//En este caso ya tengo al menos un elemento guardado en la lista enlazada
                else{
                    
                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = ptrContacto->nombre;
                    nodo1->number = ptrContacto->telefono;
                    //Nodos distintos al primer elemento, apuntan al nodo anterior de la lista
                    nodo1->last = nodeDir.back();
                    nodeDir.push_back(nodo1);

                }
                

                //Para la direccion de memoria del onjeto contacto le asigno un value de la direccion de 
                //memoria del nodo
                hashTable[ptrContacto] = nodo1;

                cout << "Contacto guardado staisfactoriamente en   memoria del celular y en almacenamiento cloud" << endl;

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

void eliminarContacto(unordered_map<Contacto*, Node*> &hashTable, vector<Contacto*> &contactoDir){
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
        //Debo hacer un caso donde pregunte donde pregunte por contacto == nullptr y nodo != nullptr
        //en ese ultimo comparo el nombre con el guardado en el nodo
        if (contactoExistHashTable(name, hashTable) || contactoExistMemoInterna(name, contactoDir)){
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
            //Debo eliminar bloque memoria Contacto con free
            //eliminar del vector contactoDir el item correspondiente a la memoria
            case ELIMINAR1:{
                bool flagMemoInterna = false;
                for (auto it = contactoDir.begin(); it != contactoDir.end(); ++it) {
                    if ((*it)->nombre == name) {
                        flagMemoInterna = true;
                        // Liberar memoria del objeto contacto
                        free(*it);  
                        //*it = nullptr;
                        // Eliminar el elemento del vector
                        contactoDir.erase(it);
                        break;
                    }
                }
                //Caso de haber liberado bloques de memoria
                if (flagMemoInterna){
                     cout << "Contacto eliminado de memoria interna EXITOSAMENTE" << endl;

                }else{
                    cout << "Contacto YA fue eliminado del celular" << endl;
                }
               
            
            }
                break;
            //Caso donde elimino memoria del almacenamiento - cloud    
            case ELIMINAR2:{

                bool flagCloud = false;
                for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
                    //Memoria del objeto tipo contacto
                    if (it->first->nombre == name) {
                        flagCloud = true;
                        free(it->first);  // Liberar memoria
                        //it->first = nullptr;
                        delete it->second;  // Liberar memoria
                        hashTable.erase(it);  // Eliminar el elemento del unordered_map
                        break;
                    }
                }

                if (flagCloud){
                    cout << "Contacto eliminado del almacenamiento-cloud EXITOSAMENTE" << endl;

                }else{
                    cout << "Contacto YA fue eliminado del cloud" << endl;
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

bool contactoExistHashTable( string name,  unordered_map<Contacto*, Node*> hashTable){
    // Verificar si el nombres es unico
    bool nameUnico = false;
    //iter sobre cada uno de los key:name del hashTable
    for (const auto& nombres : hashTable){
        //desreferencio el contenido de la direccion de memoria y lo comparo con el string
        //caso donde encuentro una coincidencia
        if (nombres.first->nombre == name){
            nameUnico = true;
            break;
        }
    }
    return nameUnico;

};

bool contactoExistMemoInterna( string name,  vector<Contacto*> contactoDir){
    // Verificar si el nombre es único
    bool nameUnico = false;
        for (const auto& contactoPtr : contactoDir) {
            if (contactoPtr->nombre == name) {
                // Se encontró el nombre
                nameUnico = true;
                break;
            }
        }
    return nameUnico;
};

void imprimir(unordered_map<Contacto*, Node*> hashTable){
    if(hashTable.size() > 0){
        // Imprimir el contenido de hashTable
        for (const auto& nombres : hashTable) {
            cout << "Key: "<< endl;
            cout << "Nombre: " << nombres.first->nombre << endl;
            cout << "Numero: " << nombres.first->telefono << endl;
            cout << "  Value: "<< endl;
            cout << "   -Nombre: " << (nombres.second)->name << endl;
            cout << "   -Numero: " << (nombres.second)->number << endl;
            cout << "   -Direccion apunta: " << (nombres.second)->last << endl;
            cout << "   -Direccion actual: " << (nombres.second) << endl;
            // Imprimir otros miembros de Node si es necesario
            
        }
    }else{
        cout << "HashTable vacia" << endl;
    }


};