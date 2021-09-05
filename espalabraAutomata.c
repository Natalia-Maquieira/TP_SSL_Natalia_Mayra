#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit */
int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
int Columna (int); /* dado un caracter, determina la columna que le corresponde */
int EsPalabra (const char *);
int EsPalabra2 (const char *);


int main () {
	char s1[] = "-0123045";
	if (!Verifica(s1)) 
	{
		printf("Caracteres invalidos\n");
		return 0;
	}		
	if (EsPalabra(s1))
	{
		printf("Pertenece al lenguaje\n");
		return 0;
	}	
	
	printf("no pertenece al lenguaje\n"); 
	return 0;
}

int Verifica (char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	{
		if (!(isdigit(s[i]) || s[i] == '+' || s[i] == '-')) 
			 
		return 0;
	}
return 1;
} 
/* fin Verifica */
int Columna (int c) {
	switch (c) {
		case '+': 
			return 1;
		case '-': 
			return 2;
		default /* es digito */: 
			return 0;
	}
}
int EsPalabra (const char *cadena) 
{ /* Automata 1 */
	static int tt [4][3] = {{2,1,1}, /* Tabla de Transiciones */
							{2,3,3},
							{2,3,3},
							{3,3,3}};
	int e = 0; 
	unsigned int i = 0; 
	int c = cadena[0]; 
	
	while (c != '\0') 
	{
		e = tt[e][Columna(c)];
		c = cadena[++i]; 
	}

	if (e == 2)  
		return 1;

	return 0;
} /* fin EsPalabra */

int EsPalabra2 (const char *s) { /* Automata 2 */
	static int tt [4][3] = {{2,1,1}, /* Tabla de Transiciones */
							{2,3,3},
							{2,3,3},
							{3,3,3}};
	int e=0; 
	unsigned int i; 
	for (i=0; s[i]!='\0' && e!=3; i++)
	{
		e = tt [e][Columna(s[i])];
	}	
		
	return e==2; /* estado final? retorna 1 */
} 