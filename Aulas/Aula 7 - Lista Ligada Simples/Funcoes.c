/*!
 *  @file Funcoes.c
 *  @author mustl
 *  @date 2025-03-14
 *  @project Aula 7 - Lista Ligada Simples
 *
 *  Implementa funcoes.
 *
 *
 *
 */

#include "Dados.h"
#include "Funcoes.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#pragma region A
Element* CriaElemento(int v, char* nome) {
	Element* aux;

	aux = (Element*)malloc(sizeof(Element));
	if (aux!=NULL) {
		aux->value = v;
		aux->prox = NULL;
		//strcpy(aux->nome, nome);
	}
	return aux;
}


#pragma endregion

/*!
 *  Cria element.
 *
 *      @param [in] v 
 *
 *      @return 
 */
Element* CriaElement(int v) {
	Element* aux;
	aux = (Element*)malloc(sizeof(Element));
	if (aux != NULL) {
		aux->value = v;
		aux->prox = NULL;
	}
	return (aux);
}


Element* InsereInicio(Element* inicio, Element* novo) {
	//validar parametros
	if (novo == NULL) return inicio;//Não há nada para inserir
	//h1
	novo->prox = inicio;
	inicio = novo;

	//h2
	/*
	if (!inicio) //ou if(inicio==NULL)
	{
		inicio = novo;	//primeiro elemento da lista!
	}
	else {
		novo->prox = inicio;
		inicio = novo;
	}
	*/

	return inicio;
}


Element* InsereFim(Element* inicio, Element* novo) {
	Element* aux = inicio;
	//se a lista for vazia
	if (inicio == NULL) {
		inicio = novo; 
		return inicio;
	}
	//senão coloca-se no fim da lista...
	while (aux->prox != NULL) aux = aux->prox;
	//insere no fim
	aux->prox = novo;

	return inicio;
}


/*!
 *  Mostra lista sem retorno de controlo
 *
 *      @param [in,out] ini 
 */
void MostraTudo(Element* ini) {
	Element* aux = ini;
	while (aux) {
		printf("Valor: %d", ini->value);
		aux = aux->prox;
	}
}

/*!
 *  Mostra lista com retorno de controlo
 *
 *      @param [in,out] h 
 *
 *      @return 
 */
int MostraLista(Element* h) {
	Element* aux = h;
	if (!h) return 0;

	while (aux != NULL) {
		printf("v=%d\n", aux->value);
		aux = aux->prox;
	}
	return 1;
}

/*!
 *  Procura elemento.
 *
 *      @param [in,out] h 
 *      @param [in]     v 
 *
 *      @return 
 */

Element* ProcuraElemento(Element* h, int v) {
	Element* aux = h;
	while (aux && aux->value<v) {
		aux = aux->prox;
	}
	if (aux && aux->value == v) return aux;	//valor encontrado
	return NULL;
}

/*!
 *  Procura elemento e devolve bool caso existe ou não
 *
 *      @param [in,out] h
 *      @param [in]     v
 *
 *      @return
 */
bool ExisteElemento(Element* h, int v) {
	Element* aux = h;
	while (aux && aux->value < v) {
		aux = aux->prox;
	}
	if (aux && aux->value == v) return true;	//valor encontrado
	return false;
}

/*!
 *  Procura elemento Recursivo! Devolve bool caso existe ou não
 *
 *      @param [in,out] h
 *      @param [in]     v
 *
 *      @return
 */
bool ExisteElementRecursivo(Element* h, int v) {
	if (h == NULL) return false;
	if (h->value == v) return true;
	return (ExisteElementRecursivo(h->prox, v));
}


/*!
 *  Insere Ordenado mas não testa se existem repetições.
 *
 *      @param [in,out] inicio
 *      @param [in,out] novo
 *
 *      @return
 */
Element* InsereOrdenado(Element* inicio, Element* novo) {
	//Validações
	if (novo == NULL) return inicio;
	//se a lista for vazia
	if (inicio == NULL)
	{
		inicio = novo;
		//ou
		// inicio = InsereInicio(inicio, novo);
		return inicio;
	}
	//restantes situações
	//procurar a posição correta
	Element* aux = inicio;
	Element* aux2 = aux;

	while ((aux->value < novo->value) && aux->prox != NULL)
	{
		aux2 = aux;
		aux = aux->prox;
	}
	//verfica se insere no fim
	if (aux->value < novo->value)
		aux->prox = novo;
	//ou
	//inicio = InsereFim(inicio, novo);
	else {				//insere entre elementos
		aux2->prox = novo;
		novo->prox = aux;
	}
	return inicio;
}

/*!
 *  Insere Ordenado sem admitir repetições.
 *
 *      @param [in,out] inicio 
 *      @param [in,out] novo   
 *
 *      @return 
 */
Element* InsereOrdenadoII(Element* inicio, Element* novo) {

	//validações
	if (novo == NULL) return inicio;
	//Se já existe, não insere
	if (ExisteElemento(inicio,novo->value)) return inicio;

	//procurar a posição
	//1ª posição
	if (inicio == NULL) {
		inicio = novo; return inicio;
	}
	if (inicio->value > novo->value) {
		novo->prox = inicio;
			inicio = novo;
	}


	Element* aux = inicio;
	Element* aux2 = aux;
	while (aux->value < novo->value && aux->prox != NULL)
	{
		aux2 = aux;
		aux = aux->prox;
	}

	//Se for na última posição
	if (aux->value < novo->value)
		aux->prox = novo;
	else
	{
		novo->prox = aux;
		aux2->prox = novo;
	}

	return inicio;
}

//Remover!!! TPC

#pragma region B


