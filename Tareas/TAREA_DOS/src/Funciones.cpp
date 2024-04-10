/**
 * @file Funciones.cpp
 * @brief Archivo que contiene el cuerpo de las funciones.
 *
 * @author Jose Pablo Laurent Chaves
 * @date 2024
 * @version 1.0
 * @license MIT
 */

#include "Funciones.hpp"

 /**
 * @brief Funcion edita el contenido del vector paisesContinente para insertar su respectivo constructor con la informacion del diccionario
 * 
 * @param id Id del pais.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @param paisesContinente Vector que alberga el constructor con el que posterior mente se  comparan 2 paises.
 */
void retornarPais(string id, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,
 vector<Pais> &paisesContinente){
        
        //itero sobre continentes
        for (const auto& continente : instrucionesPlaneta) {
        //itero sobre paises
        for (const auto& pais : continente.second) {
            //Caso de encontrar id selecionado
            if (pais.second[3] == id) {
                //Agrego contenido al vector, es decir lo edito
                paisesContinente.push_back(Pais(pais.first, stoi(pais.second[3]), stoi(pais.second[4])));
                break; 
            }
        }
    }
}

 /**
 * @brief Funcion para comparar paises.
 * 
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void compararPaises(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta){
    //Imprimo contenido del diccionario:
    for (const auto& continente : instrucionesPlaneta) {
    //Imprimo continentes
    cout << "\n"<< continente.first << ":\n";
    for (const auto& pais : continente.second) {
        //Imprimo paises e informacion del indice
        cout << "  " << pais.first << ": id: " << pais.second[3] << "\n";
    }
    cout << "\n";
    }

    //Pregunto al usuario por IDs, estos no deben ser repetidos y deben existir
    cout << "Ingrese el ID del 1er pais: ";
    string idOne;
    string idTwo;
    //utiliza como cin el contenido del string idToDelete
    cin >> idOne;
    cout << "Ingrese el ID del 2do pais: ";
    cin >> idTwo;
    // Verificar que no se digito un string vacio y que esete sea un numero
    if (!idOne.empty() && std::all_of(idOne.begin(), idOne.end(), ::isdigit)
    && !idTwo.empty() && std::all_of(idTwo.begin(), idTwo.end(), ::isdigit)) {
        //verifco que los 2 ID existan
        if (idIsUnique(idOne,instrucionesPlaneta) == false && idIsUnique(idTwo,instrucionesPlaneta) == false){
            if (idOne != idTwo){
            //Vctores de tipo Pais
            vector<Pais> paisesContinente1;
            vector<Pais> paisesContinente2;

            //Funciones de tipo void que editan contenido de los vecotres de tipo Pais
            //inicializo los constructores dentro del vector
            //estos vectores solo poseen un unico elemento
            retornarPais(idOne, instrucionesPlaneta, paisesContinente1);
            retornarPais(idTwo, instrucionesPlaneta, paisesContinente2);
            
            //Metodo publico que hace el llamado al metodo privado de sobre carga operadores ==
            paisesContinente1[0].realizarComparacion(paisesContinente1[0], paisesContinente2[0]);
            }else {
                cout << "ID deben ser distintos" << endl;
            }
            
        }else {
          cout << "No se encontro uno de los IDs" << endl;  
        }

    }else {
        cout << "Se debe ingresar un numero" << endl;
    }
}

 /**
 * @brief Elimina un país del diccionario.
 * 
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void eliminarId(unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta){

    //Imprimo contenido del diccionario:
    for (const auto& continente : instrucionesPlaneta) {
    //Muestro continente
    cout << "\n"<< continente.first << ":\n";
    for (const auto& pais : continente.second) {
        //Muestro pais e indice
        cout << "  " << pais.first << ": id: " << pais.second[3] << "\n";
    }
    cout << "\n";
    }

    //Pregunto al usuario por el id a eliminar, este debe existir
    cout << "Ingrese el ID del pais a eliminar: ";
    string idToDelete;
    //utiliza como cin el contenido del string idToDelete
    cin >> idToDelete;

    // Verificar que no se digito un string vacio y que esete sea un numero, recorro todo el contenido del
    //string buscando que sea numerico
    if (!idToDelete.empty() && std::all_of(idToDelete.begin(), idToDelete.end(), ::isdigit)) {
        //Caso donde encuentro el id, ya que es repetido
        if (idIsUnique(idToDelete,instrucionesPlaneta) == false){
         //se convierte el string a un entero
        int id = std::stoi(idToDelete);

        // Buscar y eliminar el pais con el ID dado
        //itero sobre cada uno de los continentes del dicionario
        for (auto& continente : instrucionesPlaneta) {
            //ciclo for que itera sobre los elementos del segundo dicionario anidado, es decir sobre los paises
            for (auto it = continente.second.begin(); it != continente.second.end(); ) {
                //si el dicionario cuyo key pais posee un value en la poscion 3 que corresponda el el idToDelete
                //procedo a eliminar
                if (it->second[3] == idToDelete) {
                    //elimino pais
                    cout <<it->first<<" EXITOSAMENTE eliminado."<<endl;
                    it = continente.second.erase(it);
                    
                } else {
                    //continuo buscando 
                    ++it;
                }
            }
        }
        } else {
            cout <<"El ID no se encuentra" << endl;
        }
        
    } else {
        std::cout << "Entrada invalida. Debe ingresar un ID numerico.\n";
    }
}

 /**
 * @brief Determina si el ID de un país está repetido.
 * 
 * @param num ID del país a verificar.
 * @param nombrePais Nombre del país.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @return true Si el ID está repetido.
 * @return false Si el ID no está repetido.
 */
