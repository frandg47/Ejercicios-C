#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct notas{
	float n1,n2;
};

struct registro{
	int legajo;
	char completo[40];
	notas nota;
	bool habilitado;
};

void Creararchivo(registro reg,FILE *arch);
void Listar(registro reg,FILE *arch);
void Agregar(registro reg,FILE *arch);
void Bajalogica(registro reg, FILE *arch);
void Bajafisica(registro reg, FILE *arch, FILE *aux);
void Modificar(registro reg,FILE *arch);

main()
{
	int opcion,b=1;
	registro reg;
	FILE *arch,*aux;
	
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tREGISTRO DE NOTAS\n\n\tSeleccione una opcion: \n\n1)Crear archivo con registros\n2)Listar archivo\n3)Agregar alumnos al archivo\n4)Dar de baja un alumno(baja logica)\n5)Borrar un alumno(baja fisica)\n6)Modificar datos de un alumno\n7)Salir\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: Creararchivo(reg,arch);break;
			case 2: Listar(reg,arch);break;
			case 3: Agregar(reg,arch);break;
			case 4: Bajalogica(reg,arch);break;
			case 5: Bajafisica(reg,arch,aux);break;
			case 6: Modificar(reg,arch);break;
			case 7: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}

void Creararchivo(registro reg,FILE *arch)
{
	system("cls");
	//FILE *arch;
	int n;
	
	printf("\t\tCARGA");
	printf("\nCantidad de alumnos a registrar: ");
	scanf("%d",&n);
	arch=fopen("alumnos.dat","w+b");
	
	for(int i=0;i<n;i++)
	{
		printf("\n\tALUMNO %d:",i+1);
		printf("\nLegajo: ");
		scanf("%d",&reg.legajo);
		_flushall();
		printf("\nNombre Completo: ");
		gets(reg.completo);
		strupr(reg.completo);
		printf("\nNota 1: ");
		scanf("%f",&reg.nota.n1);
		printf("\nNota 2: ");
		scanf("%f",&reg.nota.n2);
		reg.habilitado=true;
		
		fwrite(&reg,sizeof(registro),1,arch);
	}
	fclose(arch);
	printf("\nCARGADO EXITOSAMENTE!\n\n\n");
	system("PAUSE");	
}

void Listar(registro reg,FILE *arch)
{
	system("cls");
	//FILE *arch;
	
	arch=fopen("alumnos.dat","r+b");
	
	printf("\t\tLISTADO ALUMNOS");
	
	fread(&reg,sizeof(registro),1,arch);
	
	while(!feof(arch))
	{
		if(reg.habilitado==true)
		{
		printf("\nLegajo: %d ",reg.legajo);
		printf("\nNombre: ");
		puts(reg.completo);
		printf("\t\tNotas\nNota 1: %.2f\t\tNota 2: %.2f\n\n",reg.nota.n1,reg.nota.n2);
		}				
		fread(&reg,sizeof(registro),1,arch);			
	}
	fclose(arch);
	printf("\n\n\n");
	system("PAUSE");
}

void Agregar(registro reg,FILE *arch)
{
	system("cls");
	int n;
	
	printf("\t\tAGREGAR ALUMNOS");
	printf("\n\nCantidad de alumnos para agregar en el archivo: ");
	scanf("%d",&n);
	arch=fopen("alumnos.dat","a+b");
	
	for(int i=0;i<n;i++)
	{
		printf("\n\tALUMNO %d:",i+1);
		printf("\nLegajo: ");
		scanf("%d",&reg.legajo);
		_flushall();
		printf("\nNombre Completo: ");
		gets(reg.completo);
		strupr(reg.completo);
		printf("\nNota 1: ");
		scanf("%f",&reg.nota.n1);
		printf("\nNota 2: ");
		scanf("%f",&reg.nota.n2);
		reg.habilitado=true;
		
		fwrite(&reg,sizeof(registro),1,arch);
	}
	fclose(arch);
	printf("\nCARGADO EXITOSAMENTE!\n\n\n");
	system("PAUSE");
}

void Bajalogica(registro reg, FILE *arch)
{
	system("cls");
	int leg;
	bool band=false;
	
	printf("\t\tBAJA LOGICA");
	printf("\n\nIngrese legajo del alumno: ");
	scanf("%d",&leg);
	
	arch=fopen("alumnos.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	
	
	
	while(!feof(arch) and band==false)
	{
		if(reg.legajo==leg)
		{
			reg.habilitado=false;
			fseek(arch,(long)-sizeof(registro),SEEK_CUR);
			fwrite(&reg,sizeof(registro),1,arch);
			printf("\n\n\nALUMNO CON LEGAJO %d DADO DE BAJA",leg);
			band=true;
		}
		else
		{
			fread(&reg,sizeof(registro),1,arch);
		}
		
	}
	fclose(arch);
	printf("\n\n\n");
	system("PAUSE");
}

void Bajafisica(registro reg, FILE *arch, FILE *aux)
{
	system("cls");
	int leg;
	bool band=false;
	
	arch=fopen("alumnos.dat","r+b");
	aux=fopen("auxiliar.dat","wb");
	
	printf("\t\tBAJA FISICA");
	printf("\n\nIngrese legajo del alumno a eliminar: ");
	scanf("%d",&leg);
		
	fread(&reg,sizeof(registro),1,arch);
	
	while(!feof(arch))
	{
		if(reg.legajo!=leg)
		{
			fwrite(&reg,sizeof(registro),1,aux);
		}
		else
		{
			band=true;
		}
		fread(&reg,sizeof(registro),1,arch);
	}
	
	if(band==true)
	{
		printf("\n\nREGISTRO BORRADO EXITOSAMENTE");
		fclose(arch);
		fclose(aux);
		remove("alumnos.dat");
		rename("auxiliar.dat","alumnos.dat");
	}
	else
	{
		printf("\n\nREGISTRO NO ENCONTRADO");
		fclose(aux);
		remove("auxiliar.dat");
	}
	printf("\n\n\n");
	system("pause");	
}

void Modificar(registro reg,FILE *arch)
{
	system("cls");
	int leg;
	bool bandera=false;
	arch=fopen("alumnos.dat","r+b");
	printf("\t\tMODIFICACION");
	fread(&reg,sizeof(registro),1,arch);
	
	printf("\n\nIngrese legajo del alumno a modificar: ");
	scanf("%d",&leg);
	
	while(!feof(arch) and bandera==false)
	{
		if(reg.legajo==leg and reg.habilitado==true)
		{
			printf("\n\nNuevo nombre: ");
			_flushall();
			gets(reg.completo);
			strupr(reg.completo);
			printf("\n\t\tNotas");
			printf("\nNota 1: ");
			scanf("%f",&reg.nota.n1);
			printf("\nNota 2: ");
			scanf("%f",&reg.nota.n2);
			fseek(arch,(long)-sizeof(registro),SEEK_CUR);	
			fwrite(&reg,sizeof(registro),1,arch);
			bandera=true;			
		}
		else
		{
			fread(&reg,sizeof(registro),1,arch);	
		}					
	}
	
	if(bandera==true)
	{
		system("cls");
		printf("\nSe modifico correctamente el alumno");
	}
	else
	{
		printf("\n\nNO SE ENCONTRO COINCIDENCIAS");
	}
	fclose(arch);
	printf("\n\n\n");
	system("pause");	
}
