/*En una fábrica de envases de plásticos se desea procesar datos relacionado con su producción
mensual. El ingreso de lo producido por la empresa, se realiza por semana. Pudiendo haber semana
en que alguna de las maquinas no haya realizado producción.
SE PIDE: Confeccionar un programa que lea él código de cada maquinas (1, 2, 3), la cantidad de
envases que produjo en la semana, la cantidad de envase que poseen falla y debieron desecharse.
NOTA: El ingreso de datos deberá finalizar cuando se ingresa como código de maquina el 0 (cero).
Tener en cuenta que a medida que se realiza la carga se irán realizando los cálculos para poder
mostrar al final de la carga lo que se pide.
El programa deberá informar al terminar la carga:
su número de identificación de cada máquina,
la cantidad total de envases producidos y
Creando una función con tipo calcular y devolver el porcentaje de envases desechados respecto al
total de envases que ha producido por las tres máquinas.
*/

#include<stdlib.h>
#include<stdio.h>

float Calculo(int total_prod,int total_fallas);

main()
{
	int cod,cant_envases,cant_fallas,ce1,ce2,ce3,cf1,cf2,cf3,c1=0,c2=0,c3=0,s1=0,s2=0,s3=0,s,c;
	float Porcfallas;
	printf("--------------------------------------SISTEMA--------------------------------------");
	printf("\n\ningrese el codigo de maquina (codigo 0 para terminar): ");
	scanf("%d",&cod);
	
	while(cod!=0)
	{
		if(cod==1)
		{
			printf("\ningrese la cantidad de envases producidos en la semana: ");
			scanf("%d",&ce1);
			printf("\ningrese la cantidad de envases fallados en la semana: ");
			scanf("%d",&cf1);
			s1=s1+ce1; //sumatoria de envases producidos
			c1=c1+cf1; //sumatoria de envases fallados							 
		}
		if(cod==2)
		{
			printf("\ningrese la cantidad de envases producidos en la semana: ");
			scanf("%d",&ce2);
			printf("\ningrese la cantidad de envases fallados en la semana: ");
			scanf("%d",&cf2);
			s2=s2+ce2;
			c2=c2+cf2;					 
		}
		if(cod==3)
		{
			printf("\ningrese la cantidad de envases producidos en la semana: ");
			scanf("%d",&ce3);
			printf("\ningrese la cantidad de envases fallados en la semana: ");
			scanf("%d",&cf3);
			s3=s3+ce3;
			c3=c3+cf3;			 
		}
		if(cod!=1 and cod!=2 and cod!=3)
		{
			printf("\nERROR ingrese un codigo aceptado\n\n\n");
			system("PAUSE");
			system("cls");			
		}
	system("cls");
	printf("--------------------------------------SISTEMA--------------------------------------");
	printf("\n\ningrese el codigo de maquina (codigo 0 para terminar): ");
	scanf("%d",&cod);
	}
	s=s1+s2+s3; //total de envases producidos
	c=c1+c2+c3; //total de envases fallados
	Porcfallas = Calculo (s,c);
	system("PAUSE");
	system("cls");	
	printf("\n----------------------RESUMEN SEMANAL----------------------");
	printf("\nMAQUINA              ENVASES FALLADOS      TOTAL DE ENVASES");
	printf("\n  1                         %d                     %d",c1,s1);
	printf("\n  2                         %d                     %d",c2,s2);
	printf("\n  3                         %d                     %d",c3,s3);
	printf("\n-----------------------------------------------------------");
	printf("\nTOTAL PRODUCIDO:                                  %d",s);
	printf("\nTOTAL FALLAS:                                     %d",c);
	printf("\nPORCENTAJE DE FALLAS:                           %.2f%\n\n\n\n",Porcfallas);
	system("PAUSE");	
}

float Calculo(int total_prod,int total_fallas)
{
	float Calculo;
	Calculo=(float)100*total_fallas/total_prod;
	return Calculo;
}