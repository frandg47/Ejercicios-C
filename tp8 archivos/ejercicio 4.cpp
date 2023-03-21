//El gerente de la empresa que nos encomendó la realización del sistema de venta de su comercio;
//Ahora nos solicita agreguemos a dicho sistema las siguientes opciones que no fueron contemplados en el
//primer análisis.
//f. Realizar la modificación del campo “forma de venta” de una determinada factura, la búsqueda para
//modificar será por su número de factura. Nota: mostrar el valor anterior y pedir el nuevo valor del
//contenido del campo forma de venta.
//g. Realizar baja lógica a una determinada factura. La búsqueda se realiza por número de factura. Una
//vez encontrado mostrar sus datos y solicitar confirmación antes de realizar el borrado lógico. En el
//caso de no encontrarse mostrar un mensaje de error.
//h.Listar todos los registros que hayan sido marcado como borrado lógico.
//i. Realizar el borrado físico de los registros marcados con borrado lógico. Para ingresar a esta opción
//se debe solicitar una clave de ingreso.
//j. Ordenar el archivo por número de factura y listar los datos ordenados.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha
{
	int dia,mes,anio;
};

struct registro
{
	int vendedor,nfactura,metodo;
	char nombre[40];
	float importe;
	fecha fec;
	bool borrado;
};

void Creararchivo(FILE *arch);
void Carga(FILE *arch,registro reg);
void Ventas(FILE *arch,registro reg);
void Metodopago(FILE *arch,registro reg);
void ImporteVendedor(FILE *arch,registro reg);
void Listar(FILE *arch,registro reg);
void Modificar(FILE *arch,registro reg);
void Bajalogica(FILE *arch,registro reg);

main()
{
	registro reg;
	int bandera=1,opcion;
	FILE *arch;
	
	while(bandera==1)
	{
		system("cls");
		printf("\t\t\tMENU");
		printf("\n\n1)Crear archivo(si ya tiene archivo creado perdera el anterior)\n2)Carga de datos\n3)Cantidad de ventas mensual\n4)Metodos de pago en un mes\n5)Importe total mensual de un vendedor\n6)Listar archivo\n7)Modificar forma de venta\n8)Baja logica de una factura\n9)Salir");
		printf("\n\nOPCION: ");
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: Creararchivo(arch);break;
			case 2: Carga(arch,reg);break;
			case 3: Ventas(arch,reg);break;
			case 4: Metodopago(arch,reg);break;
			case 5: ImporteVendedor(arch,reg);break;
			case 6: Listar(arch,reg);break;
			case 7: Modificar(arch,reg);break;
			case 8: Bajalogica(arch,reg);break;
			case 9: system("cls");bandera=0;break;
			default: system("cls");printf("\nOPCION INCORRECTA\n\n\n\n");system("pause");break;	
		}
	}
	printf("\n\n\n\n");
	system("pause");
}

void Creararchivo(FILE *arch)
{
	system("cls");
	printf("\t\t\tCREAR ARCHIVO");
	arch=fopen("ventas.dat","w+b");
	fclose(arch);
	printf("\n\nARCHIVO CREADO EXITOSAMENTE\n\n\n\n");
	system("pause");
}

void Carga(FILE *arch,registro reg)
{
	system("cls");
	int n,band=1,c=0;
	
	printf("\t\t\tCARGA DE DATOS");
	printf("\n\nCantidad de ventas: ");
	scanf("%d",&n);
	arch=fopen("ventas.dat","a+b");
	
	while(band==1 and c<n)
	{
		system("cls");
		printf("Numero de Vendedor: ");
		scanf("%d",&reg.vendedor);
		_flushall();
		if(reg.vendedor>0 and reg.vendedor<=3)
		{
			printf("\nNombre de Vendedor: ");
			gets(reg.nombre);
			printf("\nNumero de factura: ");
			scanf("%d",&reg.nfactura);
			printf("\nImporte: $");
			scanf("%f",&reg.importe);
			printf("\nMetodo de pago (1=contado;2=credito): ");
			scanf("%d",&reg.metodo);
			_flushall();
			if(reg.metodo==1 or reg.metodo==2)
			{				
				printf("\n\tFecha de venta: ");
				printf("\nanio: ");
				_flushall();
				scanf("%d",&reg.fec.anio);
				printf("\nmes: ");
				scanf("%d",&reg.fec.mes);
				printf("\ndia: ");
				scanf("%d",&reg.fec.dia);
				reg.borrado=false;
				fwrite(&reg,sizeof(registro),1,arch);
				printf("\n\nDATOS CARGADOS EXITOSAMENTE\n\n\n\n");
				c++;
			}
			else
			{
				system("cls");
				printf("\tDATOS INCORRECTOS\n\n\n");
				band=0;				
			}
			
		}
		else
		{
			system("cls");
			printf("\tDATOS INCORRECTOS\n\n\n");
			band=0;				
		}
				
	}
	fclose(arch);	
	system("pause");	
}

void Ventas(FILE *arch,registro reg)
{
	system("cls");
	int mes,c=0;
	
	printf("\t\t\tVENTAS MENSUALES");
	printf("\n\nIngrese un mes: ");
	scanf("%d",&mes);
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	while(!feof(arch))
	{
//		printf("\n%.2f",reg.importe);
		if(reg.borrado==false)
		{
			if(mes==reg.fec.mes)
			{
				c++;
			}			
		}
		fread(&reg,sizeof(registro),1,arch);	
	}
	fclose(arch);
	printf("\n\nCANTIDAD TOTAL DE VENTAS EN MES %d: %d",mes,c);
	printf("\n\n\n\n");
	system("pause");
}

