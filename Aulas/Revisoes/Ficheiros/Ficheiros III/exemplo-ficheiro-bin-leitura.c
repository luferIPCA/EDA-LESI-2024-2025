/*
	Name:  exemplo ficheiro binário: leitura
	Author: ESI-LP1-1718
	Date: 06/12/17 14:00
	Description:   leitura a partir de um ficheiro binário dos valores das temperaturas médias diárias nos últimos 7 dias
*/
#include <stdio.h>

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

int main4(){
  FILE *af;
  char *nomeFicheiro="temperaturasSemana10.dat";
  int nlidos, i;
  double temperaturas[7];

  /* abertura do ficheiro em modo binario para leitura*/
  af = fopen(nomeFicheiro,"rb");

  if (af == NULL)
     printf("Erro na abertura do ficheiro %s.\n",nomeFicheiro);
  else{

     nlidos=fread(&temperaturas[0], sizeof(double), 7, af);	

     if (nlidos == 0)
        printf("Nao foi lido nenhum elemento!\n");
     else{
        if (nlidos < 7)
          printf("Lidos apenas %d elementos!\n",nlidos);
        for(i=0; i<nlidos; i++)
           printf("temperaturas[%d]=%.2f\n",i,temperaturas[i]);
		//printf("Idade= %d\n", x.idade);
        fclose(af);
      }
  }
  getche();
  return 0; 

}
