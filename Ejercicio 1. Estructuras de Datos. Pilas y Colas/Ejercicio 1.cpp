/*
	Ejercicio con estructuras de tipo Pila y Cola
*/


#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;

int numeros[10];
int numerosOrdenados[10];
int aux;

// Funciones auxiliares
bool esPar(int num) {
	return num % 2 == 0;
}

bool esEntero(int num) {
	return num % 1 == 0;
}

void ordenarArreglo() {
	for (int i=0; i<10; i++) {
		
		for (int j=0; j<9; j++){
			
			if (numerosOrdenados[j] > numerosOrdenados[j+1]){
				aux = numerosOrdenados[j];
				numerosOrdenados[j] = numerosOrdenados[j+1];
				numerosOrdenados[j+1] = aux;
			}
		}
	}
}

// Encolar y Apilar un valor
void ingresarDatos(int tipo){
	
	if (tipo == 1) {
		std::cout << "\n*** ESTRUCTURA DE TIPO COLA ***" << std::endl;
		std::cout << " Ingresando valores en la cola " << std::endl;
	} else if (tipo == 0) {
		std::cout << "\n*** ESTRUCTURA DE TIPO PILA ***" << std::endl;
		std::cout << " Ingresando valores en la pila " << std::endl;
	}
	
	for (int i=0; i<10; i++) {
		
		do {
			std::string numero2;
			bool valorRepetido = false;
			bool valorEsPar = false;
			bool valorEsEntero = false;
			
			// Solicitando el número
	        std::cout << "Ingresa el numero de la posición #" << i << ": ";
	        std::cin >> numero2;
	        int numero = std::atoi(numero2.c_str());
			
			// Verificando que el dato no se repite
	        for (int j=0; j<i; j++) {
	        	if (numeros[j] == numero) {
	        		valorRepetido = true;
	        		break;
				}
			}
			
			// Verificando que es par
			valorEsPar = esPar(numero);
			
			// Verificando que es entero
			valorEsEntero = esEntero(numero);
			
			// Almacenando el valor en el arreglo
	        if (valorRepetido == false && valorEsPar == true && valorEsEntero && numero > 0) {
	        	numeros[i] = numero;
	        	numerosOrdenados[i] = numero;
			} else {
				std::cout << "Ingresa un valor entero, positivo, par e irrepetible." << std::endl;
			}
			
		} while (numeros[i] == 0);
        
    }
	
}

// Buscar valor en la cola o en la pila
void buscarValor(int tipo){
	
	bool valorEncontrado = false;
	
	do {
		int valor;
		
		
		if (tipo == 1) {
			std::cout << "\n*** BUSCAR VALOR EN LA COLA ***" << std::endl;
			std::cout << "Ingresa el valor a busar en la cola: ";
		} else if (tipo == 0) {
			std::cout << "\n*** BUSCAR VALOR EN LA PILA ***" << std::endl;
			std::cout << "Ingresa el valor a busar en la pila: ";
		}
		
		std::cin >> valor;
		
		for (int i=0; i<10; i++) {
			if(numeros[i] == valor){
				std::cout << "El valor " << valor << " esta en la posicion " << i << std::endl;
				valorEncontrado = true;
			}
		}
		
		if (!valorEncontrado) {
			std::cout << "El valor no existe"<< std::endl;
		}
	} while (valorEncontrado == false);
	
}

// Valor más pequeño en la cola o en la pila
void valorPequeno(){
	std::cout << "\n*** BUSCANDO EL VALOR MAS PEQUENO ***" << std::endl;
	
	ordenarArreglo();
	
	for (int i=0; i<10; i++) {
		
		if (numerosOrdenados[0] == numeros[i]){
			std::cout << "El valor mas pequeno es el numero " << numerosOrdenados[0] << " y esta en la posicion " << i << std::endl;
		}
	}
}

