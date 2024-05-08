#include <iostream>
#include <regex>

int main(){

    //Variable tipo regex, agrupamiento busca strings my o your
    auto const regex = std::regex("(my|your) regex");

    auto const myText = std::string("A piece of text that conatins my regex");
    //se entrega un boleano si el texto ingresado coincide con las palabras claves my o your
    bool const myTextContainsRegex = std::regex_search(myText, regex);

    auto const yourText = std::string("A piece of text that conatins your regex");
    //se entrega un boleano si el texto ingresado coincide con las palabras claves my o your
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string("A piece of text that conatins their regex");
    //se entrega un boleano si el texto ingresado coincide con las palabras claves my o your
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    //Imprime booleanos
    std::cout << std::boolalpha
              << myTextContainsRegex << "\n"
              << yourTextContainsRegex << "\n"
              << theirTextContainsRegex << "\n";
}
