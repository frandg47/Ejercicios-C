#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char cadena[20],final[10]="final";
	int b=1;
	do
	{
		system("cls");
	
		printf("\t\tPALABRAS(se finaliza el programa ingresando 'final')\n");
		printf("ingrese una palabra: ");
		scanf("%s",&cadena);
		printf("Palabra: %s",cadena);
		printf("\n\n");
		
		if(strcmp(final,cadena)==0)
		{
			b=0;
		}
		
	}while(b==1);
}