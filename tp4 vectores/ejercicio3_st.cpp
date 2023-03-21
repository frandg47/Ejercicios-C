#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void SuperficieCirculo(int x1,int x2,float &circulo);
void SuperficieCuadrado(int x1,int x2,float &cuadrado);

main()
{
	int a,b;
	float sup_circ,sup_cuad;
	
	printf("ingrese dos valores enteros y distintos\n");
	printf("\nPrimer valor: ");
	scanf("%d",&a);
	printf("\nSegundo valor: ");
	scanf("%d",&b);
	
	if(a != b)
	{
		SuperficieCirculo(a,b,sup_circ);
		printf("\nla superficie del circulo es: %.2f\n",sup_circ);
		SuperficieCuadrado(a,b,sup_cuad);
		printf("\nla superficie del cuadrado es: %.2f\n\n\n\n",sup_cuad);
	}
	else
	{
		printf("\n----------------ERROR-----------------\n\n\n\n");
	}
	system("PAUSE");
}

void SuperficieCuadrado(int x1,int x2,float &cuadrado)
{
	if(x1>x2)
	{
		cuadrado=x1*x1;
	}
	else
	{
		cuadrado=x2*x2;
	}
}

void SuperficieCirculo(int x1,int x2,float &circulo)
{
	if(x1>x2)
	{
		circulo=(float)x2*M_PI;
	}
	else
	{
		circulo=(float)x1*M_PI;
	}
}

