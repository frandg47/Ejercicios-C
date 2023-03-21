#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
	char user[10];
	char contr[10];
	char apeNom[60];
	bool habilitado;
};
struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Socios{
	char Nombre[50];
	char Apellido[50];
	int Dni;
	int Edad;
	int Peso;
	int Altura;
	char Medicas[100];
	char Telefono[50];
	char Domicilio[50];
	Fecha fec;
	char rutina[380];	
};

struct registroent{
	char user[10];
	char contr[10];
	char apeNom[60];
	int dni;
	int dias[6];
	int horas;
	bool habilitado;
};






/*Modulo Gim*/
bool IniciarSesionEnt();		
void CargaRutinas();				
void MostrarActSocios();		

/*Modulo Recepcion*/
void RegistroSocios();
void MostrarSocios();
void RegistroActividad();
void BorrarSocio();
void Pagos();
bool IniciarSesion();

/*Modulo Administracion*/
bool InicioSesion();
void RegistrodeUsuario();
void MostrarUsuarios();
void RegistroAct();
void RegistroEntrenador();

bool IniciarSesionEnt()
{
	
	registro usuarios;
	char user[10];
	char pass[10];
	bool band,encontrado,correcto,band2;
	
	FILE *Socio;
	
		Socio=fopen("entrenadores.dat","r+b");
	if(Socio==NULL){
		printf("Solicite al administrador que realice la carga de usuarios");
	}
	
	rewind(Socio);
	printf("INICIAR SESION\n");
	
	_flushall();
	printf("\nNombre de Usuario: ");
	gets(user);
	
	_flushall();
	printf("\nContraseña: ");
	gets(pass);	
	
	encontrado=false;
	band=false;
	band2=false;
	fread(&usuarios,sizeof(registroent),1,Socio);
	
	while(feof(Socio)==0 && band==false){
		if((strcmp(usuarios.user,user)==0) && (strcmp(usuarios.contr,pass)==0) ){
			printf("\nUsuario Correcto");
			band=true;
			encontrado=true;
		}else{
		fread(&usuarios,sizeof(registroent),1,Socio);
		}
	}
	
		
	if(encontrado==true){
	printf("\nSesion iniciada correctamente\n");
} else{
	printf("\nUsuario o contraseña incorrectos\n");
}
	return (encontrado);
	fclose(Socio);
	}
	
void CargaRutinas()
{
	FILE *Socio;
	Socios soc;
	int doc;
	bool band;
	
	
		Socio=fopen("Socios.dat","a+b");
	if(Socio==NULL){
		printf("Solicite al administrador que realice la carga de usuarios");
	}
	printf("CARGA DE RUTINAS\n");
	printf("Ingrese el numero de documento del socio: ");
	scanf("%d",&doc);
	band=false;
	system("pause");
	system("cls");
	
	
	
	rewind(Socio);
	
	
	fread(&soc,sizeof(Socios),1,Socio);
	
	while(feof(Socio)==0 && band==false){
	if(doc==soc.Dni){
		
	printf("CARGA DE RUTINA\n");
	printf("Nombre:%s %s\n",soc.Nombre,soc.Apellido);
	printf("\nEscriba la rutina: ");
	_flushall();
	gets(soc.rutina);
	
	}else{
		fread(&soc,sizeof(Socios),1,Socio);
	}
	fclose(Socio);
}	
}

