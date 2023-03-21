#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char cadena [30];

void Ingreso(cadena Nombre[20],cadena Apellido[20],int &N);
void Listar(cadena Nombre[20],cadena Apellido[20],int N);
void Decreciente(cadena Nombre[20],cadena Apellido[20],int N);
void Creciente(cadena Nombre[20],cadena Apellido[20],int N);
void Intercambio(cadena vector[40],int N);

main()
{
	int b=1,opcion,N=0,bandera=0;
	cadena Nombre[20],Apellido[20]; 
	while(b!=0)
	{
		system("cls");
		printf("\t\t-----------------MENU-----------------");
		printf("\n\n\tElija una opcion:");
		printf("\n\n1)Ingresar datos de socios\n2)Lista de socios\n3)Ordenar lista [Z-A]\n4)Ordenar lista [A-Z]\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("cls");Ingreso(Nombre,Apellido,N);bandera=1;break;
			case 2: system("cls");if(bandera==1){Listar(Nombre,Apellido,N);}else{printf("\nNO INGRESO SOCIOS!");}break;
			case 3: system("cls");if(bandera==1){Decreciente(Nombre,Apellido,N);}else{printf("\nNO INGRESO SOCIOS!");}break;
			case 4: system("cls");if(bandera==1){Creciente(Nombre,Apellido,N);}else{printf("\nNO INGRESO SOCIOS!");}break;	
			default: printf("\n\n\t=================HASTA PRONTO!=================");b=0;
		}
	}
	printf("\n\n\t\t");
	system("PAUSE");
}

void Ingreso(cadena Nombre[20],cadena Apellido[20],int &N)
{
		
	printf("\nCantidad de socios a ingresar: ");
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		_flushall();
		printf("\nApellido del socio: ");
		gets(Apellido[i]);
		_flushall();
		printf("\nNombre del socio: ");
		gets(Nombre[i]);	
	}
	printf("\n\n\n");
	system("PAUSE");
}

void Listar(cadena Nombre[20],cadena Apellido[20],int N)
{
	printf("\t\tLISTA DE SOCIOS\n\n");
	for (int i=0;i<N;i++)
	{
		strupr(Apellido[i]);
		strupr(Nombre[i]);
		printf("%s %s\n",Apellido[i],Nombre[i]);
	}
	printf("\n\n\n");
	system("PAUSE");
}

void Decreciente(cadena Nombre[20],cadena Apellido[20],int N)
{
	cadena vector[40];
	for(int u=0;u<N;u++)
	{
		strcpy(vector[u],Apellido[u]);
		strcat(vector[u]," ");
		strcat(vector[u],Nombre[u]);
	}
	Intercambio(vector,N);
	for(int i=0;i<N;i++){
		printf("%s\n",vector[i]);
	}
	printf("\n\n\n");
	system("PAUSE");
}

void Creciente(cadena Nombre[20],cadena Apellido[20],int N)
{
	cadena vector[40];
	for(int u=0;u<N;u++)
	{
		strcpy(vector[u],Apellido[u]);
		strcat(vector[u]," ");
		strcat(vector[u],Nombre[u]);
	}
	Intercambio(vector,N);
	for(int i=N-1;i>=0;i--){
		printf("%s\n",vector[i]);
	}
	printf("\n\n\n");
	system("PAUSE");
}

void Intercambio(cadena vector[40],int N)
{
	int i,j;
	cadena aux;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(strcmp(vector[j],vector[j+1])<0)
			{
				strcpy(aux,vector[j]);
				strcpy(vector[j],vector[j+1]);
				strcpy(vector[j+1],aux);
			}			
		}
	}	
}