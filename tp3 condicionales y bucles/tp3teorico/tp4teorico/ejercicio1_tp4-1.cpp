#include<stdio.h>
#include<stdlib.h>

void Sueldo1(int c_horas,int v_horas,float djubilacion,float dobrasocial,float &sueldo);

void Sueldo2(int c_horas,int v_horas,float djubilacion,float dobrasocial,float &sueldo);

main()
{
	int c_horas,v_horas,c=0,n;
	float djubilacion=0.11,dobrasocial=0.03,sueldo;
	
	
	printf("\ningrese la cantidad de horas trabajadas: ");
	scanf("%d",&c_horas);
	printf("\ningrese el valor a pagar por hora (0 para salir): ");
	scanf("%d",&v_horas);
		
	while(v_horas!=0)
	{	
	
		if(c_horas>0 and c_horas<=60)
			{
				Sueldo1(c_horas,v_horas,djubilacion,dobrasocial,sueldo);
				printf("\nSu sueldo es: $%.2f\n",sueldo);					
			}
		else if (c_horas>60)
			{
				Sueldo1(c_horas,v_horas,djubilacion,dobrasocial,sueldo);
				printf("\nSu sueldo es: $%.2f\n",sueldo);
			}
		else	
			{
				printf("\nNo trabajo\n");
			}
		printf("\ningrese la cantidad de horas trabajadas: ");
		scanf("%d",&c_horas);
		printf("\ningrese el valor a pagar por hora (0 para salir): ");
		scanf("%d",&v_horas);		
	}
	
	
	system("pause");
}

void Sueldo1(int c_horas,int v_horas,float djubilacion,float dobrasocial,float &sueldo)
{
	sueldo=(float)c_horas*v_horas*(1-djubilacion-dobrasocial);	
}

void Sueldo2(int c_horas,int v_horas,float djubilacion,float dobrasocial,float &sueldo)
{
	sueldo=(float)c_horas*v_horas*(1-djubilacion-dobrasocial)*1.05;	
}