bool InicioSesion()
{
	bool bandera=false;
	char usuario[10],password[10];
	char nombre[10]="admin",clave[10]="admin123";                     /*CLAVE ADMINISTRADOR*/
	
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

void RegistrodeUsuario()
{
	char aux[10],aux2[10];
	FILE *arch;
	registro usuarios;
	int valor;	
	bool band;
	int cant1,cant2,c1=0,c2=0;
	bool may=false,min=false,dig=false,signos=true,consecutivas=false;
	
	printf("\t\tREGISTRAR USUARIO DE RECEPCION");
	arch=fopen("usuarios.dat","a+b");

	printf("\n\n\t\t\tATENCION!\nPara crear un usuario debe tener en cuenta las siguientes pautas: \n\ta) Ser unico para cada usuario registrado.\n\tb) Comenzar con una letra minuscula.\n\tc) Tener al menos 2 letras mayusculas.\n\td) Tener como maximo 3 digitos\n\te) El nombre de usuario debe tener entre 6 y 10 caracteres");
	
	
	
	rewind(arch);
	
	
	
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(aux);
	
	fread(&usuarios,sizeof(registro),1,arch);
	band=false;
	
	while(feof(arch)==0 && band==false){
		valor=strcmp(aux,usuarios.user);
		
		if(valor!=0){
		band=true;
	}else{
		_flushall();
		printf("Usuario existente, pruebe con otro: ");
		gets(aux);
		fread(&usuarios,sizeof(registro),1,arch);
		valor=strcmp(aux,usuarios.user);
		rewind(arch);
	}
	}

	
	
	
	
	
	
	
	
	
	
	cant1=strlen(aux); //cantidad de caracteres del nombre de usuario
	if(aux[0]>=97 and aux[0]<=122 and cant1>=6 and cant1<=10) //condicion b) y verificacion de cantidad de caracteres
	{
		for(int i=0;i<cant1;i++) //control de cantidad de mayusuculas
		{
			if(aux[i]>=65 and aux[i]<=90) 
			{
				c1++;//cantidad de mayusuculas
			}
		}
		if(c1>=2) //condicion c)
		{
			for(int j=0;j<cant1;j++) //control cantidad de digitos
			{
				if(aux[j]>=48 and aux[j]<=57)
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
				printf("\n\n\t\t\tATENCION!\nPara su contraseña debe tener en cuenta las siguientes pautas: \n\ta) Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n\tb) No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n\tc) Debera tener entre 6 y 32 caracteres.\n\td) No debe tener mas de 3 caracteres numericos consecutivos. \n\te) No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
				printf("\n\n\nClave: ");
				_flushall();
				gets(aux2);
				cant2=strlen(aux2); //cantidad de caracteres de contraseña
				if(cant2>5 and cant2<33) //condicion c de contraseña
				{
					for(int k=0;k<cant2;k++)
					{
						if(aux2[k]>64 and aux2[k]<91) //control de mayus
						{
							may=true; //al menos una mayuscula
						}
						if(aux2[k]>96 and aux2[k]<123) //control de minus
						{
							min=true; //al menos una minuscula
						}
						if(aux2[k]>47 and aux2[k]<58) //control de numeros
						{
							dig=true; //al menos 1 numero
						}
						if((aux2[k]>=0 and aux2[k]<48) or (aux2[k]>57 and aux2[k]<65) or (aux2[k]>90 and aux2[k]<97) or aux2[k]>122) //control de signos de puntuacion
						{
							signos=false; //se colocaron signos de puntuacion
						}
					}
					for(int h=0;h<cant2;h++) //se comprueba si existen letras consecutivas de manera ascendente
					{
						if(aux2[h+1]-aux2[h]==1 or aux2[h+1]-aux2[h]==33 or aux2[h+1]-aux2[h]==-33 or aux2[h+1]-aux2[h]==31 or aux2[h+1]-aux2[h]==-31)
						{
							consecutivas=true; //se encontraron caracteres consecutivos
						}
					}
					if(may==true and min==true and dig==true and signos==true and consecutivas==false) //la clave cumple los requisitos
					{
						usuarios.habilitado=true;
						_flushall();
						strcpy(usuarios.contr,aux2);
						_flushall();
						strcpy(usuarios.user,aux);
						fseek(arch,sizeof(registro),SEEK_END);
						 //se guarda el registro en el archivo 
						printf("\n\n\tUSUARIO REGISTRADO CORRECTAMENTE");
						printf("\n\nIngrese su Nombre y Apellido: ");
						_flushall();
						gets(usuarios.apeNom);
						strupr(usuarios.apeNom);
						fwrite(&usuarios,sizeof(registro),1,arch);
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
void RegistroEntrenador()
{
	
	char aux[10],aux2[10];
	FILE *arch;
	registroent usuarios;
	int valor;	
	bool band;
	int cant1,cant2,c1=0,c2=0;
	bool may=false,min=false,dig=false,signos=true,consecutivas=false;
	
	printf("\t\tREGISTRAR ENTRENADOR");
	arch=fopen("entrenadores.dat","a+b");

	printf("\n\n\t\t\tATENCION!\nPara crear un usuario debe tener en cuenta las siguientes pautas: \n\ta) Ser unico para cada usuario registrado.\n\tb) Comenzar con una letra minuscula.\n\tc) Tener al menos 2 letras mayusculas.\n\td) Tener como maximo 3 digitos\n\te) El nombre de usuario debe tener entre 6 y 10 caracteres");
	
	
	
	rewind(arch);
	
	
	
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(aux);
	
	fread(&usuarios,sizeof(registroent),1,arch);
	band=false;
	
	while(feof(arch)==0 && band==false){
		valor=strcmp(aux,usuarios.user);
		
		if(valor!=0){
		band=true;
	}else{
		_flushall();
		printf("Usuario existente, pruebe con otro: ");
		gets(aux);
		fread(&usuarios,sizeof(registroent),1,arch);
		valor=strcmp(aux,usuarios.user);
		rewind(arch);
	}
	}

	
	
	
	
	
	
	
	
	
	
	cant1=strlen(aux); //cantidad de caracteres del nombre de usuario
	if(aux[0]>=97 and aux[0]<=122 and cant1>=6 and cant1<=10) //condicion b) y verificacion de cantidad de caracteres
	{
		for(int i=0;i<cant1;i++) //control de cantidad de mayusuculas
		{
			if(aux[i]>=65 and aux[i]<=90) 
			{
				c1++;//cantidad de mayusuculas
			}
		}
		if(c1>=2) //condicion c)
		{
			for(int j=0;j<cant1;j++) //control cantidad de digitos
			{
				if(aux[j]>=48 and aux[j]<=57)
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
				printf("\n\n\t\t\tATENCION!\nPara su contraseña debe tener en cuenta las siguientes pautas: \n\ta) Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n\tb) No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n\tc) Debera tener entre 6 y 32 caracteres.\n\td) No debe tener mas de 3 caracteres numericos consecutivos. \n\te) No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
				printf("\n\n\nClave: ");
				_flushall();
				gets(aux2);
				cant2=strlen(aux2); //cantidad de caracteres de contraseña
				if(cant2>5 and cant2<33) //condicion c de contraseña
				{
					for(int k=0;k<cant2;k++)
					{
						if(aux2[k]>64 and aux2[k]<91) //control de mayus
						{
							may=true; //al menos una mayuscula
						}
						if(aux2[k]>96 and aux2[k]<123) //control de minus
						{
							min=true; //al menos una minuscula
						}
						if(aux2[k]>47 and aux2[k]<58) //control de numeros
						{
							dig=true; //al menos 1 numero
						}
						if((aux2[k]>=0 and aux2[k]<48) or (aux2[k]>57 and aux2[k]<65) or (aux2[k]>90 and aux2[k]<97) or aux2[k]>122) //control de signos de puntuacion
						{
							signos=false; //se colocaron signos de puntuacion
						}
					}
					for(int h=0;h<cant2;h++) //se comprueba si existen letras consecutivas de manera ascendente
					{
						if(aux2[h+1]-aux2[h]==1 or aux2[h+1]-aux2[h]==33 or aux2[h+1]-aux2[h]==-33 or aux2[h+1]-aux2[h]==31 or aux2[h+1]-aux2[h]==-31)
						{
							consecutivas=true; //se encontraron caracteres consecutivos
						}
					}
					if(may==true and min==true and dig==true and signos==true and consecutivas==false) //la clave cumple los requisitos
					{
						usuarios.habilitado=true;
						_flushall();
						strcpy(usuarios.contr,aux2);
						_flushall();
						strcpy(usuarios.user,aux);
						fseek(arch,sizeof(registro),SEEK_END);
						 //se guarda el registro en el archivo 
						printf("\n\n\tUSUARIO REGISTRADO CORRECTAMENTE");
						printf("\n\nIngrese su Nombre y Apellido: ");
						_flushall();
						gets(usuarios.apeNom);
						strupr(usuarios.apeNom);
						printf("\nIngrese su DNI: ");
						scanf("%d",&usuarios.dni);
						fwrite(&usuarios,sizeof(registroent),1,arch);
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
void MostrarUsuarios()
{

	registro usuarios;

	int i=0;	
	FILE *Socio;
	
	Socio=fopen("usuarios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("usuarios.dat","w+b");
	}
	
	rewind(Socio);
	fread(&usuarios,sizeof(registro),1,Socio);
	printf("SOCIOS REGISTRADOS\n");
	printf("Nombre\t\tApellido\tDni\n ");
	while(!feof(Socio)){	
	
	printf("%s\t\t%s\t\t\n",usuarios.user,usuarios.contr);
	
	
	fread(&usuarios,sizeof(registro),1,Socio);
	i++;	
}
	printf("Cantidad de socios=%d\n",i);
	
	fclose(Socio);
}

void RegistroAct()
{
	
	FILE *Acti;
	
	Acti=fopen("actividades.dat","a+b");
	if(Acti==NULL){
		Acti=fopen("actividades.dat","w+b");
	}
}

bool IniciarSesion()
{
	
	registro usuarios;
	char user[10];
	char pass[10];
	bool band,encontrado,correcto,band2;
	
	FILE *Socio;
	
		Socio=fopen("usuarios.dat","r+b");
	if(Socio==NULL){
		printf("Solicite al administrador que realice la carga de usuarios");
	}
	
	rewind(Socio);
	printf("INICIAR SESION\n");
	
	_flushall();
	printf("\nNombre de Usuario: ");
	gets(user);
	
	_flushall();
	printf("\nContraseña: ");
	gets(pass);	
	
	encontrado=false;
	band=false;
	band2=false;
	fread(&usuarios,sizeof(registro),1,Socio);
	
	while(feof(Socio)==0 && band==false){
		if((strcmp(usuarios.user,user)==0) && (strcmp(usuarios.contr,pass)==0) ){
			printf("\nUsuario Correcto");
			band=true;
			encontrado=true;
		}else{
		fread(&usuarios,sizeof(registro),1,Socio);
		}
	}
	
		
	if(encontrado==true){
	printf("\nSesion iniciada correctamente\n");
} else{
	printf("\nUsuario o contraseña incorrectos\n");
}
	return (encontrado);
	fclose(Socio);
	}
	


void RegistroSocios()
{
	int i=0;
	

	Socios soc;
		
	FILE *Socio;
	
	Socio=fopen("Socios.dat","a+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	
	printf("REGISTRO DE SOCIOS\n");
	
	_flushall();
	printf("Nombre: ");
	gets(soc.Nombre);
	strupr(soc.Nombre);
	
	_flushall();
	printf("Apellido: ");
	gets(soc.Apellido);
	strupr(soc.Apellido);
	
	printf("DNI: ");
	scanf("%d",&soc.Dni);
	
	printf("Edad: ");
	scanf("%d",&soc.Edad);
	
	printf("Peso: ");
	scanf("%d",&soc.Peso);
	
	printf("Altura en cm: ");
	scanf("%d",&soc.Altura);
	
	_flushall();
	printf("Telefono: ");
	gets(soc.Telefono);
	
	_flushall();
	printf("Ingrese indicaciones medicas: ");
	gets(soc.Medicas);
	strupr(soc.Medicas);
	
	_flushall();
	printf("Domicilio: ");
	gets(soc.Domicilio);
	strupr(soc.Domicilio);
	
	printf("FECHA DE INGRESO\n");
	printf("Dia: ");
	scanf("%d",&soc.fec.dia);
	printf("Mes: ");
	scanf("%d",&soc.fec.mes);
	printf("Año: ");
	scanf("%d",&soc.fec.anio);
	
	
	fwrite(&soc,sizeof(Socios),1,Socio);
	
	fclose(Socio);
}

void MostrarSocios()
{

	Socios soc;

	int i=0;	
	FILE *Socio;
	
	Socio=fopen("Socios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	
	
	
	rewind(Socio);
	fread(&soc,sizeof(Socios),1,Socio);
	printf("SOCIOS REGISTRADOS\n");
	printf("Nombre\t\tApellido\tDni\n ");
	while(!feof(Socio)){	
	
	printf("%s\t\t%s\t\t%d\n",soc.Nombre,soc.Apellido,soc.Dni);
	
	
	fread(&soc,sizeof(Socios),1,Socio);
	i++;	
}
	printf("Cantidad de socios=%d\n",i);
	
	fclose(Socio);
}

void RegistroActividad()
{
	Socios soc;
	int doc,opc;
	int i=0;	
	FILE *Socio;
	bool band;
	
	Socio=fopen("Socios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	printf("REGISTRO ACTIVIDADES\n");
	printf("Ingrese el DNI del socio: ");
	scanf("%d",&doc);
	band=false;
	rewind(Socio);
	
	fread(&soc,sizeof(Socios),1,Socio);
	
}

void BorrarSocio()
{
	
	Socios soc;
	 FILE *arch,*auxiliar;
	 int b,doc; //b=0 no lo encontro b=1 encontro

 /*Baja Fisica*/

 arch=fopen("Socios.dat","r+b");
 auxiliar=fopen("auxiliar.dat","wb");

 printf("Ingrese el numero de documento del socio a dar de BAJA: ");
 scanf("%d",&doc);

 fread(&soc,sizeof(Socios),1,arch);
 b=0;
 while (!feof(arch))
 {
 if (soc.Dni!=doc)
 fwrite(&soc,sizeof(Socios),1,auxiliar);
 else
 b=1;
 fread(&soc,sizeof(Socios),1,arch);
 }

 if (b==1)
 {
	printf("Aguarde un momento...\n");
	system("pause");
	system("cls");
 printf("\n\nSocio dado de baja\n");
 }
 fclose(arch);
 fclose(auxiliar);
 remove("Socios.dat");
 rename("auxiliar.dat","Socios.dat");
}	

void Pagos()
{
	Socios soc;

	int i=0;	
	FILE *Socio;
	
	Socio=fopen("Socios.dat","r+b");
	if(Socio==NULL){
		Socio=fopen("Socios.dat","w+b");
	}
	
	
	
	
	rewind(Socio);
	fread(&soc,sizeof(Socios),1,Socio);
	printf("SOCIOS REGISTRADOS\n");
	printf("Nombre\t\tApellido\tFecha de Pago\n ");
	while(!feof(Socio)){	
	
	if(soc.fec.mes==12){
		printf("%s\t\t%s\t\t%d/%d/%d\n",soc.Nombre,soc.Apellido,soc.fec.dia,soc.fec.mes-11,soc.fec.anio+1);
	}else{
		printf("%s\t\t%s\t\t%d/%d/%d\n",soc.Nombre,soc.Apellido,soc.fec.dia,soc.fec.mes+1,soc.fec.anio);
	}
	
	
	
	fread(&soc,sizeof(Socios),1,Socio);
	i++;	
}
	printf("Cantidad de socios=%d\n",i);
	
	fclose(Socio);
}



