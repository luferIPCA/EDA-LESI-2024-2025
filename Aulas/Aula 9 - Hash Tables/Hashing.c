//-----------------------------------------------------------------------
// <copyright file="Hashing.c" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2025</date>
// <author></author>
// <email></email>
// <version></version>
// <desc>Biblioteca para manipular Tabelas de Hash</desc>
// <obs>
// https://cp-algorithms.com/string/string-hashing.html#:~:text=The%20good%20and%20widely%20used%20way%20to%20define,It%20is%20called%20a%20polynomial%20rolling%20hash%20function.
// </obs>
//-----------------------------------------------------------------------

//Tabela de Hash : array de heads de listas!

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#pragma region ABORDAGEM 1

/*!
 *  Creates and  inicialize the hash.
 *
 *      @param [in] n 
 *
 *      @return 
 */
Node** CriaHash(int n) {
	Node**aux = (Node**)malloc(n * sizeof(Node*));
	//Node** aux = (Node**)calloc(n, sizeof(Node*)); inicializa a NULL

	return aux;
}

/*
Inicia a Tabela de Hash
*/
bool IniciaHash(Node **ht, int n) {
	int i;
	if (ht == NULL || n <= 0) return false;
	for (i = 0; i < n; i++) {
		ht[i] = NULL;
	}
	return true;
}

/*
Inicia a Tabela de Hash
*/
Node ** IniciaHashII(Node **ht) {
	int i;
	if (ht != NULL) {
		for (i = 0; i < MAX; i++) {
			ht[i] = NULL;
		}
	}
	return ht;
}

/*
Função de Hashing baseada em texto
*/
int Hash( char* palavra) {
	//h1: Primeiro caracter da string é "key"
	//int res = ((int)palavra[0]) % MAX;			//(int)palavra[0]-'A')
	//return res;

	//h2
	//int res = ToUpperCase(palavra[0]) % MAX;
	//return res;

	//h3;	
	/*int tot = 0;
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		tot += (int)palavra[i];
	}
    */

	//h4
	//int i = 0;
	//int tot = 0;
	//while (palavra[i]!='\0')
	//{
	//	tot += (int)palavra[i];
	//	i++;
	//}
	

	//h5
	int tot = 0;
	char* aux = palavra;
	while (*aux != '\0') {
		tot += (int)*aux;
		aux++;
	}
	return(tot % MAX);
}

/*
Hashing dependente de chaves do tipo numérico
*/
int HashII(int val) {
	if (val > 0)
		return (val % MAX);
	return 0;
}

/*
Insere elemento na Tabela de Hash
ATENÇÃO: REVER para receber "Celula" já criada
*/
Node** InsertValHash(char* autor, Node** ht) {

	//Cria nova celula para a lista
	Node* item = (struct Node*)malloc(sizeof(struct Node));
	if (!item) return ht;
	item->val = autor;
	item->next = NULL;

	//Neste caso assume-se inserir  sempre no início da lista
	ht = InsertNodeHash(item, ht);
	return ht;
}

/*
Insere elemento na Tabela de Hash
Insere ordenado na Lista
*/
Node ** InsertNodeHash(Node* item, Node *ht[]) {

	//get the hash 
	int pos = Hash(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}
	return ht;
}

/*
Array alterado diretamente via parametros
Insere ordenado na Lista
*/

void InsertNodeHashVoid(Node* item, Node *ht[]) {

	//get the hash 
	int pos = Hash(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}

}

/*
Array alterado diretamente via parametros
Insere ordenado na Lista
*/
bool InsertNodeHashBool(Node* item, Node **ht) {

	//get the hash 
	int pos = Hash(item->val);

	Node *h = ht[pos];
	if (h == NULL)			//é  o primeiro nodo da lista
		ht[pos] = item;
	else                    //gerir colisões
	{
		ht[pos] = InsertNode(item, ht[pos]);
	}
	return true;
}

/*
Procura elemento na Hash
*/
Node* FindNode(char val[], Node* ht[]) {
	int pos = Hash(val);
	if (ht[pos] == NULL) return NULL;
	return (Find(val, ht[pos]));		//Procura na respetiva lista
}

/*
Limpa Tabela de Hash
*/
Node ** Cleanup(Node *ht[]) {
	int i;
	for (i = 0; i < MAX; i++) {
		if (ht[i] != NULL) {
			ht[i] = DeleteAll(ht[i]);	//ht[i] é head da lista
		}
	}
	return ht;
}

/*
Mostra a Hash
*/
void ShowHash(Node *ht[])
{
	for (int i = 0; i < MAX; i++) {
		if (ht[i] != NULL)
		{
			printf("Index: %d \t", i);
			ShowList(ht[i]);
		}
	}
}

bool SaveHash(Node** h, char* fileName) {
	FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) return false;
	bool r = false;
	for (int i = 0; i < MAX; i++) {
		if (h[i] != NULL)
		{
			//r = SaveList(ht[i],fp);
		}
	}
	fclose(fp);
	return true;
}

/*
DESAFIOS
*/

