#include <stdio.h>
float promedio (float *, int cantidad);
float maximo (float *, int cantidad);
float minimo (float *, int cantidad);
int main(int argc, char *argv[]) {
	float temperaturas[100], *ptrt;
	ptrt= temperaturas;
	int can, j,op,i, cant=0;
		
	do{
		
		printf("Ingrese el número de temperaturas\n");
		scanf("%d", &can);
		for(j=0; j<can; j++)
		{
			scanf("%f", ptrt);
			ptrt++;
		}
		printf("Promedio:%.1f\n", promedio(ptrt,can));
		printf("Máximo:%.1f\n", maximo(ptrt,can));
		printf("Mínimo:%.1f\n", minimo(ptrt,can));
		float matriz[can][can];
		
		matriz[f][0]=promedio(ptrt,can);
		matriz[f][1]=maximo(ptrt,can);
		matriz[f][2]=minimo(ptrt,can);
		f=f+1
			
			printf("Promedio	Máximo		Mínimo");
		for(i=0;i<f;i++){
			for(j=0;i<f;j++){
				printf("%.1f	%.1f	%.1f",matriz[i][j],matriz[i][j+1],matriz[i][j+2]);
			}
		}
		printf("\nDesea ingresar mas valores?. Digite 1 para continuar, 0 para terminar");
		scanf("%d",&op); 
	cant= cant+can;
	} while(op!=0);
	// imprimir el vector
	//printf("%.1f\t",*(ptrt-1));
	for(i=0; i<cant;i++)
	{
		printf("%.1f\t",temperaturas[i]);
	}
	
	return 0;
}

float promedio (float *pt, int cantidad)
{
	float prom, suma=0;
	int j;
	for(j=0; j<cantidad; j++)
	{
		suma= suma+*(pt-1);
		pt--;
	}
	prom= suma/ cantidad;
	return prom;
}
float maximo (float *ptv1, int cantidad)
{
	int i;
	float max=0;
	ptv1=ptv1-1;
	for(i=0;i<cantidad;i++){
		if(*ptv1>max){
			max=*ptv1;
		}
		ptv1--;
	}
	return max;
}

float minimo (float *ptv1, int cantidad)
{
	int i;
	float min=*(ptv1-1);
	printf("Ptv1 es %.1f y ptv1-1 %.1f\n", *ptv1, *(ptv1-1));
	ptv1=ptv1-1;
	for(i=0;i<cantidad;i++){
		if(*ptv1<min){
			min=*ptv1;
			printf("Mínimo almacena %.1f\n", min);
		}
		ptv1--;
		printf("Ptv1-- es %.1f\n",*ptv1);
		
	}
	return min;
}
