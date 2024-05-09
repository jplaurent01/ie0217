#include "text_processor.hpp"
#include <fstream>
#include <regex>

//Constructor de la clase
TextProcessor::TextProcessor(const std::string& input_filename, const std::string& output_filename)
    : input_filename(input_filename), output_filename(output_filename){}

void TextProcessor::replace(const std::string& search_pattern, const std::string& replace_string){
    //Abrir el archivo de entrada
    std::ifstream input_file(input_filename);
    //Abrir el archivo de salida
    std::ofstream output_file(output_filename);
    //Variable para almacenar cada línea leída del archivo de entrada
    std::string line;

    //Crear un objeto regex a partir del patrón de búsqueda
    std::regex pattern(search_pattern);
    //Verificar si ambos archivos están abiertos correctamente
    if (input_file && output_file){
        //Itero sobre cada línea del archivo de entrada
        while(getline(input_file, line)){
            //Reemplazar todas las ocurrencias de pattern con la cadena de reemplazo
            std::string replaced = std::regex_replace(line, pattern, replace_string);
            //Escribo la linea modificada en el archivo de salida
            output_file << replaced << "\n";
        }
    }
    
}