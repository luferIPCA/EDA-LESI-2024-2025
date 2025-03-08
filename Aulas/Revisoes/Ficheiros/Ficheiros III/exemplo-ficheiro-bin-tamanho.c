/*
	Name:  exemplo ficheiro binário: mover o indicador de posição do ficheiro
	Author: ESI-LP1-1718
	Date: 06/12/17 14:00
	Description:  exemplo calcular o tamanho ocupado pelo ficheiro
*/

#include <stdio.h>
#pragma warning( disable : 4996 ) //evita MSG ERROR: _CRT_SECURE_NO_WARNINGS

int main5(){
  FILE *af;
  char *nomeFicheiro="temperaturasSemana10.dat";
  long int tamanho;

  af = fopen(nomeFicheiro,"rb");
  if (af == NULL)
    printf("Erro na abertura do ficheiro %s.\n",nomeFicheiro);
  else if (fseek(af,0,SEEK_END) != 0) {
    printf("Erro na colocacao no final do ficheiro %s.\n",
        nomeFicheiro);
  } else {
    tamanho = ftell(af);	//número de bytes do ficheiro
    printf("O ficheiro ocupa %ld bytes com %ld valores\n",
        tamanho, tamanho/sizeof(double));
  }
  getche();
  return 0;
}
