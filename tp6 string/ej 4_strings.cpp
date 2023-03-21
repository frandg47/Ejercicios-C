#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char poema[200];
	int vocal=0,consonante=0;
	
	printf("Ingrese un poema: ");
	gets(poema);
	for(int i=0;i<200;i++)
	{
		if(poema[i]=='a' or poema[i]=='e' or poema[i]=='i' or poema[i]=='o' or poema[i]=='u' )
		{
			vocal++;
		}
		if(poema[i]=='b' or poema[i]=='c' or poema[i]=='d' or poema[i]=='f' or poema[i]=='g' or poema[i]=='h' or poema[i]=='j' or poema[i]=='k' or poema[i]=='l' or poema[i]=='m' or poema[i]=='n' or poema[i]=='p' or poema[i]=='q' or poema[i]=='r' or poema[i]=='s' or poema[i]=='t' or poema[i]=='v' or poema[i]=='w' or poema[i]=='x' or poema[i]=='y' or poema[i]=='z')
		{
			consonante++;
		}
	}
	system("cls");
	printf("\ncantidad de vocales: %d",vocal);
	printf("\ncantidad de consonantes: %d",consonante);
	printf("\n\tPOEMA: ");
	puts(poema);
	system("PAUSE");
}