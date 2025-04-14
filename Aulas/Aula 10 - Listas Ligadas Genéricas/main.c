/*!
 *  @file main.c
 *  @author mustl
 *  @date 2025-04-14
 *  @project Aula 10 - Listas Ligadas Genéricas
 *
 *  Demonstra Lista LIgadas Genéricas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"
#include "Jogos.h"

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

void main()
{


#pragma region ListasGenericas

	ListElem* listaMaquinas = NULL;

	ListElem* listaOperacoes = NULL;

	ListElem* lista = NULL;

	Jogador j;

	j = (Jogador) malloc(sizeof(struct Dados));
	j->numero = 1;
	strcpy(j->nome,"Sara");
	 strcpy(j->preferencias[0].arma,"sniper");
	 j->preferencias[0].pontuacao = 87;
	 strcpy(j->preferencias[1].arma,"pistola");
	 j->preferencias[1].pontuacao = 67;
	 strcpy(j->preferencias[2].arma,"metralhadora");
	 j->preferencias[2].pontuacao = 57;
	 strcpy(j->preferencias[3].arma,"-");
	 j->preferencias[3].pontuacao = 0;
	 strcpy(j->preferencias[4].arma,"-");
	 j->preferencias[4].pontuacao = 0;
	 
	 lista = addItemHead(lista,j);

	 //lista = addItemOrderedIterative(lista, j, &compararNomes);

	 j = (Jogador) malloc(sizeof(struct Dados));
	 j->numero = 3;
	 strcpy(j->nome,"Bruno");
	 strcpy(j->preferencias[0].arma,"metralhadora");
	 j->preferencias[0].pontuacao = 77;
	 strcpy(j->preferencias[1].arma,"sniper");
	 j->preferencias[1].pontuacao = 79;
	 strcpy(j->preferencias[2].arma,"-");
	 j->preferencias[2].pontuacao = 0;
	 strcpy(j->preferencias[3].arma,"-");
	 j->preferencias[3].pontuacao = 0;
	 strcpy(j->preferencias[4].arma,"-");
	 j->preferencias[4].pontuacao = 0;
	 //lista = addItemHead(lista,j);
	 lista = addItemOrderedIterative(lista, j, &compararNomes);

	 j = (Jogador) malloc(sizeof(struct Dados));
	 j->numero = 2;
	 strcpy(j->nome,"Jose");
	 strcpy(j->preferencias[0].arma,"sniper");
	 j->preferencias[0].pontuacao = 87;
	 strcpy(j->preferencias[1].arma,"pistola");
	 j->preferencias[1].pontuacao = 67;
	 strcpy(j->preferencias[2].arma,"metralhadora");
	 j->preferencias[2].pontuacao = 57;
	 strcpy(j->preferencias[3].arma,"-");
	 j->preferencias[3].pontuacao = 0;
	 strcpy(j->preferencias[4].arma,"-");
	 j->preferencias[4].pontuacao = 0;
	// lista = addItemHead(lista,j);
	 lista = addItemOrderedIterative(lista, j, &compararNomes);

	 // Escrita na consola do conteúdo da lista ligada
	 showListIterative(lista,&show);
 
	 printf("-----------------------------------------------------------\n");
	 int numero = 2;
	 // Remoção da primeiro ocorrência do registo com número de jogador 2
	 lista = removeItemIterative(lista,&numero,&igual);
 
	 // Escrita na consola do conteúdo da lista ligada
	 showListIterative(lista,&show);

#pragma endregion


}
