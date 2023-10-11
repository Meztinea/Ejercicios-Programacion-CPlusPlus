#include <iostream>
#include <cstdlib>
#include <vector>


struct Nodo{
	int dato;
	Nodo *siguiente;
};


// Prototipos 
void insertarDato(Nodo *&, int);
bool validarDato(Nodo *, int);
bool esPar(int);
bool esEntero(int);
bool esRepetido(Nodo *, int);
void insertar(Nodo *&);
void mostrar(Nodo *);
int contarElementos(Nodo *);
void ordenarBurbuja(Nodo *);
void ordenarSeleccion(Nodo *);
void buscarSecuencial(Nodo *);
std::vector<int> convertir(Nodo *);
void buscarBinaria(Nodo *);
void buscarInterpolacion(Nodo *);
std::vector<int> ordenar(std::vector<int>);

// Método main
int main() {
	Nodo *lista = NULL; // Crea la estructura lista
	int nElementos;
	int opcion;
	
	do {
		std::cout << "\n##  MENU LISTA DINAMICA  ##\n" << std::endl;
		std::cout << "1. Ingresar datos" << std::endl;
		std::cout << "2. Mostrar datos" << std::endl;
		std::cout << "3. Busqueda secuencial" << std::endl;
		std::cout << "4. Busqueda binaria" << std::endl;
		std::cout << "5. Busqueda interpolacion" << std::endl;
		std::cout << "6. Ordenamiento de burbuja" << std::endl;
		std::cout << "7. Ordenamiento de seleccion" << std::endl;
		std::cout << "8. Salir\n" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1: 
			insertar(lista);
			break;
		case 2:
			mostrar(lista);
			break;
		case 3:
			buscarSecuencial(lista);
			break;
		case 4:
			buscarBinaria(lista);
			break;
		case 5:
			buscarInterpolacion(lista);
			break;	
		case 6: 
			ordenarBurbuja(lista);
			std::cout << "\nSe han ordenado los datos por ordenamiento burbuja.\n" << std::endl;
			break;
		case 7:
			ordenarSeleccion(lista);
			std::cout << "\nSe han ordenado los datos por ordenamiento seleccion.\n" << std::endl;
			break;
		case 8:
			std::cout << "Saliste del programa." << std::endl;
			break;			
		default:
			std::cout << "Digita una opcion valida." << std::endl;
		}

	} while (opcion!=8);
	
	return 0;	
}

// Búsqueda Interpolación
void buscarInterpolacion(Nodo *lista) {
	int numero;
	int iteraciones = 0;
	bool esEncontrado = false;
	std::vector<int> elementos = convertir(lista);
	elementos = ordenar(elementos);
	int inicio = 0;
	int fin = elementos.size() - 1;
	int indice;
	
	std::cout << "\n*** Busqueda Interpolacion ***" << std::endl;
	std::cout << "Digita el numero a buscar: ";
	std::cin >> numero;
	
	for (int i=0; i<10; i++) {
		iteraciones++;
		indice = ((fin) * (numero - elementos[inicio]) / (elementos[fin] - elementos[inicio]));
		
		if (indice>fin) {
			break;
		} else if (indice<0) {
			break;
		}
		
		if (indice<inicio) {
			indice = inicio;
		}
		
		if (indice>=inicio && indice<=fin) {
			if (elementos[indice] == numero) {
				std::cout << "Dato encontrado en la lista. No. de iteraciones: " << iteraciones << std::endl;
				esEncontrado = true;
				break;
			} else if (elementos[indice] < numero) {
				fin = fin -1;
			} else if (elementos[indice] > numero) {
				inicio = inicio + 1;
			}
		}
	}
	
	if (esEncontrado == false) {
		std::cout << "El dato no se encuentra en la lista. No. de iteraciones: " << iteraciones << std::endl;
	}
	
}

