/*
Funções para manipular arrays de apontadores para structs
lufer@ipca.pt

Ver:
https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#ifndef DADOS
#define DADOS

#include <stdbool.h>
#include "Data.h"
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#define N 20
#define MAX 10		//máximo de jogos

typedef struct Jogo {
	int cod;
	char nome[N];
	char tipo;
	DATA data;
}Jogo;


int InsereJogo(Jogo *jogos[], Jogo j, int pos);
int InsereJogoII(Jogo *jogos[], Jogo* j, int pos);
void MostraJogos(Jogo jogos[], int t);
void MostraJogosII(Jogo* jogos[], int t);
bool InicializaArray(Jogo* jogos[], int n);

/*Verifica se determinado jogo existe*/
bool ExisteJogo(Jogo* jogos[], int cod, int n);


Jogo* criaJogo(int cod, char* nome, char tipo);
#endif //
