#include <iostream>
#include <string> 
#include <vector>
#include "empleado.h"
#include "tarea.h"


using namespace std; 
using std::cin;
using std::endl;
using std::cout;

vector <empleado> empleados;
vector <tarea> tareas;
void IngEmpleados();
void IngTareas();
empleado* empleado=NULL;

int main(int argc, char** argv) {
		while(true){
		int op;
		cout<<"1.Contratar empleado"<<endl<<"2.Despedir empleado"<<endl<<"3.Listar empleados"<<endl<<"4.Crear tarea"<<endl<<"5.Listar tarea"<<endl<<"6.Iniciar proyecto"<<endl<<"7.salir"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				IngEmpleados();
				break;
			}
			case 2:{
				
				break;
			}
			
			case 3:{
				
				break;
			}
			case 4:{
				IngTareas();
				break;
			}
			case 5:{
				
				break;
			}
			case 6:{
				
				break;
			}
			case 7:{
				exit (EXIT_FAILURE);
				break;
			}
		}
	}
	return 0;
}

void IngEmpleados(){
	string nombre;
	int edad,nivel,habilidad,pereza;
	cout<<endl<<"Ingrese el nombre"<<endl<<": ";
	cin>>nombre;
	cout<<endl<<"Ingrese la edad"<<endl<<": ";
	cin>>edad;
	cout<<endl<<"Ingrese el nivel"<<endl<<": ";
	cin>>nivel;
	while(nivel!=1||nivel!=2||nivel!=3){
		cout<<"Dato incorrecto,vuelvalo a ingresar"<<endl<<"Ingrese el nivel"<<endl<<": ";
		cin>>nivel;
	}
	cout<<endl<<"Ingrese el porcentaje de habilidad"<<endl<<": ";
	cin>>habilidad;
	while(habilidad<0||habilidad>100){
		cout<<"Dato incorrecto,vuelvalo a ingresar"<<endl<<"Ingrese el porcentaje de habilidad"<<endl<<": ";
		cin>>habilidad;
	}
	cout<<endl<<"Ingrese el porcentaje de pereza"<<endl<<": ";
	cin>>pereza;
	while(pereza<0||pereza>100){
		cout<<"Dato incorrecto,vuelvalo a ingresar"<<endl<<"Ingrese el porcentaje de pereza"<<endl<<": ";
		cin>>pereza;
	}
	empleado e=empleado(nombre,edad,nivel,habilidad,pereza);
	empleados.push_back(e);
}

void IngTareas(){
	string descripcion;
	int nivel,carga;
	cout<<endl<<"Ingrese una descrpcion"<<endl<<": ";
	cin>> descripcion;
	cout<<endl<<"Ingrese el nivel"<<endl<<": ";
	cin>>nivel;
	while(nivel!=1||nivel!=2||nivel!=3){
		cout<<"Dato incorrecto,vuelvalo a ingresar"<<endl<<"Ingrese el nivel"<<endl<<": ";
		cin>>nivel;
	}
	cout<<endl<<"Ingrese la carga de la tarea"<<endl<<": ";
	cin>>carga;
	tarea t=tarea(descripcion,nivel,carga);
	tareas.push_back(t);
}




































