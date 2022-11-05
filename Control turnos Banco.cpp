
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include  <string.h>

using namespace std;

typedef struct Nodo
{
	int cedula;
	struct nodos*siguiente;
}tiponodo;

tiponodo *colan=NULL;
tiponodo *colavip=NULL;
void insertar ();
void mostrar ();

//typedef tiponodo *pnodo;
//typedef tiponodo *cola;
int main (){
	insertar();
	mostrar();
}


//int solic;

void insertar ()
{
	int cola, aux;
	tiponodo*creado;
	creado=(tiponodo *)malloc(sizeof(tiponodo));
	
	printf("Introduzca su numero de cedula");
	scanf("%d",creado->cedula);
	
	
	
	if((tipo*colan)==NULL)
	{
		creado->siguiente=*colan;
		*colan=creado;
	}
	else
	{
		aux=*colan;
		
		while(aux!=NULL)
		{
			if(aux->siguiente==NULL)
			{
				creado->siguiente=aux->siguiente;
				aux->siguiente=creado;
				aux=aux->siguiente;
			}
			aux=aux->siguiente;
		}
	}
}

void mostrar (cola colan)
{
	cola aux;
	aux=colan;
	if(aux==NULL)
	{
		printf("No hay clientes en cola");
	}
	else
	{
		while(aux!=NULL)
		{
			printf("Cedula: %d\t"aux->cedula);
			aux=aux->siguiente;
			printf("Clientes ordenados por orden de llegada((((((SIMCOLAS))))))");
		}
	}
}
