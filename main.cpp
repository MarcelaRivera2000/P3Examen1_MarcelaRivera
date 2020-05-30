#include <iostream>
#include <string> 
#include <vector>
#include "tarea.h"
#include <stdlib.h> 
#include <time.h> 
#include "empleado.h"

using namespace std; 
using std::cin;
using std::endl;
using std::cout;

void IngEmpleados();
void IngTareas();
void proyecto();
void dia_siguiente();
vector <empleado*> empleados;
vector <tarea*> tareas;

	
int main(int argc, char** argv) {
		while(true){
		int op;
		cout<<"1.Contratar empleado"<<endl<<"2.Despedir empleado"<<endl<<"3.Listar empleados"<<endl<<
			  "4.Crear tarea"<<endl<<"5.Listar tarea"<<endl<<"6.Iniciar proyecto"<<endl<<"7.salir"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				IngEmpleados();
				break;
			}
			case 2:{
				for(int i=0;i<empleados.size();i++){
					cout<<i<<"."<<empleados[i]->getnombre()<<endl;
				}
				int posi;
				cout<<endl<<"Ingrese la posicion de el empleado: "<<endl<<": ";
				cin>>posi;
				empleados.erase( empleados. begin() + posi );
				break;
			}
			case 3:{
				for(int i=0;i<empleados.size();i++){
					cout<<i<<"."<<empleados[i]->getnombre()<<endl;
					
				}
				break;
			}
			case 4:{
				IngTareas();
				break;
			}
			case 5:{
				for(int i=0;i<tareas.size();i++){
					cout<<i<<"."<<tareas[i]->getdescrip()<<endl;
				}
				break;
			}
			case 6:{
				 proyecto();
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
	while(nivel<1||nivel>3){
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
	empleado* e = new empleado(nombre,edad,nivel,habilidad,pereza,false);
	empleados.push_back(e);
}

void IngTareas(){
	string descripcion;
	int nivel,carga;
	cout<<endl<<"Ingrese una descrpcion"<<endl<<": ";
	cin>> descripcion;
	cout<<endl<<"Ingrese el nivel"<<endl<<": ";
	cin>>nivel;
	while(nivel<1||nivel>3){
		cout<<"Dato incorrecto,vuelvalo a ingresar"<<endl<<"Ingrese el nivel"<<endl<<": ";
		cin>>nivel;
	}
	cout<<endl<<"Ingrese la carga de la tarea"<<endl<<": ";
	cin>>carga;
	tarea* t =new tarea(descripcion,nivel,carga,false);
	tareas.push_back(t);
	
}

void proyecto(){
	int dias=0;
	for(int i=0;i<tareas.size();i++){
		dias+=tareas[i]->getcarga();
	}
	cout<<"Dias para terminar el proyecto:"<<dias<<endl<<endl;
	while(tareas.size()!=0){
		int op;
		cout<<"1. Siguiente dia"<<endl<< "2. Generar reporte"<<endl<<"3. Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				dias--;
				cout<<"Dia: "<<dias<<endl;
				
				break;
			}
			case 2:{
				dia_siguiente();
				break;
			}
			case 3:{
				cout<<"Fin del proyecto con"<<dias<<" dias faltantes"<<endl;
				exit (EXIT_FAILURE);
				break;
			}
		}		
	}	
	cout<<"TERMINADO"<<endl;
}

void dia_siguiente(){
	int back=0,progreso=0,perezosos=0,fallaron=0,lograron=0;	
	for(int i=0;i<empleados.size();i++){
		for(int j=0;j<tareas.size();j++){
			if(tareas[j]->getnivel()<=empleados[i]->getnivel()){
				if(empleados[i]->getestado()==false &&tareas[j]->getestado()==false){
					empleados[i]->setTarea(tareas[j]);
					empleados[i]->setestado(true);
					tareas[j]->setestado(true);
					progreso++;
				}
				srand (time(NULL));
				int x = rand() % 101;
				if(empleados[i]->getpereza()<x){
					perezosos++;
					int h=rand() % 101;
					if(empleados[i]->gethabilidad()<h){
						fallaron++;		
					}else{
						lograron++;
						if(tareas[j]->getcarga()==0){
							tareas.erase( tareas. begin() + j );

						}else{
							tareas[j]->setCarga(tareas[j]->getcarga()-1);

						}
					}
				}
			}else{
				back++;
			}
		}
	}
	cout<<endl<<"------------------------"<<"Tareas en backlog: "<<back<<endl<<"Tareas en proceso: "<<progreso<<endl<<
	"Empleados Perezosos: "<<perezosos<<endl<<"Empleados que fallaron: "<<fallaron<<endl<<"Empleados que lo lograron: "<<lograron<<endl;
	cout<<endl;
}


































