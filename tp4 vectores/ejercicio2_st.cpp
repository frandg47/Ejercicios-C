#include<stdio.h>
#include<stdlib.h>

void Multiplos(int x1,int x2);

main()
{
	int n,a,b,c=0;
		
	printf("\ningrese la cantidad de duplas: ");
	scanf("%d",&n);
	while(c<n)
	{
	printf("\ningrese el valor A: ");
	scanf("%d",&a);
	printf("\ningrese el valor B: ");
	scanf("%d",&b);
	if(a>=1 and a<=9 and b>=1 and b<=9)
		{
		Multiplos(a,b);
		}
	else
		{
		printf("\nERROR");
		c=n;	
		}
	c++;
	}
	system("PAUSE");
}

void Multiplos(int x1,int x2)
{
	int mult,m=10,i;
	if(x1 % x2 == 0 or x2 % x1 == 0)
	{
		for(i=1;i<=m;i++)
		{
			if(x1>x2)
			{
				mult=x1*i;	
				printf("\n%d",mult);
			}
			else if(x2>x1)
			{
				mult=x2*i;	
				printf("\n%d",mult);
			}
			else if(x2==x1)
			{
				mult=x2*i;	
				printf("\n%d",mult);
			}
		}	
	}
	else
	{
		for(i=1;i<=m;i++)
		{
			mult=x2*x1;
			mult=mult*i;
			printf("\n%d",mult);
		}
	}
	
}
