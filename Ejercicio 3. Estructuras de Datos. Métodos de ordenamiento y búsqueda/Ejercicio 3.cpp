#include <iostream>
#include <string>

std::string alumnos[10];
std::string rAlumnos[10];
float calificaciones[10];
float rCalificaciones[10];	
std::string alumnoBuscar;

// Métodos auxiliares (Vuelve al arreglo a su estado inicial, en el mismo orden que el arreglo de respaldo)
void restaurarArregloOrdenado() {
	for (int i=0; i<10; i++) {
        calificaciones[i] = rCalificaciones[i];
	}
}

// Ordenando los datos por alumno
void ordenarAlumnos() {
	std::string aux;
	for (int i=0; i<10; i++) {
		for (int j=0; j<9; j++) {
			if (alumnos[j] > alumnos[j+1]) {
				aux = alumnos[j];
				alumnos[j] = alumnos[j+1];
				alumnos[j+1] = aux;
			}
		}
	}
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (alumnos[i] == rAlumnos[j]) {
				std::cout << "Posicion # " << i <<  "  Alumno: " << alumnos[i] << "    Calificacion: " << rCalificaciones[j] << std::endl;
			}
		}
	}
		
}

// Llenar los arreglos de alumnos y calificaciones
void llenarArreglos() {
	std::cout << "\n##   Llenando los arreglos   ##" << std::endl;
	std::cout << "  ##   Ingrese los datos   ##\n" << std::endl;
	
	for (int i=0; i<10; i++) {
		
		do {
			float calificacion = 0;
			std::cout << "Alumno en posicion #" <<i <<": ";
			std::cin >> alumnos[i];
			rAlumnos[i] = alumnos[i];
			std::cout << "  Calificacion: ";
			std::cin >> calificacion;
			std::cout << "" << std::endl;
			
			if ((calificacion>0) && (calificacion<=10)) {
				calificaciones[i] = calificacion;
				rCalificaciones[i] = calificacion;
			} else {
				std::cout << "Ingresa un numero mayor a 0 o, menor o igual a 10" << std::endl;
			}
			
		} while (calificaciones[i] == 0);
		
	}
	
	for (int i=0; i<10; i++) {
		std::cout << "Alumno en posicion #" <<i <<": " << alumnos[i] << "    Calificacion: " << calificaciones[i] << std::endl;
	}
}

// Método de ordenación burbuja
void ordenarBurbuja() {
	restaurarArregloOrdenado();
	std::cout << "\n##   Ordenando los datos por metodo burbuja   ##" << std::endl;
	float aux;
	int iteraciones = 0;
	
	for (int i=10; i>0; i--) {
		for (int j=9; j>0; j--) {
			if (calificaciones[j] > calificaciones[j-1]) {
				aux = calificaciones[j];
				calificaciones[j] = calificaciones[j-1];
				calificaciones[j-1] = aux;
			}
			iteraciones++;
		}
	}

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (calificaciones[i] == rCalificaciones[j]) {
				std::cout << "Posicion # " << i <<  "  Alumno: " << alumnos[j] << "    Calificacion: " << calificaciones[i] << std::endl;
			}
		}	
	}
	
	std::cout << "Numero de iteraciones en metodo burbuja: " << iteraciones << std::endl;
	char tecla = std::cin.get();
	std::cin.ignore();
	
}

// Método de ordenación por inserción
void ordenarInsercion() {
	restaurarArregloOrdenado();
	std::cout << "\n##   Ordenando los datos por metodo insercion   ##" << std::endl;
	float key;
	int iteraciones = 0;
	
	for (int i=1; i<10; i++) {
		key = calificaciones[i]; 
		int j = i - 1;
		
		while (j >= 0 && calificaciones[j] < key) {
			calificaciones[j + 1] = calificaciones[j];
            j--;
			iteraciones++;
		}
		
		calificaciones[j + 1] = key;
	}
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (calificaciones[i] == rCalificaciones[j]) {
				std::cout << "Posicion # " << i <<  "  Alumno: " << alumnos[j] << "    Calificacion: " << calificaciones[i] << std::endl;
			}
		}	
	}
	
	std::cout << "Numero de iteraciones en metodo insercion: " << iteraciones << std::endl;
	char tecla = std::cin.get();
	std::cin.ignore();
}

