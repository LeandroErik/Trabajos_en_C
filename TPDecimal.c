#include <stdio.h> /* printf */

#include <ctype.h> /* isdigit */

int Verifica (char *);/* que los caracteres pertenezcan al alfabeto */
int Columna (int);
int ColumnaDec (int);/* dado un caracter, determina la columna que le corresponde */
int Valor (int );

int EsPalabra (const char *);
int EsDecimal (const char *);

int ObtieneValorDec (const char *, long *) ;

int main () {
	char s1[] = "+12222222.11111111";
	long *valor;
	if (! Verifica(s1)) 
	{
		printf("Caracteres invalidos\n");
		return 0;}
	
	if (EsDecimal(s1))
	{
		printf("Pertenece al lenguaje\n");
		
	
		return 0;
	}
	printf("no pertenece al lenguaje\n"); 
	return 0;
	}
	
int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++){
		if (! (isdigit(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '.'))
		return 0;
	}
	
	return 1;
	} /* fin Verifica */



int Valor (int c) {
return (c - '0');
}

/*Otros requerimientos*/
int EsDecimal (const char *cadena) { /* Automata 1 */
/* Tabla de Transicione| D . + -					*/
static int tt [5][4] = {{1,4,1,1},/* estado inicial */
						{2,4,4,4},
						{2,3,4,4},
						{2,4,4,4},
						{4,4,4,4}};
int e = 0;
unsigned int i = 0;
int c = cadena[0];
	/* recorre la cadena */
	/* primer caracter */

	while (c != '\0') {
	e = tt[e][ColumnaDec(c)];
		/* nuevo estado */
	c = cadena[++i];
		/* proximo caracter */
	}
	if (e == 2) /* estado final */ 
	return 1;
	
return 0;
} /* fin Decimal*/

int ColumnaDec (int c) 
	{
		switch (c) {
		case '.' : return 1;
		break;
		case '+': return 2;
		break;
		case '-': return 3;
		break;
		default /* es digito */: return 0;
					}
	} /* fin Columna */

/*en fase de prueba OBTENER PALABRA*/
int ObtieneValorDec (const char *cadena, long *p_numero) {

/* Tabla de Transicione| D . + -					*/
static int tt [5][4] = {{1,4,1,1},/* estado inicial */
				/*1*/	{2,4,4,4},
				/*2*/	{2,3,4,4},
				/*3*/	{2,4,4,4},
				/*4*/	{4,4,4,4}};
int e = 0;
/* estado inicial */
unsigned i = 0;
/* recorre la cadena */
int c = cadena[0];
/* primer caracter */
long a = 0;
/* contiene valor numerico absoluto de la
cadena */
int s = 1;
/* signo del número: 1 = positivo; -1 =
negativo */
while (c != '\0') 
{
e = tt [e][ColumnaDec(c)];
}
if(ColumnaDec(c) == '.'){

	switch (e) 
	{
	case 2:
		 a = 10 * a + Valor(c);
		break;
	case 3:
		
	default /* error */: break;
	}
c = cadena[++i];
}



if (e == 2) { /* estado final */
*p_numero = s * a;
return 1;
}
else return 0;
} /* fin ObtieneValor */



