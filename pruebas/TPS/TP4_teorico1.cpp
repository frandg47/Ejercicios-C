#include<stdio.h>
#include<stdlib.h>
#include<ctime>

void Carga(float v[],int &n)
{
	printf("Ingrese la cantidad de alumnos: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\n\tLegajo:[%d]\tPromedio: ",i);
		scanf("%f",&v[i]);
	}
	printf("\nLos promedios fueron cargados exitosamente!");
}

float Mayorprom(float v[],int n)
{
	int legajo;
	float may=0.00;
	
	for(int i=0;i<n;i++)
	{
		if(v[i]>may)
		{
			may=v[i];
			legajo=i;
		}
	}
	
	return legajo;	
}

main()
{
	float v[100];
	int mayorprom=0,n=0;
	
	Carga(v,n);
	mayorprom=Mayorprom(v,n);
	system("cls");
	printf("\n\tEl alumno con mejor promedio es el de legajo: %d",mayorprom);
	printf("\n\n\n\t");
	system("pause");
}