//-----------------------------------------------------------------------
// <copyright file="All.h" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2025</date>
// <author>lufer</author>
// <email>lufer@ipca.pt</email>
// <version></version>
// <desc>Biblioteca para Manipular Listas Ligadas Simples</desc>
//-----------------------------------------------------------------------
#include <stdbool.h>
#ifndef HEADER
#define HEADER

//typedef  enum boolean { false, true }   boolean;

//
//typedef struct Obra {
//	char* titulo;
//	int ano;
//	struct Obre *next;
//}Obra, *ObraPtr;


//nodo da lista
typedef struct Node
{
	char *val;			
	struct Node* next;
} Node, *NodePtr;
	

NodePtr InsertNode(NodePtr np, NodePtr h);
int Count(NodePtr h);
NodePtr DeleteNode(char *val, NodePtr h);
Node* Find(char val[], Node *h);
bool Exist(char *val, NodePtr h);
bool Save(NodePtr h);
Node *Load(Node *h);
NodePtr DeleteAll(NodePtr h);
NodePtr NewNode(char *val);
void ShowList(NodePtr h);								
void ShowNode(NodePtr p);
void ShowNodeII(Node p);

#endif