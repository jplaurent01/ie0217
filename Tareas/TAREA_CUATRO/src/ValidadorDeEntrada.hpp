#ifndef VALIDADORDEENTRADA_HPP
#define VALIDADORDEENTRADA_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <complex>
#include <sstream>


template <typename T>
class ValidadorDeEntrada {

    public:
        bool validarTipoDato(std::string input, std::string tName, T &value){

            if ( !input.empty() && all_of(input.begin(), input.end(), ::isdigit) && tName == "i"){
                try{
                    value = stoi(input);
                    std::cout << "\nDato int valido" << std::endl;
                    return true;
                }
                catch(...){
                    std::cout << "Imposible convertir a int" << std::endl;
                    return false;
                }
                
            }
            if (!input.empty() && all_of(input.begin(), input.end(), isfloat) && tName == "f"){

                try{

                    value = stof(input);
                    std::cout << "\nDato float valido" << std::endl;
                    return true;
                }
                catch(...){
                    std::cout << "Imposible convertir a float" << std::endl;
                    return false;
                }
                
            }
            if(std::is_same<T, std::complex<double>>::value && !input.empty()){ 
            //if (!input.empty() &&  tName == "St7complexIdE" && std::is_same_v<T, std::complex<float>>){
                //all_of(input.begin(), input.end(), isfloat) &&
                std::string result = input; 
                // Crear un stringstream a partir del string result
                std::stringstream ss(result);
                // Vector para almacenar las partes separadas
                std::vector<std::string> partes;
                // Variable temporal para almacenar cada parte
                std::string parte;
                // Leer partes del stringstream hasta encontrar el delimitador "_"
                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte); // Agregar la parte al vector
                }

                if (all_of(partes[0].begin(), partes[0].end(), isfloat)){
                    if (all_of(partes[1].begin(), partes[1].end(), isfloat)){
                        try {
                            //float realPart, imagPart;
                            //realPart = stod(partes[0]);
                            //imagPart = stod(partes[1]);
                            //std::cout << "\nDato compejo valido" << std::endl;
                            //std::string s = "123,5.3";//input
                            //std::istringstream is('(' + input + ')');
                            //std::complex<float> c;
                            //is >> value;
                            //value = stof(input);
                            //value = std::complex<double>(realPart, imagPart);
                            std::cout << "\nDato float valido" << std::endl;
                            return true;

                        } catch (...) {
                            std::cout << "Imposible convertir a complex" << std::endl;
                            return false;
                        }
                    }else{
                        std::cout << "La parte imaginaria no es un numero" << std::endl; 
                    }
                }else{
                    std::cout << "La parte real no es un numero" << std::endl; 
                }
                
            }
            
            return false;

        };

        void validarDimensiones(int tamanio){
            if (tamanio > 0){
                std::cout << "Dimension valida" << std::endl;
            }else {
                throw std::invalid_argument("Dimension invalida");
            }
            
        };

    private:

        static bool isfloat(const char& c) {
            return std::isdigit(c) || c == '.' || c == '-';
        };

        //static bool isComplex(const char& c) {
          //  return std::isdigit(c) || c == '.' || c == '-';
        //};


};

#endif //VALIDADORDEENTRADA_HPP