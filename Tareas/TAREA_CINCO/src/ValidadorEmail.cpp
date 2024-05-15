#include "ValidadorEmail.hpp"


ValidadorEmail::ValidadorEmail(const std::string& _nombre, const std::string& _dominio, const std::string& _extension) :
    nombre(_nombre), dominio(_dominio), extension(_extension){}

void ValidadorEmail::validarCorreo(std::vector<std::string>& almacenCorreos){
        
    //Verifico que el usuario no agregue informacion vacia
    if (!nombre.empty() && !dominio.empty()  && !extension.empty()){
        //Expresion regular
        //std::regex pattern("^[a-zA-Z0-9](?:[a-zA-Z0-9.-_]{0,14}[a-zA-Z0-9])?+@[a-zA-Z](?:[a-zA-Z.]{3,30}[a-zA-Z])?(?:\\.[a-zA-Z](?:[a-zA-Z]{2,6}[a-zA-Z])?)*$");
        validarNombre(nombre);
        std::regex patternNombre("^[a-zA-Z0-9][a-zA-Z0-9._-]*[a-zA-Z0-9]$");
        
        //Verifico que el nombre coincida con el patron de iniciar y terminar con letra o numero
        //y que contenga .-_
        if (std::regex_match(nombre, patternNombre)) {

            validarDominio(dominio);
            std::regex patternDominio("^@[a-zA-Z.]*[a-zA-Z]$");
            //Verifico que el dominio contenga unicamente @, letras y puntos
            if (std::regex_match(dominio, patternDominio)){
                
                validarExtensión(extension);
                std::regex patternExtension(R"(\.[a-zA-Z.]*[a-zA-Z]$)");

                if (std::regex_match(extension, patternExtension)){
                    std::string result = nombre + dominio + extension;

                    //Se chequea si el vector ya almaceno el email
                    auto it = std::find(almacenCorreos.begin(), almacenCorreos.end(), result);

                    //Caso donde se encuentra el email almacenado
                    if (it != almacenCorreos.end()) {
                        std::cout << "Email:  \"" << result<< "\" ya se registro." << std::endl;
                    }//Caso donde el email no esta registrado
                     else {
                        almacenCorreos.push_back(result);
                        std::cout << "Email:  \"" << result << "\" correctamente registrado." << std::endl;

                    }
                }else{
                    throw std::invalid_argument("Se ha detectado un carcater distinto a letra o . en la Extension, vuelva a intentar..."); 
                }
                
            }else{
                throw std::invalid_argument("Se ha detectado un carcater distinto a letra, . o @ en el Dominio, vuelva a intentar..."); 
            
            }
            
            //std::cout << "Direccion de correo VALIDA" << std::endl;
            //std::vector<std::string> divString = splitString(email);
           // validarNombre(divString[0]);
            //auto result = splitDominioExtension(divString[1]);
            //std::string dominio = result.first;
            //std::string extension = result.second;

        } else {

            throw std::invalid_argument("Se ha detectado un carcater distinto a letra, numero, .-_ en el Nombre, vuelva a intentar..."); 
            //std::cout << "Direccion de correo no valida" << std::endl;
        }
        
    }else{
        throw std::invalid_argument("Se agrego un nombre, dominio o extension vacio, vuelva a intentar...");     
    }
    
    
    
}


