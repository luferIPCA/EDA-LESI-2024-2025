
/*****************************************************************//**
 * @file   hash.h
 * @brief  Tabelas de Hash
 * Index->Lista Ligada
 * @author lufer
 * @date   May 2025
 *********************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include "Listas.h"



#ifndef HASH
#define HASH
#define MAX 31 /* tamanho da tabela de hashing -> recomenda-se que seja primo */



//h1: Tabela de Hash é apenas um array de apontadores para Listas
//static struct Node* hashTable[MAX];	//definir no main() sem ser "static"
//ou
//static struct Node** hashTable;

//h2: Tabela de Hash dentro de uma estrutura para controlo
typedef struct HashTable {
	int max;
	struct Node** tabela;
	//ou
	//struct Node* tabela[MAX];
}HashTable;

// -----
// RELEMBRAR:
//char* nome;
// ou
//char nome[20];

//char** nome2;
// ou
//char nome2[][];
// 
//Node** ht;
// ou
//Node* ht[]
// -----

#pragma region Asssinatura de Funcões

//Assinaturas de Métodos

//Cria e Inicializa Hash
Node** CriaHash(int n);

//Funções de Hash
int Hash(char* palavra);
int HashII(int val);

//Manipular Hash
bool IniciaHash(Node** ht, int n);
Node **IniciaHashII(Node **ht);
Node** InsertValHash(char* autor, Node** ht);
//ou
// Node ** InsertValHash(char* autor, Node *ht[]);
Node ** InsertNodeHash(Node *autor, Node *ht[]);

void ShowHash(Node *ht[]);
NodePtr FindNode(char val[], Node* ht[]);
Node **Cleanup(Node *ht[]);

bool InsertNodeHashBool(Node* item, Node **ht);

//Preservar Hash em Ficheiro
bool SaveHash(Node** h, char* fileName);
//Node** GetHash(char* fileName);

#pragma endregion

#pragma region Assinatura de Funcões Auxiliares

//Auxiliares
void AsciiTable();
int ToUpperCase(char c);


#pragma endregion

#endif // !HASH

