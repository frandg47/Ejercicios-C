#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datosCliente
{
	int codigoc;
	char ApeNom[40];
	char dire[60];
	float monCred;
};

void mostrar(datosCliente Clientes,int N);

main()
{
	datosCliente Clientes;
	int N,c=0,i=0;
	
	printf("Ingrese la cantidad de clientes a cargar datos: ");
	scanf("%d",&N);
	
	while(c<N)
	{
		system("cls");
		printf("\n\tCliente %d\n",c+1);
		printf("Codigo: ");
		scanf("%d",&Clientes.codigoc);
		printf("\nApellido y Nombre: ");
		_flushall();
		gets(Clientes.ApeNom);		
		printf("\nDomicilio: ");
		_flushall();
		gets(Clientes.dire);		
		printf("\nMonto maximo del credito: ");
		scanf("%f",&Clientes.monCred);
		mostrar(Clientes,N);
		if(Clientes.monCred>30000)
		{
			i++;
		}	
		c++;
	}
	system("cls");
	printf("\n%d Clientes superan el monto de $30000",i);
}

void mostrar(datosCliente Clientes,int N)
{
	int i=0,c=0;
	system("cls");
	printf("\n\tCliente %d cargado",i+1);
	printf("\n\tDatos:\n");
	printf("\nCodigo: %d",Clientes.codigoc);
	printf("\nApellido y Nombre: %s",Clientes.ApeNom);
	printf("\nDomicilio: %s",Clientes.dire);
	printf("\nMonto maximo del credito: $%.2f",Clientes.monCred);
	printf("\n\n\n");
	i++;
	system("PAUSE");
}