/*
Tratamento de structs e Arrays...
lufer@ipca.pt
Ver: 
	https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
	https://solarianprogrammer.com/2019/03/27/c-programming-passing-multi-dimensional-array-to-function/
*/
#include <stdio.h>
#include "funcoes.h"
#include "ArraysMulti.h"
#include "more.h"

//typedef struct pessoa {
//	int idade;
//	char nome[20];
//} pessoa;

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))


void main()
{	

#pragma region ARRAYS

	int valores[10] = { -3,0,12,34,45 };

	insereOrdenadoArray(valores, 10, 7);

	//Array simples
	pessoa v[N] = { {12,"Manel"},{23,"Maria"},{21,"Mario"} };

	/*v[0].idade = 12;
	strcpy(v[0].nome,"ola");

	v[1].idade = 120;
	strcpy(v[1].nome, "ole");*/

	/*for (int i = 0; i < 10; i++) {
		printf("Idade= %d Nome= %s\n", v[i].idade, v[i].nome);
	}*/
	mostraArray(v, 3);

	//Ordenar Array
	{
		pessoa pessoas[N] = { { 12,"Manel" },{ 23,"Maria" },{ 21,"Mario" } };

		int val[] = { 2, -3, 67, 0,1 };

		Change(val, 5, 1, 3);

		printf("Antes de ordenar:\n");
		mostraArraySimples(val, 5);	
		ordenaArrayInteiros(val, 5);	//array sai alterado
		printf("Depois de ordenar:\n");
		mostraArraySimples(val, 5);

		//Ordenar Pessoas
		printf("Antes de ordenar Pessoas:\n");
		mostraArray(pessoas, 3);	//array sai alterado
		ordenaArrayPessoas(pessoas, 3);
		printf("Depois de ordenar Pessoas:\n");
		mostraArray(pessoas, 3);
	}

	pessoa p = pessoaMaisVelha(v, 3);
	char* nome = nomePessoaMaisVelha(v, 3);
	int idade = maiorIdade(v, 3);


	//Qual o aluno com a melhor nota a LP1?

	


	// Array Multidimensionais
	{
		//array bidmensional
		int varios[10][2];
		int abc[2][2] = { 1, 2, 3 ,4 };
		int variosII[][2] = { 12,34,23 };
		int abc1[][4] = { 1, 2, 3 ,4 };	//tem de se especificar a 2a dimensão
		int abc2[6][2] = { 1, 2, 3 ,4 };

		//array tridimensional
		int xxx[][2][3] = { 1,2,3,4,5,6,7,8 };	

		varios[0][0] = 2;

		printf("Tamanho Array: %d\n", sizeof(abc2));
		printf("Tamanho Linha: %d\n", sizeof(abc2[0]));
		printf("Numero de Linhas: %d\n", LEN(abc2));
		printf("Numero de Colunas: %d\n", LEN(abc2[0]));

		inicalizaArrayBidimensional(varios, 10, 0);

		mostraArrayBidimensional(varios, 10);

		//int aux = procuraArrayBidimensional(abc2,)

		int vals[][2] = { {1,2},{3,4},{4,5}};

		ShowArrayDuplo(2,3,vals);
		ShowArrayDuploII(vals, 3, 2);
		ShowArrayDuploIII(vals, 3, 2);

		//Arrays duplos como pointers
		int** pp = ArrAlloc(3, 2);
		pp = ArrFill(pp, 3, 2);
		ShowArrayDuploIV(pp, 3, 2);

		ChangeValue(vals, 1, 1, 12);
		getche();
	}

#pragma endregion

#pragma region MAISARRAYS
	int v3[] = { 1,2,3,4 };
	int* aux3 = GetEvenArray(v3, 4);
#pragma endregion



}


