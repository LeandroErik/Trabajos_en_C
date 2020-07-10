#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit */
/**
 * @file Decimales sufijos.c
 * @brief  AFD que reconoce "Todos los números enteros en base 16" con reconocimientos de sufijos
 * @author Marbe Moreno
 */
int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
int Columna (int,int); /* dado un caracter, determina la columna que le
corresponde */
int EsPalabra (const char *);

int main () {
	char s1[] = "0XdaL";
	
	long  a  ;
	 printf("Todos los numeros enteros en base 16 \n\n");
	if (! Verifica(s1)) {
		printf("Caracteres invalidos\n");
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
	if (!(isxdigit (s[i]) || s[i]=='x' || s[i]=='X'|| s[i] == 'l' || s[i] == 'L') ) return 0;
	return 1;
} /* fin Verifica */
int Columna (int c,int aux) { //c = caracter 
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
int EsPalabra (const char *cadena) { 
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
			e = tt[e][Columna(c,aux)]; /* nuevo estado */
		}
		else{
			aux=1; //despues de 0x
			e = tt[e][Columna(c,aux)]; /* nuevo estado */
		}
		
		c = cadena[++i]; /* proximo caracter */
		
	}
	
	if (e == 3) /* estado final */ return 1;
	else if (e == 4) /* estado final */ return 1;
	return 0;
} /* fin EsPalabra */

