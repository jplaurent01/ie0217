#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp"

class EmpleadoPorHoras : public Empleado{

    private:
        int horasTrabajadas;
    
    public:
        EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int horasTrabajadas);
        double calcularPago() const override;
};

#endif //EMPLEADOPORHORAS_HPP