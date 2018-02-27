#include <iostream>
#include "oficina.h"
#include "oficina.hpp"
#include "paquete.h"
#include "paquete.hpp"
#include "region.h"
#include "region.hpp"
#include "persona.h"
#include "persona.hpp"
#include <list>
#include <string.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <cmath>
#include <cstring>

using namespace std;

bool cargarPersonas(string nombreArchivo, list<Persona> &personasMemoria);


int main()
{
    list<Persona> listIn;
    cout << "Hello world!" << endl;
    cargarPersonas("Personas.csv", listIn);
    return 0;
}


bool cargarPersonas(string nombreArchivo, list<Persona> &personasMemoria){

	string line;
	ifstream myfile(nombreArchivo.c_str());

	if (myfile.is_open())
	{
		getline (myfile,line);
		cout<<"Nombre: "<< line<<endl;

		getline (myfile,line);
		cout<<"Cantidad de vertices: "<< line<<endl;

		while (getline (myfile,line) && false)
		{

		}



	}
	else
		cout << "Unable to open file";

return true;

}
