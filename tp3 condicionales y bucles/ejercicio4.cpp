#include<stdlib.h>
#include<stdio.h>

main()
{
	float ppk1,ppk2,ppk3,cpk1,cpk2,cpk3,pp1,pp2,pp3,pneto,desc,ptotal;
	
	printf("\ningrese el precio por kilo del producto 1: ");
	scanf("%f",&ppk1);
	printf("\ningrese cantidad (en kilo) del producto 1: ");
	scanf("%f",&cpk1);
	printf("\ningrese el precio por kilo del producto 2: ");
	scanf("%f",&ppk2);
	printf("\ningrese cantidad (en kilo) del producto 2: ");
	scanf("%f",&cpk2);
	printf("\ningrese el precio por kilo del producto 3: ");
	scanf("%f",&ppk3);
	printf("\ningrese cantidad (en kilo) del producto 3: ");
	scanf("%f",&cpk3);
	
	pp1=ppk1*cpk1;
	pp2=ppk2*cpk2;
	pp3=ppk3*cpk3;
	pneto=pp1+pp2+pp3;
	ptotal=pneto;
	if(pneto>=1000)
	{
		desc=pneto*0.05;
		ptotal=ptotal-desc;
	}
	system("cls");
	printf("--------------------------FACTURA--------------------------\n");
	printf("PRODUCTO     PRECIO/kg       CANTIDAD/kg      TOTAL\n");
	printf("   01        $ %.2f           %.2f kg      $ %.2f\n",ppk1,cpk1,pp1);
	printf("   02        $ %.2f           %.2f kg      $ %.2f\n",ppk2,cpk2,pp2);
	printf("   03        $ %.2f           %.2f kg      $ %.2f\n\n\n",ppk3,cpk3,pp3);
	printf("PRECIO NETO:                                 $ %.2f\n",pneto);
	printf("DESCUENTO:                                   $ %.2f\n",desc);
	printf("PRECIO TOTAL:                                $ %.2f\n",ptotal);
	printf("-----------------------------------------------------------\n\n\n\n");
	
	system("pause");
}