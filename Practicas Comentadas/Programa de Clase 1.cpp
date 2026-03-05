//Programa de Ejemplo 1

//Instituto Tecnologico de Durango
//Departamento Metal-Mecanica
//Ingenieria Mecatronicac
//Periodo Escolar: Enero-Junio 2026
//Davey Corral Carlos Alberto No. Control: 23041001
//Programa de Clase Ejemplo 1, valor promedio

// Declaracion de librerias
#include <stdio.h> // scanf teclado, printf pantalla
#include <iostream> //Barrido Rapido de Entrada o Salida {Cout-Cin};
#include <conio.h> // entrada y salida de la consola, KB, screen o printer

using namespace std; //me preste un espacio standard (100 bytes) 

//Instanciar o declarar o asignar o meter datos;
int temp[31],i,suma;
float avg, tprom;
int dias;

int main() {
	
	//Encontrar el valor promedio
	
	printf("Cuantos dias del mes, necesitas?");
	scanf("%d",&dias);
	
	//Captura la cantidad de dias
	
	for(i=0;i<dias;i++){
		printf("\n dame la temperatura del dia: %d",i+1);
		printf("   ");
		scanf("%d", &temp[i]);
		printf("\n");	
	}

printf("los valores capturados fueron:\n");
for(i=0;i<dias;i++){
	printf("   ");
printf("%d ",temp[i]);

printf("\n\n");	
}	

//printf("Uno de los valores %d",temp[i]);
//calculo el promedio
//float tprom;
	for (i=0;i<dias;i++){
		suma += temp[i];
	tprom = (float)suma/dias;
	
	}
	
	printf("Temperatuar promedio: %.2f\n",tprom);
	
	//Encuentra el valor minimo y el maximo
	int min = temp[0];
    int max = temp[0];

    for (i = 1; i < dias; i++) {
        if (temp[i] > max) {
            max = temp[i];
        }
        if (temp[i] < min) {
            min = temp[i];
        }
    }
	
	printf("\n La temperatura maxima es: %d", max);
	printf("\n La temperatura minima es: %d", min);
	
	getch();
    return 0;
}
