//Programa de Ejemplo 2

//Instituto Tecnologico de Durango
//Departamento Metal-Mecanica
//Ingenieria Mecatronicac
//Periodo Escolar: Enero-Junio 2026
//Davey Corral Carlos Alberto No. Control: 23041001
//Programa de Clase Ejemplo 2, este programa es un ejemplo de un registros (con struct) estructura, donde guarda los datos de una persona

// Declaracion de librerias
#include <iostream> //Barrido Rapido de Entrada o Salida {Cout-Cin};

using namespace std;

int main (){ //procedimiento principal
	
	struct{
	string nombre;
	char inicial;
	int edad;
	float nota;
	} persona;
	
	persona.nombre = "Juan";
	persona.inicial = 'J';
	persona.edad = 20;
	persona.nota = 7.5;
	cout << "La edad es " << persona.edad;
	
return 0;
}
