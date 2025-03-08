/*
* Estruturas de Dados 
*/

#pragma once

#include <stdbool.h>

#pragma warning (disable: 4996)

#define N 50
/// <summary>
/// Estrutura para guardar informação em ficheiro. Não deve guardar apontadores!
/// </summary>
typedef struct ValorFicheiro {
	int v;
	char nome[N];
}ValorFicheiro;

/// <summary>
/// Estrutura para guardar informação em Lista na memória. Tem apontadores
/// </summary>
typedef struct Valor {
	struct Valor* proximo;
	int v;
	char nome[N];
}Valor, * PtrValor;