void Metodopago(FILE *arch,registro reg)
{
	system("cls");
	printf("\t\t\tVENTAS SEGUN METODO DE PAGO");
	int mes,c1=0,c2=0;
	
	printf("\n\nIngrese mes a consultar: ");
	scanf("%d",&mes);
	
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);	
	
	while(!feof(arch))
	{
		if(reg.borrado==false)
		{
			if(mes==reg.fec.mes)
			{
				if(reg.metodo==1)
				{
					c1++;
				}
				else
				{
					c2++;
				}
			}	
		}	
		fread(&reg,sizeof(registro),1,arch);
	}
	fclose(arch);
	printf("\n\nVentas contado en mes %d: %d",mes,c1);
	printf("\nVentas credito en mes %d: %d\n\n\n\n",mes,c2);
	system("pause");	
}

void ImporteVendedor(FILE *arch,registro reg)
{
	system("cls");
	printf("\t\t\tIMPORTES GENERADOS POR VENDEDOR");
	
	int mes,i=1;
	char nombre[40];	
	
	_flushall();
	printf("\n\nNombre del vendedor: ");
	gets(nombre);
	printf("\nMes a consultar: ");
	scanf("%d",&mes);
	
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	
	while(!feof(arch))
	{
		if(reg.borrado==false)
		{
			if(reg.fec.mes==mes)
			{
				if(strcmp(reg.nombre,nombre)==0)
				{
					printf("Venta %d: $%.2f\n",i,reg.importe);
					i++;
				}
			}
		}		
		fread(&reg,sizeof(registro),1,arch);
	}
	fclose(arch);
	printf("\n\n\n\n");
	system("pause");
}

void Listar(FILE *arch,registro reg)
{
	system("cls");
	printf("\t\t\tLISTADO DE VENTAS");
	
	int i=1;
	
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	
	while(!feof(arch))
	{
		if(reg.borrado==false)
		{
			printf("\n\n\t\tVENTA %d",i);
			printf("\n\nNum de Vendedor: %d",reg.vendedor);
			printf("\nNombre de Vendedor: %s",reg.nombre);
			printf("\nNumero de factura: %d",reg.nfactura);
			printf("\nImporte: $%.2f",reg.importe);
			printf("\nForma de Venta (1=contado;2=credito): %d",reg.metodo);
			printf("\nFECHA: %d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);
			printf("\n-----------------------------------------------------------\n");
			i++;
		}	
		fread(&reg,sizeof(registro),1,arch);
	}
	fclose(arch);
	printf("\n\n\n\n");
	system("pause");
}

void Modificar(FILE *arch,registro reg)
{
	system("cls");
	int num,band=1;
	
	printf("\t\t\tMODIFICACION DE FORMA DE PAGO");
	printf("\n\nNumero de factura a modificar: ");
	scanf("%d",&num);
	
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	while(!feof(arch) and band==1)
	{
		if(reg.borrado==false and num==reg.nfactura)
		{		
			printf("\nForma de pago actual(1=contado;2=credito): %d",reg.metodo);
			printf("\nNueva forma de pago: ");
			_flushall();
			scanf("%d",&reg.metodo);
			fseek(arch,(long)-sizeof(registro),SEEK_CUR);
			fwrite(&reg,sizeof(registro),1,arch);
			band=0;		
		}
		else
		{
			fread(&reg,sizeof(registro),1,arch);
		}
	}
	if(band==0)
	{
		printf("\nMODIFICACION EXITOSA");
		printf("\n\n");		
	}
	else
	{
		printf("\nNo se encontro la factura\n\n");
	}
	fclose(arch);
	system("pause");		
}

void Bajalogica(FILE *arch,registro reg)
{
	system("cls");
	printf("\t\t\tBAJA LOGICA");
	int num,band=1;
	char mod;
	
	printf("\n\nNumero de factura: ");
	scanf("%d",&num);
	
	arch=fopen("ventas.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);
	
	while(!feof(arch) and band==1)
	{
		if(num==reg.nfactura and reg.borrado==false)
		{
			printf("\n\nNum de Vendedor: %d",reg.vendedor);
			printf("\nNombre de Vendedor: %s",reg.nombre);
			printf("\nNumero de factura: %d",reg.nfactura);
			printf("\nImporte: $%.2f",reg.importe);
			printf("\nForma de Venta (1=contado;2=credito): %d",reg.metodo);
			printf("\nFECHA: %d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);
			printf("\n-----------------------------------------------------------");
			printf("\n\nDesea modificar (Y/N): ");
			_flushall();
			scanf("%c",&mod);
			if(mod=='Y' or mod=='y');
			{
				reg.borrado=true;
				fseek(arch,(long)-sizeof(registro),SEEK_CUR);
				fwrite(&reg,sizeof(registro),1,arch);
				printf("\nFactura dada de baja");
			}
			if(mod!='Y' or mod!='y')
			{
				band=0;
			}
		}
		else
		{
			fread(&reg,sizeof(registro),1,arch);
		}
	}
	fclose(arch);
	printf("\n\n");
	system("pause");		
}