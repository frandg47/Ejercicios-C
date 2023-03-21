#include<stdlib.h>
#include<stdio.h>

void PorPares(int sumatoria,int n,float &porcentaje);

float PromedioImpares(int sumatoria,int n);

main()
{
	int n,c=0,a,sumpares=0,sumimp=0;
	float porpares=0.00,promimp;
	
	printf("\ningrese una cantidad N: ");
	scanf("%d",&n);
	while(c<n)
	{
		printf("\ningrese un valor entero: ");
		scanf("%d",&a);
		if(a%2==0)
		{
			sumpares=sumpares+1;
		}
		else
		{
			sumimp=sumimp+a;
		}
		c++;
	}
	PorPares(sumpares,n,porpares);
	promimp = PromedioImpares (sumimp,n);
	printf("\nEl porcentaje de num pares ingresados es: %.2f",porpares);
	printf("\nEl promedio de num impares ingresados es: %.2f\n\n\n",promimp);
	system("PAUSE");
}

void PorPares(int sumatoria,int n,float &porcentaje)
{
	porcentaje=(float)100*sumatoria/n;
}

float PromedioImpares(int sumatoria,int n)
{
	float promedio;
	
	promedio=(float)sumatoria/n;
	return promedio;
}