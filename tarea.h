#ifndef TAREA_H
#define TAREA_H
#include<string>

class tarea{	
	public: 
		tarea(string d,int n,int c);	
		~tarea();
	private:
		string descripcion;
		int nivel,carga;
		
};

tarea::tarea(string d,int n,int c){
	descripcion=d;
	nivel=n;
	carga=c;
}

string tarea::descrip(){
	return descripcion;
}

int tarea::nivel(){
	return nivel;
}

int tarea::carga(){
	return carga;
}

#endif
