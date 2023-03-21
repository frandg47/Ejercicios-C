#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos
{
	int nro;	
	int nrocel; 
	char tipo[20];
};
struct nodo
{	
	datos info;
	nodo *sig;
};

void inicializar(nodo *&frente,nodo *&fondo);
void insertar(nodo *&frente, nodo *&fondo,datos dat);
int borrar(nodo *&frente,nodo *&fondo);
main()
{
	datos dat;
	
	nodo *frente,*fondo,*p;
	
    int i,valor=0,n,x=0;
    
    float por;
    
    dat.nro=0;
    inicializar(frente,fondo);
    
    printf("Ingrese el valor de n: ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
    {
    	printf("\nNumero de turno: %d\n",dat.nro+1);
        printf("Numero de telefono: ");
        scanf("%d",&dat.nrocel);
        
        printf("Tipos de reclamo\n ");
        printf("\nF: Facturacion, C:Compra, T:Tecnico\n");
        printf("reclamo: ");
        scanf("%s",dat.tipo);
 		strupr(dat.tipo); 
		       
        insertar(frente,fondo,dat);
        dat.nro++;
        
		valor=strcmp(dat.tipo,"T");
        if(valor==0)
		{
        	x=x+1;
        	
        }
    }
	system("cls");
	printf("\n\nEl proximo turno es: %d\n\n",borrar(frente,fondo)+1);
	
		  p=frente;
    while (p!=NULL)
    {
          printf("Numero de cliente: %d\n",p->info.nrocel);
          printf("Factura: %s\n\n",p->info.tipo);
          p=p->sig;
    }
   por=(float)x*100/n;
   
   printf("El porcentaje de los que pidieron servicio tecnico: %.2f",por);
}

void inicializar(nodo *&frente,nodo *&fondo)
{
     frente=NULL;
     fondo=NULL;
}

void insertar(nodo *&frente, nodo *&fondo,datos dat)
{
     nodo *p;
     
     p=new nodo;
     
     if (p!=NULL)
     {
           p->info=dat;
           p->sig=NULL;
           if (frente==NULL)
                 frente=p;
           else
                 fondo->sig=p;
           fondo=p;
     }  
     else
	 {
           printf("ERROR - COLA LLENA");
    }
}


int borrar(nodo *&frente,nodo *&fondo)
{
	datos dat;
	if(frente!=NULL)
	{
		int x;
		nodo *p;
		{
			p=frente;
			x=frente->info.nro;
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
