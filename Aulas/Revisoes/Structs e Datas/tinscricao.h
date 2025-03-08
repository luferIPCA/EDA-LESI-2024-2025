/*
author: oribeiro & lufer
Estruturas de dados
*/

#ifndef DADOS
#define DADOS

#include <stdbool.h>
#include "tdata.h"

typedef struct TINSC {
      char nome[50];
      TDATA dataNasc; 
}  TINSC;


typedef enum meses_do_ano {
	Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho,
	Julho, Agosto, Setembro, Outubro, Novembro, Dezembro
}meses;

typedef enum ENUM_TESCALAO { JUNIOR, M18, M35, M50 } TESCALAO;

TESCALAO determinaEscalao(TINSC insc);
void escreveInscricao(TINSC insc);

/* guarda os dados das inscrições num ficheiro binário */
bool gravarInscricoesBinario(char *nomeFicheiro, TINSC prova[], int n);

/* ler inscricoes de um ficheiro binario */
int lerInscricoesBinario(char *nomeFicheiro, TINSC prova[]);


#endif // !DADOS
