#include<stdio.h>
#include<stdlib.h>
#include<ctime>

void Ejercicio1();
void Carga(int v[],int &n);
int Menor(int v[],int n,int menor);
void Listar(int v[],int n);
void Ejercicio2();
void Carga2(int v2[],int n2);
void MayoryMenor2(int v2[],int n2);
float Promedio2(int v2[],int n2);
int CantMayProm(int v2[],int n2,float P);
void CantAyD(int v2[],int n2);
void Ejercicio3();
float Carga3(float v[],int &c);
void Buscar3(float v[],int c);
void Ejercicio4();
void Generar4(int v4[]);	
int BuscarMultiplos(int v4[],int &k);
void Ejercicio5();
void Generar5(int v5[]);
void Promedio(int v5[]);
void Sumadepares(int v5[]);
void Sumadeimpares(int v5[]);
void Ejercicio6();
void Ordenar(int v6[],int n);
void Mam(int v6[],int n);
void maM(int v6[],int n);
void Ejercicio7();
void Potencia(int A[],int B[],int n);
void Suma(int A[],int B[],int C[],int n);

main()
{
	int ejercicio,b=1;
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tTRABAJO PRACTICO N4: VECTORES\n\n\tSeleccione el ejercicio: \n\n1)Ejercicio 1\n2)Ejercicio 2\n3)Ejercicio 3\n4)Ejercicio 4\n5)Ejercicio 5\n6)Ejercicio 6\n7)Ejercicio 7\n8)Salir\n\nEJERCICIO: ");
		scanf("%d",&ejercicio);
		switch(ejercicio)
		{
			case 1: Ejercicio1();break;
			case 2: Ejercicio2();break;
			case 3: Ejercicio3();break;
			case 4: Ejercicio4();break;
			case 5: Ejercicio5();break;
			case 6: Ejercicio6();break;
			case 7: Ejercicio7();break;
			case 8: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}

void Ejercicio1()
{
	int v[50],apartado,b=1,n=0,menor=100,M=0,bandera=0;
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 1\n\n\tSeleccione el apartado: \n\n1)Cargar un vector\n2)El menor valor ingresado\n3)Listar vector\n\nOPCION: ");
		scanf("%d",&apartado);
		switch(apartado)
		{
			case 1: system("cls");Carga(v,n);bandera=1;break;
			case 2: system("cls");if(bandera==1){M=Menor(v,n,menor);printf("\tEl menor elemento es: %d",M);}else{printf("\n\tEl vector no fue cargado");};break;
			case 3: system("cls");if(bandera==1){Listar(v,n);}else{printf("\n\tEl vector no fue cargado");}break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b);
	}
	
	if(b!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 1\n\n\tSeleccione el apartado: \n\n1)Cargar un vector\n2)El menor valor ingresado\n3)Listar vector\n4)Volver\n\nOPCION: ");
		scanf("%d",&apartado);
	}
}

void Carga(int v[],int &n)
{
	printf("Ingrese la cantidad de elementos del vector: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\n\tEl elemento de la posicion [%d]: ",i);
		scanf("%d",&v[i]);
	}
	printf("\nEl vector fue cargado exitosamente!");
}

int Menor(int v[],int n,int menor)
{
	
	for(int i=1;i<n;i++)
	{
		if(v[i]<menor)
		{
			menor=v[i];
		}
	}
	return menor;
}

void Listar(int v[],int n)
{
	printf("El vector cargado es: ");
	printf("\n\n");
	
	for(int i=0;i<n;i++)
	{
		printf("\t%d",v[i]);
	}
	
}