//Método de ordenación por selección
void ordenarSeleccion() {
	restaurarArregloOrdenado();
	std::cout << "\n##   Ordenando los datos por metodo seleccion   ##" << std::endl;
	int iteraciones = 0;
	
	for (int i=0; i<9; i++) {
		int maxIndice = i;
		
		for (int j=i+1; j<10; j++) {
			if (calificaciones[j] > calificaciones[maxIndice]) {
				maxIndice = j;
			}
			iteraciones++;
		}
		
		if (maxIndice != i) {
			std::swap(calificaciones[i], calificaciones[maxIndice]);
		}
	}
	
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (calificaciones[i] == rCalificaciones[j]) {
				std::cout << "Posicion # " << i <<  "  Alumno: " << alumnos[j] << "    Calificacion: " << calificaciones[i] << std::endl;
			}
		}	
	}
	
	std::cout << "Numero de iteraciones en metodo seleccion: " << iteraciones << std::endl;
	char tecla = std::cin.get();
	std::cin.ignore();
	
}

// Algoritmo para odernar Quicksort
int iteracion = 0;
int particion(float calificaciones[], int inicio, int fin) {
	float pivote = calificaciones[fin];
	int i = (inicio -1);
	
	for (int j=inicio; j <= fin-1; j++) {
		if (calificaciones[j] >= pivote) {
			i++;
			std::swap(calificaciones[i], calificaciones[j]);
		}
		iteracion++;
	}
	
	std::swap(calificaciones[i+1], calificaciones[fin]);
	return (i+1);
}

void metodoQuicksort(float calificaciones[], int inicio, int fin) {
	if (inicio < fin) {
		int pivoteIndice = particion(calificaciones, inicio, fin);
		
		metodoQuicksort(calificaciones, inicio, pivoteIndice - 1);
		metodoQuicksort(calificaciones, pivoteIndice + 1, fin);
		
	}
}

// Método de ordenacion Quicksort
void ordenarQuicksort() {
	iteracion = 0;
	restaurarArregloOrdenado();
	std::cout << "\n##   Ordenando los datos por metodo Quicksort   ##" << std::endl;
	
	metodoQuicksort(calificaciones,0,9);
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (calificaciones[i] == rCalificaciones[j]) {
				std::cout << "Posicion # " << i <<  "  Alumno: " << alumnos[j] << "    Calificacion: " << calificaciones[i] << std::endl;
			}
		}	
	}
	
	std::cout << "Numero de iteraciones en metodo quicksort: " << iteracion << std::endl;
	char tecla = std::cin.get();
	std::cin.ignore();
	
} 

// Ordenar los datos en los arreglos alumnos y calificaciones
void ordenarDatos() {
	
	int opcion;
	
	do {
		std::cout << "\n##  Metodos de ordenacion  ##\n" << std::endl;
		std::cout << "1. Burbuja" << std::endl;
		std::cout << "2. Insercion" << std::endl;
		std::cout << "3. Seleccion" << std::endl;
		std::cout << "4. Quicksort\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			ordenarBurbuja();
			opcion = 5;
			break;
		case 2:
			ordenarInsercion();
			opcion = 5;
			break;
		case 3:
			ordenarSeleccion();
			opcion = 5;
			break;
		case 4:
			ordenarQuicksort();
			opcion = 5;
			break;
		}
	}while (opcion != 5);
	
}

// Algoritmo de búsqueda secuencial
void buscarSecuencial() {
	std::cout << "\n$$   Buscando datos por busqueda secuencial   $$" << std::endl;
	std::cout << "Ingresa el alumno a buscar: ";
	std::cin >> alumnoBuscar;
	bool alumnoEncontrado = false;
	
	for (int i=0; i<10; i++) {
		std::cout << "Posicion # " << i <<  "  Alumno: " << rAlumnos[i] << "    Calificacion: " << rCalificaciones[i] << std::endl;
	}
	
	for (int i=0; i<10; i++) {
		if(rAlumnos[i] == alumnoBuscar) {
			std::cout << "\nEl alumno " << rAlumnos[i] << " se encuentra en la posicion # " << i << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			alumnoEncontrado = true;
			break;
		} 
	}
	
	if(alumnoEncontrado == false){
		std::cout << "El dato no existe." << std::endl;
	} 
	
	char tecla = std::cin.get();
	std::cin.ignore();	
}

