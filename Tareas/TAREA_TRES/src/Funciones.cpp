/**
 * @file Funciones.cpp
 * @brief Archivo con la logica de las funciones, funciones de agregar, eliminar e imprimir contactos, entre otras.
 * 
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */

#include "Funciones.hpp"

void agregarContactos(Node* nodo1, unordered_map<Contacto*, Node*> &hashTable,
 vector<tuple<Node*, int>> &nodeDir, vector<Contacto*> &contactoDir, int &count){

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
            cout << "Contacto nuevo..."<< endl;
            //Recorro todo el string de number para ver si esta compuesto de numeros enteros
            if (all_of(number.begin(), number.end(), ::isdigit)){
                cout << "telefono correcto..."<< endl;
                //elimino todos los espacios en blanco del numero
                number.erase(remove_if(number.begin(), number.end(), ::isspace), number.end());
                //Reservo espacio de memoria de un puntero de tipo contacto
                //Contacto* ptrContacto = (Contacto*) malloc(sizeof(Contacto));
                Contacto* ptrContacto = new Contacto;
                //Asigno al puntero tipo contacto el contenido de las variables name y number
                 ptrContacto->nombre.assign(name);
                 ptrContacto->telefono.assign(number);
                 //Guardo en la memoria del celular el la direcion de memoria del nuevo contacto
                contactoDir.push_back(ptrContacto);
                cout << "Edito puntero de contactos..."<< endl;
                //Cuando la tabla hash esta vacia
                if (nodeDir.size() <= 0){

                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = ptrContacto->nombre;
                    nodo1->number = ptrContacto->telefono;
                    //el primer elemento punta a nullptr para indicar que ya termine la lista
                    nodo1->last = nullptr;
                    //nodeDir.push_back(nodo1);
                    nodeDir.push_back(make_tuple(nodo1,count));

                }//En este caso ya tengo al menos un elemento guardado en la lista enlazada
                else{
                    
                    //Creo un puntero de tipo nodo, asigno un bloque de memoria para un objeto de tipo nodo
                    nodo1 = new Node;
                    nodo1->name = ptrContacto->nombre;
                    nodo1->number = ptrContacto->telefono;
                    //Nodos distintos al primer elemento, apuntan al nodo anterior de la lista
                     nodo1->last = get<0>(nodeDir.back());
                    //nodo1->last = nodeDir.back();
                    //nodeDir.push_back(nodo1);
                    nodeDir.push_back(make_tuple(nodo1,count));
                }
                

                //Para la direccion de memoria del onjeto contacto le asigno un value de la direccion de 
                //memoria del nodo
                hashTable[ptrContacto] = nodo1;
                //Incremento en una la posicion de la memooria del nodo
                count += 1;
                cout << "Contacto guardado satisfactoriamente en memoria del celular y en almacenamiento cloud" << endl;

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

void eliminarContacto(unordered_map<Contacto*, Node*> &hashTable, vector<Contacto*> &contactoDir, vector<tuple<Node*, int>> &nodeDir){
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
        if (contactoExistHashTable(name, hashTable) || contactoExistMemoInterna(name, contactoDir)){
            cout << "Se ha encontrado informacion del contacto en la memoria interna || en el  almacenamiento-cloud." << endl;
            //Menu principal
            int opcion;
            string opcion2;
            cout << "\nEliminar Memoria:\n";
            cout << "1. Eliminar memoria del celular\n";
            cout << "2. Eliminar en la memoria del almacenamiento-cloud.\n";
            cout << "3. Salir del programa\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion2;

            //Recorro todo el contenido del string buscando que sea un entero y una opcion valida
            if(all_of(opcion2.begin(), opcion2.end(), ::isdigit) && (opcion2 == "1" || opcion2 == "2" || opcion2 == "3")){
                //Convierto el string a int
                opcion = stoi(opcion2);
                switch (opcion) {
            
            //Caso donde elimino memoria del celular
            //Debo eliminar bloque memoria Contacto con free
            //eliminar del vector contactoDir el item correspondiente a la memoria
            case ELIMINAR1:{
                //Si el el bloque de memoria ya fue eliminado, flag se mantiene como false
                bool flagMemoInterna = false;
                //Recorro todo el contenido del vector, buscando una direccion de memoria que almacene un nombre
                for (auto it = contactoDir.begin(); it != contactoDir.end(); ++it) {
                    //Caso donde la memoria almacena un nombre igual al ingresado
                    if ((*it)->nombre == name) {
                        flagMemoInterna = true;
                        //Liberar memoria del objeto contacto
                        //free(*it);
                        cout << "Memoria antes de eliminar: " << *it << endl;
                        delete  *it;
                        *it = nullptr;
                        cout << "Memoria despues de eliminar: " << *it << endl;
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
                //False se mantiene como false si la informacion ya fue eliminada de la tabla hash
                bool flagCloud = false;
                //Recorro toda la tabla hash
                for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
                    //Memoria del objeto tipo contacto
                    // if (it->first->nombre == name)
                    //En caso de que el nodo contenga un nombre igual al nombre ingresado por el usuario
                    if (it->second->name == name) {
                        flagCloud = true;
                        //Liberar memoria del objeto contacto
                        //free(it->first);
                        //debo ordenar la lista enlazada
                        sortLinkeList(it->second, nodeDir);
                        //Liberar memoria del objeto nodo
                        cout << "Memoria antes de eliminar: " << it->second << endl;
                        delete it->second;
                        it->second = nullptr;
                        cout << "Memoria despues de eliminar: " << it->second << endl;
                        //Eliminar el elemento del hashtable
                        hashTable.erase(it);
                        
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
                cout << "Opcion no valida\n";
                break;
            }
        }else {
            cout << "Se ingreso una opcion no valida" << endl;
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
        //El contacto existe si el nodo contiene infrmación sobre el nombre buscado
        if (nombres.second->name == name){
            nameUnico = true;
            break;
        }
        //Caso de que se eliminara la memoria interna
        //la direccion de memoria entraría como nullptr
        //else if (nombres.first == nullptr){
            //if (nombres.second->name == name){
              //  nameUnico = true;
            //    break;
          //  }
            
        //}
        
    }
    return nameUnico;

};

bool contactoExistMemoInterna( string name,  vector<Contacto*> contactoDir){
    // Verificar si el nombre es único
    bool nameUnico = false;
        for (const auto& contactoPtr : contactoDir) {
            //El contacto eiste si el objeto de tipo contacto almacena el bloque buscado
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
            cout << "Key (Contacto): "<< endl;
            cout << "-Nombre: " << (nombres.second)->name  << endl;
            cout << "-Telefono: " << (nombres.second)->number << endl;
            cout << "  Value (Nodo): "<< endl;
            cout << "   -Nombre: " << (nombres.second)->name << endl;
            cout << "   -Telefono: " << (nombres.second)->number << endl;
            cout << "   -Direccion actual: " << (nombres.second) << endl;
            cout << "   -Direccion a la que apunta: " << (nombres.second)->last << endl;
            // Imprimir otros miembros de Node si es necesario
            
        }
    }else{
        cout << "Almacenamiento-cloud vacio" << endl;
    }


};

void bubbleSort(vector<Contacto*> &arr) {
    int n = arr.size();
    bool intercambio;
    do {
        intercambio = false;
        for (int i = 1; i < n; i++) {
            //Elimino espacios en blanco de los nombres antes de comparar
            string nombre1 = arr[i - 1]->nombre;
            nombre1.erase(remove_if(nombre1.begin(), nombre1.end(), ::isspace), nombre1.end());

            string nombre2 = arr[i]->nombre;
            nombre2.erase(remove_if(nombre2.begin(), nombre2.end(), ::isspace), nombre2.end());

            //Comparo los nombres y intercambiar si están en el orden incorrecto
            if (nombre1 > nombre2) {
                //Intercambio los elementos
                Contacto* temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                intercambio = true;
            }
        }
        n--;
    } while (intercambio);
}


void mostrar(vector<Contacto*> contactoDir){
    cout << "Contactos almacenados en la memoria interna" << endl;
    //Vector con las direcciones de memoria de los objetos tipo contacto
    //convertir name a minuscula y quitar espacios en blanco
    if (contactoDir.size() > 0 ){
        bubbleSort(contactoDir);
        for (const auto& contacto : contactoDir) {
            cout << "Nombre: " << contacto->nombre << " - Telefono: " << contacto->telefono << endl;
        }
    }
    else{
        cout << "No hay datos almacenados internamente" << endl;
    }
    


};


void sortLinkeList(const Node* nodoAEliminar, vector<tuple<Node*, int>> &nodeDir){
    int count = 0;
    //Caso donde tengo un unico elemento en el vector
    if (nodeDir.size() <= 1){

        //Elimo primer elemento del vector
        nodeDir.erase(nodeDir.begin() + 0);
        cout << "Elimnio unico Nodo de la lista" << endl;
        //me salgo de la funcion
        return;

    }//Caso donde tengo al menos 2 elementos en el vector
    else {
            for (int i = 0; i < nodeDir.size(); i++){
                if (nodoAEliminar == get<0>(nodeDir[i])){
                    break;
                }
                count += 1;   
            }
        }

    //Caso donde elimino el primer elemento de la lista, lista posee al menos 2 nodos
    if (count == 0){
        cout << "Elimino primer nodo de la lista" << endl;
        //Node *nodoPosterior = get<0>(nodeDir[count + 1]);
        //nodoPosterior->last = nullptr;
        //Nodo que le sigue al nodoa eliminado apunta a nullptr
        get<0>(nodeDir[count + 1])->last = nullptr;
        nodeDir.erase(nodeDir.begin() + 0);

    }
    //Caso donde el nodo se encuentra en el medio de la lista
    else if (count > 0 && count <  nodeDir.size()-1){
        //Agarro el nodo nodo siguiente al que voy a eliminar
        //Node *nodoPosterior = get<0>(nodeDir[count + 1]);
        //Nodo apuntara a la direccion de memoria del nodo anterior al que voy a eliminar
        cout << "Elimino nodo intermedio de la lista" << endl;
        //El nodo que le sigue al nodo eliminado, apunta al nodo anterior
        get<0>(nodeDir[count + 1])->last = get<0>(nodeDir[count-1]);
        nodeDir.erase(nodeDir.begin() + count);
        //Nodo anterior de conserva igual, solo se modifica el nodo posterior
    }
    //Caso donde elimino ultimo nodo de la lista
    else if (count == nodeDir.size()-1){
        //En este caso no es necesario que el ultimo elemento de la lista se vaya a ajustar
        cout << "Elimino ultimo nodo de la lista" << endl;
        nodeDir.erase(nodeDir.begin() + count);
    }
    else {
         cout << "Ocurrio una particularidad" << endl;
    }
    
};