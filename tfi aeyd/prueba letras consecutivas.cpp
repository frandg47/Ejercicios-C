#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char nombre[20];
	int cant;
	
	printf("nombre: ");
	gets(nombre);
	
	cant=strlen(nombre);
	
	for(int i=0;i<cant;i++)
	{
		if(nombre[i+1]-nombre[i]==1 or nombre[i+1]-nombre[i]==33 or nombre[i+1]-nombre[i]==-33 or nombre[i+1]-nombre[i]==31 or nombre[i+1]-nombre[i]==-31)
		{
			printf("\nletras consecutivas");
		}
		else
		{
			printf("\nno hay letras consecutivas");
		}
	}
	system("pause");
}