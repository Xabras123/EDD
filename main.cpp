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
	bool on = true;
	bool encontrado=false;
	string lineIn, lineIn2;
    list<Persona> listIn;
    while(on)
	{
		cout<<"$";
		char comando[300];
		cin.getline(comando,300);
		char * pch;
		list<char*> milista;
		pch = strtok (comando," ");
		while (pch != NULL)
		{
			milista.push_back(pch);
			pch = strtok (NULL, " ");
		}
		list<char*>::iterator it=milista.begin();
		string comando1=*it;
		if (comando1=="")
		{
			if (milista.size()==2)
			{
				it++;
				lineIn=*it;
				if()
				{
					cout<<"No se cargó ningun"<<endl;
				}
				else if()
				{
					encontrado = ;
				}
				if(encontrado)
					cout<<"ya ha sido cargado anteriormente"<<endl;
				else if(!encontrado)
				{
					
					cout<<"cargado correctamente"<<endl;
				}
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comando1=="")
			
		else if(comando1=="")
		{
			if (milista.size()==2)
			{
				it++;
				lineIn=*it;
				
			}
			else if (milista.size()==1)
			{
					
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comando1==""){
			if (milista.size()==2)
			{
				it++;
				lineIn=*it;
				
			}
			else
			{
				
			}
		}
		else if(comando1==)
		{
			if (milista.size()==3)
			{
				it++;
				lineIn=*it;
				it++;
				lineIn2=*it;
				guardarPoligono(lineIn, lineIn2, poligonosMemoria);
			}
			else
				cout<< "Parametros invalidos"<<endl;
		}
		else if(comando1==)
		{
			if (milista.size()==5)
			{
				it++;
				float x=stof(*it);
				it++;
				float y=stof(*it);
				it++;
				float z=stof(*it);
				it++;
				lineIn=*it;
				componente2Punto1(lineIn,poligonosMemoria,x,y,z,false);
			}
			else if (milista.size()==4)
			{
				it++;
				float x=stof(*it);
				it++;
				float y=stof(*it);
				it++;
				float z=stof(*it);
				componente2Punto2(poligonosMemoria,x,y,z);
			}
		}
		else if(comando1==)
		{
			if (milista.size()==2)
			{
				it++;
				lineIn=*it;
				componente2Punto3(lineIn,poligonosMemoria);
			}
		}
		else if(comando1=="ayuda"){
			if (milista.size()==1)
			{
				cout<<endl<<"Comandos disponibles: "<<endl<<"   "<<endl<<"   "<<endl<<"   "<<endl<<"   "<<endl<<"   "<<endl<<"   "<<endl<<"   "<<endl<<"   salir"<<endl;
			}
			else if (milista.size()==2){
				it++;
				lineIn=*it;
				if(lineIn=="cargar")
					cout<<"===cargar <nombre_archivo>"<<endl<<"====Carga en memoria la información del objeto nombre_objeto contenida en el archivo identificado por nombre_archivo"<<endl;
				if(lineIn=="listado")
					cout<<"===listado"<<endl<<"====Lista los objetos cargados actualmente en memoria, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras."<<endl;
				if(lineIn=="envolvente")
					cout<<"==="<<endl<<"===="<<endl;
				if(lineIn=="descargar")
					cout<<"===descargar <nombre_objeto>"<<endl<<"====Descarga de la memoria toda la información básica (vértices, aristas, caras) del objeto identificado por nombre_objeto."<<endl;
				if(lineIn=="guardar")
					cout<<"===guardar <nombre_objeto nombre_archivo>"<<endl<<"===="<<endl;
				if(lineIn=="")
					cout<<"==="<<endl<<"===="<<endl;
				if(lineIn=="")
					cout<<"==="<<endl<<"===="<<endl;
				if(lineIn=="salir")
					cout<<"===salir"<<endl<<"====Termina la ejecucion de la aplicacion."<<endl;
			}
		}
		else if(comando1=="salir")
			on = false;
		else
			cout<<"===Comando no valido"<<endl;
	}
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
