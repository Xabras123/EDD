
#ifndef __OFICINA__H__
#define __OFICINA__H__
#include <stack>
#include <queue>
#include <string.h>
using namespace std;


class Oficina{

	private:
		string codigo;
		string nombre;
		string direccion;
		string ciudad;
	public:
		//Oficina();
		//~Oficina();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);
        void setDireccion(string DireccionIn);
        void setCiudad(string ciudadIn);

        string getCodigo( );
        string getNombre( );
        string getDireccion( );
        string getCiudad( );

};

#include "oficina.hpp"
#endif
