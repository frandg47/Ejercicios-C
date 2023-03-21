#include<stdio.h>
#include <stdlib.h>
#include "metodos.h"

main()
{
	int num,n,v[50];
	int b=1;
	
	printf("Bienvenido al programa!");
	printf("\n\nIngrese el numero del metodo de ordenamiento que desee ejecutar\n");
	printf("\n1 = Intercambio  \n2 = Insercion	\n3 = Seleccion  \n4 = Rapido  \n5 = Mezcla");
	printf("\n\nMetodo a seleccionar: ");
	scanf("%d",&num);	
	
	while(b!=0)
	{
	 	switch(num)
 		{
			case 1: 
					system("cls");
					printf("\nUsted ha elegido el metodo de Intercambio o Burbuja mejorada");
					printf("\n\nIngrese el orden del vector: ");
					scanf("%d",&n);
					printf("\n");
					Leer(n,v);
					Intercambio(v,n);
			        break;
			case 2:
					system("cls");
					printf("\nUsted ha elegido el metodo de Insercion o de la baraja");
					printf("\n\nIngrese el orden del vector: ");
					scanf("%d",&n);
					printf("\n");
					Leer(n,v);
					Insercion(v,n);
			        break;
			case 3:
					system("cls");
				    printf("\nUsted ha elegido el metodo de Seleccion o Sencillo");
				    printf("\n\nIngrese el orden del vector: ");
				    scanf("%d",&n);
				    printf("\n");
				    Leer(n,v);
				    Seleccion(v,n);
				    break;
			case 4: 
					system("cls");
			        printf("\nUsted ha elegido el metodo Rapido o QuickSort");
				    printf("\n\nIngrese el orden del vector: ");
				    scanf("%d",&n);
				    printf("\n");
				    quicksort_leer(n);
				    break;
			case 5:
					system("cls");
					printf("\nUsted ha elegido el metodo por Mezcla o MergeSort");
				    printf("\n\nIngrese el orden del vector: ");
				    scanf("%d",&n);
				    printf("\n");
				    leer_merge(n); 
				    break;
				    
			default: printf("\nLa opcion ingresada es erronea, por favor intente de nuevo\n");
		}
			
		   printf("\n\nSi desea continuar ingrese 1, en caso contrario ingresar 0: ");
		   scanf("%d",&b);
		   
		if(b!=0)
		{ 
				system("cls");
				b=1;
				printf("Bienvenido al programa!");
				printf("\n\nIngrese el numero del metodo de ordenamiento que desee ejecutar\n");
				printf("\n1 = Intercambio  \n2 = Insercion	\n3 = Seleccion  \n4 = Rapido  \n5 = Mezcla");
				printf("\n\nMetodo a seleccionar: ");
				scanf("%d",&num);					
		}
	}
	printf("\nPRESIONE UNA TECLA PARA SALIR...");
}

	
