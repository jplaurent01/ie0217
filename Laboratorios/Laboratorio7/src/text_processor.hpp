#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP
#include <string>

class TextProcessor {
    //Atributos privados de la clase, solo pueden accederse en ella misma
    private:
        std::string input_filename;
        std::string output_filename;
    
    public:
        //Ayuda a optimizar compilador, se le indica que cojas las variables como estan ahorrando recursos
        //Constructor
        TextProcessor(const std::string& input_filename, const std::string& output_filename);
        //Metodo publico que remplaza los strings que recibe como parametros
        void replace(const std::string& search_pattern, const std::string& replace_string);
        
};
#endif //TEXT_PROCESSOR_HPP