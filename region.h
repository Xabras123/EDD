
#ifndef __REGION__H__
#define __REGION__H__
#include <stack>
#include <queue>
using namespace std;

class Region{

	private:
		string codigo;
		string nombre;

	public:
		//Region();
		//~Region();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);

        string getCodigo( );
        string getNombre( );


};

#include "region.hpp"
#endif