//Delete(int v) : apaga a lista de colisões da chave v
//Length(int v) : comprimento da lista de colisões da chave v
//MaxLength() : maior comprimento das listas de colisões
//MinLength() : menor comprimento das listas de colisões
//Media() : média do comprimento das listas
//Gravar
//Carregar

#pragma endregion

#pragma region ABORDAGEM 2

// =================== OUTRA Abordgaem ================
//
//	HashTable é uma struct com uma Hash e um número de índexes

static HashTable ht;

/*
Outra hipótese: size==MAX!?
*/
HashTable* IniciaHashTable(int size, HashTable *ht) {
	int i;
	ht->max = size;
	ht->tabela = ( Node**) calloc(sizeof(Node*),size);
	return ht;
}


/*
Insere no início sem retorno...EVITAR
*/
bool InsertSimple(char*val, Node**hashTable)
{
	int h;
	h = Hash(val);

	Node *novo = (Node*)malloc(sizeof(Node));
	if (novo != NULL) {
		novo->val = val;
		novo->next = hashTable[h];
		hashTable[h] = novo;
		return true;
	}
	return false;
}

/*
Derivação da Função de Hash
*/
int HashIII(char *v, int M) {
	int i, h = v[0];
	for (i = 1; v[i] != '\0'; i++)
		h = (h * 251 + v[i]) % M;
	return h;
}

#pragma endregion

#pragma region HASH E LISTAS LIGADAS DUPLAS

// ========================= EXERCÍCIO - REVER =======================
// ================ Hash Com Listas Duplamente Ligadas ===============
// Livro / Palavras

typedef char *string;

typedef struct Palavra {
	string palavra;
	int    ocorrencias;
	struct Palavra *next;
	struct Palavra *prev;
} Palavra;


/*
Insere nodo de forma ordenada!
*/
//Palavra *InserePalavra(Palavra *head, string palavra) { 
Palavra *InserePalavra(Palavra *head, char *palavra) {
	Palavra *aux = head;

	if (head == NULL) //se a lista estiver vazia
	{	// aloca espaço para a nova palavra e inicializa parametros
		//usar antes método "CriaPalavra"
		Palavra *word = (Palavra*)malloc(sizeof(Palavra));
		if (word) {
			word->palavra = palavra;
			word->ocorrencias = 1;
			head = word;
		}
	}
	else
	{
		while (aux->next != NULL && strcmp(aux->next->palavra, palavra) < 0) //procura onde inserir				
		{
			aux = aux->next;
		}
		// verificar se a palavra já existe
		if (strcmp(aux->palavra, palavra) == 0) {
			aux->ocorrencias++;
			return head;
		}
		// return ou else
		// isto pode ficar no seu proprio metodo
		Palavra *word = (Palavra*)malloc(sizeof(Palavra));
		if (!word) return head;
		strcpy(word->palavra,palavra);
		word->ocorrencias = 1;

		//insere no início
		if (aux == head) {
			//Após o primeiro elemento
			if (strcmp(aux->palavra, palavra) < 0) {
				word->next = aux->next;
				aux->next = word;
				word->prev = aux;
			}
			else {
				// Adicionar na frente
				word->next = aux;
				aux->prev = word;
				head = palavra; // aux = palavra
			}
		}
		else {
			//Inserir no meio ou no fim
			// No fim
			if (!aux->next) { // aux->next != NULL
				aux->next = word;
				word->prev = aux;
				word->next = NULL;
			}
			else {
				// caso esteja entre outras palavras
				word->next = aux->next;
				word->prev = aux;
				aux->next->prev = word;
				aux->next = palavra;
			}
		}
	}
	return head;
}

/*
Remove ocorrência
*/
Palavra *RemovePalavra(Palavra *head, char *palavra) {
	if (!head) return NULL;
	Palavra *aux = head;
	while (aux->next != NULL && strcmp(palavra, aux->palavra) > 0) {
		aux = aux->next;
	}
	// elemento a eleminar no inicio
	if (aux == head) {
		aux->ocorrencias--;
		if (aux->ocorrencias == 0) {
			if(aux->next) aux->next->prev = NULL;
			head = aux->next;
			free(aux);
		}
	}
	else {
		aux->ocorrencias--;
		if (aux->ocorrencias == 0) { // verificar se funciona a remocao na ultima posicão
			if(aux->prev) aux->prev->next = aux->next;
			if (aux->next) 
				aux->next->prev = aux->prev;
			free(aux);
		}

	}
}

#pragma endregion

#pragma region AUXILIARES

// ===================== AUXILIARES ===================

	/*
	* Converte caracter em minúsculas
	*/
int ToUpperCase(char c) {
	/* subtair 21 ao valor ASCII atual do caracter(exemplo:'a'-'A'=32)
	*/
	if ('a' <= c && c <= 'z')
		return c - 32;
	else
		return (int)c;
}

/*
Mostra Tabela de ASCII
*/
void AsciiTable() {
	for (int i = 0; i < 255; i++) {
		printf("%x %d %c\n", i, i, i);
	}
}

#pragma endregion

