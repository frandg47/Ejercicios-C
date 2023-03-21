#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Ingresar en un vector los nombres las N asignaturas de la carrera Ing. Sistema de Información, paralelamente ingresar en otro vector la cantidad de alumnos inscriptos en este año cada asignatura.
//SE PIDE:
//a. En una función Sin Tipo, realizar la carga de los vectores en forma simultánea, Asignatura y nro. de inscriptos.
//b. Haciendo uso de una función Con Tipo, determinar y mostrar en la función main, que asignatura tiene el mayor
//número de inscriptos.
//c. Por medio de una función con tipo, mostrar la cantidad de inscriptos en una determinada asignatura. El nombre
//de la asignatura se ingresa por teclado solicitado en la función.

typedef char materia[20];

void carga(materia asignatura[15],int alumnos[20],int &N);
int mayorinscriptos(materia asignatura[15],int alumnos[20],int N,char asigmay[15]);
int buscar(materia asignatura[15],int alumnos[20],int N,char materia[15]);


main()
{	
	materia asignatura[15];
	int alumnos[20],opcion,b=1,N=0,bandera=0,may=0,cant=0;
	char asigmay[15], materia[15];
	while(b==1)
	{
	system("cls");
	printf("\t\tSISTEMA DE CARGA DE ASIGNATURAS Y ALUMNOS\n");
	printf("\n\tMENU");
	printf("\n1) Cargar Asignaturas\n2) Asignatura con mayor cantidad de alumnos\n3) Cantidad de alumnos de una asignatura\n");
	printf("\nOPCION: ");
	scanf("%d",&opcion);
	switch(opcion)
	{	
	case 1: carga(asignatura,alumnos,N);bandera=1;break;
	case 2: if(bandera==1)
		{
		may=mayorinscriptos(asignatura,alumnos,N,asigmay);
		printf("\nLa materia %s tiene la mayor cantidad de alumnos (%d)",asigmay,may);
		}
			else
		{
			system("cls");
			printf("No se ingresaron datos!");
		}
		break;
		case 3: if(bandera==1)
		{
		cant=buscar(asignatura,alumnos,N,materia);
		printf("\nLa materia %s tiene %d alumnos",materia,cant);
		}
			else
		{
			system("cls");
			printf("No se ingresaron datos!");
		}
	default: b=0;	
	}
	system("PAUSE");	
	}
	
	
		
	
	
}

void carga(materia asignatura[15],int alumnos[20],int &N)
{
	system("cls");
	printf("Ingrese la cantidad de asignaturas: ");
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		_flushall();
		printf("\n\tMateria[%d]: ",i+1);
		fgets(asignatura[i],15,stdin);
		printf("\n\tAlumnos inscriptos: ");
		scanf("%d",&alumnos[i]);
	}	
	printf("\tLa carga se realizo correctamente!");
}

int mayorinscriptos(materia asignatura[15],int alumnos[20],int N,char asigmay[15])
{
	int may=0;
	
	for(int i=0;i<N;i++)
	{
		if(alumnos[i]>may)
		{
			may=alumnos[i];
			for(int j=0;j<15;j++)
			{
				asigmay[j]=asignatura[i][j];
			}			
		}	
	}	
	return may;
}

int buscar(materia asignatura[15],int alumnos[20],int N,char mat[15])
{
	
	int cantalum=0;
	system("cls");
	_flushall();
	printf("Ingrese la materia: ");
	gets(mat);	
	for(int i=0;i<N;i++)
	{
		
		if(strcmp(mat,asignatura[i])==0)
		{
			cantalum=alumnos[i];	
		}
		printf("%d",cantalum);
	}
	return cantalum;
}