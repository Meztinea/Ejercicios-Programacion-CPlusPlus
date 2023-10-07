#include <iostream>

// Define la estructura llamada Nodo
struct Nodo{
	std::string nombre;
	Nodo *der;
	Nodo *izq;
};

// Creando la estructura Árbol
Nodo *arbol = NULL;

// Función para crear un nuevo Nodo
Nodo *crearNodo(std::string nombre) {
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo -> nombre = nombre;
	nuevo_nodo -> der = NULL;
	nuevo_nodo -> izq = NULL;
	
	return nuevo_nodo;
}

// Prototipos
void crearArbol();
void insertarNodo(Nodo *&, std::string);
void mostrarArbol(Nodo *, int);
bool buscarNodo(Nodo *, int);
void buscar();
void recorrerInorden(Nodo *);
void recorrerPreorden(Nodo *);
void recorrerPostorden(Nodo *);

// Método main
int main() {
	int opcion;
	int contador;
	
	do {
		std::cout << "\n##  MENU ARBOL BINARIO  ##\n" << std::endl;
		std::cout << "1. Crear arbol" << std::endl;
		std::cout << "2. Mostrar arbol" << std::endl;
		std::cout << "3. Recorrido Inorden" << std::endl;
		std::cout << "4. Recorrido Preorden" << std::endl;
		std::cout << "5. Recorrido Postorden" << std::endl;
		std::cout << "6. Salir\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			crearArbol();
			break;
		case 2:
			mostrarArbol(arbol, contador);
			break;
		case 3:
			recorrerInorden(arbol);
			break;
		case 4: 
			recorrerPreorden(arbol);
			break;
		case 5: 
			recorrerPostorden(arbol);
			break;
		case 6:
			std::cout << "Saliste del programa." << std::endl;
			break;
		default:
			std::cout << "Digita una opcion valida." << std::endl;
		}

	} while (opcion!=6);
	
	return 0;	
}

// Recorrido posorden
void recorrerPostorden(Nodo *arbol) { // Izq Der Raiz
	if (arbol == NULL) {
		return;
	}
	else {
		recorrerPostorden(arbol->izq);
		recorrerPostorden(arbol->der);
		std::cout << arbol->nombre << "  -  ";
	}
}

// Recorrido preorden
void recorrerPreorden(Nodo *arbol) { // Raíz Izq Der
	if (arbol == NULL) {
		return;
	}
	else {
		std::cout << arbol->nombre << "  -  ";
		recorrerPreorden(arbol->izq);
		recorrerPreorden(arbol->der);
	}
}

// Recorrer Inorden
void recorrerInorden(Nodo *arbol) {  // Izq Raiz Der
	if (arbol == NULL) {
		return;
	}
	else {
		recorrerInorden(arbol->izq);
		std::cout << arbol->nombre << "  -  ";
		recorrerInorden(arbol->der);
	}
}

// Mostrar el árbol
void mostrarArbol(Nodo *arbol, int contador) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, contador+1);
		for (int i=0; i<contador; i++) {
			std::cout << "    ";
		}
		std::cout << arbol->nombre << std::endl;
		mostrarArbol(arbol->izq, contador+1);
	}
}

// Inicia el proceso de creación del árbol
void crearArbol() {
	std::string nombre;
	
	std::cout << "Ingresa el nombre: ";
	std::cin >> nombre;
	Nodo *nuevo_nodo = crearNodo(nombre);
	arbol = nuevo_nodo;
		
	insertarNodo(arbol, nombre);
}

// Inserta femenino o masculino
void insertarNodo (Nodo *&arbol, std::string nombre) {
	if (arbol == NULL) {
		Nodo *nuevo_nodo = crearNodo(nombre);
		arbol = nuevo_nodo;
	}
	else{
		std::string actual = arbol->nombre;
		std::string femenino, masculino, ascendenteFem, ascendenteMas;
		
		if (arbol->izq == NULL) {
			std::cout << actual << "  Tiene ascendente masculino? (S/N): ";
			std::cin >> masculino;
			
			if (masculino == "s" || masculino == "S") {
				std::cout << "Ingresar el nombre: ";
				std::cin >> ascendenteMas;
				insertarNodo(arbol->izq, ascendenteMas);
				insertarNodo(arbol->izq, "");
			}
			
		}
		if (arbol->der == NULL) {
			std::cout << actual << "  Tiene ascendente femenino? (S/N): ";
			std::cin >> femenino;
			
			if (femenino == "s" || femenino == "S") {
				std::cout << "Ingresar el nombre: ";
				std::cin >> ascendenteFem;
				insertarNodo(arbol->der, ascendenteFem);
				insertarNodo(arbol->der, "");
			}
		}
		
	}
}

