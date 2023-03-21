void Leer(int n,int vector[50])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("Ingrese el elemento de la posicion [%d]: ",i);
		scanf("%d",&vector[i]);
	}
	system("cls");
	printf("Este es el vector que usted ingreso\n");
	for(int g=1;g<=n;g++)
	{
		printf("\nElemento [%d]: %d",g,vector[g]);
	}
}

void Intercambio(int vector[50],int n)
{
	int i,j,aux;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vector[j]>vector[j+1])
			{
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}			
		}
	}	

	
	printf("\n\nEl ordenamiento por metodo de Intercambio ha sido exitoso! Vector ordenado:\n");
	for(int s=0;s<n;s++)
	{
		printf("\nElemento [%d]: %d",s,vector[s]);
	}
	
}

int Insercion(int vector[50],int n)
{
	int i,aux,pos;
		
	for(i=0;i<n;i++)
	{
		pos=i;
		aux=vector[i];
		
		while(pos>0 && vector[pos-1]>aux)
		{
			vector[pos] = vector[pos-1];
			pos--;
		}
		vector[pos]=aux;
	}
	printf("\n\nEl ordenamiento por metodo de Insercion ha sido exitoso! Vector ordenado:\n");
	for(int s=0;s<n;s++)
	{
		printf("\nElemento [%d]: %d",s,vector[s]);
	}
}

int Seleccion(int vector[50],int n)
{
	int i,j,aux,min;
	
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(vector[j]<vector[min])
			{
				min=j;
			}
		}
		aux=vector[i];
		vector[i]=vector[min];
		vector[min]=aux; 
	}
	printf("\n\nEl ordenamiento por metodo de Seleccion ha sido exitoso! Vector ordenado:\n");
	for(int s=0;s<n;s++)
	{
		printf("\nElemento [%d]: %d",s,vector[s]);
	}
}

void quicksort(int v[],int p,int u)
{
	int piv,izq,der,med;

	if(p<u)
	{
		piv=v[p];
		izq=p;
		der=u;
		
		while(izq<der)
		{
			while(der>izq and v[der]>piv)
			{
				der--;
			}
			if(der>izq)
			{
				v[izq]=v[der];
				izq++;
			}
			while(izq<der and v[izq]<piv)
			{
				izq++;
			}
			if(izq<der)
			{
				v[der]=v[izq];
				der--;
			}
			
		}
	v[der]=piv;
	med=der;
	quicksort(v,p,med-1);
	quicksort(v,med+1,u);
		
	}
	
	
}


void quicksort_leer(int n)
{
	int a[50];
	
	for(int t=0;t<n;t++)
	{
		printf("Ingrese el elemento de la posicion [%d]: ",t);
		scanf("%d",&a[t]);
	}
	
	system("cls");
	
	printf("Este es el vector que usted ingreso\n");
	for(int g=0;g<n;g++)
	{
		printf("\nElemento %d: %d",g,a[g]);
	}
	
	quicksort(a,0,n-1);

	printf("\n\nEl ordenamiento por el metodo Rapido ha sido exitoso! Vector ordenado:\n");
	for(int s=0;s<n;s++)
	{
		printf("\nElemento [%d]: %d",s,a[s]);
	}
}

void mezcla(int l[50],int ini, int m, int fin)
{
    int aux[20]; 
    int i,j,k,t;
    k=0;
    i=ini;
    j=m+1;
    
    while(i<=m && j<=fin)
	{
        k++;
        if (l[i]<l[j]){
            aux[k]=l[i];
            i++;
        }
        else{
            aux[k]=l[j];
            j++;
        }
    }
    for(t=i;t<=m;t++){
        k++;
        aux[k]=l[t];
    }
    for(t=j;t<=fin;t++){
        k++;
        aux[k]=l[t];
    }
    for(t=1;t<=k;t++)
        l[ini+t-1]=aux[t];
}


void m_sort(int l[50], int ini, int fin)
{
    int m;
    m=ini+(fin-ini)/2;
    if (ini<fin)
	{
        m_sort(l,ini,m);
        m_sort(l,m+1,fin);
        mezcla(l,ini,m,fin);
    }
}

void leer_merge(int num)
{	
	int a[50],i,d;
	for(int t=0;t<num;t++)
	{
		printf("Ingrese el elemento de la posicion [%d]: ",t);
		scanf("%d",&a[t]);
	}
	
	system("cls");
	printf("Este es el vector que usted ingreso\n");
	for(int g=0;g<num;g++)
	{
		printf("\nElemento [%d]: %d",g,a[g]);
	}
	
	m_sort(a,0,num-1);

	printf("\n\nEl ordenamiento por metodo Mergesort ha sido exitoso! Vector ordenado:\n");
	for(int s=0;s<num;s++)
	{
		printf("\nElemento [%d]: %d",s,a[s]);
	}
}






