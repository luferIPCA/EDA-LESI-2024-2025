/*
	Name:  exemplo ficheiro binário: escrita
	Author: ESI-LP1-1718
	Date: 06/12/17 14:00
	Description:   ler os valores das temperaturas médias diárias nos últimos 7 dias,
                   guardando os esses valores num ficheiro binário
*/
#include <stdio.h>
#include "Dados.h"

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS


#define N 2

int main6(){
  FILE *af;
  char *nomeFicheiro="Pessoas.dat";
  int nescritos, i;

   P pessoas[N] = { { 12,"ola" },{ 24 ,"ole"} };


  /* abertura do ficheiro em modo binario para escrita*/
  af = fopen(nomeFicheiro,"wb");	
  if (af == NULL)
     printf("Erro na abertura do ficheiro %s.\n",nomeFicheiro);	
  else{
		for (int i = 0; i < N; i++) {
			printf("Idade=%d\n", pessoas[i].idade);
			fwrite(&pessoas[i], sizeof(P), 1, af);	
		}
	fclose(af);  
	
  }  

  getche();  
  return 0; 
}