bool idIsUnique(string num, string nombrePais,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta){
    // Verificar si el ID es único
    bool idUnico = true;
    //recorro el dicionario por continentes
    for (const auto& continente : instrucionesPlaneta) {
        //recorro la informacion de los paises
        for (const auto& pais : continente.second) {
            //Caso donde encontre un id repetido y nombre repetido
            if (pais.second[3] == num && pais.first != nombrePais) {
                idUnico = false;
                break;
            }
        }
        if (!idUnico) {
            break;
        }
    }
    return idUnico;
}

 /**
 * @brief Funcion determina se el id está repetido, Sobrecargo esta funcion.
 * 
 * @param num ID del país a verificar.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @return true Si el ID está repetido.
 * @return false Si el ID no está repetido.
 */
bool idIsUnique(string num,
unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta){
    // Verificar si el ID es único
    bool idUnico = true;
    //recorro el dicionario por continentes
    for (const auto& continente : instrucionesPlaneta) {
        //recorro la informacion de los paises
        for (const auto& pais : continente.second) {
            //Caso donde encontre un id repetido o nombre repetido
            if (pais.second[3] == num) {
                idUnico = false;
                break;
            }
        }
        if (!idUnico) {
            break;
        }
    }
    return idUnico;
}

//agrego un nuevo pais al diccionario
/**
 * @brief Agrega un nuevo país por continente al vector.
 * 
 * @param nombreContinente Nombre del continente.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void agregarInformacion(string nombreContinente, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta){
    //Variables de interaccion con el usuario
    string nombrePais;
    int id;
    string id0;
    int habitantes;
    string habitantes0;
    string input5G;
    bool tec5G = true;
    string inputAeropuerto;
    bool aeropuerto = true;
    string inputInvestigacion;
    bool investigacion;

    cout << "Ingrese el nombre del pais" << endl;
    cin >> nombrePais;
    //Verifico si el nombre no es nulo
    if (!nombrePais.empty()){
        cout << "Ingrese un numero primo (Pais 1er mundo) o  no primo (Pais en desarrollo), debe ser MAYOR a 1" << endl;
        cin >> id0;
        //Verifico si el id es un numero entero
        if (std::all_of(id0.begin(), id0.end(), ::isdigit)){
            id = stoi(id0);
            //chequeo si el numero es mayor a 1
            if (id > 1){
                //Chequeo si el id o el nombre son unicos
                if (idIsUnique(to_string(id), nombrePais, instrucionesPlaneta) == true){
                    //debo chequear si el numero es o no es primo
                    //caso numero primo, pais primer mundo
                    if (isPrimo(id) == true){
                       cout << "Ingrese un numero con la cantidad de habitantes" << endl;
                       cin >> habitantes0; 
                       //verifico que el se ingrese un numero 
                       if (std::all_of(habitantes0.begin(), habitantes0.end(), ::isdigit)){
                        habitantes = stoi(habitantes0);
                        if (habitantes > 1){
                            
                        //Debo preguntar por 5G, aeropuerto y centro de investigacion
                        cout << "El pais posee Tecnologia 5G (true/false)" << endl;
                        cin >> input5G;
                        if(!input5G.empty() && (input5G == "true"|| input5G == "false")){
                            if (input5G == "true"){
                                tec5G = true;
                            }else {
                                tec5G = false;
                            }
                            cout << "El pais posee Aeropuerto (true/false)" << endl;
                            cin >> inputAeropuerto;
                            if (!inputAeropuerto.empty() && (inputAeropuerto == "true" || inputAeropuerto == "false")){
                                if (inputAeropuerto == "true"){
                                    aeropuerto = true;
                                }else{
                                    aeropuerto = false;
                                }
                                cout << "El pais posee Centro de investigacion (true/false)" << endl;
                                cin >> inputInvestigacion;
                                if (!inputInvestigacion.empty() && (inputInvestigacion == "true" || inputInvestigacion == "false")){
                                    
                                    if (inputInvestigacion == "true"){
                                        investigacion = true;
                                    }else {
                                        investigacion = false;
                                    }
                                    instrucionesPlaneta[nombreContinente][nombrePais] = {boolToString(tec5G), boolToString(aeropuerto), boolToString(investigacion), to_string(id), to_string(habitantes)};
                                    cout << "Pais: "<< nombrePais <<" exitosamente creado" << endl;
                                }else {
                                    cout << "Opcion no valida";
                                }
                                
                                
                            }else{
                                cout << "Opcion invalida" << endl;
                            }
                            
                        }else{
                            cout << "Opcion invalida" << endl;
                        }

                        }else{
                            cout << "De ingresar una cantidad de habitantes mayor a 1" << endl;
                        }
                        
                       }
                       else{
                        cout << "Ingrese un numero de habitantes " << endl;
                       }
                       
                    }
                    //numero no primo, Pais en desarrollo
                    else{
                       cout << "Ingrese un numero con la cantidad de habitantes" << endl;
                       cin >> habitantes;
                       //verifico que el se ingrese un numero de habitantes mayor a 1
                       if (!cin.fail() && habitantes > 1){
                        //debo preguntar por el aeropuerto
                        cout << "El pais posee Aeropuerto (true/false)" << endl;
                        cin >> inputAeropuerto;
                        if (!inputAeropuerto.empty() && (inputAeropuerto == "true" || inputAeropuerto == "false")){
                            if (inputAeropuerto == "true"){
                                aeropuerto = true;
                            }else{
                                aeropuerto = false;
                            }
                            instrucionesPlaneta[nombreContinente][nombrePais] = {"false", boolToString(aeropuerto), "false", to_string(id), to_string(habitantes)};
                            cout << "Pais: "<< nombrePais <<" exitosamente creado" << endl;
                        }else{
                            cout << "Opcion no valida"<< endl;
                        }
                        
                       }
                       else{
                        cout << "Ingrese un numero de habitantes y que sea mayor a 1" << endl;
                       }
                    }
                    
                }
                else{
                    cout <<"Se ha detectado un caracter o nombre repetido"<< endl;
                }
            }else{
                cout <<"Ingrese un numero mayor a 1" << endl;
            }
        
        }
        else{
            cout << "Debe ingresar un numero entero" << endl;
        }

    }
    else{
        cout << "Debe ingresear un nombre";
    }
    
}
//convierto de booleano a string
 /**
 * @brief Convierte un booleano a string.
 * 
 * @param valor Valor bool a convertir.
 * @return std::string "true" si el valor es true, "false" si es false.
 */
