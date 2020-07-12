#include <stdio.h> 
#include <ctype.h> 

/**
 * @file decimalesSufijos.c
 * @brief  AFD que reconoce "Todos los números enteros en base 10, que pueden estar precedidos por un signo" con reconocimientos de sufijos
 * @author Marbe Moreno
 * @author Erik Quispe
 */
int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
int Columna (int,char); /* dado un caracter, determina la columna que le
corresponde */
int EsPalabra (const char *);

int main () {
	char s1[] = "090";
	 printf("Todos los numeros enteros en base 10 \n\n");
	if (! Verifica(s1)) {
		printf("***Caracteres invalidos***\n");
		return 0;
	}	
	if (EsPalabra(s1)){	
		printf("***********************\n");
		printf("*Pertenece al lenguaje*\n");
		printf("***********************\n");
		return 0;
	}		
	printf("***No pertenece al lenguaje***\n"); 
	return 0;
}

//definiciones
int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	if (! (isdigit(s[i]) || s[i] == '-' || s[i] == '+'|| s[i] == 'l' || s[i] == 'L' || s[i] == 'u' || s[i] == 'U')) return 0;
	return 1;
} /* fin Verifica */
int Columna (int c,char firstD) {
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
int EsPalabra (const char *cadena) { 
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
		e = tt[e][Columna(c,auxC)]; /* nuevo estado */
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

