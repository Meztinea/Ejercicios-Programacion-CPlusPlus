#include <iostream>
#include <string>
#include <cstdlib>

int numeros[10];
int numerosOrdenados[10];
int numeroBuscar;
int aux;

// Funciones auxiliares
// Verifica si es entero
bool esEntero(int num) {
	return num % 1 == 0;
}

// Verifica que es par
bool esPar(int num) {
	return num % 2 == 0;
}

// Verifica que el dato no se repite
bool esRepetido(int num) {
	for(int i=0; i<10; i++) {
		for (int j=0; j<i; j++) {
        	if (numeros[j] == num) {
        		return true;
			}
		}
	}
	return false;
}

// Imprime todos los datos del arreglo
void imprimirArreglo() {
	std::cout << "\nDatos en el arreglo: \n";
	for (int i=0; i<10; i++) {
		std::cout << "Posicion: " << i <<"   ";
		std::cout << "Numero:   " << numeros[i] <<"   \n";
	}
	std::cout << "\n";
}

// Imprime todos los datos del arreglo ordenado
void imprimirArregloOrdenado() {
	std::cout << "\nDatos en el arreglo ordenado: \n";
	for (int i=0; i<10; i++) {
		std::cout << "Posicion: " << i <<"   ";
		std::cout << "Numero:   " << numerosOrdenados[i] <<"   \n";
	}
	std::cout << "\n";
}


// Ordena los datos del arreglo en orden ascendente
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


// Algoritmo de búsqueda secuencial
void busquedaSecuencial() {
	std::cout << "\n*** Busqueda Secuencial ***" << std::endl;
	std::cout << "Ingresa el numero a buscar: ";
	std::cin >> numeroBuscar;
	bool numeroEncontrado = false;
	imprimirArreglo();
	
	std::cout << "\nNumero de iteraciones: " << std::endl;
	for (int i=0; i<10; i++) {
		std::cout << "Iteracion # " << i+1 << ". Dato encontrado: " << numeros[i] << std::endl;
		
		
		if(numeros[i] == numeroBuscar) {
			std::cout << "\nEl numero " << numeros[i] << " se encuentra en la posicion # " << i << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			numeroEncontrado = true;
			break;
		} 
	}
	
	if(numeroEncontrado == false){
		std::cout << "El dato no existe." << std::endl;
	} 
	
}

// Búsqueda binaria
void busquedaBinaria() {

	std::cout << "\n*** Busqueda Binaria ***" << std::endl;
	std::cout << "Ingresa el numero a buscar: ";
	std::cin >> numeroBuscar;
	ordenarArreglo();
	imprimirArregloOrdenado();
	std::cout << "Numero de iteraciones: " << std::endl;
	
	int inferior = 0;
	int superior = 10;
	int mitad = (inferior + superior)/2;
	bool numeroEncontrado;
	
	for (int i=0; i<10; i++) {
		
		std::cout << "Iteracion # " << i+1 << ". Dato encontrado: " << numerosOrdenados[mitad] << std::endl;
		
		if (numerosOrdenados[mitad] == numeroBuscar) {
			std::cout << "\nEl numero " << numerosOrdenados[mitad] << " se encuentra en la posicion # " << mitad << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			numeroEncontrado = true;
			break;
		}
		
		if(numerosOrdenados[mitad] > numeroBuscar){
			superior = mitad;
			mitad = (inferior + superior)/2;
		}
		
		if (numerosOrdenados[mitad] < numeroBuscar) {
			inferior = mitad;
			mitad = (inferior + superior)/2;
		}
		
		if ((mitad == inferior && numeroEncontrado == false) | (mitad == superior && numeroEncontrado == false)) {
			std::cout << "El dato no existe." << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			break;
		}
	}
	
}

// Búsqueda por interpolación 
void busquedaInterpolacion() {
	
	std::cout << "\n*** Busqueda Interpolacion ***" << std::endl;
	std::cout << "Ingresa el numero a buscar: ";
	std::cin >> numeroBuscar;
	ordenarArreglo();
	imprimirArregloOrdenado();
	std::cout << "Numero de iteraciones: " << std::endl;
	
	int inicio = 0;
	int fin = 9;
	int indice;
	bool numeroEncontrado = false;
	
	for (int i=0; i<10; i++) {
		
		indice = ((fin) * (numeroBuscar - numerosOrdenados[inicio]) / (numerosOrdenados[fin] - numerosOrdenados[inicio]));
		std::cout << "Iteracion # " << i+1 << ". Dato encontrado: " << numerosOrdenados[indice] << std::endl;
		
		if (indice>fin) {
			break;
		} else if (indice<0) {
			break;
		}
		
		if (indice<inicio) {
			indice = inicio;
		}
		
		if (indice>=inicio && indice<=fin) {
			if (numerosOrdenados[indice] == numeroBuscar) {
				std::cout << "\nEl numero " << numerosOrdenados[indice] << " se encuentra en la posicion # " << indice << std::endl;
				std::cout << "Numero de iteraciones: " << i+1 << std::endl;
				numeroEncontrado = true;
				break;
			} else if (numerosOrdenados[indice] < numeroBuscar) {
				fin = fin -1;
			} else if (numerosOrdenados[indice] > numeroBuscar) {
				inicio = inicio + 1;
			}
		}
	}
	
	if (numeroEncontrado == false) {
		std::cout << "El dato no existe." << std::endl;
	}
	
}

// Ingresar datos en el arreglo
void ingresarDatos() {
	
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
			valorRepetido = esRepetido(numero);
			
			// Verificando que es par
			valorEsPar = esPar(numero);
			
			// Verificando que es entero
			valorEsEntero = esEntero(numero);
			
			// Almacenando el valor en el arreglo
	        if (valorRepetido == false && valorEsPar && valorEsEntero && numero > 0) {
	        	numeros[i] = numero;
	        	numerosOrdenados[i] = numero;
			} else {
				std::cout << "Ingresa un valor entero, positivo, par e irrepetible." << std::endl;
			}
			
		} while (numeros[i] == 0);
        
    }
	
}

// Método principal
int main() {
	
	int opcion;
	
	do {
		std::cout << "\nMENU DE OPCIONES" << std::endl;
		std::cout << "METODOS DE BUSQUEDA\n" << std::endl;
		std::cout << "1. SECUENCIAL" << std::endl;
		std::cout << "2. BINARIA" << std::endl;
		std::cout << "3. INTERPOLACION" << std::endl;
		std::cout << "4. INGRESAR DATOS" << std::endl;
		std::cout << "5. SALIR\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
			case 1: 
				busquedaSecuencial();
				break;
			case 2:
				busquedaBinaria();
				break;
			case 3:
				busquedaInterpolacion();
				break;
			case 4:
				ingresarDatos();
				break;
			case 5:
				std::cout << "Saliste del programa.";
				break;
			default:
				std::cout << "Opcion invalida. Por favor, ingrese un numero valido." << std::endl;
		}
		
	}while (opcion != 5);
	
	return 0;
}
