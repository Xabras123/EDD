
#ifndef __REGION__H__
#define __REGION__H__
#include <stack>
#include <queue>
#include "paquete.h"
using namespace std;

class Region{

	private:
		string codigo;
		string nombre;
		list<Paquete> listaPaquetes;

	public:
		//Region();
		//~Region();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);
        void setListaPaquetes(list<Paquete> listaPaquetesIn);

        string getCodigo( );
        string getNombre( );
        list<Paquete> getListaPaquetes();
        bool agregarPaquete(Paquete paqueteIn);


};

#include "region.hpp"
#endif
