#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void InicioSesion(char usuario[10],char password[10]);
//void Listar(registro reg,FILE *arch);
//void Agregar(registro reg,FILE *arch);
//void Bajalogica(registro reg, FILE *arch);
//void Bajafisica(registro reg, FILE *arch, FILE *aux);
//void Modificar(registro reg,FILE *arch);

main()
{
	int opcion,b=1,band=0;
	char usuario[10],password[10];
	FILE *arch,*aux;
	
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tMODULO GYM\n\n\tSeleccione una opcion: \n\n1)Iniciar Sesion\n2)Visualizar listado de Socios y actividad que desarrolla\n3)Registrar rutinas de gimnasia\n4)Cerrar la aplicacion\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: InicioSesion(usuario,password);band=1;break;
			case 2: system("cls");if(band==1){printf("\t\tLISTA DE SOCIOS");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");system("pause");}break;
			case 3: system("cls");if(band==1){printf("\t\tREGISTRO DE RUTINAS");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");system("pause");}break;
			case 4: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}

void InicioSesion(char usuario[10],char password[10])
{
	system("cls");
	printf("\t\tINICIO DE SESION");
	printf("\n\nUSUARIO: ");
	_flushall();
	gets(usuario);	
	printf("\nCONTRASENIA: ");
	_flushall();
	gets(password);
}