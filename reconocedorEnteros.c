#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * @file reconocedorEnteros.c
 * @brief  AFD que reconoce "Todos los números enteros en base 8,10 y 16, " con reconocimientos de sufijos
 * @author Marbe Moreno
 */

int VerificaDecimal (char *); /* que los caracteres pertenezcan al alfabeto */
int ColumnaDecimal (int,char); /* dado un caracter, determina la columna que le corresponde */
int EsPalabraDecimal (const char *);

int VerificaOctal (char *); /* que los caracteres pertenezcan al alfabeto */
int ColumnaOctal (int,int); /* dado un caracter, determina la columna que le corresponde */
int EsPalabraOctal (const char *);

int VerificaHexadecimal (char *); /* que los caracteres pertenezcan al alfabeto */
int ColumnaHexadecimal (int,int); /* dado un caracter, determina la columna que le corresponde */
int EsPalabraHexadecimal (const char *);

int main(int argc, char *argv[]){
	if ( argc == 1 )
	{
		printf("Debe ingresar una Cadena en Linea de Comandos\n");
		return EXIT_FAILURE;
	}
	if ( argc != 2 ){
		printf("Cantidad de Argumentos Incorrecta\n");
		return EXIT_FAILURE;
	}
	
	
	
	
	
	if (! VerificaHexadecimal(argv[1])) {
		printf("***No esta dentro del alfabeto hexadecimal***\n");
		
	}else if (EsPalabraHexadecimal(argv[1])){	
		printf("****************************************************************************************\n");
		printf("*Pertenece al lenguaj el lenguaje descripto en el para constantes enteras hexadecimales*\n");
		printf("****************************************************************************************\n");
		return 0;
	}	
	
	if (! VerificaOctal(argv[1])) {
		printf("***No esta dentro del alfabeto es octal***\n");
		
	}else if (EsPalabraOctal(argv[1])){	
		printf("**********************************************************************************\n");
		printf("*Pertenece al lenguaj el lenguaje descripto en el para constantes enteras octales*\n");
		printf("**********************************************************************************\n");
		return 0;
	}
	
	if (! VerificaDecimal(argv[1])) {
		printf("***No esta dentro del alfabeto es decimal***\n");
		
	}else if (EsPalabraDecimal(argv[1])){	
		printf("************************************************************************************\n");
		printf("*Pertenece al lenguaj el lenguaje descripto en el para constantes enteras decimales*\n");
		printf("************************************************************************************\n");
		return 0;
	}	
		
	printf("***No pertenece al lenguaje***\n"); 
	
	
	
	
	
	
	
	return 0;
}

/*Decimal*/

//definiciones
int VerificaDecimal (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	if (! (isdigit(s[i]) || s[i] == '-' || s[i] == '+'|| s[i] == 'l' || s[i] == 'L' || s[i] == 'u' || s[i] == 'U')) return 0;
	return 1;
} /* fin Verifica */
int ColumnaDecimal (int c,char firstD) {
	switch (c) {
	case '-': return 0;
	case '+': return 1;
	case 'l': return 3;
	case 'L': return 4;	
	case 'U':return 5;	
	case 'u':return 6;		
	default /* decimal */:{
		return 2;	

	};
	}
} /* fin Columna */
int EsPalabraDecimal (const char *cadena) { 
//D =decimales, U,u= unsigned, L,l= long
//                           - + D L l U u
	static int tt [10][7] ={{1,1,3,9,9,9,9}, /* Tabla de Transiciones */
							{9,9,2,9,9,9,9},
							{9,9,2,4,4,9,9},
							{9,9,3,5,5,6,6},
							{9,9,9,9,9,9,9},
							{9,9,9,9,9,7,7},
							{9,9,9,8,8,9,9},
							{9,9,9,9,9,9,9},
							{9,9,9,9,9,9,9},
							{9,9,9,9,9,9,9},
							};
	int e = 0; /* estado inicial */
	unsigned int i = 0; /* recorre la cadena */
	int c = cadena[0]; /* primer caracter */
	char auxC=cadena[0]; /*auxiliar primer caracter */
	while (c != '\0' && c!=9) {
		if (i==1 && auxC=='0' && c!='\0')return 0; //no permito que una cadena de enteros decimal tenga cero '0' a la izquierda
		if (i==2 && cadena[1]=='0' && (auxC=='+' ||auxC=='-') && c!='\0')return 0;//no permito que una cadena despues de un signo posea '0' y mas digitos despues
		e = tt[e][ColumnaDecimal(c,auxC)]; /* nuevo estado */
		c = cadena[++i]; /* proximo caracter */
	}
	if (e == 3) /* estado final */ return 1;
	else if (e==2) /*estado final */return 1;
	else if (e==4) /*estado final */return 1;
	else if (e==5) /*estado final */return 1;
	else if (e==6) /*estado final */return 1;
	else if (e==7) /*estado final */return 1;
	else if (e==8) /*estado final */return 1;
	return 0;
} /* fin EsPalabra */

