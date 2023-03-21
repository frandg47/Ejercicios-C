#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BibliotecaGym.h"



main()
{
	int opcion,b=1;
	
	
	bool band;
	
	while(b!=0)
	{
		
		system("cls");
		printf("\t\tMODULO ADMINISTRACION\n\n\tSeleccione una opcion: \n\n1)Iniciar Sesion\n2)Registrar usuario de Recepcion\n3)Registrar Entrenador\n4)Registrar Actividades del Gym\n5)Calcular pago al entrenador\n6)Entrenador con mayor carga horaria\n0)Cerrar la aplicacion\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: band=InicioSesion();break;
			case 2: system("cls");if(band==true){RegistrodeUsuario();}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");system("pause");}break;
			case 4: system("cls");if(band==true){RegistroAct();}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 3: system("cls");if(band==true){RegistroEntrenador();}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
/*Agregar Funcion a biblioteca*/			case 5: system("cls");if(band==true){printf("\t\tCALCULAR PAGO DEL ENTRENADOR");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
/*Agregar Funcion a biblioteca*/			case 6: system("cls");if(band==true){printf("\t\tENTRENADOR CON MAYOR CARGA HORARIA");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
/*Si se olvidan la contraseña o el usuario ver ahi*/		case 7: system("cls");if(band==true){MostrarUsuarios();}else{printf("\t\tDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 0: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}


	
	
	
	