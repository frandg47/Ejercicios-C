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
			if(m[i][j]<=0)
			{
				printf("\nEl elemento no puede ser menor que cero\n");
				j--;
			}
		}
	}
	printf("\n\nLA MATRIZ SE CARGO CORRECTAMENTE");
}

void cambio(float m[10][10],int M,int N)
{
	int i,j,o,p;
	
	printf("\nIngrese la posicion de la matriz que desea reemplazar por cero\n\tFila: ");
	scanf("%d",&o);
	printf("\n\tColumna: ");
	scanf("%d",&p);
	m[o-1][p-1]=0;
	
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

void mostrarfc(float m[10][10],int M,int N)
{
	int i,j,foc,fila,col;
	
	printf("\nIngrese 1 para mostrar una fila o 0 para una columna: ");
	scanf("%d",&foc);
		
	if(foc==1)
	{
		printf("\n\tIngrese el numero de fila: ");
		scanf("%d",&fila);
		for(j=0;j<N;j++)
		{
			printf("\t%.2f",m[fila-1][j]);
		}	
	}
	else
	{
		printf("\n\tIngrese el numero de columna: ");
		scanf("%d",&col);
		for(i=0;i<M;i++)
		{
			printf("\n%.2f",m[i][col-1]);
		}	
	}
}

main()
{
	float m[10][10],may=0,men=0;
	int M,N,b=1,opcion,bandera=0;
	
	while(b!=0)
	{
		system("cls");
		printf("\n\t\tEjercicio 2");
		printf("\n\n1)Ingresar elementos a la Matriz\n2)Listar matriz cargada\n3)Cambiar un elemento por 0\n4)Mostrar una fila o una columna");
		printf("\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("cls");printf("\nIngrese cantidad de filas: ");scanf("%d",&M);printf("\nIngrese cantidad de columnas: ");scanf("%d",&N);ingresar(m,M,N);bandera=1;break;
			case 2: system("cls");if(bandera==1){listar(m,M,N);}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			case 3: system("cls");if(bandera==1){cambio(m,M,N);printf("\t");listar(m,M,N);}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			case 4: system("cls");if(bandera==1){mostrarfc(m,M,N);}else{printf("\n\tSE DEBE CARGAR LA MATRIZ");}break;
			default: system("cls");printf("\n\tINGRESE UNA OPCION VALIDA");
		}
		
		printf("\n\n\nIngrese 1 para continuar, 0 para salir: ");
		scanf("%d",&b);
		
	}
	printf("\n\t\tHASTA PRONTO!\n\n\n\n");
	system("PAUSE");	
}