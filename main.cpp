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
#include <vector>

using namespace std;

bool cargarPersonas(string nombreArchivo, list<Persona> &personasMemoria);
vector<string> tokenizador(string stringIn, char token);
bool buscarPersona(string cedulaIn, list<Persona> &personasMemoria);
bool registrarPersona(string nombre, string apellido, string cedula, string direccion, string ciudad, string telefono, list<Persona> &personasMemoria);
bool cargarPaquetes(string nombreArchivo, list<Paquete> &paquetesMemoria,  list<Persona> &personasMemoria,list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria);
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
	string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
	,string ciudadOficinaIn, string codigoRegionIn, string nombreRegionstringIn,
	list<Paquete> &paquetesMemoria, list<Persona> &personasMemoria,list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria);
bool registrarPaqueteUnico(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,list<Paquete> &paquetesMemoria, list<Persona> &personasMemoria);
bool buscarPaquete(string numGuiaIn, list<Paquete> &paquetesMemoria);
Persona buscarPersona2(string cedulaIn, list<Persona> &personasMemoria);
bool buscarOficina(string codigo, list<Oficina> &oficinasMemoria);
bool buscarRegion(string codigo, list<Region> &regionesMemoria);
Oficina buscarOficina2(string codigo, list<Oficina> &oficinasMemoria);
Region buscarRegion2(string codigo, list<Region> &regionesMemoria);
void imprimirRegiones(list<Region> &regionesMemoria);
void imprimirOficinas(list<Oficina> &oficinasMemoria);
void imprimirPaquetesXRegion2(list<Oficina> &oficinasMemoria);
void imprimirPaquetesXRegion(list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria, list<Paquete> &paquetesMemoria);

