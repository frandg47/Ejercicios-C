#include<stdio.h>
#include<stdlib.h>

void Registro(FILE *arch,float valor);
void Listar(FILE *arch,float valor);

main()
{
	int b=1,opcion;
	float valor;
	FILE *arch;
	
	while(b==1)
	{
		system("cls");
		printf("\t\t\tMENU");
		printf("\n\n1)Registrar venta\n2)Mayor venta\n3)Listar ventas\n4)Monto total de ventas\n5)Borrar archivo\n6)Salir\n");
		printf("\tOPCION: ");
		scanf("%d",&opcion);
		arch=fopen("valores.dat","r+b");		
		switch(opcion)
		{		
			case 1: Registro(arch,valor);break;
//			case 2: Mayor(arch);break;
			case 3: Listar(arch,valor);break;
//			case 4: Total(arch);break;
//			case 5: Borrar(arch);break;
			case 6: b=0;break;
			default: system("cls");printf("\nINGRESO INCORRECTO");system("pause");break;
		}
	}
}

void Registro(FILE *arch,float valor)
{
	system("cls");
	fclose(arhc);
	arch=fopen("valores.dat","w+b");
	printf("\t\tREGISTRO");
	printf("\n\nCargue venta (ingrese 0 para terminar): ");
	scanf("%f",&valor);
	fwrite(&valor,sizeof(float),1,arch);
	while(valor!=0)
	{
		printf("\n\nCargue venta (ingrese 0 para terminar): ");
		scanf("%f",&valor);
		fwrite(&valor,sizeof(float),1,arch);		
	}
	printf("\n\nDATOS CARGADOS EXITOSAMENTE\n\n\n\n");
	system("pause");
}

void Listar(FILE *arch,float valor)
{
	system("cls");
	printf("\t\tVENTAS\n\n");
	rewind(arch);
	fread(&valor,sizeof(float),1,arch);
	while(!feof(arch))	
	{
		printf("%.6f\t-\t",valor);
		fread(&valor,sizeof(float),1,arch);
	}
	printf("\n\n\n");
	system("pause");
}