void Ejercicio2()
{
	int v2[50],apartado2,b2=1,n2,bandera2=0,CMP=0;
	float P=0.00;
	
	while(b2!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 2\n\n\tSeleccione el apartado: \n\n1)Cargar las notas\n2)Menor y Mayor nota\n3)Promedio de notas\n4)Cantidad de notas superiores al promedio\n5)Cantidad de alumnos aprobados y desaprobados\n\nOPCION: ");
		scanf("%d",&apartado2);
		switch(apartado2)
		{
			case 1: system("cls");printf("\tIngrese la cantidad de notas: ");scanf("%d",&n2);Carga2(v2,n2);bandera2=1;break;
			case 2: system("cls");if(bandera2==1){MayoryMenor2(v2,n2);}else{printf("\n\tLas notas no fueron cargadas");};break;
			case 3: system("cls");if(bandera2==1){P=Promedio2(v2,n2);printf("\tEl promedio de notas es: %.2f",P);}else{printf("\n\tLas notas no fueron cargadas");};break;
			case 4: system("cls");if(bandera2==1 and P>0){CMP=CantMayProm(v2,n2,P);printf("\tCantidad de notas mayores al promedio: %d",CMP);}else{printf("\n\tEl promedio no fue calculado");};break;
			case 5: system("cls");if(bandera2==1){CantAyD(v2,n2);}else{printf("\n\tLas notas no fueron cargadas");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b2);
	}
	
	if(b2!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 2\n\n\tSeleccione el apartado: \n\n1)Cargar las notas\n2)Menor y Mayor nota\n3)Promedio de notas\n4)Cantidad de notas superiores al promedio\n5)Cantidad de alumnos aprobados y desaprobados\n\nOPCION: ");
		scanf("%d",&apartado2);
	}
}

void Carga2(int v2[],int n2)
{
	for(int i=1;i<=n2;i++)
	{
		printf("\nLa nota del alumno [%d]: ",i);
		scanf("%d",&v2[i]);	
		if(v2[i]<1 or v2[i]>10)
		{
			printf("\nLa nota del alumno [%d] es incorrecta, cargue nuevamente\n",i);
			i--;
		}				
	}
	printf("\nLas notas fueron cargadas exitosamente!");
}

void MayoryMenor2(int v2[],int n2)
{
	int may=0,men=11;
	
	for(int i=1;i<=n2;i++)
	{
		if(v2[i]>may)
		{
			may=v2[i];
		}
	}
	for(int j=1;j<=n2;j++)
	{
		if(v2[j]<men)
		{
			men=v2[j];
		}
	}
	printf("\nLa mayor nota es: %d\n\nLa menor nota es: %d",may,men);
}

float Promedio2(int v2[],int n2)
{
	int s=0;
	float promedio;
	
	for(int i=1;i<=n2;i++)
	{
		s=s+v2[i];
	}
	promedio=float(s/n2);
	return promedio;
}

int CantMayProm(int v2[],int n2,float P)
{
	int cant=0;
	
	for(int i=1;i<=n2;i++)
	{
		if(v2[i]>P)
		{
			cant++;
		}
	}
	return cant;
}

void CantAyD(int v2[],int n2)
{
	int aprob=0,desap=0;
	
	for(int i=1;i<=n2;i++)
	{
		if(v2[i]>=6)
		{
			aprob++;
		}
		else
		{
			desap++;
		}
	}
	printf("\tAlumnos aprobados: %d\n\n\tAlumnos desaprobados: %d",aprob,desap);
}

void Ejercicio3()
{
	int apartado3,b3=1,c=0,bandera3=0,reales=0;
	float v3[100];
	
	while(b3!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 3\n\n\tSeleccione el apartado: \n\n1)Cargar vector indeterminado\n2)Buscar un valor en el vector\n\nOPCION: ");
		scanf("%d",&apartado3);
		switch(apartado3)
		{
			case 1: system("cls");reales=Carga3(v3,c);system("cls");printf("\n\tLa cantidad de valores reales ingresados: %d",reales);bandera3=1;break;
			case 2: system("cls");if(bandera3==1){Buscar3(v3,c);}else{printf("\n\tLas valores no fueron cargados");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b3);
	}
	
	if(b3!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 3\n\n\tSeleccione el apartado: \n\n1)Cargar vector indeterminado\n2)Buscar un valor en el vector\n\nOPCION: ");
		scanf("%d",&apartado3);
	}
}

float Carga3(float v[],int &c)
{
	int i=1,b=1,reales=0;
	float num;
	
	while(b==1)
	{
		printf("\nIngrese el elemento %d: ",i);
		scanf("%f",&num);
		i++;
		if(num!=0)
		{
			v[c]=num;
			c++;
			if((num-int(num))!=0)
			{
				reales++;
			}
		}
		else
		{
			b=0;
		}		
	}	
	return reales;	
}

