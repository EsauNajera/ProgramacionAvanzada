
/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-02-20.11-31
Practica Clases Heredadas con Constructor
************************/
#include <iostream>
class A {
public:
A(int argA){
std::cout<<"Hola desde A\n";
varA=argA;
}
int getA(){return(varA);}
private:
int varA;
};

class B : public A {
public:
	B(int argA,int argB) : A(argA){
		std::cout<<"Hola desde B\n";
		varB=argB;
	}
	int getB(){return(varB);}
private:
	int varB;
};

int main(){
A testA(10);
std::cout<<"varA: "<<testA.getA()<<std::endl;
B testB(101,102);
std::cout<<"B class varA: "<<testB.getA()<<std::endl;
std::cout<<"B class varB: "<<testB.getB()<<std::endl;
}
