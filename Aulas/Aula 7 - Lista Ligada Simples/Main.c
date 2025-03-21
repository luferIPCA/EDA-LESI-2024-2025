/*!
 *  @file Main.c
 *  @author mustl
 *  @date 2025-03-14
 *  @project Aula 7
 *
 *  Implements the main.
 *      
 */
#include "Dados.h"
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "Funcoes.h"

void main() {

#pragma region Element

#pragma region PerceberStruct

	Element *a2 = (Element*)malloc(sizeof(Element));
	if (!a2) return;
	a2->value = 123;
	
	Element a4 = { 12,"ola", NULL};
	Element a5 = { 23, "ole", a2};

	Element* a1;
	Element* a3;

	/*a1->prox = a2;	//ERRO, porquê
	a2->prox = a3;		
	a3->prox = a1;*/	//ERRO, porquê


	a1 = &a4;
	a2 = &a5;
	a3 = a1->prox;
	//a3 = a1->prox->prox;			//ERRO...porquê?
	//a3->value = a2->prox->value;	//ERRO...porquê?
	a3 = a2->prox;
	//free(a2);				//ERRO...porquê?

#pragma endregion

#pragma region Lista

	Element e1 = { 12,"Ola", NULL};
	Element* head = NULL;

	head = CriaElemento(12, "Benfica");

	e1.prox = CriaElemento(123, "Porto");

	head->prox = &e1;

	int r = MostraLista(head);

#pragma endregion

#pragma endregion

	//outra lista
	Element* inicio = NULL;

	Element* novo;
	novo = CriaElement(129);
	if (novo != NULL)
		printf("Valor: %d\n", novo->value);

	inicio = InsereFim(inicio, novo);
	inicio = InsereInicio(inicio, novo);

	inicio = InsereOrdenadoII(inicio, novo);

}