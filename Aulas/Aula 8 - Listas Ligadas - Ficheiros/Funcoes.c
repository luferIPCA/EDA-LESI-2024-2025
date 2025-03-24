/*!
 *  @file Funcoes.c
 *  @author mustl
 *  @date 2025-03-21
 *  @project Aula 8 - Listas Ligadas - Ficheiros
 *
 *  Implementa funcoes.
 *      Alterar
 *      Remover
 *      Gravar em ficheiro
 *      Carregar de ficheiro
 */

#include "Dados.h"

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
	while (aux && aux->value < v) {
		aux = aux->prox;
	}
	if (aux && aux->value == v) return aux;	//valor encontrado
	return NULL;
}


Element* CriaElemento(int v, char* nome) {
	Element* aux;

	aux = (Element*)malloc(sizeof(Element));
	if (aux != NULL) {
		aux->value = v;
		aux->prox = NULL;
		//strcpy(aux->nome, nome);
	}
	return aux;
}

/*!
 *  Insere Ordenado sem admitir repetições.
 *
 *      @param [in,out] inicio
 *      @param [in,out] novo
 *
 *      @return
 */
Element* InsereOrdenado(Element* inicio, Element* novo) {

	//validações
	if (novo == NULL) return inicio;
	//Se já existe, não insere
	if (ProcuraElemento(inicio, novo->value)) return inicio;

	//procurar a posição
	//1ª posição
	if (inicio == NULL) {
		inicio = novo; return inicio;
	}
	if (inicio->value > novo->value) {
		novo->prox = inicio;
		inicio = novo;
	}
	//procura posição
	Element* aux = inicio;
	Element* aux2 = aux;
	while (aux->value < novo->value && aux->prox != NULL)
	{
		aux2 = aux;
		aux = aux->prox;
	}
	//se for na última posição
	if (aux->value < novo->value)
		aux->prox = novo;
	else
	{
		novo->prox = aux;
		aux2->prox = novo;
	}
	return inicio;
}

 /**
 * @brief Altera dados do Elemento
 * @param [in]	h	Apontador para inicio da Lista
 * @param [in]	cod	Codigo do elemento a alterar
 * @param [in]	novoNome	novo nome para o elemento
 * @return	Apontador para Lista
 */
Element* AlteraElement(Element* h, int v, char*novoNome) {
	Element* aux = ProcuraElemento(h, v);
	if (aux != NULL)		//se encontrou o Element
	{
		strcpy(aux->nome, novoNome);
	}
	return h;
}

Element* RemoveElement(Element* h, int cod) {
	if (h == NULL) return NULL;			//Lista vazia
	//if (!ProcuraElemento(h, cod)) return h;	//se não existe

	if (h->value == cod) {		//remove no inicio da lista
		Element* aux = h;
		h = h->prox;
		free(aux);
	}
	else
	{
		Element* aux = h;
		Element* auxAnt = aux;
		while (aux && aux->value != cod) {	//procura para revover
			auxAnt = aux;
			aux = aux->prox;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->prox = aux->prox;
			free(aux);
		}
	}
	return h;
}

/**
* @brief Remove Element de forma Recursiva. Còdigo indexado pelo seu código (cod)
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	cod	Codigo do Element a alterar
* @return	Apontador para Lista
*/
Element* RemoveElementRecursivo(Element* head, int cod) {
	Element* aux;

	if (head == NULL)
		return NULL;

	if (head->value == cod) {
		aux = head;
		head = head->prox;
		free(aux);
	}
	else {
		head->prox = RemoveElementRecursivo(head->prox, cod);
	}
	return head;
}

/**
* @brief Ordena Lista
* @param [in]	h	Apontador para inicio da Lista
* @return	Apontador para Lista ordenada
*/
Element* OrdenaLista(Element* h) {
	if (h == NULL) return NULL;
	Element* listaOrdenada = NULL;
	Element* aux = h;
	Element* novo;
	while (aux) {
		novo = CriaElemento(aux->value, aux->nome);
		listaOrdenada = InsereOrdenado(listaOrdenada, novo);
		aux = aux->prox;
	}
	return listaOrdenada;
}


/**
* @brief Destroi todos os nodos da lista
* @param [in]	h	Apontador para inicio da Lista
*/

void DestroiLista(Element** h) {
	if (h != NULL) {
		Element* aux;
		while (*h) {
			aux = *h;
			*h = (*h)->prox;
			free(aux);
		}
	}
}

//ou

Element* DestroiListaII(Element* h) {
	if (h != NULL) {
		Element* aux;
		while (h) {
			aux = h;
			h = h->prox;
			free(aux);
		}
	}
}


#pragma region FICHEIROS

// ========================= Ficheiros ============================
//Ver : https://www.geeksforgeeks.org/readwrite-structure-file-c/

/**
* @brief Preservar dados em ficheiro
* Grava todos os nodos da Lista em Ficheiro
*/
bool GravarElementBinario(char* nomeFicheiro, Element* h) {
	FILE* fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava todos registos da lista no ficheiro
	Element* aux = h;
	ElementFile auxElement;	//struct auxiliar para gravar em ficheiro!
	while (aux) {			//while(aux!=NULL)
		//Colocar no registo de ficheiro a inf que está no registo de memória
		auxElement.value = aux->value;
		strcpy(auxElement.nome, aux->nome);
		fwrite(&auxElement, sizeof(ElementFile), 1, fp);
		aux = aux->prox;
	}
	fclose(fp);
	return true;
}

/**
* @brief Lê informação de ficheiro
*/
Element* LerElementsBinario(char* nomeFicheiro) {
	FILE* fp;
	Element* h = NULL;
	Element* aux;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	//lê n registos no ficheiro
	ElementFile auxElement;
	while (fread(&auxElement, sizeof(ElementFile), 1, fp)) {
		//printf("Element=%s\n", auxElement.nome);
		aux = CriaElemento(auxElement.value, auxElement.nome);
		h = InsereOrdenado(h, aux);
	}
	fclose(fp);
	return h;
}
#pragma endregion
