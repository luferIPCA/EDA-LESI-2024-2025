/*!
 *  @file Calc.c
 *  @author mustl
 *  @date 2025-02-28
 *  @project Hoje
 *
 *  Implements the calc.
 */

#include "Funcoes.h"
#include <malloc.h>
#include <stdio.h>



void main() {

#pragma region A

	int a = 10;
	int b = 12;

	int r = Soma(&a, &b);

	int v[] = { 2,3, - 4,7 };

#pragma endregion

#pragma region ArraysApontadores

	int* vPtr[2];
	vPtr[0] = &a;
	vPtr[1] = &b;
	int x = MaiorPt(vPtr, 2);

	// outro exemplo
	int var1 = 10;
	int var2 = 20;
	int var3 = 30;
	int* ptrArr[] = { &var1, &var2, &var3 };

	//outro
	char* valor[] = { "Benfica", "Sporting", "Braguinha", "Porto" };

#pragma endregion

#pragma region FuncoesArrayApontadores

	//int r;
	int s = SomaMaiorArray(v, 4, &r);

	//ATENÇÃO
	//apontador para inteiro
	int* p = (int*)malloc(sizeof(int));
	if (p == NULL) {
		printf("No Memory..."); return;
	}
	*p = 42;
	printf("*p=%d\n",*p); 
	free(p);	//libertar antes de associar a outro endereço
	p = NULL;	//certificar que não fica a apontar para nada

	//p = &s;		//p aponta para memória não dinâmica
	//free(p); // ERROR...porquê

	//array de apontadores para inteiros
	int** valoresPtr = (int**)malloc(10 * sizeof(int*));
	if (valoresPtr == NULL) {
		printf("Falha de memória!\n");
		return 1;
	}
	for (int i = 0; i < 10; ++i) {
		valoresPtr[i] = (int*)malloc(sizeof(int));
		if (valoresPtr[i] == NULL) {
			printf("Falha de memória!\n");
			return 1;
		}
		*valoresPtr[i] = 2*i;
	}

	//int** valoresPtr = (int*)calloc(2,sizeof(int));
	//valoresPtr[0] = &r;
	//valoresPtr[1] = &s;

	s = SomaMaiorArrayPtr(valoresPtr, 2, &r);

	//libertar memória
	//free(valoresPtr); //INCORRETO...porquê?
	for (int i = 0; i < 10; ++i) {
		free(valoresPtr[i]);
	}
	free(valoresPtr);

#pragma endregion

#pragma region Dinamica

	//estático
	Pessoa t[10];
	t[0].idade = 12;
	t[0].colega = NULL;

	//Dinamico
	Pessoa* turma;
	//turma->idade = 12;	//ERRO: porquê
	int tamanhoTurma = 2;

	turma = (Pessoa*)malloc(tamanhoTurma *sizeof(Pessoa));
	if (turma == NULL) return;

	turma[0].idade = 12;
	turma[0].colega = &t[0];

	turma[1].idade = turma[0].idade * 2;
	turma[1].colega = &turma[0];

	for (int i = 0; i < tamanhoTurma; i++) {
		printf("Idade: %d\n", turma[i].idade);
		printf("Idade colega: %d\n", turma[i].colega->idade);
	}

	Pessoa* aux;
	aux = &turma[0];
	printf("Idade colega: %d\n", aux->colega->idade);


	free(turma);



#pragma endregion

}