void Buscar3(float v[],int c)
{
	int i,j=0;
	float num;
	
	printf("\n\tIngrese el valor que desea buscar: ");
	scanf("%f",&num);
	
	for(i=1;i<=c;i++)
	{
		if(num==v[i])
		{
			j++;
		}
	}
	if(j>0)
	{
		printf("\nEl valor fue encontrado %d veces",j);
	}
	else
	{
		printf("\nEl valor no fue encontrado");
	}		
}

void Ejercicio4()
{
	int apartado4,b4=1,c=0,bandera4=0,v4[100],cant,k=0;
		
	while(b4!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 4\n\n\tSeleccione el apartado: \n\n1)Generar vector aleatorio\n2)Listar el vector\n3)Buscar multiplos de un valor ingresado en el vector\n\nOPCION: ");
		scanf("%d",&apartado4);
		switch(apartado4)
		{
			case 1: system("cls");Generar4(v4);bandera4=1;break;
			case 2: system("cls");if(bandera4==1){Listar(v4,100);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 3: system("cls");if(bandera4==1){cant=BuscarMultiplos(v4,k);printf("\n\tLa cantidad de multiplos de %d es: %d",k,cant);}else{printf("\n\tLas valores no fueron cargados");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b4);
	}
	
	if(b4!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 4\n\n\tSeleccione el apartado: \n\n1)Cargar vector indeterminado\n2)Listar el vector\n3)Buscar multiplos de un valor ingresado en el vector\n\nOPCION: ");
		scanf("%d",&apartado4);
	}
}
	
void Generar4(int v4[])	
{
	for(int i=0;i<100;i++)
	{
		v4[i]=1+rand()%(432);
	}
	printf("\n\tEl vector fue generado correctamente con 100 valores entre 1 y 432!");
}

int BuscarMultiplos(int v4[],int &k)
{
	int c=0;
	
	printf("\n\tIngrese un escalar: ");
	scanf("%d",&k);
	
	for(int i=0;i<100;i++)
	{
		if((v4[i]%k)==0)
		{
			c++;
		}
	}
	return c;
}

void Ejercicio5()
{
	int apartado5,b5=1,bandera5=0,v5[100];
			
	while(b5!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 5\n\n\tSeleccione el apartado: \n\n1)Generar vector aleatorio\n2)Promedio de num pares e impares del vector\n3)Suma de valores que se ubican en posiciones pares\n4)Suma de valores que se ubican en posiciones impares\n\nOPCION: ");
		scanf("%d",&apartado5);
		switch(apartado5)
		{
			case 1: system("cls");Generar5(v5);bandera5=1;break;
			case 2: system("cls");if(bandera5==1){Promedio(v5);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 3: system("cls");if(bandera5==1){Sumadepares(v5);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 4: system("cls");if(bandera5==1){Sumadeimpares(v5);}else{printf("\n\tLas valores no fueron cargados");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b5);
	}
	
	if(b5!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 5\n\n\tSeleccione el apartado: \n\n1)Generar vector aleatorio\n2)Promedio de num pares e impares del vector\n3)Suma de valores que se ubican en posiciones pares\n4)Suma de valores que se ubican en posiciones impares\n\nOPCION: ");
		scanf("%d",&apartado5);
	}
}

void Generar5(int v5[])
{
	for(int i=0;i<100;i++)
	{
		v5[i]=1+rand()%(100);
	}
	printf("\n\tEl vector fue generado correctamente!");
}
	
void Promedio(int v5[])
{
	int nump=0,numi=0,sump=0,sumi=0;
	float prompares=0.00,promimpares=0.00;
	
	for(int i=0;i<100;i++)
	{
		if(v5[i]%2==0)
		{
			nump++;
			sump=sump+v5[i];
		}
		else
		{
			numi++;
			sumi=sumi+v5[i];
		}
	}
	prompares=float(sump/nump);
	promimpares=float(sumi/numi);
	printf("\nEl promedio de pares es: %.2f",prompares);
	printf("\nEl promedio de impares es: %.2f",promimpares);
}
	
void Sumadepares(int v5[])
{
	int sump=0;
	
	for(int i=0;i<100;i=i+2)
	{
		sump=sump+v5[i];
	}
	printf("\n\tLa suma de valores en posiciones pares es: %d",sump);
}	

