#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int esDecimal(char termino[]){
    return 1;
}

int resolverRestaYMultip(char termino[]){
    int resultado=0;

  	char *token;
  	token = strtok(termino, "-");
    int contador=1;
  	int nro;
    while(token!= NULL) 
   	{
            if (esDecimal(token)){
                nro = atoi(token);
                if (contador==1)
                    resultado += nro;
                else 
                    resultado -= nro;
                    }
            else{
                if (contador==1)
                    resultado += resolverMultip(token);
                else 
                    resultado -= resolverMultip(token);
                    }

            token = strtok(NULL, "-");
            contador ++;
   	}

    return resultado;
};


int resolverMultip(char termino[]){
    int resultado=0;
  	char *token;
  	token = strtok(termino, "*");
    int contador=1;
  	int nro; 
     
    while(token!= NULL) 
   	{
            if (esDecimal(token)){
                nro = atoi(token);
                if (contador==1)
                    resultado += nro;
                else 
                    resultado *= nro;
                    }
            else{
                printf("La expresion %s no es un numero decimal \n",token);
                    }

            token = strtok(NULL, "");
            contador ++;
   	}

    return resultado;
};


int main(int argc, char *argv[])
{
    char operacion[80] = "3-4*7+3-5";
    int resultado = 0;

  	char *token;
  	token = strtok(operacion, "+");
  	int nro;
    int nroASumar;

    while(token!= NULL) 
   	{
            if (esDecimal(token)){
                nro = atoi(token);
                resultado += nro;}
            else{
                nroASumar = resolverRestaYMultip(token);
                resultado += nroASumar;
            }
      token = strtok(NULL, "+");
   	}
       printf("El resultado de la operacion es %d \n",resultado);
       system("pause");
       return 0;
}