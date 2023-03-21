#include<stdio.h>
#include<stdlib.h>

void intervalo (float a, float b, int n);

main()
{
	int n;
	float A,B;
	
	printf("\ningrese los limites de un intervalo (A,B]");
	printf("\nigrese A: ");
	scanf("%f",&A);
	printf("\nigrese B: ");
	scanf("%f",&B);
	printf("\ningrese la cantidad N de numeros a analizar: ");
	scanf("%d",&n);
	
	intervalo (A,B,n);
	
	system("PAUSE");
}

void intervalo (float a,float b,int n)
{
	int c=0,c1=0,c2=0;
	float x;
	while(c<n)
	{
		printf("\ningrese un valor: ");
		scanf("%f",&x);
		if(x>a and x<=b)
		{
			c1++;
		}
		else
		{
			c2++;
		}
		c++;
	}
	printf("\nla cantidad de valores dentro del intervalo: %d",c1);
	printf("\nla cantidad de valores fuera del intervalo: %d\n\n\n\n",c2);
}