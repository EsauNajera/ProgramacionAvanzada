#include <iostream> // Librería estándar de C++ para operaciones de entrada y salida (como cin y cout).
#include <string.h> // Librería de C para manipular cadenas de caracteres (necesaria aquí para usar 'strcpy').

using namespace std; // Nos permite usar elementos de la biblioteca estándar (como cout o endl) sin tener que escribir "std::" antes de cada uno.

int cuenta_precio; // Variable global. Está declarada pero no se utiliza en ninguna parte de este programa.

class serie_libros { // Definición de la clase principal.
 public: // Sección pública: estos métodos pueden ser llamados desde cualquier parte del programa.
  serie_libros(char *, char *); // Declaración del constructor de la clase (se ejecuta al crear un nuevo libro).
  void ver_libro();             // Método para imprimir en pantalla los datos del libro.
  void poner_precio();          // Método para solicitar y guardar el precio del libro.
  void poner_pags(int *);       // Método para solicitar y guardar las páginas, recibe un puntero.

 private: // Sección privada: estos atributos solo pueden ser modificados o leídos desde dentro de esta misma clase.
  // IMPORTANTE: Al ser 'static', 'pags' y 'precio' son compartidas por TODOS los objetos de esta clase.
  // Si cambias el precio del segundo libro, también cambiará internamente el del primero.
  static int pags; 
  static int precio; 
  char titulo[64]; // Arreglo de caracteres para guardar el título del libro (hasta 63 letras + el carácter nulo).
  char autor[64];  // Arreglo de caracteres para guardar el nombre del autor.
};

// Las variables estáticas de una clase deben inicializarse o definirse fuera de la clase en C++. Aquí se reserva su espacio en memoria.
int serie_libros::pags;
int serie_libros::precio;

// Implementación del método para asignar las páginas.
void serie_libros::poner_pags(int* pags){
	cout<<"Dame el número de páginas\n";
	cin>> *pags; // Toma lo que escribe el usuario y lo guarda en la dirección de memoria a la que apunta el puntero.
}

// Implementación del constructor. Se ejecuta automáticamente cada vez que haces un 'new serie_libros(...)'.
serie_libros::serie_libros(char* titulo, char* autor){
	strcpy(serie_libros::titulo, titulo); // Copia el texto del parámetro 'titulo' hacia el atributo privado 'titulo'.
	strcpy(serie_libros::autor, autor);   // Copia el texto del parámetro 'autor' hacia el atributo privado 'autor'.
	serie_libros::poner_precio();         // Llama a la función para pedirle al usuario que teclee el precio.
	serie_libros::poner_pags(&serie_libros::pags); // Llama a la función de las páginas pasándole la dirección de memoria (&) de la variable estática.
}

// Implementación del método para asignar el precio.
void serie_libros::poner_precio(){
	cout << "Dame el precio para el libro "<<serie_libros::titulo<<" :\n";
	cin >> serie_libros::precio; // Lee el teclado y lo guarda en la variable estática 'precio'.
}

// Implementación del método para imprimir los datos.
void serie_libros::ver_libro(){
	cout << "----------------\n";
	cout << "Nombre: " << serie_libros::titulo<<endl;
	cout << "Autor: " << serie_libros::autor<<endl;
	cout << "Precio: " << serie_libros::precio<<endl;
	cout << "Páginas: " << serie_libros::pags<<endl;
	cout << "----------------\n";
}

// Función principal: es el punto de inicio donde arranca la ejecución del programa.
int main(){
    // Se crea un objeto dinámico en memoria (usando 'new') y se le pasan el título y el autor.
    // Al hacer esto, el constructor se activa y te pedirá en consola el precio y las páginas.
    serie_libros* quimicaII = new serie_libros("Quimica: La Ciencia Central","Brown");
    
    // Como 'quimicaII' es un puntero (por el *), se usa la flecha (->) en lugar de un punto (.) para llamar a sus métodos.
    quimicaII->ver_libro(); 

    // Se crea un segundo objeto dinámico. Activará de nuevo el constructor y te pedirá nuevos datos.
    // OJO: Al sobreescribir las páginas y el precio aquí, se reescriben los valores estáticos.
    serie_libros* misIdeales = new serie_libros("Mein Kampf","A. Hitler");
    misIdeales->ver_libro();

    return(0); // Indica que el programa finalizó con éxito.
}