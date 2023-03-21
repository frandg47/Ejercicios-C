#include<stdio.h>
#include<stdlib.h>

int Fibonacci(int x);

main()
{
	int numero,fib=0;
	
	printf("ingrese un numero perteneciente a la serie de fibonacci: ");
	scanf("%d",&numero);
	
	if(numero>=0)
	{
		fib=Fibonacci(numero);
		system("cls");
		printf("el resultado de %d en la serie de fibonacci es: %d", numero,fib);
	}
	else
	{
		printf("\n-1\n\n\n");
	}
	
}

int Fibonacci(int x)
{
	
		
	if(x==0)
	{
		return 0;
	}
	else if (x==1)
	{
		return 1;
	}
	else
	{
		return Fibonacci(x-1)+Fibonacci(x-2);
	}
		
}