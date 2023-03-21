#include<stdio.h>
#include<stdlib.h>

main()	
{
	int A,c=1,s=0;
	float promedio=0.00;
	
	while(c<=3)
	{
		printf("\ningrese nota del alumno: ");
		scanf("%d",&A);
		if(A>0 and A<=10)
		{
			s=s+A;		
			c=c+1;
		}
		
		else
		{
			printf("\nERROR EN LA CARGA DE NOTAS, INGRESE NUEVAMENTE LAS 3 NOTAS\n\n\n");
			c=1;
			s=0;
			system("pause");
			system("cls");			
		}
		
	}
	promedio=(float)s/3;
	printf("\nel promedio del alumno es: %.2f\n\n\n",promedio);
	if(promedio>=6)
	{
		printf("\nEL ALUMNO APROBO EL ANIO\n\n\n");
	}
	else
	{
		printf("\nEL ALUMNO NO APROBO EL ANIO\n\n\n");
	}
	
	system("pause");
}