// Algoritmo búsqueda binaria
void buscarBinaria() {
	std::cout << "$$   Buscando datos por metodo binario   $$" << std::endl;
	std::cout << "Ingresa el alumno a buscar: ";
	std::cin >> alumnoBuscar;
	int inferior = 0;
	int superior = 10;
	int mitad = (inferior + superior)/2;
	bool alumnoEncontrado = false;
	ordenarAlumnos();
		
	for (int i=0; i<10; i++) {
		
		if (alumnos[mitad] == alumnoBuscar) {
			std::cout << "\nEl alumno " << alumnos[mitad] << " se encuentra en la posicion # " << mitad << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			alumnoEncontrado = true;
			break;
		}
		
		if(alumnos[mitad] > alumnoBuscar){
			superior = mitad;
			mitad = (inferior + superior)/2;
		}
		
		if (alumnos[mitad] < alumnoBuscar) {
			inferior = mitad;
			mitad = (inferior + superior)/2;
		}
		
		if ((mitad == inferior && alumnoEncontrado == false) | (mitad == superior && alumnoEncontrado == false)) {
			std::cout << "El dato no existe." << std::endl;
			std::cout << "Numero de iteraciones: " << i+1 << std::endl;
			break;
		}
	}
	
	char tecla = std::cin.get();
	std::cin.ignore();
	
}

float buscarAlumno(std::string alumno) {
	for (int i=0; i<10; i++) {
		if (rAlumnos[i] == alumno) {
			return rCalificaciones[i];
		}
	}
	return -1;
}

// Algoritmo búsqueda por interpolación
void buscarInterpolacion() {
	std::cout << "$$   Buscando datos por metodo de interpolacion   $$" << std::endl;
	std::cout << "Ingresa el alumno a buscar: ";
	std::cin >> alumnoBuscar;	
	ordenarAlumnos();
	float calificacion = buscarAlumno(alumnoBuscar);
	int inicio = 0;
	int fin = 9;
	int indice;
	bool alumnoEncontrado = false;
	
	for (int i=0; i<10; i++) {
		
		indice = ((fin) * (calificacion - calificaciones[inicio]) / (calificaciones[fin] - calificaciones[inicio]));
		
		if (indice>fin) {
			break;
		} else if (indice<0) {
			break;
		}
		
		if (indice<inicio) {
			indice = inicio;
		}
		
		if (indice>=inicio && indice<=fin) {
			if (calificaciones[indice] == calificacion) {
				std::cout << "\nEl alumno " << alumnos[indice] << " se encuentra en la posicion # " << indice << std::endl;
				std::cout << "Numero de iteraciones: " << i+1 << std::endl;
				alumnoEncontrado = true;
				break;
			} else if (calificaciones[indice] < calificacion) {
				fin = fin -1;
			} else if (calificaciones[indice] > calificacion) {
				inicio = inicio + 1;
			}
		}
	}
	
	if (alumnoEncontrado == false) {
		std::cout << "El dato no existe." << std::endl;
	}
	
	char tecla = std::cin.get();
	std::cin.ignore();
}

// Buscando datos Menú
void buscarDatos() {
	
	int opcion;
	
	do {
		std::cout << "\n##  Metodos de busqueda  ##\n" << std::endl;
		std::cout << "1. Secuencial" << std::endl;
		std::cout << "2. Binaria" << std::endl;
		std::cout << "3. Por interpolacion\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			buscarSecuencial();
			opcion = 4;
			break;
		case 2:
			buscarBinaria();
			opcion = 4;
			break;
		case 3:
			buscarInterpolacion();
			opcion = 4;
			break;
		}
	}while (opcion != 4);
	
}

// Menú principal
int main() {  

	int opcion;
	
	do {
		std::cout << "\n***  MENU DE OPCIONES  ***" << std::endl;
		std::cout << "1. Llenado de arreglos" << std::endl;
		std::cout << "2. Ordenacion de datos" << std::endl;
		std::cout << "3. Busqueda de datos" << std::endl;
		std::cout << "4. Salir\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			llenarArreglos();
			break;
		case 2:
			ordenarDatos();
			break;
		case 3:
			buscarDatos();
			break;
		case 4:
			std::cout << "Saliste del programa.";
		}
	
	}while (opcion != 4);

	return 0;
}
