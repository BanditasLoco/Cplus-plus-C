#include <stdio.h>
#include <conio.h>

float promedio (float *, int );
float maximo (float *, int );
float minimo (float *, int );
float mayorprm(float *, int, int);
float menorprm( float *, int, int);
float altas (float *, int);
float bajas(float *, int);
float normales(float *, int);
void copia(float *, float *, int);
void ordSeleccion (float a[], int);
void ordSeleccionP (float *, int);
void ordInserccion(float a[], int);
int main() {
	
	float v1[100], v2[100], *ptv1, *ptv2, mat[10][3], p;
	int n, i=1, op, t=0, f=0;
	ptv1=v1;
	ptv2=v2;
	do{
		
		printf("¿Cuántas temperaturas va a ingresar?\n");
		scanf("%d", &n);
		printf("Ingrese temperaturas entre 5 y 32\n");
		do{
			printf("Ingrese la %i temperatura\n", i);
			scanf("%f", &p);
			if(p>=5&&p<=32){
				*ptv1=p;
				i++;
				ptv1++;
			}
			//ptv1++;
		}while(i<=n);
		
		printf("\nEl promedio es %.1f", promedio(ptv1,n));
		printf("\nEl máximo valor es %.1f", maximo(ptv1,n));
		printf("\nEl mínimo valor es %.1f", minimo(ptv1,n));
		mat[f][0]=promedio(ptv1,n);
		mat[f][1]=maximo(ptv1,n);
		mat[f][2]=minimo(ptv1,n);
		mat[f][3]=mayorprm(ptv1,n,promedio(ptv1,n));
		mat[f][4]=menorprm(ptv1,n,promedio(ptv1,n));
		mat[f][5]=altas(ptv1,n);
		mat[f][6]=bajas(ptv1,n);
		mat[f][7]=normales(ptv1,n);
		t=t+n;
		printf ("\nEl número de valores mayores al promedio es %.1f\n", mayorprm(ptv1,n,promedio(ptv1,n)));
		printf ("El número de valores menores al promedio es %.1f\n", menorprm(ptv1,n,promedio(ptv1,n)));
		printf ("El número de temperaturas altas es %.1f\n", altas(ptv1,n));
		printf ("El número de temperaturas bajas es %.1f\n", bajas(ptv1,n));
		printf ("El número de temperaturas normales es %.1f\n", normales(ptv1,n));
		
		printf("El vector copiado es\n");
		copia(ptv1,ptv2,n);
		for(i=0;i<n;i++){
			printf("%.1f \t",*ptv2);
			ptv2++;
		}
		
		printf("\nVector ordenado es\n");
		ordSeleccion(v1,n);
		for(i=0;i<n;i++){
			printf("%.1f \t",v1[i]);
		}
		
		printf("\nApuntador ordenado es:\n");
		ordSeleccion(ptv2,n);
		ptv2=ptv2-n;
		for(i=0;i<n;i++){
			printf("%.1f \t",*ptv2);
			ptv2++;
		}
		
		printf("\nVector ordenado por inserción:\n");
		ordInserccion(v1,n);
	
		for(i=0;i<n;i++){
			printf("%.1f \t",v1[i]);
			ptv2++;
		}
		printf("\nDesea ingresar más valores?, Digite 1 para continuar o 0 para terminar\n");
		scanf("%d", &op);
		f++;
	}while(op!=0);
	
	printf("\npromedio    máximos    mínimos    mayores al promedio    menores al promedio    altas	bajas    normales\n");
	for(i=0;i<f;i++){
		printf("%.1f    	%.1f	%.1f     	%.1f	    		%.1f	    	  %.1f  	%.1f	  %.1f", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], mat[i][5], mat[i][6], mat[i][7]);
		printf("\n");
	}
	printf("\n\nLos valores ingresados son: \n");
	for(i=0;i<t;i++){
		printf("%.1f\n", v1[i]);
	}
	getch();
	return 0;
}
float promedio (float *ptv1, int n){
	int i;
	float pr=0;
	ptv1=ptv1-1;
	for(i=0; i<n; i++){
		pr=pr+*ptv1;
		ptv1--;
	}
	return (pr/n);
}
float maximo (float *ptv1, int n){
	float max=0;
	int i;
	ptv1=ptv1-1;
	for(i=0;i<n;i++){
		if(*ptv1>max){
			max=*ptv1;
		}
		ptv1--;
	}
	return max;
}
float minimo (float *ptv1, int n){
	float min=*(ptv1-1);
	int i;
	ptv1=ptv1-1;
	for(i=0;i<n;i++){
		if(*ptv1<min){
			min=*ptv1;
		}
		ptv1--;
	}
	return min;
}
float mayorprm(float *ptv1, int n,int p){
	int i, cant=0;
	ptv1=ptv1-1;
	for (i=0;i<n;i++){
		if (*ptv1>p){
			cant=cant+1;
		}
		ptv1--;
	}
	return cant;
}

float menorprm(float *ptv1, int n, int p){
	int i, cant=0;
	ptv1=ptv1-1;
	for (i=0;i<n;i++){
		if (*ptv1<p){
			cant=cant+1;
		}
		ptv1--;
	}
	return cant;
}

float altas (float *ptv1, int n){
	int al=0, i, a=20;
	ptv1=ptv1-1;

	for (i=0;i<n;i++){
		if (*ptv1>a){
			al=al+1;
		}
		ptv1--;
	}
	return al;
}

float bajas (float *ptv1, int n){
	int al=0, i, a=10;
	ptv1=ptv1-1;
	
	for (i=0;i<n;i++){
		if (*ptv1<a){
			al=al+1;
		}
		ptv1--;
	}
	return al;
}

float normales (float *ptv1, int n){
	int c=0, min=10, max=20;
	ptv1=ptv1-1;
	
	for (int i=0;i<n;i++){
		if(*ptv1>=min&&*ptv1<=max){
			c++;
		}
		ptv1--;
	}
	return c;
}
void copia (float *ptv1, float *ptv2, int n){
	int i;
ptv1=ptv1-n;
	for(i=0;i<n;i++){
		*ptv2=*ptv1;
			ptv1++;
			ptv2++;
	}
}

void ordSeleccion (float a[], int n)
{
	int indiceMenor, i, j;
	for (i=0;i<n-1;i++)
	{
		indiceMenor=i;
		for(j=i+1;j<n;j++)
			if (a[j]<a[indiceMenor])
				indiceMenor=j;
		if(i!=indiceMenor)
		{
			double aux=a[i];
			a[i]=a[indiceMenor];
			a[indiceMenor]=aux;
		}
	}
}

void ordSeleccionP (float *p, int n)
{
	int indiceMenor, i, j;
	p=p-n;
	for (i=0;i<n-1;i++)
	{
		indiceMenor=i;
		for(j=i+1;j<n;j++)
			if (*(p+j)<*(p+indiceMenor))
				indiceMenor=j;
		if(i!=indiceMenor)
		{
			float aux=*(p+i);
			*(p+i)=*(p+indiceMenor);
			*(p+indiceMenor)=aux;
		}
	}
}

void ordInserccion(float a[], int n){
	int i, j, aux;
	for(i=1;i<n;i++){
		j=i;
		aux=a[i];
		while(j>0 && aux<a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		a[j]=aux;
	}
}
