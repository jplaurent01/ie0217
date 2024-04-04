#include "EmpleadoAsalariado.hpp"


//Lgica del constructor
EmpleadoAsalariado::EmpleadoAsalariado(std:: string _nombre, int _edad, double _salario)
    : Empleado (_nombre, _edad, _salario) {}

//Logica del metodo calcular pago, heredea  del metdo calcular pago por medio funcion virtual
double EmpleadoAsalariado::calcularPago() const {
    return salario;
}