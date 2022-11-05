#include<stdio.h>
#include <stdlib.h>

void leer(int *pv,int);
void imprimir(int *pv,int);
void imprimirdir(int *pv,int);
void modificar(int *pv,int);
void menu(int *pv,int);



int main(){
	int i;
	int v[5],*pv;
	pv=v;
	
	menu(pv,i);


}

void leer(int *pv,int i){
	for(i=0;i<5;i++)
		scanf("%d",pv++);
}

void imprimir(int *pv,int i){
	printf("Los valores son\n");

for(i=0;i<5;i++)
	printf("%d\t",*(pv++));
}

void imprimirdir(int *pv,int i){
	printf("Las direcciones son\n");
	for(i=0;i<5;i++)
		printf("%d\t",pv++);
}

void modificar(int *pv,int i){
	int n;
	for(i=0;i<5;i++)
		printf("posición %d\t%d\n",i+1,*(pv+i));
	
	printf("Que posición de dato desea cambiar?\n");
	scanf("%d",&n);
n--;
	printf("Ingrese el dato");
		scanf("%d",pv+n);
}

void menu(int *pv,int i){ 
	int op=1;

do{
	printf("\n\t\tMENU\n");
	printf("1.- Ingresar datos\n");
	printf("2.- Mostrar datos\n");
	printf("3.- Mostrar dirección de memoria\n");
	printf("4.- Modificar\n");
	printf("0.- Salir\n");
	printf("\n\nIngresar la opcion que desea:\n");
	scanf("%d", &op);
	system("cls");
	switch(op)
	{
	case 1: 
		leer(pv,i);
		break;
	case 2: 
		imprimir(pv,i);
		break;
	case 3: 
		imprimirdir(pv,i);
		break;
	case 4: 
		modificar(pv,i);;
		break;
	case 0:
		exit(1);
	default:
		printf("No es opción valida\n");
	}
	
}while (op!= 0);
}