// Valor más grande en la cola o en la pila
void valorGrande(){
	std::cout << "\n*** BUSCANDO EL VALOR MAS GRANDE ***" << std::endl;
	
	ordenarArreglo();
	
	for (int i=0; i<10; i++) {
		
		if (numerosOrdenados[9] == numeros[i]){
			std::cout << "El valor mas grande es el numero " << numerosOrdenados[9] << " y esta en la posicion " << i << std::endl;
		}
	}
}

// Desencolar estructura
void desencolar(){
	std::cout << "\n*** Desencolando estructura ***" << std::endl;
	
	for (int i=0; i<10; i++) {
		std::cout << "El valor extraido es el numero " << numeros[i] << " en la posicion #" << i << std::endl;
	}

	std::cout << "La cola ya esta vacia" << std::endl;
}

// Desapilar estructura
void desapilar(){
	std::cout << "\n*** Desapilando estructura ***" << std::endl;
	
	for (int i=9; i>=0; i--) {
		std::cout << "El valor desapilado es el numero " << numeros[i] << " en la posicion #" << i << std::endl;
	}
	
	std::cout << "La pila ya esta vacia." << std::endl;
}

// Muestra el menu principal
void mostrarMenuPrincipal(){
	std::cout << "*** MENU DE OPCIONES ***" << std::endl;
	std::cout << "1. Pila" << std::endl;
	std::cout << "2. Cola" << std::endl;
	std::cout << "3. Salir\n" << std::endl;
	}

// Muestra el menu de pilas
void mostrarMenuPilas(){
	
	int opcionPilas;
	
	do {
		std::cout << "\n*** ESTRUCTURA DE TIPO PILA ***" << std::endl;
		std::cout << "1. Apilar valor" << std::endl;
		std::cout << "2. Buscar valor en la pila" << std::endl;
		std::cout << "3. Valor mas pequeño" << std::endl;
		std::cout << "4. Valor mas grande" << std::endl;
		std::cout << "5. Desapilar estructura" << std::endl;
		std::cout << "6. Regresar al menu principal\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcionPilas;
		
		switch (opcionPilas) {
			case 1: 
				ingresarDatos(0);
				std::cout << "La pila ya esta llena\n";
				break;
			case 2:
				buscarValor(0);
				break;
			case 3:
				valorPequeno();
				break;
			case 4:
				valorGrande();
				break;
			case 5:
				desapilar();
				break;
			case 6:
				std::cout << "Regresaste al menu principal\n\n";
				break;
		}
	} while (opcionPilas != 6);
}

// Muestra el menu de colas
void mostrarMenuColas(){
	
	int opcionColas;
	
	do {
		std::cout << "\n*** ESTRUCTURA DE TIPO COLA ***" << std::endl;
		std::cout << "1. Encolar valor" << std::endl;
		std::cout << "2. Buscar valor en la cola" << std::endl;
		std::cout << "3. Valor mas pequeño" << std::endl;
		std::cout << "4. Valor mas grande" << std::endl;
		std::cout << "5. Desencolar estructura" << std::endl;
		std::cout << "6. Regresar al menu principal\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcionColas;
		
		switch (opcionColas) {
			case 1: 
				ingresarDatos(1);
				std::cout << "La cola ya esta llena\n";
				break;
			case 2:
				buscarValor(1);
				break;
			case 3:
				valorPequeno();
				break;
			case 4:
				valorGrande();
				break;
			case 5:
				desencolar();
				break;
			case 6:
				std::cout << "Regresaste al menu principal\n";
				break;
		}
	} while (opcionColas != 6);
}

int main(){
		
	int opcionPrincipal;
	
	do{
		mostrarMenuPrincipal();
		
		std::cout << "Elige una opcion: ";
		std::cin >> opcionPrincipal;
		
		switch (opcionPrincipal) {
			case 1: 
				mostrarMenuPilas();
				break;
			case 2:
				mostrarMenuColas();
				break;
			case 3:
				std::cout << "Saliste del programa." << std::endl;
				break;
			default:
				std::cout << "Opcion invalida. Por favor, ingrese un numero valido." << std::endl;
		}
	} while (opcionPrincipal != 3);
}


