#include<stdio.h>
#include<stdlib.h>

void ingresar(float m[10][10],int M,int N)
{
	int i,j;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("\nElemento de fila %d, columna %d: ",i+1,j+1);
			scanf("%f",&m[i][j]);
		}
	}
	printf("\n\nLA MATRIZ SE CARGO CORRECTAMENTE");
}

float maymen(float m[10][10],float &men)
{
	int i,j;
	float may=0;
	men=m[0][0];
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(may<m[i][j])
			{
				may=m[i][j];
			}
			if(m[i][j]<men)
			{
				men=m[i][j];
			}
		}
	}
	return may;
}

void listar(float m[10][10],int M,int N)
{
	int i,j;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%.2f  ",m[i][j]);
			if(j>=0 and j<N-1)
			{
				printf("-  ");
			}
		}
		printf("\n");
	}
}

main()
{
	float m[10][10],may=0,men=0;
	int M=4,N=3,b=1,opcion,bandera=0;
	
	while(b!=0)
	{
		system("cls");
		printf("\n\t\tEjercicio 1");
		printf("\n\n1)Ingresar elementos a la Matriz\n2)Encontrar menor y mayor elemento\n3)Listar matriz cargada\n4)Salir");
		printf("\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("cls");ingresar(m,M,N);bandera=1;break;
			case 2: system("cls");if(bandera==1){may=maymen(m,men);printf("\nEl mayor elemento es %f y el menor elemento es %f",may,men);}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			case 3: system("cls");if(bandera==1){listar(m,M,N);}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			case 4: system("cls");b=0;break;
			default: system("cls");printf("\n\tINGRESE UNA OPCION VALIDA");
		}
		
		printf("\n\n\nIngrese 1 para continuar, 0 para salir: ");
		scanf("%d",&b);
		
	}
	printf("\n\t\tHASTA PRONTO!\n\n\n\n");
	system("PAUSE");	
}