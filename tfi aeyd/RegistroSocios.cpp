#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rutina{
	char Ejercicio[100];
	int Series;
	int Repeticiones;
};

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Socios{
	char Nombre[50];
	char Apellido[50];
	int Dni;
	int Edad;
	int Peso;
	int Altura;
	char Medicas[100];
	char Telefono[50];
	char Domicilio[50];
	Fecha fec;
	Rutina rut[10];
	char Actividad[50];
	int horario;	
};


void RegistroSocios();
void MostrarSocios();
void RegistroActividad();

main()
{

	
	int opcion;
do{
	
	printf("		MENU		");
	printf("\n1------Registrar Socio\n");
	printf("\n2------Mostrar Listado De socios\n");
	printf("\n3------Registrar Actividad de socio\n");
	printf("\n0------Finalizar\n");
	printf("\nElija lo que desea realizar: ");
	scanf("%d",&opcion);
	system("pause");
	system("cls");
	switch(opcion){
		case 1:	RegistroSocios();
				system("pause"); 
				system("cls");			
		break;
		case 2: MostrarSocios();
				system("pause");
				system("cls");
		break;		
		case 3: RegistroActividad();
				system("pause");
				system("cls");
		break;
	} 	
} while(opcion!=0);
	

}

void RegistroSocios()
{
	int i=0;
	

	Socios soc;
		
	FILE *Socio;
	
	Socio=fopen("Socios.dat","a+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	
	printf("REGISTRO DE SOCIOS\n");
	
	_flushall();
	printf("Nombre: ");
	gets(soc.Nombre);
	
	_flushall();
	printf("Apellido: ");
	gets(soc.Apellido);
	
	printf("DNI: ");
	scanf("%d",&soc.Dni);
	
	printf("Edad: ");
	scanf("%d",&soc.Edad);
	
	printf("Peso: ");
	
	scanf("%d",&soc.Peso);
	
	printf("Altura en cm: ");
	scanf("%d",&soc.Altura);
	
	_flushall();
	printf("Telefono: ");
	gets(soc.Telefono);
	
	_flushall();
	printf("Ingrese indicaciones medicas: ");
	gets(soc.Medicas);
	
	_flushall();
	printf("Domicilio: ");
	gets(soc.Domicilio);
	
	printf("FECHA DE INGRESO\n");
	printf("Dia: ");
	scanf("%d",&soc.fec.dia);
	printf("Mes: ");
	scanf("%d",&soc.fec.mes);
	printf("Año: ");
	scanf("%d",&soc.fec.anio);
	
	
	fwrite(&soc,sizeof(Socios),1,Socio);
	
	fclose(Socio);
}

void MostrarSocios()
{

	Socios soc;

	int i=0;	
	FILE *Socio;
	
	Socio=fopen("Socios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	
	
	
	rewind(Socio);
	fread(&soc,sizeof(Socios),1,Socio);
	printf("SOCIOS REGISTRADOS\n");
	printf("Nombre\t\tApellido\tDni\n ");
	while(!feof(Socio)){	
	
	printf("%s\t\t%s\t\t%d\n",soc.Nombre,soc.Apellido,soc.Dni);
	
	
	fread(&soc,sizeof(Socios),1,Socio);
	i++;	
}
	printf("Cantidad de socios=%d\n",i);
	
	fclose(Socio);
}

void RegistroActividad()
{
	Socios soc;
	int doc,opc;
	int i=0;	
	FILE *Socio;
	bool band;
	
	Socio=fopen("Socios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	printf("REGISTRO ACTIVIDADES\n");
	printf("Ingrese el DNI del socio: ");
	scanf("%d",&doc);
	band=false;
	rewind(Socio);
	
	fread(&soc,sizeof(Socios),1,Socio);
	while(feof(Socio)==0 && band==false){
		if(soc.Dni==doc){
			printf("Socio:%s %s\n",soc.Nombre,soc.Apellido);
			
			printf("\n\t\t************************************************************");
printf("\n\t\t** C R O N O G R A M A **");
printf("\n\t\t************************************************************");
printf("\n\t\t** Horario\tLunes\tMartes\tMiercoles Jueves Viernes Sabado**");
printf("\n\t\t************************************************************");
for(int h=8;h<22;h++){
	printf("\n\t\t** %d:00",h);
}
band=true;
		}else{
			fread(&soc,sizeof(Socios),1,Socio);
		}
	}
}
	

