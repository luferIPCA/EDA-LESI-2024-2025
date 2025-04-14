/**
* Listas Ligadas Genéricas
* João Carlos Silva
* Lufer
*/

#pragma once

#include <stdio.h>

typedef struct ListElem {
	void *data;
	struct ListElem *next;
} ListElem;

// Insert a new element with *data in the head of the list 
// *data must point to storage in the heap
ListElem* addItemHead(ListElem* head, void *data);

// Applies show function to all elements on the list, iteratively
void showListIterative(ListElem *head, void (*show)(void *data));

// Applies show function to all elements on the list, recursively
void showListRecursive(ListElem *head, void (*show)(void *data));

// Insert a new element with *data in last position of the list, iteratively
// *data must point to storage in the heap
ListElem* addItemLastIterative(ListElem* head, void *data);

// Insert a new element with *data in last position of the list, recursively
// *data must point to storage in the heap
ListElem* addItemLastRecursive(ListElem* head, void *data);

// Insert a new element with *data in the list according to the order defined by function compare, iteratively
// *data must point to storage in the heap
ListElem* addItemOrderedIterative(ListElem* head, void *data, int (*compare)(void *data1, void *data2));

// Insert a new element with *data in the list according to the order defined by functoin compare, recursively
// *data must point to storage in the heap
ListElem* addItemOrderedRecursive(ListElem* head, void *data, int (*compare)(void *data1, void *data2));

// Removes the first item on the list that compares positively with *data through function compare, iteratively 
ListElem* removeItemIterative(ListElem* head, void *data, int (*compare)(void *data1, void *data2));

// Removes the first item on the list that compares positively with *data through function compare, recursively
ListElem* removeItemRecursive(ListElem* head, void *data, int (*compare)(void *data1, void *data2));

// List length
int listLength(ListElem* head);

// Delete list
ListElem* deleteList(ListElem* head);

// Element on the list on specific position
ListElem* obtainElementPosition(ListElem* head, int pos);

// First element on the list with *data compared through function compare
ListElem* obtainElement(ListElem* head, void* data, int (*compare)(void * data1, void *data2));




//ListElem* CreateElement(void* dados) {
//	ListElem* nova = (ListElem*)malloc(sizeof(ListElem));
//	if (nova != NULL) {
//		nova->data = dados;
//		nova->next = NULL;
//	}
//	return nova;
//}

//
//typedef struct Maquina {
//	int cod;
//	struct Maquina* next;
//}Maquina;
//
//Maquina* CreateMaquina(int cod) {
//	Maquina* nova = (Maquina*)malloc(sizeof(Maquina));
//	if (nova != NULL) {
//		nova->cod = cod;
//		nova->next = NULL;
//	}
//	return nova;
//}

