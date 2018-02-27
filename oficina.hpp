#ifndef __OFICINA__HPP__
#define __OFICINA__HPP__

#include <iostream>
#include "oficina.h"
#include <string>
#include <list>
using namespace std;

void Oficina::setCodigo(string codigoIn){
    codigo = codigoIn;
}
void Oficina::setNombre(string nombreIn){
    nombre = nombreIn;
}
void Oficina::setDireccion(string direccionIn){
    direccion = direccionIn;
}
void Oficina::setCiudad(string ciudadIn){
    ciudad = ciudadIn;
}
string Oficina::getCodigo( ){
    return codigo;
}
string Oficina::getNombre( ){
    return nombre;
}
string Oficina::getDireccion( ){
    return direccion;
}
string Oficina::getCiudad( ){
    return ciudad;
}

#endif
