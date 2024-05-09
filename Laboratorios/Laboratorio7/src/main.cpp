#include <iostream>
#include "text_processor.hpp"

//Siempre es necesario que se llame main, es por donde entramos el progrma
int main(int argc, char* argv[]) {
    if(argc < 5){
        std::cerr << "Usage: " << argv[0] << "-f <filename> -o <outputfile> -search <search_pattern> -replace <replace_string>\n";
    }
    
    //Se recolectan los comandos desde la terminal
    std::string filename = argv[2];
    std::string outputfile = argv[4];
    std::string search_pattern = argv[6];
    std::string replace_string = argv[8];

    TextProcessor processor(filename, outputfile);
    processor.replace(search_pattern, replace_string);
    
    return 0;
}







