#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int Verifica (char *);/* que los caracteres pertenezcan al alfabeto */
int ColumnaExp (int);/* dado un caracter, determina la columna que le corresponde */
int Valor (int );
int EsExpresion (const char *);
void ObtieneValorExp (const char *);

/*Funciones matematicas*/
void sumar(int ,int );
void restar(int ,int );
void multiplicar(int ,int );
void dividir(int ,int );


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

	if (! Verifica(argv[1])) 
	{
		printf("Caracteres invalidos\n");
		return 0;}
	
	if (EsExpresion(argv[1]))
	{
		printf("ES EXPRESION\n");
		ObtieneValorExp(argv[1]);
		
		return 0;
	}
	printf("no pertenece al lenguaje\n"); 
	return 0;
	}
	
int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++){
		if (! (isdigit(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' ))
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
void ObtieneValorExp (const char *cadena) {
/* Tabla de Transicione| D + - / *				*/
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
	break;
	case 2: 
	if (c=='+') op = '+';
	if (c=='-'){ op = '-';}
	if (c=='/'){ op = '/';}
	if (c=='*'){ op = '*';}
	break;
	case 3:
		c2 =c2*10+Valor(c);
	default /* error */: break;
	}
c = cadena[++i];
}

if (e == 3) { /* estado final */
switch (op){
	
	case '+':sumar(c1,c2);
	break;
	case '-':restar(c1,c2);
	break;
	case'/':dividir(c1,c2);
	break;
	case '*':multiplicar(c1,c2);
	break;
	default /* error */: break;
	
}
}
}

void sumar(int a,int b){
int resultado=0;
resultado = a + b;
printf("%d \n",resultado);
} /* fin ObtieneValor */

void restar(int a,int b){
unsigned resultado =0;
resultado = a - b;
printf("%d \n",resultado);
}
void dividir(int a,int b){
	float resultado =0;
	resultado = a/b;
	printf("%f \n",resultado);

}
void multiplicar(int a,int b){
	int resultado =0;
	resultado = a*b;
	printf("%d \n",resultado);

}