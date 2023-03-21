#include<stdio.h>
#include<stdlib.h>

main()
{
	int c_horas,v_horas,c=0,n;
	float djubilacion=0.11,dobrasocial=0.03,sueldo;
	
	printf("\ningrese la cantidad de trabajadores a determinar su sueldo: ");
	scanf("%d",&n);
	
	for(c=0;c<n;c++)
	{
		printf("\ningrese la cantidad de horas trabajadas: ");
		scanf("%d",&c_horas);
		printf("\ningrese el valor a pagar por hora: ");
		scanf("%d",&v_horas);
	
		if(c_horas>0 and c_horas<=60)
			{
				sueldo=(float)c_horas*v_horas*(1-djubilacion-dobrasocial);
				printf("\nSu sueldo es: $%.2f\n",sueldo);					
			}
		else if (c_horas>60)
			{
				sueldo=(float)c_horas*v_horas*(1-djubilacion-dobrasocial)*1.05;
				printf("\nSu sueldo es: $%.2f\n",sueldo);
			}
		else	
			{
				printf("\nNo trabajo\n");
			}	
	}
	
	
	system("pause");
}