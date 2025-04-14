/*****************************************************************//**
 * @file   Jogos.c
 * @brief  
 * 
 * @author lufer
 * @date   April 2025
 *********************************************************************/
#include "Jogos.h"
#include "ll.h"

// Implementações

// Escrita na consola do dados de um jogador
void show(void* data)
{
	Jogador j = (Jogador)data;
	if (j != NULL)
		printf("%d %s ", j->numero, j->nome);
	for (int i = 0; i < 5; i++)
		printf("%s %d ", j->preferencias[i].arma, j->preferencias[i].pontuacao);
	printf("\n");
}

// Se iguais devolve 0
// se número do jogador referenciado por data1 for inferior devolve -1
// caso contrário 1
int comparar(void* data1, void* data2)
{
	Jogador d1 = (Jogador)data1;
	Jogador d2 = (Jogador)data2;
	if (d1->numero < d2->numero) return(-1);
	else if (d1->numero > d2->numero) return(1);
	else return(0);
}

int compararNomes(void* data1, void* data2)
{
	Jogador d1 = (Jogador)data1;
	Jogador d2 = (Jogador)data2;
	return(strcmp(d1->nome, d2->nome));
}


// Se iguais devolve 1 senão devolve 0
int igual(void* data1, void* data2)
{
	Jogador d1 = (Jogador)data1;
	int* d2 = (int*)data2;
	if ((d1 != NULL) && (d2 != NULL)) return(d1->numero == *d2);
	else return(0);
}