/*
* lufer
* Implementação de funções
*/
#include "Funcoes.h"
#include <stdio.h>

/// <summary>
/// Procura a posição onde se encontra o aluno com o numero
/// </summary>
/// <param name="alunos"></param>
/// <param name="n"></param>
/// <param name="numero"></param>
/// <returns></returns>
int ProcuraPosicao(Pessoa alunos[], int n, int numero) {
	int pos = 0;
	while (pos < n) {
		if (alunos[pos].numero == numero)
			return  pos;
		pos++;
	}
	return -1;
}

/// <summary>
/// Encontra uma pessoa; remove e devolve a ficha dela!
/// O total de valores decrementa;
/// </summary>
/// <param name="alunos"></param>
/// <param name="n"></param>
/// <param name="numero"></param>
/// <returns></returns>
Pessoa RemovePessoa(Pessoa alunos[], int *n, int numero) {
	//1ª fase: encontrar a pessoa
	Pessoa aux;
	aux.numero = -1;

	int i = 0;
	while (i < *n) {
		if (alunos[i].numero == numero) {
			//"Apagar" a pessoa do array - desloca tudo uma casa para a esquerda
			int j = i + 1;
			aux = alunos[i];	//preserva celula a remover
			while (j < *n) {
				alunos[i] = alunos[j];
				j++;
				i++;
			}
			(*n)--;
			break;
		}
	}
	return aux;					//devolve celula removida
}

#pragma region Listas

Pessoa* CriaPessoa(int numero, char nome[], Sexo s) {
	Pessoa *q = (Pessoa*)malloc(sizeof(Pessoa));
	strcpy(q->nome, nome);
	q->numero = numero;
	q->sexo = s;
	q->next = NULL;
	return q;
}

#pragma endregion