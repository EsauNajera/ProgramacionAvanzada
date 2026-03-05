//Programa de Ejemplo 4

//Instituto Tecnologico de Durango
//Departamento Metal-Mecanica
//Ingenieria Mecatronica
//Periodo Escolar: Enero-Junio 2026
//Davey Corral Carlos Alberto No. Control: 23041001
//Programa de Clase Ejemplo 4, este programa es un ejemplo de uso de una matriz

#include <iostream>

using namespace std;

// Declaraci�n de constante
const int A32 = 10;

// Variable tipo caracter
char variable = 'Z';

// Matriz booleana
bool m[3][3] = {true, false, true, false, false, true, true, false, false};

// Vector de caracteres
char vectorChar[3] = {'x','a','w'};

// Vector de numeros flotantes
float vectorFloat[5] = {1.1, 2.3, 0.45, 413.08, 1013.005};

int main()
{
    cout << "Valor de la constante A32: " << A32 << endl;
    cout << "Valor de la variable char: " << variable << endl;

    cout << "\nValores de la matriz booleana:" << endl;
    for(int i = 0; i <3; i++){
	for(int j = 0; j < 3; j++)
    {
        cout << m[i][j] << " ";
    }
    	cout << endl;
	}
    
	cout << "\nValores del vector de caracteres:" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << vectorChar[i] << " ";
    }

    cout << "\n\nValores del vector de flotantes:" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << vectorFloat[i] << " ";
    }

    cout << endl;

    return 0;
}
