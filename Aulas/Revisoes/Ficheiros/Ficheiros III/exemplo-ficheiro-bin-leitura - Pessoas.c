/*
	Name:  exemplo ficheiro binário: leitura
	Author: ESI-LP1-1718
	Date: 06/12/17 14:00
	Description:   leitura a partir de um ficheiro binário dos valores das temperaturas médias diárias nos últimos 7 dias
*/
#include <stdio.h>
#include "Dados.h"

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS


#define N 2

int main(){
  FILE *af;
  char *nomeFicheiro="Pessoas.dat";
  int nlidos, i;

  P pessoas[N];

  /* abertura do ficheiro em modo binario para leitura*/
  af = fopen(nomeFicheiro,"rb");

  if (af == NULL)
     printf("Erro na abertura do ficheiro %s.\n",nomeFicheiro);
  else{
	 int i = 0;
	 while (fread(&pessoas[i++], sizeof(P), 1, af) == 1);
	 
	 nlidos = i-1;

     if (nlidos == 0)
        printf("Nao foi lido nenhum elemento!\n");
     else{
          printf("Lidos apenas %d elementos!\n",nlidos);
			for (int i = 0; i < nlidos; i++) {
				printf("Idade=%d Nome=%s\n", pessoas[i].idade, pessoas[i].nome);
			}
        fclose(af);
      }
  }
  getche();
  return 0; 

}
