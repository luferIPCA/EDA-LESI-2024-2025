/*
* author: lufer
* email: lufer@ipca.pt
* date: 2025
* desc: Definição de Assinaturas, #defines, typedef
*/

//#pragma once
#ifndef X
#define X 1

#include <stdbool.h>

int* changeValue(const int* p);
int* Maior(int* p, int* q);
int get(int* ptr);
bool ExisteValorPosicao(int v[], int n, int valor, int* pos);

#define N 20
typedef struct Pessoa {
	int idade;
	char nome[N];
	struct Pessoa* primo;
}Pessoa;


typedef struct DATA {
	int dia, mes, ano;
}  DATA;

typedef struct Jogo {
	int cod;
	char nome[N];
	char tipo;
	DATA data;
}Jogo;

int InsereJogo(Jogo* jogos[], Jogo j, int pos);


#endif  // !X