string boolToString(bool valor) {
    //Dependiendo del contenido booleano de la variable valor, retorno un string de true o false
    return valor ? "true" : "false";
}

//Convierto de string a booleano
/**
 * @brief Convierte un string a bool.
 * 
 * @param str String a convertir.
 * @return true Si el string es "true".
 * @return false caso contrario.
 */
bool stringToBool(const string& str) {
    string lowerStr;
    // Convertir la cadena a minúsculas
    for (char c : str) {
        lowerStr += tolower(c);
    }
    if (lowerStr == "true") {
        return true;
    } else {
        return false;
    }
}

//Funcion que me filtra la informacion de acuerdo al continente:
/**
 * @brief Filtra la información de los países por continente.
 * 
 * @param keyWord Palabra clave de dicionario para filtrar.
 * @param cantidadPaises0 Cantidad de países filtrados.
 * @param primos0 Cantidad de países con id primo.
 * @param noPrimos0 Cantidad de países con id no primo.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 * @param paisesPrimerMundoContinente Vector de países de primer mundo del continente.
 * @param paisesEnDesarrolloContinente Vector de países en desarrollo del continente.
 */
void filterByContinent(string keyWord, int &cantidadPaises0, int &primos0, int &noPrimos0, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,  vector<PaisPrimerMundo> &paisesPrimerMundoContinente, vector<PaisEnDesarrollo> &paisesEnDesarrolloContinente){

    if (keyWord == "Oceania" || keyWord == "Asia" || keyWord == "Africa" || keyWord == "Europa" || keyWord == "America"){
        //Busco en el dicionario de acuerdo a la palabra clave, en relacion con el continente
        if (instrucionesPlaneta.find(keyWord) != instrucionesPlaneta.end()) {
            cantidadPaises0 = instrucionesPlaneta[keyWord].size();
            //itero sobre el dicionario de acuerdo al contienente selecionado
            for (const auto& par : instrucionesPlaneta[keyWord]) {
                //accedo al identificador unico par.second[indice], accedo a los valores del dicionario anidado
                //con esto puedo recolectar los valores del pais para generar objetos de tipo pais
                //convierto del indice en integer
                int id = std::stoi(par.second[3]);

                //Caso de encontrar pais desarrollado
                if (isPrimo(id)) {
                    //agrego contructor de paises de primer mundo
                    //Nombre, id, habitantes, 5g, aeropuerto, investigacion
                    paisesPrimerMundoContinente.push_back(PaisPrimerMundo(par.first, stoi(par.second[3]), stoi(par.second[4]), stringToBool(par.second[0]), stringToBool(par.second[1]), stringToBool(par.second[2])));
                    //cuento numeros primos
                    primos0++;
                } else {
                    //Nombre, id, habitantes, aeropuerto
                    paisesEnDesarrolloContinente.push_back(PaisEnDesarrollo(par.first, stoi(par.second[3]), stoi(par.second[4]), stringToBool(par.second[1])));
                    //cuento numeors no primos
                    noPrimos0++;
                }
            }

        } else {
            std::cout << "No se encontró el continente " << keyWord << std::endl;
        }
        
    }
    else{
        cout <<"OCURRIO EN ERROR EN keyWord"<<endl;
    }
}


