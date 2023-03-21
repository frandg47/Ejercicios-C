#include <stdio.h>
#include <stdlib.h>

struct nodo{
	char nombre[20];
	int telefono;
	int edad;
	nodo *sig;
};
void insertarpila(nodo *&pila);
void recorrer(nodo *pila);
void mayor(nodo *pila);

main()
{
	int n,b;
	
	nodo *pila	= NULL;
	
	printf("Ingrese la cantidad de pacientes: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		insertarpila(pila);
	}
	
	recorrer(pila);
	
	printf("El paciente con mayor edad es: ");
	mayor(pila);
	
	system("pause");
}
void insertarpila(nodo *&pila)
{
	nodo *nuevonodo=new nodo();
	
		printf("Ingrese nombre : ");
		_flushall();
		gets(nuevonodo->nombre);
		printf("Ingrese telefono: ");
		scanf("%d",&nuevonodo->telefono);
		printf("Ingrese edad : ");
		scanf("%d",&nuevonodo->edad);
	
	nuevonodo->sig=pila;
	pila=nuevonodo;
	
}
void recorrer(nodo *pila)
{
	 nodo *p;
	 p=pila;
	 while (p!=NULL)
	 {
		 _flushall();
		 puts(p->nombre);
		 printf("%d\n",p->telefono);
		 printf("%d\n",p->edad);
		 p=p->sig;
	 }
}
void mayor(nodo *pila)
{
	nodo *p,*aux;
	int mayor=0;

	p=pila;
	
	while (p!=NULL)
	{
		if(p->edad>mayor)
		{
			mayor=p->edad;
			aux=p;
		}
		p=p->sig;
	}
	
	printf("\n Los datos del paciente con mayor edad son:");
	printf("\nNombre: %s",aux->nombre);
	printf("\nTelefono: %d",aux->telefono);
	printf("\nEdad: %d\n",aux->edad);

	system("pause");
}
