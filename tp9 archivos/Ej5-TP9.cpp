#include <stdio.h>
#include <stdlib.h>

struct datos{
	
	int cod;
	float imp;
};

struct nodo{
	
	datos info;
	nodo *sig;
	
};

void inicializar(nodo *&frente,nodo *&fondo);
void insertar(nodo *&frente,nodo *&fondo,datos dat);
int borrar(nodo *&frente,nodo *&fondo);
main()
{
	nodo *frente,*fondo,*p;
	datos dat;
	int i,n,x,borrado;	
	inicializar(frente,fondo);
	
	system("color a");
	
	printf("Ingrese la cantidad de valores: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Ingrese el codigo: ");
		scanf("%d",&dat.cod);
		printf("Ingrese el importe: ");
		scanf("%f",&dat.imp);
		insertar(frente,fondo,dat);
		
	}
	
	printf("\n\nSE BORRA EL VALOR: %d\n\n",borrar(frente,fondo));
	
	  p=frente;
    while (p!=NULL)
    {
          printf("Codigo: %d\n",p->info.cod);
          printf("Importe: %.2f\n\n",p->info.imp);
          p=p->sig;
    }
   
	
	
}

void inicializar(nodo *&frente,nodo *&fondo)
{
	
	frente=NULL;
	fondo=NULL;
}

void insertar(nodo *&frente,nodo *&fondo,datos dat)
{
	nodo *p;
	
	p=new nodo;
	
	if(p!=NULL){
		
		p->info=dat;
		p->sig=NULL;
		if(frente==NULL)
		{
			frente=p;
		}
		else
		{
			fondo->sig=p;
		}
			fondo=p;
		
	}
	
}

int borrar(nodo *&frente,nodo *&fondo)
{
	datos dat;
	if(frente!=NULL)
	{
		
		nodo *p;
		int x;
		
		{
			p=frente;
			x=frente->info.cod;
			frente=frente->sig;
			delete p;
			
			if (frente==NULL)
			{
				fondo=NULL;	
			}
			
			return x;
			
			
		}
		
	
		
		
	}

	
	
}
