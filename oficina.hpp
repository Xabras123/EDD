#ifndef __OFICINA__HPP__
#define __OFICINA__HPP__

#include <iostream>
#include "oficina.h"
#include <string>
#include <list>
#include "region.h"
#include "paquete.h"
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
void Oficina::setListaRegiones(list<Region> listaRegionesIn){
    listaRegiones = listaRegionesIn;
}
void Oficina::setListaPaquetes(list<Paquete> listaPaquetesIn){
    listaPaquetes = listaPaquetesIn;
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
list<Region> Oficina::getListaRegiones(){
    return listaRegiones;
}
list<Paquete> Oficina::getListaPaquetes(){
    return listaPaquetes;
}
#endif
