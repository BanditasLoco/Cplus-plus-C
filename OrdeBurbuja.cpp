#include<stdio.h> 
#include<conio.h> 

void ordburbuja (long a[],int n);
void leer(long a[],int n);
void imprimir(long a[],int n);



int main(){ 

	int n;
	long a[10];
	printf("ingrese el tamaño del vector:");
	scanf("%d",&n);	
	leer (a,n);
	printf("el vector ingresado es:\n");
	imprimir (a,n);
	
	printf ("\nel vector ordenado es:\n");
	ordburbuja(a,n);
	imprimir (a,n);	
	
	
	getch(); 
	return 0;
} 


void leer(long a[10],int n)
{
int i;
	printf("\ningrese los valores del vector\n");
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &a[i]);
		
	}
	
	
}

void ordburbuja(long a[10],int n)
{
	int interruptor=1;
	int pasada, i;
	for(pasada=0; pasada< n-1 && interruptor; pasada++)
	{
		/* bucle externo controla la cantidad de pasada*/
		interruptor=0 ;
		for(i=0;i<n-pasada-1; i++)
			if(a[i] > a[i+1])
		{
			/* elementos desordenados, es necesario intercambio*/
			long aux;
			interruptor =1;
			aux = a[i];
			a[i]= a[i+1];
			a[i+1]= aux;
		}
	}
}

void imprimir(long a[10],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%ld\t", a[i]);
		
	}
	
	
}