int main()
{
	bool on = true;
	bool encontrado=false;
	string lineIn=" ", lineIn2=" ", comand=" ";
	list<Persona> listIn;
	list<Paquete> listInP;
	list<Oficina> listInO;
	list<Region> listInR;
	list<char*> miLista;
	while(on)
	{
		cout<<"$ ";
		char comando[300]={' '};
		cin.getline(comando,300);
		char * pch;
		miLista.clear();
		pch = strtok (comando," ");
		while (pch != NULL)
		{
			miLista.push_back(pch);
			pch = strtok (NULL, " ");
		}
		list<char*>::iterator it;
		it=miLista.begin();
		comand=*it;
		if (comand=="cargarPersonas")
		{
			if (miLista.size()==2)
			{
				it++;
				lineIn=*it;
				if(cargarPersonas(lineIn,listIn))
				{
					cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
				}
				else if(!cargarPersonas(lineIn,listIn))
				{
					cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
				}
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comand=="cargarPaquetes")
		{
			if (miLista.size()==2)
			{
				it++;
				lineIn=*it;
				if(cargarPaquetes(lineIn,listInP, listIn, listInO, listInR))
				{
					cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
				}
				else if(!cargarPaquetes(lineIn,listInP, listIn, listInO, listInR))
				{
					cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
				}
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comand=="registrarPersona")
		{

			if (miLista.size()==1)
			{
				string nombre,apellido,cedula,direccion,ciudad,telefono;
				cout<<"Nombre: ";
				cin>>nombre;
				cout<<"Apellido: ";
				cin>>apellido;
				cout<<"Cedula: ";
				cin>>cedula;
				cout<<"Direccion: ";
				cin>>direccion;
				cout<<"Telefono: ";
				cin>>telefono;
				if(registrarPersona(nombre,apellido,cedula,direccion,ciudad,telefono,listIn))
					cout<<"La persona con identificación "<<cedula<<" ha sido registrado exitosamente"<<endl;
				else
					cout<<"La persona con identificación "<<cedula<<" ya se encuntra registrada en el sistema"<<endl;
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comand=="registrarPaquete"){
			if (miLista.size()==1)
			{
				string cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia;
				cout<<"Cedula remitente: ";
				cin>>cedulaRemitente;
				cout<<"Cedula destinatario: ";
				cin>>cedulaDestinatario;
				cout<<"Peso: ";
				cin>>peso;
				cout<<"Tipo de contenido: ";
				cin>>tipoContenido;
				cout<<"Numero de guia: ";
				cin>>numGuia;
				if(registrarPaqueteUnico(cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia,listInP,listIn))
					cout<<"El paquete con numero de guia "<<numGuia<<" ha sido registrado exitosamente"<<endl;
				else
					cout<<"El paquete con numero de guia "<<numGuia<<" ya se encuentra registrado en el sistema"<<endl;
			}
			else
			{
				cout<< "Parametros invalidos"<<endl;
			}
		}
		else if(comand=="conteoPaquetes")
		{
			if (miLista.size()==1)
			{
				imprimirPaquetesXRegion(listInO,listInR,listInP);	
			}
			else
				cout<< "Parametros invalidos"<<endl;
		}
		else if(comand=="ayuda"){
			if (miLista.size()==1)
			{
				cout<<endl<<"Comandos disponibles: "<<endl<<"   cargarPersonas"<<endl<<"   cargarPaquetes"<<endl<<"   registrarPersona"<<endl<<"   registrarPaquete"<<endl<<"   conteoPaquetes"<<endl<<"   salir"<<endl;
			}
			else if (miLista.size()==2){
				it++;
				lineIn=*it;
				if(lineIn=="cargarPersonas")
					cout<<"===cargarPersonas <nombre_archivo>"<<endl<<"====Carga en memoria la información de las personas contenida en el archivo identificado por nombre_archivo"<<endl;
				if(lineIn=="cargarPaquetes")
					cout<<"===cargarPaquetes <nombre_archivo>"<<endl<<"====Carga en memoria la información de los paquetes contenida en el archivo identificado por nombre_archivo"<<endl;
				if(lineIn=="registrarPersona")
					cout<<"===registrarPersona"<<endl<<"====Permite insertar en el sistema la información asociada de una persona."<<endl;
				if(lineIn=="registrarPaquete")
					cout<<"===registrarPaquete"<<endl<<"====Permite insertar en el sistema un paquete a entregar con toda su información asociada"<<endl;
				if(lineIn=="conteoPaquetes")
					cout<<"===conteoPaquetes"<<endl<<"====Realiza el conteo de los paquetes registrados en que se encuentran pendientes por entregar"<<endl;
				if(lineIn=="salir")
					cout<<"===salir"<<endl<<"====Termina la ejecucion de la aplicacion."<<endl;
			}
		}
		else if(comand=="salir")
			on = false;
		else
			cout<<"===Comando no valido"<<endl;
	}
	return 0;
}

bool cargarPersonas(string nombreArchivo, list<Persona> &personasMemoria)
{
	string line;
	ifstream myfile(nombreArchivo.c_str());
	vector<string> vtoken;
	int res = 0;
	if (myfile.is_open())
	{
		getline (myfile,line);
		int i = 0;
		while((myfile.peek()!=EOF))
		{
			getline (myfile,line);
			vtoken = tokenizador(line, ',');
			if(registrarPersona(vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], personasMemoria))
			{
				res=res;
			}
			else res= 1;
			i++;
		}
	}
	else
		return false;
	if(res==1)
		cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
	return true;
}

bool cargarPaquetes(string nombreArchivo, list<Paquete> &paquetesMemoria, list<Persona> &personasMemoria,list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria){
	string line;
	ifstream myfile(nombreArchivo.c_str());
	vector<string> vtoken;
	int res = 0;
	if (myfile.is_open())
	{
		getline (myfile,line);
		int i = 0;
		while((myfile.peek()!=EOF)){
			getline (myfile,line);
			vtoken = tokenizador(line, ',');
			if(registrarPaquete(vtoken[10],vtoken[9],vtoken[8],vtoken[7],vtoken[6],vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], paquetesMemoria, personasMemoria, oficinasMemoria, regionesMemoria)){
				res=res;
			}else res=1;
			i++;
		}
	}
	else
		return false;
	if(res==1)
		cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
	return true;
}

vector<string> tokenizador(string stringIn, char token)
{
	vector<string> listOut;
	string aux;
	int i = 0;
	while( i <= stringIn.size()){

		if(stringIn[i] == token){
			i++;
			listOut.insert(listOut.begin(), aux );
			aux.clear();
		}
		aux += stringIn[i];
		i++;
	}
	aux.resize(aux.size()-1);
	listOut.insert(listOut.begin(), aux );
	return listOut;
}

bool registrarPersona(string nombre, string apellido, string cedula, string direccion, string ciudad, string telefono, list<Persona> &personasMemoria){

	if(!buscarPersona(cedula, personasMemoria))
	{
		Persona personaAux;
		personaAux.setNombre(nombre);
		personaAux.setApellido(apellido);
		personaAux.setCedula(cedula);
		personaAux.setDireccion(direccion);
		personaAux.setCiudad(ciudad);
		personaAux.setTelefono(telefono);
		personasMemoria.insert(personasMemoria.begin(), personaAux);
		return true;
	}
	else 
		return false;
}

bool buscarPersona(string cedulaIn, list<Persona> &personasMemoria)
{
	for (list<Persona>::iterator it=personasMemoria.begin(); it != personasMemoria.end(); ++it)
	{
		if((*it).getCedula() == cedulaIn)
		{
			return true;
		}
	}
	return false;
}
Persona buscarPersona2(string cedulaIn, list<Persona> &personasMemoria)
{
	Persona personaOu;
	for (list<Persona>::iterator it=personasMemoria.begin(); it != personasMemoria.end(); ++it)
	{
		if((*it).getCedula() == cedulaIn)
		{
			return (*it);
		}
	}
	return personaOu;
}
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
	string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
	,string ciudadOficinaIn, string codigoRegionIn ,string nombreRegionstringIn ,
	list<Paquete> &paquetesMemoria, list<Persona> &personasMemoria, list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria)
{
	list<Paquete> listaPAux;
	list<Region> listaRAux;
	Paquete paqueteAux;
	Oficina auxO;
	Region auxR;
	if(!buscarPaquete(numGuiaIn, paquetesMemoria))
	{
		if(buscarOficina(codigoOficinaIn, oficinasMemoria))
		{
			paqueteAux.setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
			paqueteAux.setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
			paqueteAux.setPeso(1);
			paqueteAux.setNumGuia(numGuiaIn);
			paquetesMemoria.insert(paquetesMemoria.begin(), paqueteAux);
			if(!buscarRegion(codigoRegionIn, regionesMemoria)){
				auxR.setCodigo(codigoRegionIn);
				auxR.setNombre(nombreRegionstringIn);
				regionesMemoria.insert(regionesMemoria.begin(), auxR);
				buscarOficina2(codigoOficinaIn, oficinasMemoria).agregarRegion(auxR);

			}
			buscarOficina2(codigoOficinaIn, oficinasMemoria).agregarPaquete(paqueteAux, codigoRegionIn);
		}
		else 
		{
			auxO.setCodigo(codigoOficinaIn);
			auxO.setNombre(nombreOficinaIn);
			auxO.setDireccion(direccionOficinaIn);
			auxO.setCiudad(ciudadOficinaIn);
			if(!buscarRegion(codigoRegionIn, regionesMemoria))
			{
				auxR.setCodigo(codigoRegionIn);
				auxR.setNombre(nombreRegionstringIn);
				regionesMemoria.insert(regionesMemoria.begin(), auxR);
				auxO.agregarRegion(auxR);

			}
			paqueteAux.setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
			paqueteAux.setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
			paqueteAux.setPeso(1);
			paqueteAux.setNumGuia(numGuiaIn);
			auxO.agregarPaquete(paqueteAux, codigoRegionIn);
			paquetesMemoria.insert(paquetesMemoria.begin(), paqueteAux);
			oficinasMemoria.insert(oficinasMemoria.begin(),auxO);
		}
		return true;
	}
	else return false;
}