std::vector<int> ordenar(std::vector<int> array) {
	int aux;
	int n = array.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++){
			if (array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	return array;
}

// Búsqueda Binaria
void buscarBinaria(Nodo *lista) {
	int iteraciones = 0;
	bool esEncontrado = false;
    std::vector<int> elementos = convertir(lista);
	int numero;
	std::cout << "\n*** Busqueda Binaria ***" << std::endl;
	std::cout << "Digita el numero a buscar: ";
	std::cin >> numero;

    int inicio = 0;
    int fin = elementos.size() - 1;

    while (inicio <= fin) {
    	iteraciones++;
        int medio = inicio + (fin - inicio) / 2;
        if (elementos[medio] == numero) {
            Nodo* nodoEncontrado = lista;
            for (int i = 0; i < medio; ++i) {
                nodoEncontrado = nodoEncontrado->siguiente;
            }
            std::cout << "Dato encontrado en la lista. No. de iteraciones: " << iteraciones << std::endl;
            esEncontrado = true;
            break;
        } else if (elementos[medio] < numero) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    if (esEncontrado == false) {
    	std::cout << "El dato no se encuentra en la lista. No. de iteraciones: " << iteraciones << std::endl;
	}
}

std::vector<int> convertir(Nodo *lista) {
    std::vector<int> elementos;
    Nodo* actual = lista;
    while (actual != NULL) {
        elementos.push_back(actual->dato);
        actual = actual->siguiente;
    }
    return elementos;
}

// Búsqueda Secuencial
void buscarSecuencial(Nodo *lista) {
	std::cout << "\n*** Busqueda Secuencial ***" << std::endl;
	int numero;
	std::cout << "Digita el numero a buscar: ";
	std::cin >> numero;
	
	Nodo* actual = lista;
	int iteraciones = 0;
	bool esEncontrado = false;
	while (actual != NULL) {
		iteraciones++;
        if (actual->dato == numero) {
            std::cout << "Dato encontrado en la lista. No. de iteraciones: " << iteraciones << std::endl;
            esEncontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (esEncontrado == false) {
    	std::cout << "El dato no se encuentra en la lista. No. de iteraciones: " << iteraciones << std::endl;
	}
}

// Muestra todos los elementos de la lista - 
void mostrar(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	int posicion = 0;
	
	std::cout << "\nDatos en la lista:  " << std::endl;
	while (actual != NULL) {
		std::cout << "Posicion #" << posicion << "   Dato: " << actual->dato << std::endl;
		actual = actual->siguiente;
		posicion++;
	}
	std::cout << "\n";
}

// Recibe el dato - lo valida y lo inserta en la lista1
void insertar(Nodo *&lista) {
	bool esInsertado = false;
	bool esValido = false;
	std::string datoIngresado;
	int nElementos;
	int nElementosInsertados;
	std::cout << "Indica la dimension de la lista: ";
	std::cin >> nElementos;
	
	if (nElementos <= 10 && nElementos > 0) {
		do {
		
			do {
				std::cout << "Digita el dato a insertar: ";
				std::cin >> datoIngresado;
				int dato = std::atoi(datoIngresado.c_str());
				
				// Validando el dato
				esValido = validarDato(lista, dato);
				
				if (esValido == true) {
		        	insertarDato(lista, dato);
		        	esInsertado = true;
		        	nElementosInsertados++;
				} else {
					std::cout << "Ingresa un valor entero, positivo, par e irrepetible." << std::endl;
				}
				
			} while (esInsertado == false);
		
		} while (nElementos != nElementosInsertados);
	}
	else {
		std::cout << "La lista puede contener entre 1 y 10 elementos. Intenta nuevamente." << std::endl;
	}
	
}

// Insertar un dato en la lista
void insertarDato(Nodo *&lista, int numero){
	Nodo *nuevo = new Nodo();
	nuevo->dato = numero;
	
	Nodo *aux1 = lista;
	Nodo *aux2;	
	
	while (aux1 != NULL)  { //&& (aux1->dato < numero))
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (lista == aux1) {
		lista = nuevo;
	}
	else {
		aux2->siguiente = nuevo;
	}
	nuevo->siguiente = aux1;
}
	
// Valida si el dato es apto para insertarse
bool validarDato(Nodo *lista, int numero){
	bool valorRepetido = false;
	bool valorEsPar = false;
	bool valorEsEntero = false;
	
	//Verificando que el dato no se repite
	valorRepetido = esRepetido(lista, numero);
		
	// Verificando que es par
	valorEsPar = esPar(numero);
	
	// Verificando que es entero
	valorEsEntero = esEntero(numero);
	
	if (valorRepetido == false && valorEsPar && valorEsEntero && numero > 0) { 
    	return true;
	} else {
		return false;
	}
	
}

// Verifica si es entero
bool esEntero(int num) {
	return num % 1 == 0;
}

// Verifica que es par
bool esPar(int num) {
	return num % 2 == 0;
}

// Verifica que el dato no se repite
bool esRepetido(Nodo *lista, int num) {
	Nodo* actual = lista;
	bool esEncontrado = false;
	while (actual != NULL) {
        if (actual->dato == num) {
            esEncontrado = true;
            break;
        }
        actual = actual->siguiente;
    }
	if (esEncontrado){
		return true;
	}
	else{
		return false;
	}
}

// Cuenta la cantidad de elementos que contiene la lista
int contarElementos(Nodo *lista) {
	int contador;
	Nodo *actual = new Nodo();
	actual = lista;
	
	while (actual != NULL) {
		contador++;
		actual = actual->siguiente;
	}
	return contador;
}

// Ordenamiento burbuja
void ordenarBurbuja(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	
	if (actual == NULL || actual->siguiente == NULL) {
		return;
	}
	else {
		bool intercambioRealizado;
        do {
            intercambioRealizado = false;
            Nodo* actual = lista;
            Nodo* siguiente = lista->siguiente;

            while (siguiente != NULL) {
                if (actual->dato > siguiente->dato) {
                    std::swap(actual->dato, siguiente->dato);
                    intercambioRealizado = true;
                }
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
        } while (intercambioRealizado);
	}
}


// Ordenamiento por seleccion
void ordenarSeleccion(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	
	if (actual == NULL || actual->siguiente == NULL) {
		return;
	}
	else {
		Nodo* actual = lista;
		while (actual != NULL) {
            Nodo* minimo = actual;
            Nodo* siguiente = actual->siguiente;

            while (siguiente != NULL) {
                if (siguiente->dato < minimo->dato) {
                    minimo = siguiente;
                }
                siguiente = siguiente->siguiente;
            }

            if (minimo != actual) {
                std::swap(actual->dato, minimo->dato);
            }
            actual = actual->siguiente;
        }
	}
}

