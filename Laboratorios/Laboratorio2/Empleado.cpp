#include "Empleado.hpp"
#include <iostream>

Empleado::Empleado(std::string _nombre, int _edad, double _salario) :
    nombre(_nombre), edad(_edad), salario(_salario) {}

void Empleado::mostrarDetalles() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Salario: " << salario << std::endl;
}

