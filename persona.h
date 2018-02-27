
#ifndef __PERSONA__H__
#define __PERSONA__H__
#include <stack>
#include <queue>
using namespace std;


class Persona{

	private:
		string codigo;
		string nombre;
		string apellido
		string direccion;
		string ciudad;
		string telefono;
	public:
		//Persona();
		//~Persona();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);
        void setDireccion(string DireccionIn);
        void setCiudad(string ciudadIn);
        void setTelefono(string telIn);
	void setNombre(string apellidoIn)

        string getCodigo( );
        string getNombreYApellido( );
        string getDireccion( );
        string getCiudad( );
        string getTelefono();
	string getApellido()

};

#include "persona.hpp"
#endif