void Sumadeimpares(int v5[])
{
	int sumi=0;
	
	for(int i=1;i<100;i=i+2)
	{
		sumi=sumi+v5[i];
	}
	printf("\n\tLa suma de valores en posiciones impares es: %d",sumi);
}

void Ejercicio6()
{
	int apartado6,b6=1,bandera6=0,v6[100],n=0;
			
	while(b6!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 6\n\n\tSeleccione el apartado: \n\n1)Cargar un arreglo de orden N\n2)Listar el vector\n3)Ordenar de mayor a menor\n4)Ordenar de menor a mayor\n\nOPCION: ");
		scanf("%d",&apartado6);
		switch(apartado6)
		{
			case 1: system("cls");Carga(v6,n);bandera6=1;break;
			case 2: system("cls");if(bandera6==1){Listar(v6,n);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 3: system("cls");if(bandera6==1){Ordenar(v6,n);Mam(v6,n);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 4: system("cls");if(bandera6==1){Ordenar(v6,n);maM(v6,n);}else{printf("\n\tLas valores no fueron cargados");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b6);
	}
	
	if(b6!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 6\n\n\tSeleccione el apartado: \n\n1)Cargar un arreglo de orden N\n2)Listar el vector\n3)Ordenar de mayor a menor\n4)Ordenar de menor a mayor\n\nOPCION: ");
		scanf("%d",&apartado6);
	}
}

void Ordenar(int v6[],int n)
{
	int i,j,aux;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(v6[j]>v6[j+1])
			{
				aux=v6[j+1];
				v6[j+1]=v6[j];
				v6[j]=aux;
			}
		}
	}
}

void Mam(int v6[],int n)
{
	int i;
	
	printf("\n\tEl vector ordenado: ");
	
	for(i=n;i>0;i--)
	{
		printf("\t%d",v6[i]);
	}
}

void maM(int v6[],int n)
{
	int i;
	
	printf("\n\tEl vector ordenado: ");
	
	for(i=1;i<=n;i++)
	{
		printf("\t%d",v6[i]);
	}
}

void Ejercicio7()
{
	int apartado7,b7=1,bandera7=0,A[50],B[50],C[50],n=0,band=0;
			
	while(b7!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 7\n\n\tSeleccione el apartado: \n\n1)Cargar un arreglo A\n2)Listar el vector\n3)Potencia de cada elemento de A en un vector B\n4)Suma de A y B en un vector C\n\nOPCION: ");
		scanf("%d",&apartado7);
		switch(apartado7)
		{
			case 1: system("cls");Carga(A,n);bandera7=1;break;
			case 2: system("cls");if(bandera7==1){Listar(A,n);}else{printf("\n\tLas valores no fueron cargados");};break;
			case 3: system("cls");if(bandera7==1){Potencia(A,B,n);band=1;}else{printf("\n\tLas valores no fueron cargados");};break;
			case 4: system("cls");if(band==1){Suma(A,B,C,n);}else{printf("\n\tLas valores no fueron cargados");};break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n");
		}
		
		printf("\n\n\nIngrese 1 para continuar en este ejercicio, 0 para volver: ");
		scanf("%d",&b7);
	}
	
	if(b7!=0)
	{
		system("cls");
		printf("\t\tEJERCICIO 7\n\n\tSeleccione el apartado: \n\n1)Cargar un arreglo A\n2)Listar el vector\n3)Potencia de cada elemento de A en un vector B\n4)Suma de A y B en un vector C\n\nOPCION: ");		printf("\t\tEJERCICIO 6\n\n\tSeleccione el apartado: \n\n1)Cargar un arreglo de orden N\n2)Listar el vector\n3)Ordenar de mayor a menor\n4)Ordenar de menor a mayor\n\nOPCION: ");
		scanf("%d",&apartado7);
	}
}

void Potencia(int A[],int B[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		B[i]=A[i]*A[i];
	}
	Listar(B,n);
}

void Suma(int A[],int B[],int C[],int n)
{
	for(int i=0;i<n;i++)
	{
		C[i]=A[i]+B[i];
	}
	Listar(C,n);
}