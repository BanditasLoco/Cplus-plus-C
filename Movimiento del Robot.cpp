#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Recorrido
{
	int x=0;
	int y=0;
	char hora [20];
	char cod [20];
	struct Recorrido *siguiente;
}nodo;

void insertar();
void mostrarLS();
void eliminar();
void buscarNodoLS();
void cambio();

void menu();
nodo *primero=NULL, *ultimo= NULL, *robot=NULL;

int main(){

	menu();
}


void insertar()
{
	//nuevo=nuevo->siguiente;
	
	int i=0,px, py,c=0,s=0;
	nodo *nuevo;
	nuevo = (nodo *)malloc(sizeof(nodo));
	if(c==0)
	{
	printf("Ingrese el código del robot");
	scanf("%s",nuevo->cod);
	c=1;
	}
	printf("Desea cambbiar el código? (1) si, cualquier otro valor no");
	scanf("%i",&s);
		   if(s==1){
		   printf("Ingrese el código del robot");
		   scanf("%s",nuevo->cod);
		   }
		   
	while(i!=1)
	{	
	printf("Ingrese coordenada X\n");
	scanf("%d",&px);
	if(px<=10)
		i=1;
	else
	printf("Valor fuera de los limites vuelva a ingresar\n");
	}
	i=0;
	nuevo->x=px;
	
	while(i!=1)
	{	
		printf("Ingrese coordenada Y\n");
		scanf("%d",&py);
		if(py<=100)
			i=1;
		else
			printf("Valor fuera de los limites vuelva a ingresar\n");
		
	}
	nuevo->y=py;
	
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	strftime(nuevo->hora,15,"%H:%M:%S",tlocal);
	
	system("cls");
	if(primero==NULL)
	{
		primero=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}
	else
	{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}	
}

void mostrarLS(){
	int i=1;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("Código de Robot; %s\nRecorrido %d; (%d,%d) a las %s horas\n",actual->cod,i, actual->x,actual->y,actual->hora);
			actual = actual->siguiente;
			i++;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void buscarNodoLS(){
	int x, y, i=0;
	nodo * buscar;
	buscar=(nodo *)malloc(sizeof(nodo));
	buscar=primero;
	printf("\nIngrese coordenada X\n");
	scanf("%d",&x);
	printf("\nIngrese coordenada Y\n");
	scanf("%d",&y);
	system("cls");
	while(buscar!=NULL)
	{
		if(buscar->x==x&&buscar->y==y)
			i++;
		buscar=buscar->siguiente;
	}
	if(i!=0)
	printf("La posición buscada es la número %i\n",i);
	else
		printf("El robot no recorrió dicha posición\n");
}

void cambio(){
	nodo * nuevo;
	nuevo=(nodo *)malloc(sizeof(nodo));
	printf("Ingrese el nuevo código");
	scanf("%s",nuevo->cod);
	if(primero==NULL)
	{
		primero=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}	
}

void menu()
{ int op=1;

do{
	printf("\n\t\tMENU\n");
	printf("1.- Ingresar recorrido y hora\n");
	printf("2.- Mostrar recorddio\n");
	printf("3.- Buscar por posición\n");
	printf("0.- Salir\n");
	printf("\n\nIngresar la opcion que desea:\n");
	scanf("%d", &op);
	system("cls");
	switch(op)
	{
	case 1: 
		insertar();
		break;
	case 2: 
		mostrarLS();
		break;
	case 3: 
		buscarNodoLS();
		break;
	case 4: 
		cambio();
		break;
	case 0:
		exit(1);
	default:
		printf("No es opción valida\n");
	}
	
}while (op!= 0);

}


	

	

