#include <iostream>
#include <string>
#include <cstdlib>


// Define la estructura llamada Nodo
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

// Creando la estructura Árbol
Nodo *arbol = NULL;

// Función para crear un nuevo Nodo
Nodo *crearNodo(int numero, Nodo *padre) {
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo -> dato = numero;
	nuevo_nodo -> der = NULL;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> padre = padre;
	
	return nuevo_nodo;
}

bool buscarNodo(Nodo *arbol, int numero);
void eliminarNodo(Nodo *nodoEliminar);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);
void modificarNodo(Nodo *nodoModificar, int numero);

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
	bool esRepetido = false;
	esRepetido = buscarNodo(arbol, num);
	if (esRepetido == true) {
		return true;
	}
	else {
		return false;
	}
}

// Función para insertar elementos en el arbol
void insertarNodo (Nodo *&arbol, int numero, Nodo *padre) {
	if (arbol == NULL) {
		Nodo *nuevo_nodo = crearNodo(numero, padre);
		arbol = nuevo_nodo;
	}
	else{
		int valorNodoRaiz = arbol->dato;
		if (numero < valorNodoRaiz) {
			insertarNodo(arbol->izq, numero, arbol);
		}
		else {
			insertarNodo(arbol->der, numero, arbol);
		}
	}
	
}

// Insertar Nuevo Nodo
void insertarNuevoNodo() {
	bool esInsertado = false;
	
	do {
		bool valorRepetido = false;
		bool valorEsPar = false;
		bool valorEsEntero = false;

		std::string datoIngresado;
		std::cout << "Digita el dato a insertar: ";
		std::cin >> datoIngresado;
		int dato = std::atoi(datoIngresado.c_str());
		
		// Verificando que el dato no se repite
		valorRepetido = esRepetido(dato);
			
		// Verificando que es par
		valorEsPar = esPar(dato);
		
		// Verificando que es entero
		valorEsEntero = esEntero(dato);
		
		if (valorRepetido == false && valorEsPar && valorEsEntero && (dato > 0) && (dato <= 38)) { // 
        	insertarNodo(arbol, dato, NULL);
        	esInsertado = true;
        	//std::cout << "Dato insertado" << std::endl;
		} else {
			std::cout << "Ingresa un valor entero, positivo, par e irrepetible." << std::endl;
		}
			
	} while (esInsertado == false);
	
}

// Mostrar Árbol
void mostrarArbol(Nodo *arbol, int contador) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, contador+1);
		for (int i=0; i<contador; i++) {
			std::cout << "    ";
		}
		std::cout << arbol->dato << std::endl;
		mostrarArbol(arbol->izq, contador+1);
	}
}

// Buscar Nodo en el Árbol
bool buscarNodo(Nodo *arbol, int numero) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->dato == numero) {
		return true;
	}
	else if (numero < arbol->dato) {
		return buscarNodo(arbol->izq, numero);
	}
	else if (numero > arbol->dato) {
		return buscarNodo(arbol->der, numero);
	}
	return false;
}

// Buscar nodo a eliminar
void eliminar(Nodo * arbol, int numero) {
	if (arbol == NULL) {
		return;
	}
	else if (numero < arbol->dato) {
		eliminar(arbol->izq, numero);
	}
	else if (numero > arbol->dato) {
		eliminar(arbol->der, numero);
	}
	else {
		eliminarNodo(arbol);
	}
}

// Eliminar nodo del árbol
void eliminarNodo(Nodo *nodoEliminar) {
	if (nodoEliminar->izq && nodoEliminar->der) { // Tiene dos hijos -> FUNCIONA
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if (nodoEliminar->izq) {
		reemplazar(nodoEliminar, nodoEliminar->izq); // Tiene hijo izq -> FUNCIONA
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->der) {
		reemplazar(nodoEliminar, nodoEliminar->der); // Tiene hijo der -> FUNCIONA
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL); // Nodo hoja (sin hijos) -> FUNCIONA
		destruirNodo(nodoEliminar);
	}
	
}

// Destruye el nodo que se quiere eliminar
void destruirNodo(Nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}

// Remplaza el nodo eliminado apuntando del hijo al padre y del padre al hijo
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		nuevoNodo->padre = arbol->padre;
	}
}

