#include<stdlib.h>
#include<stdio.h>

int SumasSucesivas(int x);

main()
{
	int x,n,c=0,Cuadrado;
	
	printf("ingrese la cantidad de numeros que desea calcular su cuadrado: ");
	scanf("%d",&n);
	while(c<n)
	{
		printf("\ningrese el valor: ");
		scanf("%d",&x);
		Cuadrado = SumasSucesivas(x);
		printf("\nEl cuadrado del valor es: %d\n\n\n",Cuadrado);
		c++;
	}
	system("PAUSE");	
}

int SumasSucesivas(int x)
{
	int cuadrado=0,n=0,m=1;
	while(n<x)
	{
		cuadrado=cuadrado+m;
		m=m+2;
		n=n+1;
	}
	return cuadrado;
}