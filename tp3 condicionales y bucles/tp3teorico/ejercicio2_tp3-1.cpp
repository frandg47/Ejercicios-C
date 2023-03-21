#include<stdio.h>
#include<stdlib.h>

main()
{
	int c=0,n;
	float x,y;
	
	printf("\ingrese la cantidad de puntos a analizar: ");
	scanf("%d",&n);
	
	while(c<n)
	{
		printf("\ningrese el valor en el eje absisa: ");
		scanf("%f",&x);
		printf("\ningrese el valor en el eje ordenada: ");
		scanf("%f",&y);
		
		if(x<=3 and x>=-3 or y<=3 and y>=-3)
		{
			printf("\nel punto se encuentra dentro del cuadrado\n");
		}	
		else
		{
			printf("\nel punto se encuentra fuera del cuadrado\n");	
		}
		c=c+1;
	}
	
	system("pause");
}