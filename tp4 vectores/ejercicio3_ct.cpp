#include<stdlib.h>
#include<stdio.h>

float horas(int x);
float segundos(int x);

main()
{
	int x;
	float h,m,s;
	
	printf("\ningrese una cantidad mayor a 600: ");
	scanf("%d",&x);
	if(x>600)
	{
		h = horas(x);
		printf("\nel valor en horas es: %.2f",h);
		printf("\nel valor en minutos es: %d",x);
		s = segundos(x);
		printf("\nel valor en segundos es: %.2f\n\n\n",s);
	}
	else
	{
		printf("\nERROR\n\n\n");
	}
	system("PAUSE");	
}

float horas(int x)
{
	float hor;
	hor=(float)x/60;
	return hor;
}

float segundos(int x)
{
	float seg;
	seg=(float)x*60;
	return seg;
}