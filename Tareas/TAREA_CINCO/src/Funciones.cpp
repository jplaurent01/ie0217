#include "Funciones.hpp"

void validarNombre(const std::string &nombre){
    char primerCaracter = nombre.front();  //primer caracter
    char ultimoCaracter = nombre.back();   //ultimo caracter

    //Verifico que no empice ni termine en . _ -
    if (primerCaracter != '.' && primerCaracter != '_' && primerCaracter != '-' &&
        ultimoCaracter != '.' && ultimoCaracter != '_' && ultimoCaracter != '-'){

        //Verifico que el tamnio del nombre se 15 excluyendo . y guiones
        if (nombreTamanio(nombre, 0) <= 15){
            //Indica que los puntos y guiones deben aparecer 2 o mas veces consecutivas
            std::regex pattern("[.-_]{2,}");
            //Verifica que no existan . y guiones consecutivos
            if (!std::regex_search(nombre, pattern)){

                //Busco coincidencias de .-_
                std::regex patternTwo("[.-_]");
                //Busco coincidencias de .-_
                if(std::regex_search(nombre, patternTwo)){

                    //std::cout << "Nombre valido..." << std::endl;

                }else{

                throw std::invalid_argument("Nombre debe contener alguno de los caracteres .-_, vuelva a intentar...");                
                
                }
                
            }else {
                throw std::invalid_argument("Nombre contiene los caracteres .-_ consecutivos, vuelva a intentar...");
            }
            

        }else{
                throw std::invalid_argument("La extension del nombre supera los 15 caracteres, vuelva a intentar...");
        } 
    }else{
        throw std::invalid_argument("Se encontro un . _ - al inicio y/o final del nombre, vuelva a intentar...");
    }
     
};

//Excluye los . y guinees, cuento la cantidad de caracteres especiales en el string
int nombreTamanio(const std::string &nombre, int Flag = -1){
    int count = 0;
    //Caso donde el nombre admite ._-
    if (Flag == 0){

        for (const auto &element : nombre){
            if (element != '.' || element != '_' || element != '-'){
                count +=1;
            }
            
        }
    }else{
        //Caso donde dominio y extensio admiten .
        for (const auto &element : nombre){
            if (element != '.'){
                count +=1;
            }
            
        }
    }

    return count;
};


void validarDominio(const std::string &dominio){
    char primerCaracter = dominio.front();  //primer caracter
    char ultimoCaracter = dominio.back();   //ultimo caracter

    //Verifico que el dominio siempre empiece en @
    if (primerCaracter == '@'){
        //Verifico que dominio no empice ni termine en .
        if (primerCaracter != '.' && ultimoCaracter != '.' ){
            //verifico que el usuario haya agregado solo un @
            int arroba = contarArrobas(dominio);

            if (arroba < 2){
                //Separa el dominio por @ para poder realizar el conteo de caracteres sin @
                std::vector<std::string> splitArroba = splitString(dominio);
                //Verifico que el dominio este en 3 y 30 caracteres, excluyendo .
                int tamanioDominio = nombreTamanio(splitArroba[1]);
                //std::cout << "Tamnio dominio" << tamanioDominio << std::endl;
                if (tamanioDominio >2 && tamanioDominio <31){
                    //Verifica que no existan . consecutivos
                    std::regex pattern("[.]{2,}");
                    //Verifica que no existan . consecutivos
                    if (!std::regex_search(dominio, pattern)){

                        //Busco que el dominio contenga letras y almenos un .
                        std::regex patternTwo("[a-zA-Z.]");
                        if(std::regex_search(dominio, patternTwo)){

                            //std::cout << "Dominio valido ..." << std::endl;

                        }else{

                        throw std::invalid_argument("Dominio debe contener alguna letra o ., vuelva a intentar...");                
                        
                        }

                    }else{
                        throw std::invalid_argument("Se encontro segmentos consecutivos separados por un unico punto, vuelva a intentar...");
                    }
                    
                }else{
                    throw std::invalid_argument("La extension del dominio es superior los 30 caracteres o es inferior a 3 caracteres, vuelva a intentar...");
                }
            }else{
                throw std::invalid_argument("El dominio contiene mas de 1 @, vuelva a intentar..."); 
            }
            
            
            
        }else{
            throw std::invalid_argument("Se ha detectado un . al inicio y/o final del dominio, vuelva a intentar...");
        }
        
    }else{
        throw std::invalid_argument("Dominio debe empezar con @, vuelva a intentar...");
    }

};

