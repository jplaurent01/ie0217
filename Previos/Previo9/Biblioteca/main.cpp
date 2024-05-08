#include "biblioteca.hpp"

int main(){
    Biblioteca biblioteca;
    biblioteca.agregarLibro("Gatsby", "Scott");
    biblioteca.agregarLibro("1984", "owell");

    biblioteca.mostrarCatalogo();
    return 0;
}
