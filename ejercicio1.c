#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int esNumero() --- serìa si es alguno de los 3 de abajo
// int esDecimal()
// int esHexadecimal()
// int esOctal()

int main(int argc, char *argv[])
{
    char str[80] = "123&0x25F&A48&0365";
  	char *token;
  	token = strtok(str, "&");
  	
    while(token!= NULL) 
   	{
      printf( "%s \n",token);


// ACA TIENE QUE RECONOCER CADA TIPO DE NUMERO,
// contar cuantos de cada tipo y
// decir si hay algun token erroneo


      token = strtok(NULL, "&");
   	}
       system("pause");
       return 0;
}

