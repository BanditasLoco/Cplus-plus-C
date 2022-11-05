#include <stdio.h>
#include <stdlib.h>

float maximo (float *, int);
float minimo (float *ptv1, int n);
void ordburbuja (float a[],int n);
int main(int argc, char *argv[]) {
	float j1[100], j2[100], j3[100], j4[100];
	float p[100],*ptr;
	int i=0,j,n,v=0;
	int g1=0, g2=0, g3=0, g4=0;

	
	do{
		printf("\n\nPresione cualquier tecla para jugar una ronda.\nPresione 0 para dejar de jugar\n");
		scanf("%i",&j);
		
		printf("\nFuerza Obtenida\n");
		j1[i]=10+rand()%(101-10);
		printf("Jugador 1\n%.1fN\n",j1[i]);
	
		j2[i]=10+rand()%(101-10);
		printf("Jugador 2\n%.1fN\n",j2[i]);
			
		j3[i]=10+rand()%(101-10);
		printf("Jugador 3\n%.1fN\n",j3[i]);
		
		j4[i]=10+rand()%(101-10);
		printf("Jugador 4\n%.1fN\n",j4[i]);
		
		/*Avances*/
		printf("\nVeces alcanzadas mayor puntaje\n");
		printf("\nJugador 1\n");
		if(j1[i]>j2[i]&&j1[i]>j3[i]&&j1[i]>j4[i])
			g1=g1+1;
		for(n=0;n<g1;n++){
			printf("*");
		}
		
		printf("\nJugador 2\n");
		if(j2[i]>j1[i]&&j2[i]>j3[i]&&j2[i]>j4[i])
			g2=g2+1;
		for(n=0;n<g2;n++){
			printf("*");
		}
		
		printf("\nJugador 3\n");
		if(j3[i]>j1[i]&&j3[i]>j2[i]&&j3[i]>j4[i])
			g3=g3+1;
		for(n=0;n<g3;n++){
			printf("*");
		}
		
		printf("\nJugador 4\n");
		if(j4[i]>j1[i]&&j4[i]>j2[i]&&j4[i]>j3[i])
			g4=g4+1;
		for(n=0;n<g4;n++){
			printf("*");
		}

		
		for(n=0;n<4;n++){
			p[v]=j1[i];
			p[v+1]=j2[i];
			p[v+2]=j3[i];
			p[v+3]=j4[i];
		}
		
		
		ptr=p;
		printf("\nMayor Fuerza alcanzada %.0fN\n", maximo(ptr,4));
		printf("Menor Fuerza lograda %.0fN\n", minimo(ptr,4));
	ordburbuja(p,4);
	printf("Los valores en orden ascendente son\t");
	for(n=0;n<4;n++)
		printf("%.0fN\t",p[n]);
		
		if(j1[i]==100)
			printf("\nGanador! Jugador 1\n");
		if(j2[i]==100)
			printf("\nGanador! Jugador 2\n");
		if(j3[i]==100)
			printf("\nGanador! Jugador 3\n");
		if(j4[i]==100)
			printf("\nGanador! Jugador 4\n");
		
		
		i++;
	} while(j!=0);
	return 0;
}

float maximo (float *ptv1, int n){
	float max=0;
	int i;
	for(i=0;i<n;i++){
		if(*ptv1>max){
			max=*ptv1;
		}
		ptv1++;
	}
	return max;
}

float minimo (float *ptv1, int n){
	float min=*ptv1;
	int i;
	for(i=0;i<n;i++){
		if(*ptv1<min){
			min=*ptv1;
		}
		ptv1++;
	}
	return min;
}

void ordburbuja(float a[100],int n)
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
			float aux;
			interruptor =1;
			aux = a[i];
			a[i]= a[i+1];
			a[i+1]= aux;
		}
	}
}
