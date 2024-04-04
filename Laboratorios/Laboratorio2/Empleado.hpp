#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP


#include <string>
class Empleado{
    protected:
        std::string nombre;
        int edad;
        double salario;
    //Empleado    
    public:
        Empleado(std::string _string, int _edad, double _salario);
        virtual ~Empleado(){}
        virtual double calcularPago() const = 0 ;//Metodo virtual puro
        virtual void mostrarDetalles() const;

};

#endif //EMPLEADO_HPP