#include "EmpleadoPorHoras.hpp"

//Constructos, elementos necesario para correr la clase
EmpleadoPorHoras::EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas)
    : Empleado(_nombre, _edad, _salario), horasTrabajadas(_horasTrabajadas) {}

//se crea un metodo propio para calcular pago, al pertenecer a un metodo virtual puro
double EmpleadoPorHoras::calcularPago() const {
    return salario * horasTrabajadas;
}