/*fin decimal*/

/**octal**/
//definiciones
int VerificaOctal (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	if ((! (isdigit(s[i]) || s[i] == 'L' || s[i] == 'l')) || s[i] == '9' || s[i] == '8') return 0;
	return 1;
} /* fin Verifica */

int ColumnaOctal (int c,int aux) { //c = caracter 
	if(!aux){
		switch (c) {
			case '0': return 0;
		}
	}
	else {
		switch (c) {
		case 'L': return 2;
		case 'l': return 2;
		default /* es octal */: return 1;
		}
	}
} /* fin Columna */
int EsPalabraOctal (const char *cadena) { 
/*---------Tabla de Transiciones-------------*/
//O={0+1+2+3+4+5+6+7}
						//   0 O l,L 
	static int tt [5][3] = {{1,4,4},  // estado 0-
							{4,2,4}, //estado 1
							{4,2,3}, //estado 2+
							{4,4,4}, //estado 3+ 
							{4,4,4}}; //estado 4 (rechazo)
	int e = 0; /* estado inicial */
	int aux;
	unsigned int i = 0; /* recorre la cadena */
	int c = cadena[0]; /* primer caracter */
	while (c != '\0' && e!=3) {
		if(i<1){
			aux=0;//iniciar 0x
			e = tt[e][ColumnaOctal(c,aux)]; /* nuevo estado */
		}
		else{
			if (i==2 && c=='0' && cadena[1]=='0')return 0; //no permito que una cadena de enteros octal tenga cero '0' una vez mas ademas de su prefijo
			aux=1; //despues de 0x
			e = tt[e][ColumnaOctal(c,aux)]; /* nuevo estado */
		}
		c = cadena[++i]; /* proximo caracter */
	}
	if (e == 2) /* estado final */ return 1;
	else if (e == 3) /* estado final */ return 1;
	return 0;
} /* fin EsPalabra */
/**fin octal**/


/**inicio hexa**/
int VerificaHexadecimal (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	if (!(isxdigit (s[i]) || s[i]=='x' || s[i]=='X'|| s[i] == 'l' || s[i] == 'L') ) return 0;
	return 1;
} /* fin Verifica */
int ColumnaHexadecimal (int c,int aux) { //c = caracter 
	if(!aux){
		switch (c) {
			case '0': return 0;
		}
	}
	else {
		switch (c) {
		case 'X': return 1;
		case 'x': return 1;
		case 'L': return 3;
		case 'l': return 3;
		default /* es digito */: return 2;
	}
	
	
}
} /* fin Columna */
int EsPalabraHexadecimal (const char *cadena) { 
/*---------Tabla de Transiciones-------------*/
//H={0+1+2+3+4+5+6+7+8+9+a+b+c+d+e+f+A+B+C+D+E+F}
						//   0 X,x H L,l
	static int tt [6][4] = {{1, 5, 5, 5}, // estado 0-
							{5, 2, 5, 5}, //estado 1
							{5, 5, 3, 5}, //estado 2
							{5, 5, 3, 4}, //estado 3+
							{5, 5, 5, 5}, //estado 4+ 
							{5, 5, 5, 5}};//estado 5 (rechazo)
	int e = 0; /* estado inicial */
	int aux;
	unsigned int i = 0; /* recorre la cadena */
	int c = cadena[0]; /* primer caracter */
	while (c != '\0' && e!=5) {
		if(i<1){
			aux=0;//iniciar 0x
			e = tt[e][ColumnaHexadecimal(c,aux)]; /* nuevo estado */
		}
		else{
			aux=1; //despues de 0x
			e = tt[e][ColumnaHexadecimal(c,aux)]; /* nuevo estado */
		}
		c = cadena[++i]; /* proximo caracter */	
	}	
	if (e == 3) /* estado final */ return 1;
	else if (e == 4) /* estado final */ return 1;
	return 0;
} /* fin EsPalabra */

/*fin hexa*/
