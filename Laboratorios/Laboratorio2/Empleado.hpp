#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP


#include <string>
class Empleado{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    protected:
        std::string nombre;
        int edad;
        double salario;
    //Empleado    
    public:
        Empleado(std::string _string, int _edad, double _salario);
        //Destructor
        virtual ~Empleado(){}
        //Obligo a todos los empleados a emplear el metodo de manera personalizada, todos los tipos de empleados
        //obligados a crear el metodo
        //metodo virtual puro con const = 0
        virtual double calcularPago() const = 0 ;//Metodo virtual puro
        //Diferencia entre metodo virtual puro es const
        virtual void mostrarDetalles() const;

};

#endif //EMPLEADO_HPP