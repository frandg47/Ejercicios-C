#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rutina{
	char Ejercicio[100];
	int series;
	int reps;
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
	rutina rut[10];
	char Actividad[50];
	int horario;	
};


void Cargarutinas();
void MostrarRutina();

main()
{
	Cargarutinas();
	MostrarRutina();
	system("pause");
	system("cls");
	

	
	system("pause");
	system("cls");
}

void Cargarutinas()
{
	Socios soc;
	int n,opc,doc;
	bool band;
	FILE *Rutina;
	
	Rutina=fopen("Socios.dat","r+b");
	
	if(Rutina==NULL){
		printf("Creando archivo...");
		Rutina=fopen("Socios.dat","w+b");
		system("pause");
		system("cls");
		printf("Archivo creado exitosamente...");
		system("pause");
		system("cls");
	}
	
	

	

	
	
	printf("CARGA DE RUTINAS\n");
	printf("Ingrese el DNI del socio: ");
	scanf("%d",&doc);
	band=false;
	rewind(Rutina);
	
	fread(&soc,sizeof(Socios),1,Rutina);
	while(feof(Rutina)==0 && band==false){
		
		if(soc.Dni==doc){
	
	system("cls");
	
	for(int i=0;i<10;i++){
		
		printf("CARGA DE RUTINAS\n");
		_flushall();
		printf("Ingrese el ejercicio numero %d(Ingrese 0 para dejar de cargar): ",i+1);
		gets(soc.rut[i].Ejercicio);
		opc=strcmp(soc.rut[i].Ejercicio,"0");
		if(opc==0){
			break;
		}
		printf("Ingrese el numero de series: ");
		scanf("%d",&soc.rut[i].series);
		
		printf("Ingrese el numero de repeticiones: ");
		scanf("%d",&soc.rut[i].reps);
		
		fwrite(&soc,sizeof(Socios),1,Rutina);
		system("cls");
}	band=true;
		}else{
		fread(&soc,sizeof(Socios),1,Rutina);
		}
	}
	
	
	fclose(Rutina);
	
	}
	
	
	


void MostrarRutina()
{
	Socios soc;
	int doc;
	FILE *Rutina;
	
	Rutina=fopen("Socios.dat","r+b");
	printf("RUTINA\n");
	printf("Ingrese el DNI del socio: ");
	scanf("%d",&doc);
	
	rewind(Rutina);
	fread(&soc,sizeof(Socios),1,Rutina);
	
	printf("EJERCICIO\tSERIES\tREPETICIONES\n");
	while(!feof(Rutina)){
		
		if(soc.Dni==doc){
		for(int i=0;i<10;i++){
		
	printf("%s\t%d\t%d\n",soc.rut[i].Ejercicio,soc.rut[i].series,soc.rut[i].reps);	
	}
	}else{
	fread(&soc,sizeof(Socios),1,Rutina);	
	}
	
	
	}
	fclose(Rutina);

}