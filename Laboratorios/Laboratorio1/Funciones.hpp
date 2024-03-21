#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>
#include "Contacto.hpp"
 //Copia de listaContactos[] y referencia de &numContactos para modificar su valor
void agregarContacto(Contacto listaContactos[], int &numContactos);
 //Copia de listaContactos[] y numContactos
void mostrarContacto(const Contacto listaContactos[], int numContactos);
//Copia de listaContactos[] y numContactos
void buscarContacto(const Contacto listaContactos[], int numContactos);
#endif //FUNCIONES_HPP