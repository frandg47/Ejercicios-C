#include <stdio.h>
#include <stdlib.h>

struct nodo
{
 float dato;
 nodo *sig;
};

void insertarNodo(nodo *&fin, float x);
void mostrarlista(nodo *lista);
void eliminar(nodo *&lista,float b);


main()
{
	int n;
	float x,b;
	
	nodo *lista	= NULL;
	
	printf("\n Ingrese tamanio de lista: ");
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		printf("\n Ingrese un valor real ");
		scanf("%f", &x);
		insertarNodo(lista, x);
	}
	
	mostrarlista(lista);
	
	printf("ingrese el elemento a borrar: ");
	scanf("%f",&b);
	eliminar(lista,b);
	
	
	printf("Elementos que quedaron\n");
	mostrarlista(lista);
	
	system("pause");
}
void insertarNodo(nodo *&lista, float x)
{
	nodo *nuevonodo= new(nodo); 
	nuevonodo->dato=x;
	
	nodo *aux1=lista;
	nodo *aux2;
	
	
	while((aux1!=NULL)&&(aux1->dato<x))
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
void eliminar(nodo *&lista,float b)
{
	nodo *act, *ant;

	if(lista!=NULL)
	{
	
		act=lista;
		ant=lista;
	
		while ((act!=NULL) && (act->dato < b))
		{
		
			ant=act;
 			act=act->sig;
 		
 		}
			
		if ((act!=NULL) && (act->dato== b))
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
