#include<stdlib.h>
#include<stdio.h>

main()
{
	int a,b,c,r1,r2;
	float r3;	
	
	printf("\ningrese el valor del primer valor: ");
	scanf("%d",&a);
	printf("\ningrese el valor del segundo valor: ");
	scanf("%d",&b);
	printf("\ningrese el valor del tercer valor: ");
	scanf("%d",&c);
	
	if(a==b)
	{
		r1=a+b+c;
		printf("\nla suma de los 3 valores es: %d\n\n\n",r1);
	}
	if(a<c)
	{
		r2=a*b;
		printf("\nel producto del primero y segundo valor es: %d\n\n\n",r2);
	}
	if(b>a)
	{
		if(a!=0)
		{
			r3=(float)b/a;
			printf("\nla division del segundo valor entre el primero es: %.2f\n\n\n",r3);
		}
		else
		{
			printf("\nerror no se puede dividir por 0\n\n\n");
		}
	}
	system("pause");
}