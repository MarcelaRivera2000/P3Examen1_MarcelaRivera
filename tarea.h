#ifndef TAREA_H
#define TAREA_H
#include<string>

using namespace std; 

class tarea{	
	public: 
		int getnivel();
		int getcarga();	
		void setCarga(int car);
		string getdescrip();
		tarea(string d,int n,int c,bool e);
		bool getestado();
		bool setestado(bool v);
		bool getterminado();
		bool setterminado(bool vv);
		~tarea();
	private:
		string descripcion;
		int nivel,carga;
		bool estado;
		bool terminada;
		
};

tarea::tarea(string d,int n,int c,bool e){
	descripcion=d;
	nivel=n;
	carga=c;
	estado=e;
	terminada=false;
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

bool tarea::getterminado(){
	return terminada;
}

bool tarea:: setterminado(bool vv){
terminada=vv;
}

void tarea::setCarga(int car){
	carga=car;
}
#endif
