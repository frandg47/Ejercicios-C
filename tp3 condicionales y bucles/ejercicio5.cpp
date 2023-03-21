#include<stdlib.h>
#include<stdio.h>

main()
{
	int nota,edad;
	
	printf("ingrese la nota del alumno: ");
	scanf("%d",&nota);
	printf("\ningrese la edad del alumno: ");
	scanf("%d",&edad);
	if(nota>=6)
	{
		if(edad<=10)
		{
			printf("\nel alumno pertenece a la division A y curso 1\n\n");
		}
		if(edad>10 and edad<=20)
		{
			printf("\nel alumno pertenece a la division A y curso 2\n\n");
		}
		if(edad>20)
		{
			printf("\nel alumno pertenece a la division A y curso 3\n\n");
		}
	}
	else
	{
		printf("\nel alumno pertenece a la division B\n\n\n");
	}
	system("pause");
}