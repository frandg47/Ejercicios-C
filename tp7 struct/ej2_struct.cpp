#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct PuntosPlano
{
	float p1[10],p2[10];
};

void carga (PuntosPlano puntos);
void mostrar(PuntosPlano puntos);
void distancia(PuntosPlano puntos);

main()
{
	PuntosPlano puntos;
	int b=1,opcion,bb=0;
	
	while(b!=0)
	{
		system("cls");
		printf("====================MENU====================");
		printf("\n1) Cargar los puntos\n2) Mostrar los puntos\n3) Distancia de P1 al origen\n4) Longitud que une a ambos puntos\n5) Salir");
		printf("\n\n\tOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: system("cls");carga(puntos);bb=1;break;
			case 2: system("cls");if(bb==1){mostrar(puntos);}else{printf("NO INGRESO LOS PUNTOS\n\n\n");system("PAUSE");}break;
			case 3:	system("cls");if(bb==1){distancia(puntos);}else{printf("NO INGRESO LOS PUNTOS\n\n\n");system("PAUSE");}break;
			//case 4:	system("cls");if(bb==1){longitud(puntos);}else{printf("NO INGRESO LOS PUNTOS\n\n\n");system("PAUSE");}break;
			case 5: system("cls");printf("GRACIAS POR USAR NUESTROS SERVICIOS");b=0;break;
			default: system("cls");printf("Ingrese un valor correcto");system("PAUSE");break;	
		}
	}
}

void carga(PuntosPlano puntos)
{
	
	printf("\n\tPUNTO 1");
	printf("\nIngrese coordenada eje x: ");
	scanf("%f",&puntos.p1[1]);
	printf("\nIngrese coordenada eje y: ");
	scanf("%f",&puntos.p1[2]);
	
	printf("\n\tPUNTO 2");
	printf("\nIngrese coordenada eje x: ");
	scanf("%f",&puntos.p2[1]);
	printf("\nIngrese coordenada eje y: ");
	scanf("%f",&puntos.p2[2]);
	
	printf("\n\n");
	system("PAUSE");
	
}

void mostrar (PuntosPlano puntos)
{
	printf("\tPUNTOS INGRESADOS: ");
	printf("\n");
	printf("P1(%.2f,%.2f)",puntos.p1[1],puntos.p1[2]);
	printf("\n");
	printf("P2(%.2f,%.2f)",puntos.p2[1],puntos.p2[2]);
	printf("\n\n");
	system("PAUSE");
}

void distancia(PuntosPlano puntos)
{
	float d;
	
	d=sqrt(pow(puntos.p1[0],2)+pow(puntos.p1[1],2));
	printf("La distancia del punto P1 al origen es: %.2f",d);
	printf("\n\n");
	system("PAUSE");
	
}

