/*
	Name:  exemplo ficheiro binário: escrita
	Author: ESI-LP1-1718
	Date: 06/12/17 14:00
	Description:   ler os valores das temperaturas médias diárias nos últimos 7 dias,
                   guardando os esses valores num ficheiro binário
*/
#include <stdio.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS


int main2(){
  FILE *af;
  char *nomeFicheiro="temperaturasSemana10.dat";
  int nescritos, i;
  double temperaturas[7];

  for(i=0; i<7; i++){
     printf("temperatura do dia %d: ", i+1);
     scanf("%lf",&temperaturas[i]);     
  }
  /* abertura do ficheiro em modo binario para escrita*/
  af = fopen(nomeFicheiro,"wb");

  if (af == NULL)
     printf("Erro na abertura do ficheiro %s.\n",nomeFicheiro);
  else{
     nescritos=fwrite(&temperaturas[0], sizeof(double), 7, af);
     if (nescritos == 0)
        printf("Nao foi escrito nenhum elemento!\n");
     else
	 {
        if (nescritos < 7)
           printf("Escritos apenas %d elementos!\n",nescritos);
        fclose(af);
     } 
  }
  getche();
  return 0; 
}
