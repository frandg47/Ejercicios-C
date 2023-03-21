#include <stdio.h>
#include <string.h>
#include <conio.h>
void mostrar(char nombre1[101]);
int longt(char nombre1[101]);
main()
{
	char nombre[101];
	printf("Ingresar nombres, separados por una coma:");
	gets(nombre);
	mostrar(nombre);
	printf("\nCantidad de caracteres ingresador:%d", longt(nombre));
	getch();
}
void mostrar(char nombre1[101])
{
	for(int i = 0; i < strlen(nombre1); i++)
	{
		if(nombre1[i] == 44) //44 codigo ascii de la coma
		{
			printf("\n");
		}
		else
		{
			printf("%c", nombre1[i]);
		}
	}
}
int longt(char nombre1[101])
{
	int cont = 0, i = 0;
	while(nombre1[i] != NULL) //NULL es el enter
	{
		if(nombre1[i] != 44)
		{
			cont++;
		}
		i++;
	}
	return cont;
}