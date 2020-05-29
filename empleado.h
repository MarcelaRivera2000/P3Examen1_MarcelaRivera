#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<string>

class empleado{
	public: 
		empleado(string n,int e,int nn,int h,int p);
		string nombre();
		int edad();
		int nivel();
		int habilidad();
		int pereza();
		~empleado();
	private:
		string nombre;
		int edad,nivel,habilidad,pereza;
};

empleado::empleado(string n,int e,int nn,int h,int p){
	nombre=n;
	edad=e;
	nivel=nn;
	habilidad=h;
	pereza=p;
}

string empleado::nombre(){
	return nombre;
}

int empleado::edad(){
	return edad;
}

int empleado::nivel(){
	return nivel;
}

int empleado::habilidad(){
	return habilidad;
}

int empleado::pereza(){
	return pereza;
}

#endif

