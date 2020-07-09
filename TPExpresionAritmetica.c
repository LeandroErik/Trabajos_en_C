#include <stdio.h> /* printf */

#include <ctype.h> /* isdigit */

int Verifica (char *);/* que los caracteres pertenezcan al alfabeto */

int ColumnaExp (int);/* dado un caracter, determina la columna que le corresponde */
int Valor (int );

int EsExpresion (const char *);

int ObtieneValorExp (const char *);

int main () {
	char s1[] = "2+1";
	int valor ;

	if (! Verifica(s1)) 
	{
		printf("Caracteres invalidos\n");
		return 0;}
	
	if (EsExpresion(s1))
	{
		printf("ES EXPRESION\n");
		valor = ObtieneValorExp(s1);
		printf("%d \n",valor);
		return 0;
	}
	printf("no pertenece al lenguaje\n"); 
	return 0;
	}
	
int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++){
		if (! (isdigit(s[i]) || s[i] == '+' || s[i] == '-' ))
		return 0;
	}
	return 1;
} /* fin Verifica */

int Valor (int c) {
return (c - '0');
}

/*Otros requerimientos*/
int EsExpresion (const char *cadena) { /* Automata 1 */
/* Tabla de Transicione| D + - / *					*/
static int tt [5][5] = {{1,4,4,4,4},/* estado inicial */
						{1,2,2,2,2},
						{3,4,4,4,4},
						{3,4,4,4,4},
						{4,4,4,4,4}};
int e = 0;
unsigned int i = 0;
int c = cadena[0];
	/* recorre la cadena */
	/* primer caracter */

	while (c != '\0') {
	e = tt[e][ColumnaExp(c)];
		/* nuevo estado */
	c = cadena[++i];
		/* proximo caracter */
	}
	if (e == 3) /* estado final */ 
	return 1;
	
return 0;
} /* fin Decimal*/

int ColumnaExp (int c) 
	{
		switch (c) {
		case '+': return 1;
		break;
		case '-': return 2;
		break;
		case '/': return 2;
		break;
		case '*': return 2;
		break;
		default /* es digito */: return 0;
					}
	} /* fin Columna */

/*en fase de prueba OBTENER PALABRA*/
int ObtieneValorExp (const char *cadena) {
/* Tabla de Transicione| D + - / .					*/
static int tt [5][5] = {{1,4,4,4,4},/* estado inicial */
						{1,2,2,2,2},
						{3,4,4,4,4},
						{3,4,4,4,4},
						{4,4,4,4,4}};
int e = 0;
/* estado inicial */
unsigned i = 0;
/* recorre la cadena */
int c = cadena[0];
int c1 = 0;
int c2 = 0;
/* primer caracter */
long a = 0;
int esPrimerValor=1;
/* contiene valor numerico absoluto de la
cadena */
char op ;
/* signo del número: 1 = positivo; -1 =
negativo */
while (c != '\0') {
e = tt [e][ColumnaExp(c)];
	switch (e) {
	case 1:
		c1=c1*10+Valor(c);
		printf("leguee al case%d \n",c1);
	
	break;
	case 2: if (c=='+') op = '+';
	if (c=='-'){ op = '-';}
	if (c=='/'){ op = '/';}
	if (c=='*'){ op = '*';}
	printf("leguee al case  de operaciones %d \n",op);
	break;
	case 3:
		c2 =c2*10+Valor(c);
		printf("leguee al case%d \n",c2);
	default /* error */: break;
	}
c = cadena[++i];
}

if (e == 3) { /* estado final */
switch (op){
	
	case '+': return c1+c2;
	break;
	case '-':return c1-c2;
	break;
	case'/':return c1/c2;
	break;
	case '*':return c1*c2;
	break;
	default /* error */: break;
	
}

}

} /* fin ObtieneValor */
