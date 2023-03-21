#include<stdio.h>
#include<stdlib.h>

main()
{
	int J,K,I,L;
	float r1=0.00,r2=0.00;
	
	printf("\ningrese el valor de I: ");
	scanf("%d",&I);
	printf("\ningrese el valor de J: ");
	scanf("%d",&J);
	printf("\ningrese el valor de K: ");
	scanf("%d",&K);
	printf("\ningrese el valor de L: ");
	scanf("%d",&L);
	
	r1=(float)I/J;
	r2=(float)K/L;
	
	if(r1==r2)
	{
		printf("\nel resultado de las divisiones es igual\n\n\n");
	}
	else
	{
		printf("\nel resultado de las divisiones NO es igual\n\n\n");
	}
	
	system("pause");
}