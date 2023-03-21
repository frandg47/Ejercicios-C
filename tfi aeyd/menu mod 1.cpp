#include<stdio.h>
#include<stdlib.h>
#include<string.h>



bool InicioSesion(char usuario[10],char password[10]);
//void Listar(registro reg,FILE *arch);
//void Agregar(registro reg,FILE *arch);
//void Bajalogica(registro reg, FILE *arch);
//void Bajafisica(registro reg, FILE *arch, FILE *aux);
//void Modificar(registro reg,FILE *arch);

main()
{
	int opcion,b=1;
	char usuario[10],password[10];
	FILE *arch,*aux;
	bool band;
	
	
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tMODULO ADMINISTRACION\n\n\tSeleccione una opcion: \n\n1)Iniciar Sesion\n2)Registrar usuario de Recepcion\n3)Registrar Actividades del Gym\n4)Calcular pago al entrenador\n5)Entrenador con mayor carga horaria\n6)Cerrar la aplicacion\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: band=InicioSesion(usuario,password);break;
			case 2: system("cls");if(band==true){printf("\t\tREGISTRAR USUARIO DE RECEPCION");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 3: system("cls");if(band==true){printf("\t\tREGISTRO ACTIVIDADES DEL GYM");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 4: system("cls");if(band==true){printf("\t\tCALCULAR PAGO DEL ENTRENADOR");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 5: system("cls");if(band==true){printf("\t\tENTRENADOR CON MAYOR CARGA HORARIA");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 6: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}

bool InicioSesion(char usuario[10],char password[10])
{
	bool bandera=false;
	char nombre[10]="admin",clave[10]="admin123";
	
	system("cls");
	printf("\t\tINICIO DE SESION");
	printf("\n\nUSUARIO: ");
	_flushall();
	gets(usuario);
	if(strcmp(usuario,nombre)==0)
	{
		printf("\nCONTRASENIA: ");
		_flushall();
		gets(password);	
		if(strcmp(password,clave)==0)
		{
			bandera=true;
		}	
		else
		{
			printf("\n\tCLAVE INCORRECTA");
		}
	}
	else
	{
		printf("\n\tUSUARIO INCORRECTO");
	}	
	printf("\n\n\n");
	system("pause");
	return bandera;
}