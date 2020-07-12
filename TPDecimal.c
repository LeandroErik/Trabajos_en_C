#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
int Columna (int); /* dado un caracter, determina la columna que le  corresponde */
int EsPalabra (const char *);/*Verifica que sea una palabra reconocida*/
void ObtieneValor (const char *);/*Imprimer el valor reconocido por pantall*/

int main(int argc, char *argv[]){
if ( argc == 1 )
	{
		printf("Debe ingresar una Cadena en Linea de Comandos\n");
		return EXIT_FAILURE;
	}
if ( argc != 2 )
	{
		printf("Cantidad de Argumentos Incorrecta\n");
		return EXIT_FAILURE;
	}

 if (! Verifica(argv[1])) 
	{
		printf("Caracteres invalidos\n");
		return 0;
	}
	
	if (EsPalabra(argv[1]))
	{
		printf("Pertenece al lenguaje\n");
		
	 	ObtieneValor(argv[1]);
	 
		return 0;
	}
	printf("No pertenece al lenguaje\n"); 
	return 0;
	}
	
 
int EsPalabra (const char *cadena) { /* Automata 1 */
 static int tt [4][3] = {{2,1,1}, /* Tabla de Transiciones */
 						{2,3,3},
						{2,3,3},
						{3,3,3}};
						
 int e = 0; /* estado inicial */
 unsigned int i = 0; /* recorre la cadena */
 int c = cadena[0]; /* primer caracter */

 while (c !='\0')
 	 {/*mientras que haya cracteres*/
 		e = tt[e][Columna(c)]; /* nuevo estado */
 		c = cadena[++i]; /* proximo caracter */
 	}
 if (e == 2) /* estado final */ 
 return 1;

 return 0;
} /* fin EsPalabra */

int Verifica (char *s) {
 unsigned i;
 	for (i=0; s[i]; i++)
 		if (! (isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
 		{
 			return 0;
 		}	
 	return 1;
} /* fin Verifica */

int Columna (int c) {
 switch (c) {
 case '+': return 1;
 case '-': return 2;
 default /* es digito */: return 0;
 }
} /* fin Columna */

int Valor (int c) {
 return (c - '0');
} /* fin Valor */

void ObtieneValor (const char *cadena) {
 static int tt [4][3] = {{2,1,1},
 						{2,3,3},
						{2,3,3},
						{3,3,3}};
 int e = 0; /* estado inicial */
 unsigned i = 0; /* recorre la cadena */
 int c = cadena[0]; /* primer caracter */
 int a = 0; /* contiene valor numerico absoluto de la
cadena */
 int s = 1; /* signo del número: 1 = positivo; -1 =
negativo */
 while (c != '\0') 
 	{
 		e = tt [e][Columna(c)];
 		switch (e) {
 				case 1:
  				if (c=='-') s = -1;
 				break;
 				case 2: 
 				a = 10 * a + Valor(c);
 				break;
 				default /* error */: 
 				break;
 }
 	c = cadena[++i];
 }
 if (e == 2) 
 	{ /* estado final */
	printf("Resultado : %d \n",s * a);
	}
} /* fin ObtieneValor */


