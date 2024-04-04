#include <iostream>
//Se incluyen los encabezados
#include "EmpleadoAsalariado.hpp"
#include "EmpleadoPorHoras.hpp"

int main() {
    //Se inicializan los construcores
    EmpleadoAsalariado emp1("Marito", 30, 2000);
    EmpleadoPorHoras emp2("Juana", 25, 10, 40);
    
    //Se muestran los resultados de la construccion de los objetos
    std::cout << "Detalles del empleado asalariado" << std::endl;
    emp1.mostrarDetalles();
    std::cout << "Pago $ " << emp1.calcularPago() <<std::endl;
    std::cout << "\nDetalles del emleado por hora:" << std::endl;
    emp2.mostrarDetalles();
    std::cout << "Pago $" << emp2.calcularPago() << std::endl;
    return 0;
}





