#ifndef TAREA_H
#define TAREA_H
#include<string>

using namespace std; 

class tarea{	
	public: 
		int getnivel();
		int getcarga();	
		string getdescrip();
		tarea(string d,int n,int c,bool e);
		bool getestado();
		bool setestado(bool v);
		~tarea();
	private:
		string descripcion;
		int nivel,carga;
		bool estado;
		
};

tarea::tarea(string d,int n,int c,bool e){
	descripcion=d;
	nivel=n;
	carga=c;
	estado=e;
}

string tarea::getdescrip(){
	return descripcion;
}

int tarea::getnivel(){
	return nivel;
}

int tarea::getcarga(){
	return carga;
}
bool tarea::getestado(){
	return estado;
}
bool tarea:: setestado(bool v){
estado=v;
}
#endif
