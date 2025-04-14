#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h"

/**
*/
//ListElem* addItemHead(ListElem* head, ListElem *novo) 
ListElem* addItemHead(ListElem* head, void *data) {
	ListElem* aux;
	
	if((aux = (ListElem*) malloc(sizeof(ListElem))) == NULL)
		return head;
	aux->data = data;
	//aux->next = NULL;

	aux->next = head;	//Insere à cabeça
	head = aux;
	return head;			//atualiza head
}

ListElem* addItemLastRecursive(ListElem* head, void *data) {
	ListElem *aux;
	
	if(head == NULL) {
		aux = (ListElem*) malloc(sizeof(ListElem));
		aux->data = data;
		aux->next = NULL;
		return aux;
	}
	
	head->next = addItemLastRecursive(head->next, data);
	
	return head;
}

ListElem* addItemLastIterative(ListElem* head, void *data) {
	ListElem *aux, *prev;

	aux = (ListElem*)malloc(sizeof(ListElem));
	aux->data = data;
	aux->next = NULL;

	if (head == NULL) {	
		return aux;
	}

	for(prev = head; prev->next != NULL; prev = prev->next)
		;

	prev->next = aux;

	return head;
}

/**
 * @brief Insere ordenado com duplo apontador.
 * 
 * @param head
 * @param newElem
 * @param compare
 */
void addItemOrdered(ListElem** head, ListElem* newElem, int (*compare)(void* data1, void* data2)) {
	ListElem** aux = head;
	while (*aux && (compare((*aux)->data, newElem->data) < 0))
		aux = &((*aux)->next);
	newElem->next = *aux;
	*aux = newElem;
}

void showListIterative(ListElem* head, void (*mostra)(void *data)) {
	ListElem* aux = head;
	while(aux != NULL) {
		mostra(aux->data);
		aux = aux->next;
	}
}

void showListRecursive(ListElem* head, void (*show)(void *data)) {
	if(head != NULL) {
		show(head->data);
		showListRecursive(head->next, show);
	}
}

ListElem* removeItemIterative(ListElem* head, void *data, int (*compare)(void *data1, void *data2)) {
	ListElem *aux, *prev;
	
	// List is empty
	if(head == NULL)
		return NULL;
	
	// Element to remove is on the head of the list
	if(compare(head->data, data) == 1) {
		aux = head->next;
		free(head);
		return aux;
	} 
	
	// Element to remove is in the tail of the list
	for(prev = head; prev->next != NULL; prev = prev->next)
	{
		if(compare(prev->next->data, data) == 1) {
			aux = prev->next;
			prev->next = prev->next->next;
			free(aux);
			break;
		}
	}
	
	return head;
}

ListElem* removeItemRecursive(ListElem* head, void *data, int (*compare)(void *data1, void *data2)) {
	ListElem* aux;
	
	if(head == NULL)
		return NULL;
	
	if(compare(head->data, data) == 1) {
		aux = head->next;
		free(head);
		return aux;
	} else {
		head->next = removeItemRecursive(head->next, data, compare);
		return head;
	}
}


ListElem* addItemOrderedIterative(ListElem* head, void *data, int (*compare)(void *data1, void *data2)) {
	ListElem* n, *aux;
	
	n = (ListElem*) malloc(sizeof(ListElem));
	n->data = data;
	n->next = NULL;
	
	if(head == NULL || compare(data, head->data) < 0) {
		n->next = head;
		return n;
	}
	
	for(aux = head; aux->next != NULL; aux = aux->next) {
		if(compare(data, aux->next->data) < 0) {
			n->next = aux->next;
			aux->next = n;
			return head;
		}
	}
	aux->next = n;
	return head;
}

ListElem* addItemOrderedRecursive(ListElem* head, void *data, int (*compare)(void *data1, void *data2)) {
	ListElem* aux;
	
	if(head == NULL || compare(data, head->data) < 0) {
		aux = (ListElem*) malloc(sizeof(ListElem));
		if (aux != NULL) {
			aux->data = data;
			aux->next = head;
		}
		return aux;
	}
	head->next = addItemOrderedRecursive(head->next, data, compare);
	return head;
}