//Cuento la cantida de @ de un string si tiene más de 2 es invalido
int contarArrobas(const std::string &text){
    int arrobas = 0;
    for (char c : text) {
        if (c == '@') {
            arrobas++;
        }
    }
    return arrobas;
};

//Divido string a partir de caracter especial "@"
std::vector<std::string> splitString(const std::string &nombre){
     
    //Crear un stringstream a partir del string result
    std::stringstream ss(nombre);
    //Vector para almacenar las partes separadas
    std::vector<std::string> partes;
    //Variable temporal para almacenar cada parte
    std::string parte;
    //Leer partes del stringstream hasta encontrar el delimitador "@"
    while (std::getline(ss, parte, '@')) {
        partes.push_back(parte); // Agregar la parte al vector
    }
    //retorno un vecotr con las partes
    return partes;
    
};

void validarExtension(const std::string &extension){

    char primerCaracter = extension.front();  //primer caracter
    char ultimoCaracter = extension.back();   //ultimo caracter

    //Verifico que el primer caracter de la extenson sea . y que el ultimo caracter de la extension no 
    //sea punto
    if (primerCaracter == '.' && ultimoCaracter != '.' ){

        //Cuento el numero de letras de la extension, no cuento puntos
        int tamanioExtension = nombreTamanio(extension);
        //Verifico que tenga entre 2 y 6 letras
        if (tamanioExtension >1 && tamanioExtension <7){
            
            //Busco que el dominio contenga letras y al menos un .
            std::regex patternTwo("[a-zA-Z.]");
            if(std::regex_search(extension, patternTwo)){

                //std::cout << "Extension valido ..." << std::endl;

            }else{

            throw std::invalid_argument("Extension debe contener alguna letra o ., vuelva a intentar...");                
            
            }

        }else{
            throw std::invalid_argument("La extension contiene menos de 2 letras o mas de 6 letras, vuelva a intentar..."); 
        }
        
    }else{
        throw std::invalid_argument("El primer caracter de la extension debe ser . y el ultimo caracter no debe ser punto, vuelva a intentar..."); 
    }
    

};

/*
void validarDominio(const std::string &nombre){

};

std::vector<std::string> splitString(const std::string &nombre){
     
    //Crear un stringstream a partir del string result
    std::stringstream ss(nombre);
    //Vector para almacenar las partes separadas
    std::vector<std::string> partes;
    //Variable temporal para almacenar cada parte
    std::string parte;
    // Leer partes del stringstream hasta encontrar el delimitador ","
    while (std::getline(ss, parte, '@')) {
        partes.push_back(parte); // Agregar la parte al vector
    }

    if (partes.size() > 2){
        throw std::invalid_argument("Se ha ingresado multiplies veces el caracter @, vuelva a intentar...");
    }else if (partes.size() == 0){
        throw std::invalid_argument("No se ha detectado el caracter @, vuelva a intentar...");
    }
    
    return partes;
    
};

*/

/*
std::pair<std::string, std::string> splitDominioExtension(const std::string &nombre){
    std::string partOne;
    std::string partTwo;
    int dotCount = 0;

    //Recorro cada una de las letras del string
    for (auto it = nombre.rbegin(); it != nombre.rend(); ++it) {

        if (!partTwo.empty()){

            //Cuento los puntos que tengo en el string
            if (*it == '.'){
                dotCount += 1;
            }
            //En este caso ya complete la extension
            if ((dotCount == 2 || dotCount == 1) && (partTwo.size() >= 2 || partTwo.size() <= 6)){
                partOne += *it;
            }else{
                //if (partTwo.size()>6){
                  //  partOne += *it;
                //}
                //else{
                    partTwo += *it;
                //}
                
            }
            
        }else{
            //Cuento los puntos que tengo en el string
            if (*it == '.'){
                dotCount += 1;
            }

            partTwo += *it;
        }
        
        //reversed += *it; 
    }

    //Puedo tener 2 casos, donde partTwo > a 6 y partTwo mayor a 6
    getreverse(partOne, 0);
    getreverse(partTwo, 0);

    std::cout << "Dominio: " << partOne << std::endl;
    std::cout << "Extesnsion: " << partTwo << std::endl;
    return std::make_pair(partOne, partTwo);
    
};

*/

/*
void getreverse(std::string &str, int i){
    if (i > (str.length() - 1 - i)){
        return;
    }
    std::swap(str[i], str[str.length() - i - 1]);
    i++;
    getreverse(str, i);
};
*/
