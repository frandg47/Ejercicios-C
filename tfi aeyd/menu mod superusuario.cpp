#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct registro{
	char user[10];
	char contr[10];
	char apeNom[60];
	bool habilitado;
};

bool InicioSesion(char usuario[10],char password[10]);
void RegistrodeUsuario(FILE *arch,registro usarios);

main()
{
	int opcion,b=1;
	char usuario[10],password[10];
	FILE *arch;
	bool band;
	registro usuarios;
	
	
	while(b!=0)
	{
		system("cls");
		printf("\t\tMODULO ADMINISTRACION\n\n\tSeleccione una opcion: \n\n1)Iniciar Sesion\n2)Registrar usuario de Recepcion\n3)Registrar Actividades del Gym\n4)Calcular pago al entrenador\n5)Entrenador con mayor carga horaria\n6)Cerrar la aplicacion\n\nOPCION: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1: band=InicioSesion(usuario,password);break;
			case 2: system("cls");if(band==true){RegistrodeUsuario(arch,usuarios);}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");system("pause");}break;
			case 3: system("cls");if(band==true){printf("\t\tREGISTRO ACTIVIDADES DEL GYM");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 4: system("cls");if(band==true){printf("\t\tCALCULAR PAGO DEL ENTRENADOR");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 5: system("cls");if(band==true){printf("\t\tENTRENADOR CON MAYOR CARGA HORARIA");}else{printf("\t\t\nDEBE INICIAR SESION\n\n\n");}system("pause");break;
			case 6: system("cls");b=0;break;
			default: printf("\n\nIngrese una opcion valida, intente de nuevo\n\n\n\n");system("PAUSE");
		}
	}
	printf("\n\n\t");
	system("PAUSE");
}

bool InicioSesion(char usuario[10],char password[10])
{
	bool bandera=false;
	char nombre[10]="admin",clave[10]="admin123";
	
	system("cls");
	printf("\t\tINICIO DE SESION");
	printf("\n\nUSUARIO: ");
	_flushall();
	gets(usuario);
	if(strcmp(usuario,nombre)==0)
	{
		printf("\nCONTRASENIA: ");
		_flushall();
		gets(password);	
		if(strcmp(password,clave)==0)
		{
			bandera=true;
		}	
		else
		{
			printf("\n\tCLAVE INCORRECTA");
		}
	}
	else
	{
		printf("\n\tUSUARIO INCORRECTO");
	}	
	printf("\n\n\n");
	system("pause");
	return bandera;
}

void Coincidencias(FILE *arch,registro usuarios)
{
	arch=fopen("usuarios.dat","r+b");
	fread(&reg,sizeof(registro),1,arch);	
	
	
	while(!feof(arch))
	{
		if(usuarios.apeNom==leg)
		{
			reg.habilitado=false;
			fseek(arch,(long)-sizeof(registro),SEEK_CUR);
			fwrite(&reg,sizeof(registro),1,arch);
			printf("\n\n\nALUMNO CON LEGAJO %d DADO DE BAJA",leg);
			band=true;
		}
		else
		{
			fread(&reg,sizeof(registro),1,arch);
		}
		
	}
	fclose(arch);
	printf("\n\n\n");
	system("PAUSE");
}

void RegistrodeUsuario(FILE *arch,registro usuarios)
{
	int cant1,cant2,c1=0,c2=0;
	bool may=false,min=false,dig=false,signos=true,consecutivas=false;
	
	printf("\t\tREGISTRAR USUARIO DE RECEPCION");
	arch=fopen("usuarios.dat","a+b");
	printf("\n\nNombre y Apellido: ");
	_flushall();
	gets(name);
	strupr(usuarios.apeNom);
	Coincidencias(arch,usuarios);
	printf("\n\n\t\t\tATENCION!\nDebe tener en cuenta las siguientes pautas: \n\ta) Ser unico para cada usuario registrado.\n\tb) Comenzar con una letra minuscula.\n\tc) Tener al menos 2 letras mayusculas.\n\td) Tener como maximo 3 digitos\n\te) El nombre de usuario debe tener entre 6 y 10 caracteres");
	printf("\n\n\nUsuario: ");
	gets(usuarios.user);
	cant1=strlen(usuarios.user); //cantidad de caracteres del nombre de usuario
	if(usuarios.user[0]>=97 and usuarios.user[0]<=122 and cant1>=6 and cant1<=10) //condicion b) y verificacion de cantidad de caracteres
	{
		for(int i=0;i<cant1;i++) //control de cantidad de mayusuculas
		{
			if(usuarios.user[i]>=65 and usuarios.user[i]<=90) 
			{
				c1++;//cantidad de mayusuculas
			}
		}
		if(c1>=2) //condicion c)
		{
			for(int j=0;j<cant1;j++) //control cantidad de digitos
			{
				if(usuarios.user[j]>=48 and usuarios.user[j]<=57)
				{
					c2++;//cantidad de digitos
				}
			}
			if(c2<=3) //condicion d)
			{
				printf("\n\n\t\t\tUSUARIO APROBADO!\n\n\n");
				system("pause");
				system("cls");
				printf("\t\tREGISTRAR USUARIO DE RECEPCION");
				printf("\n\n\t\t\tATENCION!\nDebe tener en cuenta las siguientes pautas: \n\ta) Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n\tb) No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n\tc) Debera tener entre 6 y 32 caracteres.\n\td) No debe tener mas de 3 caracteres numericos consecutivos. \n\te) No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
				printf("\n\n\nClave: ");
				_flushall();
				gets(usuarios.contr);
				cant2=strlen(usuarios.contr); //cantidad de caracteres de contraseña
				if(cant2>5 and cant2<33) //condicion c de contraseña
				{
					for(int k=0;k<cant2;k++)
					{
						if(usuarios.contr[k]>64 and usuarios.contr[k]<91) //control de mayus
						{
							may=true; //al menos una mayuscula
						}
						if(usuarios.contr[k]>96 and usuarios.contr[k]<123) //control de minus
						{
							min=true; //al menos una minuscula
						}
						if(usuarios.contr[k]>47 and usuarios.contr[k]<58) //control de numeros
						{
							dig=true; //al menos 1 numero
						}
						if((usuarios.contr[k]>=0 and usuarios.contr[k]<48) or (usuarios.contr[k]>57 and usuarios.contr[k]<65) or (usuarios.contr[k]>90 and usuarios.contr[k]<97) or usuarios.contr[k]>122) //control de signos de puntuacion
						{
							signos=false; //se colocaron signos de puntuacion
						}
					}
					for(int h=0;h<cant2;h++) //se comprueba si existen letras consecutivas de manera ascendente
					{
						if(usuarios.contr[h+1]-usuarios.contr[h]==1 or usuarios.contr[h+1]-usuarios.contr[h]==33 or usuarios.contr[h+1]-usuarios.contr[h]==-33 or usuarios.contr[h+1]-usuarios.contr[h]==31 or usuarios.contr[h+1]-usuarios.contr[h]==-31)
						{
							consecutivas=true; //se encontraron caracteres consecutivos
						}
					}
					if(may==true and min==true and dig==true and signos==true and consecutivas==false) //la clave cumple los requisitos
					{
						usuarios.habilitado=true;
						fwrite(&usuarios,sizeof(registro),1,arch); //se guarda el registro en el archivo 
						printf("\n\n\tUSUARIO REGISTRADO CORRECTAMENTE");
					}
					else
					{
						system("cls");
						printf("\t\tEL NOMBRE DE USUARIO O CLAVE NO CUMPLE ALGUNA DE LAS CONDICIONES");		
					}
				}			
			}
			else
			{
				system("cls");
				printf("\t\tEL NOMBRE DE USUARIO O CLAVE NO CUMPLE ALGUNA DE LAS CONDICIONES");		
			}		
		}
		else
		{
			system("cls");
			printf("\t\tEL NOMBRE DE USUARIO O CLAVE NO CUMPLE ALGUNA DE LAS CONDICIONES");		
		}	
	}
	else
	{
		system("cls");
		printf("\t\tEL NOMBRE DE USUARIO O CLAVE NO CUMPLE ALGUNA DE LAS CONDICIONES");		
	}
	fclose(arch);
	printf("\n\n\n");
	system("pause");
}
