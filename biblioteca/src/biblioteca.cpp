//============================================================================
// Name        : biblioteca.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <vector>
using namespace std;
/*Titulo:nombre del libro
 * Codigo:Numero de libro(asignado por el encargado del registro)
 * Clasificacion: Cuentos infantiles,Novelas clasicas,Novelas adolescentes,Historia,Matematica,Ciencias)
 * Estado(string):En buen estado,Dañado.
 * Guardado:Recurso para saber si un libro ya ha sido almacenado o no
 */
struct libro{
	string titulo;
	string codigo;
	string clasificacion;
	string estado;
	int guardado;
};
typedef struct libro libro;
void pantalla_principal();
void lista_libros();
void inventariado();
void crear_archivo_de_libros(libro dato){
	ofstream archivo;
	archivo.open("libros.txt",ios::out|ios::binary|ios::app);
	archivo.write(dato.titulo.c_str(),50);
	archivo.write(dato.codigo.c_str(),50);
	archivo.write(dato.clasificacion.c_str(),50);
	}
//Registro de nuevo material que ingresa a la biblioteca
void registrar_libro(){
	libro libro_ingresado;
	int estado;
	int accion;
	cout<<"*******REGISTRO DE LIBROS*******"<<endl;
	cout<<"Ingrese Titulo del Libro"<<endl;
	cin.ignore();
	getline(cin,libro_ingresado.titulo);
	cout<<"Ingrese Clasificación del Libro"<<endl;
	getline(cin,libro_ingresado.clasificacion);

	cout<<"Seleccione estado"<<endl;
	cout<<"[1]Estado Optimo"<<endl;
	cout<<"[2]Para mantenimiento"<<endl;
	cin>>estado;
	if(estado==1){
		libro_ingresado.estado="Buen estado";

	}
	if(estado==2){
		libro_ingresado.estado="Dañado";
	}
	crear_archivo_de_libros(libro_ingresado);
	cout<<"¿Desea registrar otro material?"<<endl;
	cout<<"[1] Si"<<endl;
	cout<<"[2] No"<<endl;
	cin>>accion;
	system("cls");
	if(accion==1){
	 registrar_libro();
	}
	if(accion==2){
		pantalla_principal();
	}


	}
/*
 * funcion pantalla_principal:Funcion para abrir la pantalla de inicio que muestra al
 * usuario las opciones:
 * -De -ingresar un nuevo registro
 * -Acceder al inventario donde se muestran los libros con sus respectivos titulos y con la cantidad de ejemplares existentes
 * -Acceder al inventario de todos los libros en general con su respectivo codigo,titulo y estado del material
 *
 */
void pantalla_principal(){
	int elegir;
	cout<<"                                                ********BIBLIOTECA RICARDO PALMA********     "<<endl;
	cout<<"                                                      ***Sistema de Inventario***              "<<endl;
	cout<<" "<<endl;
	cout<<"                                                    [1] Registrar material nuevo"<<endl;
	cout<<"                                                    [2] Mostrar lista de libros registrados"<<endl;
	cout<<"                                                    [3] Mostrar inventario(Por cantiddad)"<<endl;
  cin>>elegir;
  system("cls");
  if(elegir==1){
	  registrar_libro();
  }
  /*if(elegir==2){
	  lista_libros();
  }
  if(elegir==3){
	  inventariado();
  }*/

}
int main() {
	pantalla_principal();

system("pause");


	return 0;
}
