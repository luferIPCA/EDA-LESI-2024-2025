/*
* author: lufer
* email: lufer@ipca.pt
* date: 2025
* desc: Aritmética de Apontadores; Arrays e Apontadores
*/

#pragma warning (disable: 4996)
#include <stdio.h>
#include "Dados.h"
#include <malloc.h>

typedef struct Pessoas {
	Pessoa p;
	struct Pessoas* proximo;
}Pessoas;

void main() {

#pragma region Aritmetica_Pointers

	int x = 10, y = x * 2;
	int *p = &x;

	printf("&x = %p\n", &x);
	printf("*p = %d\n", *p);

	//printf("*p++ = %d\n", *p++);	//CUIDADO
	printf("++(*p) = %d\n", ++(*p));
	printf("(*p)++ = %d\n", (*p)++);
	printf("(*p) = %d\n", (*p));
	printf("++*p = %d\n", ++*p);

	int maior = *Maior(&x, &y);
	printf("Maior valor entre %d e %d = %d\n", x,y, maior);
	//p = Maior(&x, &y);

#pragma endregion

#pragma region Arrays_Pointers

	//arrays e pointers
	//https://www.programiz.com/c-programming/c-pointers-arrays
	int valores[] = { 1,2,3,4 };
	int* ptr;

	ptr = valores;	//nome do array é o mesmo que &array[0]
	//ptr = &valores[0]	
	//*ptr == valores[0]

	//&x[0] é equivalente a x
	//x[0] é equivalente a *x
	//&x[i] é equivalente a x + i
	//x[i] é equivalente a *(x + i).

	printf("p[0]=%d\n", *ptr);
	//printf("p[1]=%d\n", *(ptr + 1));

	for (int i = 0; i < 4; i++) {
		printf("p[%d]=%d\n",i, *(ptr + i));
	}

#pragma endregion

#pragma region Parametros_Pointers

	int pos;
	bool aux = ExisteValorPosicao(valores, 4, 12, &pos);

	int novo = get(&pos);
	printf("pos= %d\n", pos);

#pragma endregion

#pragma region Structs_Pointers_I

	Pessoa q;
	q.idade = 12;
	strcpy(q.nome, "Julio");

	Pessoa *pq;
	pq = &q;
	//(*pq).idade = 12;
	//ou
	pq->idade = 12;
	strcpy(pq->nome, "Paulo");

	Pessoa z;
	z.idade = 13;
	strcpy(z.nome, "Maria");

	//Definir Maria como prima de Julio
	q.primo = &z;

	printf("Nome Primo: %s", q.primo->nome);

#pragma endregion

#pragma region Structs_Pointers_II

	Pessoa* pp;
	pp = (Pessoa*)malloc(sizeof(Pessoa));
	pp->idade = 12;

	Pessoas* head = NULL;
	head = (Pessoas*)malloc(sizeof(Pessoas));
	head->p = *pp;
	head->proximo = &z;

#pragma endregion

	getche();			//until keypressed
}