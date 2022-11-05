#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato; 
	struct Nodo *siguiente; 
	struct Nodo *anterior; 
};
void insertar();
void mostrarID();
void mostrarDI();
void buscar();
void eliminar();
void menu();

struct Nodo *primero=NULL;
struct Nodo *ultimo=NULL;
int main() 
{
	menu();
	
	return 0;
}

void menu()
{ int op;	
do{
	
	printf("\nMENU\n");
	printf("1.- Insertar nodo\n");
	printf("2.- MostrarID\n");
	printf("3.- MostrarDI\n");
	printf("4.- Buscar nodo\n");
	printf("5.- Eliminar nodo\n");
	printf("6.- Salir\n");
	
	printf("\n\nIngresar la opcion que desea:\n");
	scanf("%d", &op);
	system("cls");
	switch(op)
	{
	case 1: 
		insertar();
		break;
	case 2: 
		mostrarID();
		break;
	case 3: 
		mostrarDI();
		break;
	case 4: 
		buscar();
		break;
	case 5:
		eliminar();
		break;
	case 6:
		exit(1);
	default:
		printf("No es opción valida\n");
	}
}while (op!= 6);	
}
	
	void insertar()
	{
		struct Nodo *nuevo= (struct Nodo *)malloc(sizeof(struct Nodo));
		printf("Ingrese el dato\n");
		scanf("%d", &nuevo->dato);
		if(primero==NULL){
			primero=nuevo;
			primero->siguiente=primero;
			primero->anterior=ultimo;
			ultimo=nuevo;	
		}
		else{
			ultimo->siguiente=nuevo;
			nuevo->siguiente=primero;
			nuevo->anterior=ultimo;
			ultimo=nuevo;
			primero->anterior=ultimo;
		}	
		
		
	} 
	void mostrarID(){
		struct Nodo *actual= (struct Nodo *)malloc(sizeof(struct Nodo));
		actual=ultimo;
		
		if(ultimo==NULL){
			printf("Lista vacia\n");
		}else{
			do{
				printf("%d\n",actual->dato);
				actual=actual->anterior;
			}while (actual!=ultimo);
		}
	}
	void mostrarDI(){
		struct Nodo *actual= (struct Nodo *)malloc(sizeof(struct Nodo));
		actual=primero;
		
		if(primero==NULL){
			printf("Lista vacia\n");
		}else{
			do {
				printf("%d\n",actual->dato);
				actual=actual->siguiente;
			}while (actual!=primero);
		}
	}
	void buscar(){
		int datobuscado, encontrado=0; 
		struct Nodo *actual = (struct Nodo *) malloc(sizeof(struct Nodo)) ;
		
		printf("Ingrese el dato que va a ser buscado en la lista: ");
		scanf("%d",&datobuscado);
		actual = primero;
		if(primero!=NULL){ 
			do{
				if(actual->dato==datobuscado){ 
					printf("El dato %d se encuentra en la lista\n",datobuscado);	
					encontrado=1;		
				}	
				actual=actual->siguiente;
			}while (actual!=primero && encontrado!=1);
			if(encontrado==0){ 
				printf("EL dato %d no se encuentra en la lista\n",datobuscado);		
			}
		}
		else{
			printf("Lista vacía");
		}
	}
	void eliminar(){
		int datobuscado, encontrado=0;
		struct Nodo *actual = (struct Nodo *) malloc(sizeof(struct Nodo)) ;	
		struct Nodo *anterior = (struct Nodo *) malloc(sizeof(struct Nodo)) ;	
		actual = primero;	
		anterior=NULL;
		printf("\nIngrese el dato que desea eliminar:\t");
		scanf("%d", &datobuscado);
		if(primero!=NULL){ 
			do {
				if(actual->dato==datobuscado){
					if(actual==primero && actual==ultimo){
						primero=NULL;
						ultimo=NULL;
					}
					else{
						if(actual==primero){ 
							primero=primero->siguiente;
							primero->anterior=ultimo;
							ultimo->siguiente=primero;
						}
						else{
							if(actual==ultimo){ 
								ultimo=anterior;
								ultimo->siguiente=primero;
								primero->anterior=ultimo;
							}
							else{
								anterior->siguiente=actual->siguiente;	
								actual->siguiente->anterior=anterior;
							}
						}		
						encontrado=1;	
						printf("el dato %d ha sido eliminado\n",datobuscado);
					}
				}		
				anterior=actual;
				actual=actual->siguiente;	
			}while (actual!=primero && encontrado!=1);
			if(encontrado==0){
				printf("El dato %d no se encuentra en la lista\n",datobuscado);
			}
			else{
				free(anterior);
			}
		}
		else{
			printf("Lista vacía\n");
		}
	}