//Funcion determina si el numero es o no es primo
/**
 * @brief Determina si un número es primo.
 * 
 * @param num Número a verificar.
 * @return true Si el número es primo.
 * @return false Si el número no es primo.
 */
bool isPrimo(int num){
    //caso menor a igual 1
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Imprime la información de un planeta y sus países.
 * 
 * @param tierra Objeto de tipo Planeta a imprimir.
 * @param instrucionesPlaneta Diccionario con instrucciones para crear países.
 */
void imprimirPlaneta(Planeta tierra, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta) {
    cout << "\nInformacion General: \n";
    cout << "Planeta posee " << tierra.number_continets <<" continentes: ";
    for(auto it = tierra.continets.begin(); it != tierra.continets.end(); ++it) {

    // Verifico si no he llegado al ultimo elemento del vector
    if (it != tierra.continets.end() - 1) {
        //chequeo si llegue al penultimo elemento del vector
        if(it != tierra.continets.end() - 2){
            // imprimo contenido del iterador
            cout << *it; 
            cout << ", ";
        }
        else{
            //imprimo elemento actual del iterado
            cout << *it; 
        }
        
    }else{
        //imprimo elemento actual del iterado
         cout <<" y "<<*it <<"."; 
        }
    }

     // Crear un nuevo vector para almacenar los 3 strings aleatorios
    
    // Usar un generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    //tmano entre 0 y tamano vector
    uniform_int_distribution<> distrib(0, tierra.continets.size() - 1);

    // del vector tierra.continets, genero un subvector de longitud 3 con 3 continentes aleatorios por donde 
    //pasa el avion
    while (tierra.selectedContinents.size() < 3) {
        //indice selecionado aleatoriamente
        int index = distrib(gen);
        //seleciono el continente
        string continent = tierra.continets[index];
        //verifico si ya llegue al ultimo elemento del vector.
        if (find(tierra.selectedContinents.begin(), tierra.selectedContinents.end(), continent) == tierra.selectedContinents.end()) {
            tierra.selectedContinents.push_back(continent);
        }
    }

    cout <<"\nDe estos continentes, el avion pasa por los siguientes: ";
    for(auto it = tierra.selectedContinents.begin(); it != tierra.selectedContinents.end(); ++it) {

    //Verifico si no he recorrido todo el contenido del vector
    if (it != tierra.selectedContinents.end() - 1) {
        //verifico si no he llegado al segundo elemento del vector
        if(it != tierra.selectedContinents.end() - 2){
            //Contenido actual del iterador
            cout << *it; 
            cout << ", "; 
        }
        else{
            cout << *it;
        }
        
    }else{
        //Imprimo el ultimo elemento del vector.
         cout <<" y "<<*it <<".\n";
        }
    }

    cout <<"\nInformacion sobre los paises: \n";
    //Objetos de continentes, se establece un total de 3 continentes por los cuales pasa el avion

    //varaibles con contenidos del filtro de acuerdo al continente:
    //Estas variables de modifican ya que sran parametros por referencia
    //se enviaran como variables originales.
    int cantidadPaises0 = 0, cantidadPaises1 = 0, cantidadPaises2 = 0;
    int primos0 = 0, noPrimos0 = 0;
    int primos1 = 0, noPrimos1 = 0;
    int primos2 = 0, noPrimos2 = 0;
    //Vector de constructores paises de primer mundo
    //estos vectores se llenaran con constructores de paisesPrimerMundoContinente
    //se ennviarán como parametros por referencia.
    vector<PaisPrimerMundo> paisesPrimerMundoContinente1;
    vector<PaisPrimerMundo> paisesPrimerMundoContinente2;
    vector<PaisPrimerMundo> paisesPrimerMundoContinente3;

    //Vector de constructores paises en desarrollo
    //estos vectores se llenaran con constructores de paisesEnDesarrolloContinente
    //se ennviarán como parametros por referencia.
    vector<PaisEnDesarrollo> paisesEnDesarrolloContinente1;
    vector<PaisEnDesarrollo> paisesEnDesarrolloContinente2;
    vector<PaisEnDesarrollo> paisesEnDesarrolloContinente3;

    //el siguiente llamado a las funciones tipo void pretende crear N vectores de tipo paisesEnDesarrollo y paisesPrimerMundo.
    //Caso para el 1er continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[0], cantidadPaises0, primos0, noPrimos0, instrucionesPlaneta, paisesPrimerMundoContinente1, paisesEnDesarrolloContinente1);
    //Caso para el 2do continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[1], cantidadPaises1, primos1, noPrimos1, instrucionesPlaneta, paisesPrimerMundoContinente2, paisesEnDesarrolloContinente2);
    //Caso para el 3er continente por donde pasa el avion.
    filterByContinent(tierra.selectedContinents[2], cantidadPaises2, primos2, noPrimos2, instrucionesPlaneta, paisesPrimerMundoContinente3, paisesEnDesarrolloContinente3);

    //se crean los tres objetos de los continentes por donde pasa el avion.
    //se establece que el avion pasa unicmente por3 continentes.
    Continentes continente1(tierra.selectedContinents[0], cantidadPaises0, noPrimos0, primos0);
    Continentes continente2(tierra.selectedContinents[1], cantidadPaises1, noPrimos1, primos1);
    Continentes continente3(tierra.selectedContinents[2], cantidadPaises1, noPrimos2, primos2);

    //Muestro la informacion de los continentes llamando a sus repectivos medotos de mostrarDetalles()
    continente1.mostrarDetalles();
    continente2.mostrarDetalles();
    continente3.mostrarDetalles();
    
    //Informacion paises de primer mundo, la idea es crear un vector de paises de 1er mundo y en desarrollo
    //el vector lo que guarda son los constructrores de los paises.
    cout <<"\nInformacion sobre los paises de primer mundo: \n";

    //Evaluo si el vector no esta vacio para imprimir
    if (paisesPrimerMundoContinente1.size() > 0){
        cout <<"\nPaises desarrollados de " << tierra.selectedContinents[0] << ":" <<endl;

        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente1) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesPrimerMundoContinente2.size()>0){
        cout <<"\nPaises de primer mundo de " << tierra.selectedContinents[1] << ":" <<endl;

        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente2) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesPrimerMundoContinente3.size() > 0){
        cout <<"\nPaises de primer mundo de " << tierra.selectedContinents[2] << ":" <<endl;

            // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
            for (auto& pais : paisesPrimerMundoContinente3) {
                pais.mostrarDetalles();
            }   
    }
    
    
    
    


     //Informacion paises en desarrollo, la idea es crear un vector de paises de 1er mundo y en desarrollo
    //el vector lo que guarda son los constructrores de los paises.
    cout <<"\nInformacion sobre los paises en desarrollo: \n";

    //Evaluo si el vector no esta vacio para imprimir
    if (paisesEnDesarrolloContinente1.size() > 0){
        cout <<"\nPaises en desarrollo de " << tierra.selectedContinents[0] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente1) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesEnDesarrolloContinente2.size() > 0){
        cout <<"\nPaises en desarrollo de " << tierra.selectedContinents[1] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente2) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesEnDesarrolloContinente3.size() > 0){
        cout <<"\nPaises en desarrollo de " << tierra.selectedContinents[2] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente3) {
            pais.mostrarDetalles();
        }
    }
    

}








