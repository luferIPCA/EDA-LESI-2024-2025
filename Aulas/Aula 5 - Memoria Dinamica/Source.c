/*!
 *  @file Source.c
 *  @author lufer
 *  @date 2025-03-07
 *  @project Aula 5 - Memoria Dinamica
 *
 *  Apontadores em Estruturas de dados dinâmicas.
 */

#include "Dados.h"
#include <stdio.h>
#include <malloc.h>		//função malloc()
#include <string.h>

#pragma warning (disable:4996)

void main() {

#pragma region Structs

	Aluno a1;
	a1.num = 12;

	printf("Num: %d\n", a1.num);

	Aluno* p;
	p = &a1;
	printf("Num: %d\n", p->num);

	Aluno* k = (Aluno*)malloc(sizeof(Aluno));
	if (k == NULL) return;
	k->num = 13;
	printf("Num: %d\n", k->num);

	//array de 10 alunos
	Aluno* turma = (Aluno*)malloc(10 * sizeof(Aluno));
	if (turma == NULL) return;
	turma[5].num = 27;
	strcpy(turma[5].nome, "Paulo");

#pragma endregion

#pragma region ApontadoresStructs

	Erasmus a2;
	a2.a.num = 12;
	strcpy(a2.a.nome, "XXXX");
	strcpy(a2.pais, "Marrocos");
	a2.next = NULL;
	

	Erasmus a3;
	a3.a = a1;	//CUIDADO
	//a3.a.num = a1.num;
	strcpy(a3.pais, "Espanha");
	a3.next = NULL;

	a2.next = &a3;

	printf("Nome a2: %s\n", a2.a.nome);
	printf("Numero Proximo (a3): %d\n", a2.next->a.num);
	printf("Pais Proximo (a3): %s\n", a2.next->pais);

	Erasmus a4;
	a4.a.num = 23;;
	strcpy(a4.pais, "França");
	a4.next = NULL;
	
	a3.next = &a4;

	printf("Num : %d\n", a2.a.num);				//num de a2
	printf("Num : %d\n", a2.next->a.num);		//num de a3
	printf("Num : %d\n", a2.next->next->a.num);	//num de a4


	Erasmus* aux;
	aux = &a2;
	while (aux != NULL) {
		printf("Num: %d - Pais: %s\n", aux->a.num, aux->pais);
		aux = aux->next;
	}

#pragma endregion

//libertar memória
//free(p);	//ERRO pois p não foi criado com malloc()
free(k);
free(turma);

}