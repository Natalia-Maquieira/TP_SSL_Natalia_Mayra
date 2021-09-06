#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Verifica (char *); /* que los caracteres pertenezcan al alfabeto */
//int esNumero() --- serìa si es alguno de los 3 de abajo
int esDecimal(const char *);
 int esHexadecimal(const char *);
 int esOctal(const char *);

int main(int argc, char *argv[])
{
    int contadorNroDecimales = 0;
    int contadorNroOctales = 0;
    int contadorNroHexadecimales = 0;
    char str[80] = "123&0x25F&A48&0365";
  	char *token;
  	token = strtok(str, "&");
  	
    while(token!= NULL) 
   	{
      printf( "%s \n",token);

    if (esDecimal(str)){
        contadorNroDecimales = contadorNroDecimales + 1;
    }
     if (esOctal(str)){
        contadorNroOctales = contadorNroOctales + 1;
    }
    if (esHexadecimal(str)){
        contadorNroHexadecimales = contadorNroHexadecimales + 1;
    }
// ACA TIENE QUE RECONOCER CADA TIPO DE NUMERO,
// contar cuantos de cada tipo y
// decir si hay algun token erroneo


      token = strtok(NULL, "&");
   	}
       system("pause");
       return 0;
}

int Verifica(char *s) {
	unsigned i;
	for (i=0; s[i]; i++)
	{
		if (!(isdigit(s[i]) || s[i] == '+' 
			 || s[i] == '-')) 
			 
		return 0;
	}
return 1;
} 
