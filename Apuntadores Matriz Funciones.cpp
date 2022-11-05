#include <stdio.h>
#include <conio.h>
void leer(int *,int,int);
void imprimir(int *, int, int);
void imparcero(int *, int, int);
int main(int argc, char *argv[]) {
	int i, j;
	int matriz[2][3];
	int (*pm)[3];
	// asignando la direccón de memoria de la matriz al puntero
	pm=matriz;
	leer(pm[3],i,j);
	imprimir(pm[3],i,j);
	imparcero(pm[3],i,j);
	
	// lectura desde teclado del vector


// tarea 2
/*
Cambiar el programa aplicando funciones, considerando que las funciones reciben como parametro el puntero a la matriz, y el tamaño de la matriz.
de orden mxn
*/
}

void leer(int (*pm)[3],int i, int j){
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", *(*(pm+i)+j));
		}
	}
}

void imprimir(int (*pm)[3], int i, int j){
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d\t", (*(pm+i)+j));
		}
		printf("\n");
	}
}

void imparcero(int (*pm)[3], int i, int j){
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			
			if(*(*(pm+i)+j)%2==0)
			{
				*(*(pm+i)+j)=0;
			}
			
		}
		printf("\n");
	}
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d", (*(pm+i)+j));
		}
		printf("\n");
	}

}
