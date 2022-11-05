#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int dato;
	struct Nodo * derecho;
	struct Nodo * izquierdo;
	
}nodo;

// prototipos de las funciones
void insertar(nodo *&arbol, int);
void mostrar(nodo * arbol, int);
bool buscar(nodo *arbol, int datobuscar);
int contarNodos(nodo *arbol);
void preorden(nodo * arbol);
void postorden(nodo * arbol);
void inorden(nodo * arbol);
int mayor(nodo *arbol);
int menor(nodo *arbol);
void menu();
int getLevelCount(nodo * arbol);
void printLevel(nodo * arbol, int level);
void printElements(nodo * arbol);
void Borrar(nodo *a, int datoeli);
int EsHoja(nodo *r);

nodo * arbol=NULL;
int main(int argc, char *argv[]) {
	menu();
	return 0;
}

void menu()
{
	int op, datoGuardar, c=0, bus, datoeli;
		
	do
	{
		printf("1-> Insertar\n");
		printf("2-> Mostrar\n");
		printf("3-> Buscar\n");
		printf("4-> PreOrden\n");
		printf("5-> InOrden\n");
		printf("6-> PostOrden\n");
		printf("7-> Recorrido por Niveles\n8-> Eliminar\n");
		printf("Ingrese la opcion\n");
		scanf("%d", &op);
		switch(op)
		{
		case 1: 
			system("cls");
			printf("Ingrese el dato a guardar en el nodo\n");
			scanf("%d", &datoGuardar);
			insertar(arbol, datoGuardar);
			break;
		case 2:
			printf("Los nodos que conforman el arbol son:\n");
			mostrar(arbol, c);
			break;
		case 3:
			printf("Ingrese el valor a buscar\n");
			scanf("%d", &bus);
			if(buscar(arbol, bus)== false)
			{
				printf("No se encuentra en el arbol");
			}
			else{
				printf("El valor %d si se encuentra en el arbol", bus);
			}
			break;
		case 4:
			preorden(arbol);
			break;
		case 5:
			postorden(arbol);
			break;
		case 6:
			inorden(arbol);
			break;
		case 7:
			printElements(arbol);
			break;
		case 8:
			printf("Ingrese el valor a eliminar\n");
			scanf("%d",&datoeli);
			Borrar(arbol,datoeli);
			break;
		}
		
	} while(op!=10);
}


void insertar(nodo *&arbol, int d)
{
	int raiz;
	if(arbol==NULL) // arbol vacio
	{
		nodo * nuevo= (nodo *) malloc(sizeof(nodo));
		nuevo->dato= d;
		nuevo->izquierdo=NULL;
		nuevo->derecho= NULL;
		arbol= nuevo;
	}
	else{
		
		raiz= arbol->dato;
		if(d<raiz)
		{
			insertar(arbol->izquierdo, d);
		}
		else{
			insertar(arbol->derecho, d);
		}
	}
}


void mostrar(nodo * arbol, int con)
{
	int i;
	if(arbol==NULL)
	{
		return;
	}
	else{
		mostrar(arbol->derecho, con+1);
		for(i=0; i<con; i++)
		{
			printf("   ");
		}
		printf("%d\n", arbol->dato);
		mostrar(arbol->izquierdo, con+1);
	}
}







bool buscar(nodo *arbol, int datobuscar)
{
	if(arbol==NULL)
	{
		return false;
		
	}
	else{
		if(arbol->dato== datobuscar)
		{
			return true;
		}
		else{
			if(datobuscar<arbol->dato )
			{
				return buscar(arbol->izquierdo, datobuscar);
			}
			else{
				return buscar(arbol->derecho, datobuscar);
			}
		}
		
	}
	
}

int contarNodos(nodo *arbol)
{
	int cni,cnd;
	if (arbol!=NULL)
	{
		cni= contarNodos(arbol->izquierdo);
		cnd= contarNodos(arbol->derecho);
			return cni+cnd+1;
	}
	else{
		return 0;
	}
	
}



