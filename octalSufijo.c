#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit */
/**
 * @file octalSufijos.c
 * @brief  AFD que reconoce "Todos los números enteros en base 8, " con reconocimientos de sufijos
 * @author Marbe Moreno
 * @author Erik Quispe
 */
int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
int Columna (int,int); /* dado un caracter, determina la columna que le
corresponde */
int EsPalabra (const char *);

int main () {
	char s1[] = "0002055202L";
	
	 printf("Todos los numeros enteros en base 8 con o sin sufijo long \n");
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
	
	printf("****No pertenece al lenguaje****\n"); 
	return 0;
}

//definiciones
int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	if ((! (isdigit(s[i]) || s[i] == 'L' || s[i] == 'l')) || s[i] == '9' || s[i] == '8') return 0;
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
		case 'L': return 2;
		case 'l': return 2;
		default /* es octal */: return 1;
		}
	}
} /* fin Columna */
int EsPalabra (const char *cadena) { 
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
			e = tt[e][Columna(c,aux)]; /* nuevo estado */
		}
		else{
			if (i==2 && c=='0' && cadena[1]=='0')return 0; //no permito que una cadena de enteros octal tenga cero '0' una vez mas ademas de su prefijo
			aux=1; //despues de 0x
			e = tt[e][Columna(c,aux)]; /* nuevo estado */
		}
	
		c = cadena[++i]; /* proximo caracter */
	}
	if (e == 2) /* estado final */ return 1;
	else if (e == 3) /* estado final */ return 1;
	return 0;
} /* fin EsPalabra */

