#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<BibliotecaGym.h>

main()
{

	bool band;
	int opcion;
do{
	
	printf("		MENU RECEPCION	");
	printf("\n1------Inicio de Sesion\n");
	printf("\n2------Registrar Socio\n");
	printf("\n3------Mostrar Listado De socios\n");
	printf("\n4------Registrar Actividad de socio\n"); /*Agregar Funcion a biblioteca*/
	printf("\n5------Borrar Socio\n");
	printf("\n6------Mostrar Fechas de Pago\n");
	printf("\n0------Finalizar\n");
	printf("\nElija lo que desea realizar: ");
	scanf("%d",&opcion);
	system("pause");
	system("cls");
	switch(opcion){
		case 1:	band=IniciarSesion();
				system("pause");
				system("cls");	
		break;	
		case 2:	if(band==true){
				RegistroSocios();
				system("pause"); 
				system("cls");			
	}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;
		case 3: if(band==true){
				MostrarSocios();
				system("pause");
				system("cls");
	}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;		
		case 4: if(band==true){
				RegistroActividad();
				system("pause");
				system("cls");
					}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;
		case 5: if(band==true){
				BorrarSocio();
				system("pause");
				system("cls");
					}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;
		case 6: if(band==true){
				Pagos();
				system("pause");
				system("cls");
					}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;
		
	} 	
} while(opcion!=0);
	

}




