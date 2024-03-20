//Este es un archivo de encabezado.
#ifndef PERSONA_H //Si no existe una varibale PERSONA_H
#define PERSONA_H //Se proede a dfinir PERSONA_H

#include <string>
using namespace std;

class Persona {
    //Se declaran los atributos de la clase persona
    private:
        string nombre; 
        int edad;

    public:
        //Se declaara un constructor como publico
        Persona(string nombre, int edad);
        //Se declaran los siguientes metoso como publicos para poder utilizar en el curspo de la clase
        //Al ser publico es posible retornar el valor de un atributo privado
        string getName();
        int getEdad();
        void setEdad(int Edad);

};

#endif //PERSONA_H