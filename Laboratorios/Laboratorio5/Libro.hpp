#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>
//Clase libro
class Libro {
public:
    //Atributos publicos
    std::string titulo;
    std::string autor;
    int anioPublicacion;

    //Constructor de la clase
    Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}

    //Sobrecarga de operador < anioPublicacion < l.anioPublicacion
    bool operator<(const Libro& l) const {
        return anioPublicacion < l.anioPublicacion;
    }
};
#endif //LIBRO_HPP