#ifndef __PERSONA__HPP__
#define __PERSONA__HPP__

#include <iostream>
#include "persona.h"
#include <string>
#include <list>
using namespace std;

void Persona::setCodigo(string codigoIn){
    codigo = codigoIn;
}
void Persona::setNombre(string nombreIn){
    nombre = nombreIn;
}
void Persona::setDireccion(string direccionIn){
    direccion = direccionIn;
}
void Persona::setCiudad(string ciudadIn){
    ciudad = ciudadIn;
}
void Persona::setTelefono( string telefonoIn){
    telefono =  telefonoIn;
}
void Persona::setApellido(string apellidoIn){
    apellido = apellidoIn;   
}

string getApellido(){
    return apellido;
}
string Persona::getCodigo( ){
    return codigo;
}
string Persona::getNombreYApellido( ){
    return nombreYApellido;
}
string Persona::getDireccion( ){
    return direccion;
}
string Persona::getCiudad( ){
    return ciudad;
}
string Persona::getTelefono (){
    return telefono;
}
#endif
