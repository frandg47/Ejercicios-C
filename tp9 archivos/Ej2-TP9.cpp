#include <stdio.h>
#include <stdlib.h>

struct nodo
{
 int legajo;
 int edad;
 char nombre[50];
 nodo *sig;
};
void insertarNodo(nodo *&lista, int n);

void eliminar(nodo *&lista, int b);


main()
{
	int n,b,i;
	
	nodo *lista	= NULL;
	
	printf("\n Ingrese cantidad de empleados: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("EMPLEADO #%d\n",i+1);
		insertarNodo(lista, n);
	}
	
	
	printf("ingrese el numero de legajo que desea borrar: ");
	scanf("%d",&b);
	eliminar(lista,b);
	
	
	system("pause");
}
void insertarNodo(nodo *&lista, int n)
{
	nodo *nuevonodo= new(nodo); 
	
		printf("Ingrese legajo : ");
		scanf("%d",&nuevonodo->legajo);
		_flushall();
		printf("Ingrese apellido y nombre : ");
		gets(nuevonodo->nombre);
		printf("Ingrese edad : ");
		scanf("%d",&nuevonodo->edad);
	
	nodo *aux1=lista;
	nodo *aux2;
	

	
	while((aux1!=NULL))
	{
		aux2=aux1;
		aux1=aux1->sig;		
	}
	if(lista==aux1)
	{
		lista=nuevonodo;
	}
	else
	{
		aux2->sig=nuevonodo;
	}
	
	nuevonodo->sig=aux1;


	

}	
void eliminar(nodo *&lista, int b)
{
	nodo *act, *ant;

	if(lista!=NULL)
	{
	
		act=lista;
		ant=lista;
	
		while ((act!=NULL) && (act->legajo < b))
		{
		
			ant=act;
 			act=act->sig;
 		
 		}
			
		if ((act!=NULL) && (act->legajo== b))
		{
		
			if (ant!=act)
			{
						
			ant->sig=act->sig;
			}
			else
			{
				lista=act->sig;
			}
			
			delete(act);
			printf("\nNodo eliminado\n");				 	 
		 	
		}
			
		
		
	}
	else
	{
		printf("Error");
		
	}
	
}
void mostrarlista(nodo *lista)
{
	nodo *actual=new nodo();
	
	actual=lista;
	
	while(actual!=NULL)
	{
		printf("\n%.2f",actual->dato);
		actual=actual->sig;
	}
	
}
