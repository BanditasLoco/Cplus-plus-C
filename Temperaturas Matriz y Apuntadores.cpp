#include <stdio.h>
#include <conio.h>
/* 
Construir un programa que calcule los valores de temperatura en farenheit,kelvin,rankie
en base al valor de temperatura ingresado en celsius
desplegar los resultados de una distribucion
El usuario puede ingresar la cantidad de valores que desee,cuando el usuario ingrese el valor de 100 automaticamente el programa 
dejara de solicitar mas temperaturas
1. Crear la estructura
2. Acceder Manipular la estructuta sin apuntadores
3. Acceder y manipular a la estructura a traves de apuntadores
*/
struct temperatura {
	float TC[100][4];

	
};
float rankie(float);
float kelvin(float);
float faren(float);
int main(int argc, char *argv[]) {
	int i=-1,n=0;
	struct temperatura t1;
	//definir variable tipo puntero
	struct temperatura *pt;
	//asignar la direccion de memoria al apuntador
	pt=&t1;
	do{
		i++;		
		
		printf("Ingrese la temperatura en Celcius\t");
		scanf("%f",&pt->TC[i][0]);
		

		if(pt->TC[i][0]!=100){	
			pt->TC[i][1]=pt->TC[i][0]+273;
			pt->TC[i][2]=(9*pt->TC[i][0])/5+32;
			pt->TC[i][3]=(9*pt->TC[i][0])/5+491.67;
			n++;
		}
	} while(pt->TC[i][0]!=100);
	
	
	printf("ºC\tºK\tºF\tºR\n");
	for(i=0;i<n;i++)	
	printf("%.1f\t%.1f\t%.1f\t%.1f\t\n",pt->TC[i][0],pt->TC[i][1],pt->TC[i][2],pt->TC[i][3]);
	

	
	/*printf("La temperatura en ºR es %.2f\n",rankie(t1.TC));
	printf("La temperatura en ºK es %.2f\n",kelvin(t1.TC));
	printf("La temperatura en ºF es %.2f\n",faren(t1.TC));
	*/
	

	return 0;
}

float rankie (float c){
	return (c*9)/5+491.67;
}
	
	float kelvin(float c){
		return c+273;
	}
		
		float faren(float c){
			return(c*9)/5+32;
		}
			
			