// Función para encontrar el nodo más izq posible
Nodo *minimo (Nodo *arbol){
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}

// Buscar nodo a Modificar
void modificar(Nodo * arbol, int numero, int modificarPor) {
	if (arbol == NULL) {
		return;
	}
	else if (numero < arbol->dato) {
		modificar(arbol->izq, numero, modificarPor);
	}
	else if (numero > arbol->dato) {
		modificar(arbol->der, numero, modificarPor);
	}
	else {
		modificarNodo(arbol, modificarPor);
	}
}

// Modificar el dato del nodo por el nuevo dato
void modificarNodo(Nodo *nodoModificar, int modificarPor) {
	nodoModificar->dato = modificarPor;
}

// Recorrido inorden
void recorrerInorden(Nodo *arbol) {  // Izq Raiz Der
	if (arbol == NULL) {
		return;
	}
	else {
		recorrerInorden(arbol->izq);
		std::cout << arbol->dato << "  -  ";
		recorrerInorden(arbol->der);
	}
}

// Recorrido preorden
void recorrerPreorden(Nodo *arbol) { // Raíz Izq Der
	if (arbol == NULL) {
		return;
	}
	else {
		std::cout << arbol->dato << "  -  ";
		recorrerPreorden(arbol->izq);
		recorrerPreorden(arbol->der);
	}
}

// Recorrido posorden
void recorrerPosorden(Nodo *arbol) { // Izq Der Raiz
	if (arbol == NULL) {
		return;
	}
	else {
		recorrerPosorden(arbol->izq);
		recorrerPosorden(arbol->der);
		std::cout << arbol->dato << "  -  ";
	}
}

// Método main
int main() {
	int opcion;
	int contador = 0;
	int numeroBuscar;
	int numeroEliminar;
	int numeroModificar;
	int modificarPor;
	bool esEncontrado = false;
	
	do {
		std::cout << "\n##  MENU DE OPCIONES  ##\n" << std::endl;
		std::cout << "1. AGREGAR UN NODO AL ARBOL" << std::endl;
		std::cout << "2. MOSTRAR NODOS DEL ARBOL" << std::endl;
		std::cout << "3. BUSCAR UN NODO EN EL ARBOL" << std::endl;
		std::cout << "4. MODIFICAR UN NODO DEL ARBOL" << std::endl;
		std::cout << "5. ELIMINAR UN NODO DEL ARBOL" << std::endl;
		std::cout << "6. RECORRIDO DEL ARBOL INORDEN" << std::endl;
		std::cout << "7. RECORRIDO DEL ARBOL PREORDEN" << std::endl;
		std::cout << "8. RECORRIDO DEL ARBOL POSORDEN" << std::endl;
		std::cout << "9. SALIR DEL PROGRAMA\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			insertarNuevoNodo();
			break;
		case 2:
			mostrarArbol(arbol, contador);
			break;
		case 3:
			// 10 - 2 - 8 - 12 - 6 - 38 - 4 - 14
			std::cout << "Digita el dato a buscar: ";
			std::cin >> numeroBuscar;
			esEncontrado = buscarNodo(arbol, numeroBuscar);
			if (esEncontrado == true) {
				std::cout << "Dato encontrado en el arbol" << std::endl;
			}
			else{
				std::cout << "Dato no existente." << std::endl;
			}
			break;
		case 4:
			std::cout << "Digita el dato a modificar: ";
			std::cin >> numeroModificar;
			std::cout << "Digita el dato que reemplaza: ";
			std::cin >> modificarPor;
			modificar(arbol, numeroModificar, modificarPor);
			break;
		case 5: 
			std::cout << "Digita el dato a eliminar: ";
			std::cin >> numeroEliminar;
			eliminar(arbol, numeroEliminar);
			break;
		case 6:
			std::cout << "Recorrido en Inorden:  ";
			recorrerInorden(arbol);
			break;
		case 7:
			std::cout << "Recorrido en Preorden:  ";
			recorrerPreorden(arbol);
			break;
		case 8:
			std::cout << "Recorrido en Posorden:  ";
			recorrerPosorden(arbol);
			break;
		case 9:
			std::cout << "Saliste del programa." << std::endl;
			break;	
			
		default:
			std::cout << "Digita una opcion valida." << std::endl;
		}

	} while (opcion!=9);
	
	return 0;	
}
