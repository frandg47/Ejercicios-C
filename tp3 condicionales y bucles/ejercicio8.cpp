#include<stdlib.h>
#include<stdio.h>

main()
{
	int cantcorrec,canttotal;
	float porc;
	
	printf("\ningrese la cantidad de preguntas realizadas al postulante: ");
	scanf("%d",&canttotal);
	printf("\ncuantas contesto correctamente? ");
	scanf("%d",&cantcorrec);
	
	porc=(cantcorrec/canttotal)*100;
	
	if(porc>=50 and porc<75)
	{
		printf("\nse encuentra en NIVEL REGULAR\n\n\n\n");
	}
	if(porc>=75 and porc<90)
	{
		printf("\nse encuentra en NIVEL MEDIO\n\n\n\n");
	}
	if(porc>=90)
	{
		printf("\nse encuentra en NIVEL SUPERIOR\n\n\n\n");
	}
	
	system("pause");
}