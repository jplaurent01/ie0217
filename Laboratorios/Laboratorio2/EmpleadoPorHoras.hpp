#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp"

class EmpleadoPorHoras : public Empleado{
    //atributo pirvado, solamente accesible dentro de la clase
    private:
        int horasTrabajadas;
    //constructor y metodo publico
    public:
        EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int horasTrabajadas);
        double calcularPago() const override;
};

#endif //EMPLEADOPORHORAS_HPP