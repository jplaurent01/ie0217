// Nombre del archivo: Funciones.cpp
//
// Descripción: 
//
// Copyright (c) 2024 Jose Pablo Laurent Chaves
// Licencia: MIT

#include "Funciones.hpp"
bool idIsUnique(string num, string nombrePais,
 unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta){
    // Verificar si el ID es único
    bool idUnico = true;
    //recorro el dicionario por continentes
    for (const auto& continente : instrucionesPlaneta) {
        //recorro la informacion de los continentes
        for (const auto& pais : continente.second) {
            //Caso donde encontre un id repetido o nombre repetido
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

//agrego un nuevo pais al diccionario
void agregarInformacion(string nombreContinente, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> &instrucionesPlaneta){
    //Variables de interaccion con el usuario
    string nombrePais;
    int id;
    int habitantes;
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
        cin >> id;
        //Verifico si el id es un numero entero
        if (!cin.fail()){
            //chequeo si el numero es mayor a 1
            if (id > 1){
                //Chequeo si el id o el nombre son unicos
                if (idIsUnique(to_string(id), nombrePais, instrucionesPlaneta) == true){
                    //debo chequear si el numero es o no es primo
                    //caso numero primo, pais primer mundo
                    if (isPrimo(id) == true){
                       cout << "Ingrese un numero con la cantidad de habitantes" << endl;
                       cin >> habitantes; 
                       //verifico que el se ingrese un numero de habitantes mayor a 1
                       if (!cin.fail() && habitantes > 1){
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

                       }
                       else{
                        cout << "Ingrese un numero de habitantes y que sea mayor a 1" << endl;
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
string boolToString(bool valor) {
    return valor ? "true" : "false";
}
//Convierto de string a booleano
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
void filterByContinent(string keyWord, int &cantidadPaises0, int &primos0, int &noPrimos0, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta,  vector<PaisPrimerMundo> &paisesPrimerMundoContinente, vector<PaisEnDesarrollo> &paisesEnDesarrolloContinente){

    if (keyWord == "Oceania" || keyWord == "Asia" || keyWord == "Africa" || keyWord == "Europa" || keyWord == "America"){
        //Busco en el dicionario de acuerdo a la palabra clave, en relacion con el continente
        if (instrucionesPlaneta.find(keyWord) != instrucionesPlaneta.end()) {
            cantidadPaises0 = instrucionesPlaneta[keyWord].size();
            //itero sobre el dicionario de acuerdo al contienente selecionado
            for (const auto& par : instrucionesPlaneta[keyWord]) {
                //accedo al identificador unico par.second[indice], accedo a los valores del dicionario anidado
                //con esto puedo recolectar los valores del pais para generar objetos de tipo pais
                int id = std::stoi(par.second[3]);

                //Caso de encontrar pais desarrollado
                if (isPrimo(id)) {
                    //agrego contructor de paises de primer mundo
                    //Nombre, id, habitantes, 5g, aeropuerto, investigacion
                    paisesPrimerMundoContinente.push_back(PaisPrimerMundo(par.first, stoi(par.second[3]), stoi(par.second[4]), stringToBool(par.second[0]), stringToBool(par.second[1]), stringToBool(par.second[2])));
                    primos0++;
                } else {
                    //Nombre, id, habitantes, aeropuerto
                    paisesEnDesarrolloContinente.push_back(PaisEnDesarrollo(par.first, stoi(par.second[3]), stoi(par.second[4]), stringToBool(par.second[1])));
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
bool isPrimo(int num){
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

void imprimirPlaneta(Planeta tierra, unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> instrucionesPlaneta) {
    cout << "Informacion General: \n";
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
        cout <<"\n Paises desarrollados de " << tierra.selectedContinents[0] << ":" <<endl;

        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente1) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesPrimerMundoContinente2.size()>0){
        cout <<"\n Paises de primer mundo de " << tierra.selectedContinents[1] << ":" <<endl;

        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesPrimerMundoContinente2) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesPrimerMundoContinente3.size() > 0){
        cout <<"\n Paises de primer mundo de " << tierra.selectedContinents[2] << ":" <<endl;

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
        cout <<"\n Paises en desarrollo de " << tierra.selectedContinents[0] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente1) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesEnDesarrolloContinente2.size() > 0){
        cout <<"\n Paises en desarrollo de " << tierra.selectedContinents[1] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente2) {
            pais.mostrarDetalles();
        }
    }
    
    //Evaluo si el vector no esta vacio para imprimir
    if (paisesEnDesarrolloContinente3.size() > 0){
        cout <<"\n Paises en desarrollo de " << tierra.selectedContinents[2] << ":" <<endl;
        // Iterar sobre el vector y llamar al método mostrarDetalles() para cada objeto
        for (auto& pais : paisesEnDesarrolloContinente3) {
            pais.mostrarDetalles();
        }
    }
    

}








