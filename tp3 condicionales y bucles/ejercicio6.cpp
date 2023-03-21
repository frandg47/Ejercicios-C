#include<stdio.h>
#include<stdlib.h>

main()
{
	int mes,dia;
	
	printf("ingrese valor correspondiente al mes: ");
	scanf("%d",&mes);
	printf("\ningrese valor correspondiente al dia: ");
	scanf("%d",&dia);
	
	if(dia>=21 and mes==12 or mes<=3)
	{
		printf("\nES VERANO\n\n");
	}
	else if(dia>=21 and mes==3 or mes<=6)
	{
		printf("\nES OTONIO\n\n");
	}
	else if(dia>=21 and mes==6 or mes<=9)
	{
		printf("\nES INVIERNO\n\n");
	}
	else if(dia>=21 and mes==9 or mes<=12)
	{
		printf("\nES PRIMAVERA\n\n");
	}	
	
	system("pause");
	
}