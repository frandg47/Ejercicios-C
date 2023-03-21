#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BibliotecaGym.h"

main()
{

	bool band;
	int opcion;
do{
	
	printf("		MENU GYM	");
	printf("\n1------Inicio de Sesion\n");
	printf("\n2------Listado de Socios\n");/*Agregar Funcion a biblioteca*/
	printf("\n3------Cargar Rutinas\n");
	printf("\n0------Finalizar\n");
	printf("\nElija lo que desea realizar: ");
	scanf("%d",&opcion);
	system("pause");
	system("cls");
	switch(opcion){
		case 1:	band=IniciarSesionEnt();
				system("pause");
				system("cls");	
		break;	
		case 2:	if(band==true){
				MostrarActSocios();
				system("pause"); 
				system("cls");			
	}else{
		printf("\nDebe iniciar Sesion\n");
		system("pause");
		system("cls");
	}
		break;
		case 3: if(band==true){
				CargaRutinas();
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


