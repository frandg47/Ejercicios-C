#include <stdio.h>
#include <stdlib.h>

struct nodo{
	char nombre[20];
	int cantidad;
	nodo *sig;
};

void insertarpila(nodo *&pila);
void eliminar(nodo *&pila, int b);
void recorrer(nodo *pila);

main()
{
	nodo *pila	= NULL;
	
	int n,b;
	
	printf("Ingrese la cantidad de programas: ");
	scanf("%d",&n);
	
		for(int i=0;i<n;i++)
	{
		insertarpila(pila);
	}
	
		recorrer(pila);
	
	printf("Ingrese la cantidad de lineas del programa que desea eliminar: ");
	scanf("%d",&b);
	
	eliminar(pila,b);
	
	recorrer(pila);
	
	
	system("pause");
}
void insertarpila(nodo *&pila)
{
	nodo *nuevonodo=new nodo();
	
		printf("Ingrese nombre : ");
		_flushall();
		gets(nuevonodo->nombre);
		printf("Ingrese cantidad de lineas: ");
		scanf("%d",&nuevonodo->cantidad);
		
	nuevonodo->sig=pila;
	pila=nuevonodo;
	
	
}
void eliminar(nodo *&pila, int b)
{
	nodo *p;
	char aux[40];
	
	p=pila;
	b=p->cantidad;
	pila=pila->sig;
	delete p;

}
void recorrer(nodo *pila)
{
	 nodo *p;
	 p=pila;
	 while (p!=NULL)
	 {
		 _flushall();
		 puts(p->nombre);
		 printf("%d\n",p->cantidad);
		 p=p->sig;
	 }
}