void preorden(nodo *arbol)
{
	
	if(arbol==NULL)
	{
		return;
	}
	else{
		printf("%d", arbol->dato);
		preorden(arbol->izquierdo);
		preorden(arbol->derecho);
	}
}

void postorden(nodo * arbol)
{
	//i-d-r
	if(arbol==NULL)
	{
		return;
	}
	else{
		preorden(arbol->izquierdo);
		preorden(arbol->derecho);
		printf("%d", arbol->dato);
		}
}


void inorden(nodo * arbol)
{
	//i-d-r
	if(arbol==NULL)
	{
		return;
	}
	else{
		preorden(arbol->izquierdo);
		printf("%d", arbol->dato);
		preorden(arbol->derecho);
	}
}

int getLevelCount(nodo * arbol)
{
	if (arbol == NULL)
	{
		return 0;
	}
	int izquierdoMaxLevel = 1 + getLevelCount(arbol->izquierdo);
	int derechoMaxLevel = 1 + getLevelCount(arbol->derecho);
	if (izquierdoMaxLevel > derechoMaxLevel)
	{
		return izquierdoMaxLevel;
	}
	else
	{
		return derechoMaxLevel;
	}
}

void printLevel(nodo * arbol, int level)
{
	if (arbol != NULL && level == 0)
	{
		printf("%d\n", arbol->dato);
	}   
	else if (arbol != NULL)
	{
		printLevel(arbol->izquierdo, level - 1);
		printLevel(arbol->derecho, level - 1);
	}
}

void printElements(nodo * arbol)
{
	int i;
	int levelCount = getLevelCount(arbol);
	for (i = 0; i < levelCount; i++)
	{
		printLevel(arbol, i);
	}
}



void Borrar(nodo *a, int datoeli)
{
	nodo *padre = NULL;
	nodo *actual;
	nodo *nodo_;
	int aux;
	actual = a;
	/* Mientras el árbol no este vacío */
	while (actual!= NULL) {
		if (datoeli == actual->dato) { /* Si el valor está en el nodo actual */
			if (EsHoja(actual)) { /* Y si además es un nodo hoja: se puede borar */
				if (padre) /* Si tiene padre (no es el nodo raiz) */
					/* se debe anular el puntero que le hace referencia */
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
				free(actual); /* Borrar el nodo */
				actual = NULL;
				return;
			}
			else { /* Si el valor está en el nodo actual, pero no es hoja */
				padre = actual;
				/* Busca el nodo más izquierdo de rama derecha */
				if (actual->derecho) {
					nodo_ = actual->derecho;
					while (nodo_->izquierdo) {
						padre = nodo_;
						nodo_ = nodo_->izquierdo;
					}
				}
				/* O buscar nodo más derecho de rama izquierda */
				else {
					nodo_ = actual->izquierdo;
					while (nodo_->derecho) {
						padre = nodo_;
						nodo_ = nodo_->derecho;
					}
				}/* Intercambiar valores del nodo a borrar o del nodo encontrado
				y continuar, cerrando el bucle. el bucle se asegura 
				de que sólo se eliminan nodos hoja. */
				aux = actual->dato;
				actual->dato = nodo_->dato;
				nodo_->dato = aux;
				actual = nodo_;
			}
			
		}
		else { /* Si todavía no se ha encontrado el valor, se debe seguir buscando */
			padre = actual;
			if (datoeli > actual->dato) actual = actual->derecho;
			else if (datoeli < actual->dato) actual = actual->izquierdo;
		}
	}
}

int EsHoja(nodo *r)
{
	return !r->derecho && !r->izquierdo;
}

int mayor(nodo *arbol)
{
	if(arbol==NULL){
		return -1;
	}
	else{
		if(arbol->derecho==NULL){
			return arbol->dato;
		}
		else{
			return mayor(arbol->derecho);
		}
	}
}
	
int menor(nodo *arbol)
{
		if(arbol==NULL){
			return -1;
		}
		else{
			if(arbol->izquierdo==NULL){
				return arbol->dato;
			}
			else{
				return mayor(arbol->izquierdo);
			}
		}
}
