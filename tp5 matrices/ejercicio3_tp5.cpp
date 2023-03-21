#include<stdio.h>
#include<stdlib.h>

void cargarnd(int m[10][10],int M,int N)
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			m[i][j]=1 + rand()%500;
		}
	}
}

void listar(float m[10][10],int M,int N)
{
	int i,j;
	
	for(i=0;i<M;i++)
	{
		printf("\n\tTaller %d\n",i);
		for(j=0;j<N;j++)
		{
			printf("%d  ",m[i][j]);
			if(j>=0 and j<N-1)
			{
				printf("-  ");
			}
		}
		printf("\n");
	}
}

int maymen(int m[10][10],int M,int N)
{
	int i,j;
	int may=0;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(may<m[i][j])
			{
				may=m[i][j];
		}
	}
	return may;
}

main()
{
	int m[10][10],may=0;
	int M=1,N=3,b=1,opcion,bandera=0;
	
	while(b!=0)
	{
		system("cls");
		printf("\n\t\tEjercicio 3");
		printf("\n\n1)Ingresar elementos a los talleres\n2)Cantidades producidas de prendas por cada taller\n3)El taller que más producio");
		printf("\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("cls");cargarnd(m,M,N);bandera=1;break;
			case 2: system("cls");if(bandera==1){listar(m,M,N);printf("\nLa tienda con mas ventas vendio: %d",)}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			case 3: system("cls");if(bandera==1){may(m,M,N)}els
			default: system("cls");printf("\n\tINGRESE UNA OPCION VALIDA");
		}
		
		printf("\n\n\nIngrese 1 para continuar, 0 para salir: ");
		scanf("%d",&b);
		
	}
	printf("\n\t\tHASTA PRONTO!\n\n\n\n");
	system("PAUSE");	
}