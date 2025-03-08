/*
* Métodos para gerir Arrays e Listas Simples
*/

#include "Dados.h"
#include <stdio.h>

#pragma region METODOS_ARRAYS

/// <summary>
/// Verifica se valor existe num array
/// </summary>
/// <param name="valores"></param>
/// <param name="n"></param>
/// <param name="novo"></param>
/// <returns></returns>
bool Existe(int valores[], int n, int novo) {
	bool encontrou = false;
	for (int i = 0; i < n; i++) {
		if (valores[i] == novo) {
			encontrou = true;
			break;
		}
	}
	return(encontrou);
}

/// <summary>
/// Insere um valor num array
/// </summary>
/// <param name="valores"></param>
/// <param name="tot"></param>
/// <param name="novo"></param>
/// <returns></returns>
int InsereFinal(int valores[], int tot, int novo) {
	//Verificar outras regras..
	valores[tot] = novo; tot++;
	return tot;
}

#pragma endregion


#pragma region METODOS_LISTAS

/// <summary>
/// Verifica se existe valor numa lista
/// </summary>
/// <param name="valor"></param>
/// <param name="h"></param>
/// <returns></returns>
bool ExisteLista(int valor, Valor* h) {
	bool encontrou = false;
	if (h != NULL)
	{
		Valor* auxLista = h;
		while (auxLista != NULL) {
			if (auxLista->v == valor) {
				encontrou = true;
				break;
			}
			auxLista = auxLista->proximo;
		}
	}
	return encontrou;
}

/// <summary>
/// Insere valor numa lista ligada simples
/// </summary>
/// <param name="novoValor"></param>
/// <param name="head"></param>
/// <returns></returns>
Valor* InsereInicioLista(Valor* novoValor, Valor* head) {
	novoValor->proximo = head;
	head = novoValor;
	return head;
}

/// <summary>
/// Apresenta conteúdo de toda a lista
/// </summary>
/// <param name="head"></param>
void MostraLista(Valor* head) {
	Valor* aux = head;
	while (aux) {
		printf("Num: %d - Nome: %s\n", aux->v, aux->nome);
		aux = aux->proximo;
	}
}

#pragma region FICHEIROS
/// <summary>
/// Grava Lista em Ficheiro
/// </summary>
/// <param name="fileName"></param>
/// <param name="h"></param>
/// <returns></returns>
bool GravaFicheiro(char fileName[], Valor* h)
{
	FILE* fp = fopen(fileName, "wb");
	if (fp != NULL) {
		Valor* auxLista = h;
		ValorFicheiro auxFile;
		while (auxLista != NULL) {
			//copia valores da memória para celula do ficheiro
			auxFile.v = auxLista->v;
			strcpy(auxFile.nome, auxLista->nome);
			//Grava célula no ficheiro
			fwrite(&auxFile, sizeof(ValorFicheiro), 1, fp);
			//avança para próximo da lista
			auxLista = auxLista->proximo;
		}
		fclose(fp);
		return true;
	}
	return false;
}

/// <summary>
/// Evita nova estrutura...
/// </summary>
/// <param name="fileName"></param>
/// <param name="h"></param>
/// <returns></returns>
bool GravaFicheiroII(char fileName[], Valor* h)
{
	FILE* fp = fopen(fileName, "wb");
	if (fp != NULL) {
		Valor* auxLista = h;
		Valor* temp = h;
		while (auxLista != NULL) {
			//copia valores da memória para celula do ficheiro
			//auxFile.v = auxLista->v;
			//strcpy(auxFile.nome, auxLista->nome);
			temp->proximo = auxLista->proximo;
			auxLista->proximo = NULL;
			fwrite(auxLista, sizeof(ValorFicheiro), 1, fp);
			auxLista = temp->proximo;
			//auxLista = auxLista->proximo;
		}
		fclose(fp);
		return true;
	}
	return false;
}

/// <summary>
/// Le toda a informação do ficheiro para a lista em memória
/// </summary>
/// <param name="fileName"></param>
/// <param name="h"></param>
/// <returns></returns>
Valor* LeFicheiro(char fileName[], Valor* h) {
	Valor* aux;
	ValorFicheiro auxFile;
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL)
		return h;
	aux = (Valor*)calloc(1, sizeof(Valor));
	while (fread(&auxFile, sizeof(ValorFicheiro), 1, fp) != NULL) {
		//copiar da celula do ficheiro para a celula da memoria
		aux->v = auxFile.v;
		strcpy(aux->nome, auxFile.nome);
		//Insere nova celula na lista
		h = InsereInicioLista(aux, h);
		//criar nova celula em memória
		aux = (Valor*)calloc(1, sizeof(Valor));
	}
	fclose(fp);
	return h;
}
#pragma endregion

#pragma endregion
