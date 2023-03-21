#include<stdio.h>
#include<stdlib.h>

void Suma(int x,float &sumatoria);

main()
{
	int a,n,c=0;
	float sum=0.00;
	
	printf("ingrese la cantidad de valores a sumar: ");
	scanf("%d",&n);
	while(c<n)
	{
		printf("ingrese un valor: ");
		scanf("%d",&a);
		Suma(a,sum);
		c++;
	}
	printf("\nla suma total de los valores ingresados es: %.1f\n\n\n",sum);
	
	system("PAUSE");
}

void Suma(int x,float &sumatoria)
{
	sumatoria=sumatoria+x;
}