#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<string>
#include "tarea.h"


using namespace std; 

class empleado{
	private:
		string nombre;
		int edad,nivel,habilidad,pereza;
		bool estado;
		tarea* tare;
	public: 
		empleado(string n,int e,int nn,int h,int p,bool es);
		string getnombre();
		int getedad();
		int getnivel();
		int gethabilidad();
		int getpereza();
		bool getestado();
		void setestado(bool v);
		void setTarea(tarea* tt);
		tarea* getTarea();
		~empleado();
	
};

empleado::empleado(string n,int e,int nn,int h,int p,bool es){
	nombre=n;
	edad=e;
	nivel=nn;
	habilidad=h;
	pereza=p;
	estado=es;
}

string empleado::getnombre(){
	return nombre;
}

int empleado::getedad(){
	return edad;
}

int empleado::getnivel(){
	return nivel;
}

int empleado::gethabilidad(){
	return habilidad;
}

int empleado::getpereza(){
	return pereza;
}

bool empleado:: getestado(){
	return estado;
}

void empleado:: setestado(bool v){
estado=v;
}

tarea* empleado::getTarea(){
	return tare;
}

void empleado::setTarea(tarea* tt){
	tare=tt;
}

#endif












