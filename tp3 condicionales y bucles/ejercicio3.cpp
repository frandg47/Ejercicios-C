#include<stdlib.h>
#include<stdio.h>
#include<cmath>

main()
{
	int a,b;
	float raiz;
	
	printf("\ningrese un valor: ");
	scanf("%d",&a);
	
	if(a>=0)
	{
		raiz=(float)sqrt(a);
		printf("\nla raiz cuadrada del valor ingresado es: %.2f\n\n\n",raiz);
	}
	else
	{
		b=-a;
		raiz=(float)sqrt(b);
		printf("\nla raiz cuadrada del valor ingresado es: %.2f\n\n\n",raiz);
	}
	system("pause");
}