bool registrarPaqueteUnico(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,list<Paquete> &paquetesMemoria, list<Persona> &personasMemoria)
{
	Paquete paqueteAux;
	if(!buscarPaquete(numGuiaIn, paquetesMemoria))
	{
		paqueteAux.setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
		paqueteAux.setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
		paqueteAux.setPeso(1);
		paqueteAux.setNumGuia(numGuiaIn);
		paquetesMemoria.insert(paquetesMemoria.begin(), paqueteAux);
		return true;
	}
	else 
	{
		return false;
	}
}
bool buscarPaquete(string numGuiaIn, list<Paquete> &paquetesMemoria)
{
	for (list<Paquete>::iterator it=paquetesMemoria.begin(); it != paquetesMemoria.end(); ++it){
		if((*it).getNumGuia() == numGuiaIn){
			return true;
		}
	}
	return false;
}
bool buscarOficina(string codigo, list<Oficina> &oficinasMemoria)
{
	for (list<Oficina>::iterator it=oficinasMemoria.begin(); it != oficinasMemoria.end(); ++it)
	{
		if((*it).getCodigo() == codigo)
		{
			return true;
		}
	}
	return false;
}
bool buscarRegion(string codigo, list<Region> &regionesMemoria)
{
	for (list<Region>::iterator it=regionesMemoria.begin(); it != regionesMemoria.end(); ++it)
	{
		if((*it).getCodigo() == codigo)
		{
			return true;
		}
	}
	return false;
}
Oficina buscarOficina2(string codigo, list<Oficina> &oficinasMemoria)
{
	Oficina o;
	for (list<Oficina>::iterator it=oficinasMemoria.begin(); it != oficinasMemoria.end(); ++it)
	{
		if((*it).getCodigo() == codigo)
			o=*it;
		else
			o.setCodigo("-1");
	}
	return o;
}
Region buscarRegion2(string codigo, list<Region> &regionesMemoria)
{
	Region r;
	for (list<Region>::iterator it=regionesMemoria.begin(); it != regionesMemoria.end(); ++it)
	{
		if((*it).getCodigo() == codigo)
			r=*it;
		else
			r.setCodigo("-1");
	}
	return r;
}
void imprimirRegiones(list<Region> &regionesMemoria)
{
	for (list<Region>::iterator it=regionesMemoria.begin(); it != regionesMemoria.end(); ++it)
		cout<<"Region: "<<(*it).getNombre()<<endl;
}
void imprimirOficinas(list<Oficina> &oficinasMemoria)
{
	for (list<Oficina>::iterator it=oficinasMemoria.begin(); it != oficinasMemoria.end(); ++it)
		cout<<"Oficina: "<<(*it).getNombre()<<endl;
}
void imprimirRegionesXoficina(list<Oficina> &oficinasMemoria){

	for (list<Oficina>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
		cout<<"oficina "<<(*itO).getNombre()<<" y su region "<<(*itO).getListaRegiones().front().getNombre()<<endl;
}
void imprimirPaquetesXRegion2(list<Oficina> &oficinasMemoria)
{
	for (list<Oficina>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
	{
		cout<<(*itO).getNombre()<< " con "<<(*itO).getListaRegiones().size() <<" regiones y su region cabeza"<<(*itO).getListaRegiones().front().getNombre()
		<<" y sus paquetes "<<"n = "<<(*itO).getListaRegiones().front().getListaPaquetes().size()<<
		(*itO).getListaRegiones().front().getListaPaquetes().front().getRemitente().getNombre()<<endl;
	}
}
void imprimirPaquetesXRegion(list<Oficina> &oficinasMemoria, list<Region> &regionesMemoria, list<Paquete> &paquetesMemoria)
{
	int cantidadAcum = 0;
	list<Region> LRAux;
	for (list<Region>::iterator itR1=regionesMemoria.begin(); itR1 != regionesMemoria.end(); ++itR1){
		for (list<Oficina>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO){
			LRAux=(*itO).getListaRegiones();
			for (list<Region>::iterator itR=LRAux.begin(); itR != LRAux.end(); ++itR){
				if((*itR1).getNombre() == (*itR).getNombre())
				{
					cantidadAcum += (*itR).getListaPaquetes().size();
				}
			}
		}
		cout<<cantidadAcum<<" paquetes en la region de reparto "<<(*itR1).getNombre()<<endl;
		cantidadAcum=0;
	}
	cout<<" Para un total de "<<paquetesMemoria.size()<<" paquetes en el sistema"<<endl;
}
