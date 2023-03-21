#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	int dia, mes, anio;
};

struct notas{
	float primert,segundot,tercert;
};

struct alumnos{
	int dni;
	char Nombre[50];
	fecha fec;
	notas nota;
};

main()
{
	alumnos alu;
	int n;
	float promedio, PROM=0;
	
	printf("\tIngrese cantidad de alumnos: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("\n\tALUMNO [%d]",i+1);
		printf("\nDNI: ");
		scanf("%d",&alu.dni);
		_flushall();
		printf("\nNOMBRE: ");
		gets(alu.Nombre);
		printf("\nFECHA DE NACIMIENTO:");
		printf("\nAnio: ");
		scanf("%d",&alu.fec.anio);
		printf("\nMes: ");
		scanf("%d",&alu.fec.mes);
		printf("\nDia: ");
		scanf("%d",&alu.fec.dia);
		printf("\n\tNOTAS:");
		printf("\nNota 1: ");
		scanf("%f",&alu.nota.primert);
		printf("\nNota 2: ");
		scanf("%f",&alu.nota.segundot);
		printf("\nNota 3: ");
		scanf("%f",&alu.nota.tercert);
		promedio=(alu.nota.primert+alu.nota.segundot+alu.nota.tercert)/3;
		PROM=PROM+promedio;
	}
	printf("\n\nEl promedio de todos los alumnos es: %.2f",PROM/n);
	printf("\n\n\n");
	system("PAUSE");
}