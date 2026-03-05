//Programa de Ejemplo 3

//Instituto Tecnologico de Durango
//Departamento Metal-Mecanica
//Ingenieria Mecatronicac
//Periodo Escolar: Enero-Junio 2026
//Davey Corral Carlos Alberto No. Control: 23041001
//Programa de Clase Ejemplo 3, este programa es un ejemplo de uso de una funcion con llamada por 

#include <iostream>

using namespace std;

int ver_numero(int valor){
	
	//intrucciones a ejecutar cada llamada de la funcion
	cout << "El valor del parametro es " << valor <<  endl;
}

int main(){
	
	ver_numero(1);// primera llamada se lleva el parametro ("dato")
	ver_numero(1801); //segunda llamada
	ver_numero(-53); //tercer llamada
	
}
