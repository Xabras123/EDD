#ifndef __REGION__HPP__
#define __REGION__HPP__

#include <iostream>
#include "region.h"
#include "paquete.h"
#include <string>
#include <list>
using namespace std;

void Region::setCodigo(string codigoIn){
    codigo = codigoIn;
}
void Region::setNombre(string nombreIn){
    nombre = nombreIn;
}


string Region::getCodigo( ){
    return codigo;
}
string Region::getNombre( ){
    return nombre;
}
void Region::setListaPaquetes(list<Paquete> listaPaquetesIn){
    listaPaquetes = listaPaquetesIn;
}
list<Paquete> Region::getListaPaquetes(){
    return listaPaquetes;
}
bool Region::agregarPaquete(Paquete paqueteIn){
    listaPaquetes.insert(listaPaquetes.begin(), paqueteIn);
    return true;
}
#endif // __REGION__HPP__
