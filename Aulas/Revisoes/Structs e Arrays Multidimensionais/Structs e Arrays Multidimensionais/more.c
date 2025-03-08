/*
file:	Functions.c
desc:	Várias funções para lidar com arrays
author: lufer
email:	lufer@ipca.pt
vers:	1.0
Ver: http://www.cs.dartmouth.edu/~campbell/cs50/ccontinued.html
*/

#include <stdio.h>	// necessário para inout/output
#include <locale.h>	// ASCII SET
#include "more.h"
#include <assert.h>
#include <stdlib.h>

#define MAX 20		//gerir dimensão de arrays

/* ====================== Métodos sobre Arrays ======================*/


/*
O que faz esta função?
*/
int* GetWhat() {
	static int  r[MAX];				//porquê static?
	int i;
	
	/*
	Generate the first seed value. A NULL arguments forces
	time() to read the computer’s internal time in seconds.
	The srand then uses this value to initialize rand()
	*/
	srand((unsigned)time(NULL));	//srand = seed randon
	/* carrega o array*/
	for (i = 0; i < MAX; ++i) {
		r[i] = rand();
		//printf("r[%d] = %d\n", i, r[i]);
	}
	return r;
}


/**
 * @brief Percorre um array e devolve os valores que são pares.
 * 
 * @param v - array de valores a analisar
 * @param size	- dimensão do array
 * @return	- array com valores encontrados
 */
int* GetEvenArray(int *v, int size) 
{
	int i;
	int c = 0;
	int *vals;

	/* verifica quantos são pares */
	for (i = 0; i < size; i++) {
		if (*(v + i) % 2 == 0) c++;
	}

	/* ? */
	vals = (int *)malloc (c*sizeof(int));	//int *vals[c]
	assert(vals != NULL);

	/* ? */
	int j = 0;
	for (i = 0; i < size; i++)
	{
		if (*(v + i) % 2 == 0)
		{
			//vals[j] = (int)malloc(sizeof(int));
			vals[j] = *(v + i);
			j++;
			//*(vals + j++) = *(v + i); 
		}
	}
	return vals;
}


/*
Percorre um array e devolve quantos e quais os valores que são pares
*/
//Res GetEvenArrayI(int *v, int size)
//{
//	int c = 0;
//	Res aux;
//	int i;
//
//	int *vals;
//
//	for (i = 0; i < size; i++) {
//		if (*(v + i) % 2 == 0) c++;
//	}
//
//	vals = (int*)malloc(c * sizeof(int));
//
//	int j = 0;
//	for (i = 0; i < size; i++)
//	{
//		if (*(v + i) % 2 == 0)
//		{
//			*(vals + j++) = *(v + i);
//		}
//	}
//	aux.p = vals;
//	aux.s = c;
//	return aux;
//}


/*
Calcula a média de um array
*/
double GetAverage(int *arr, int size) {

	int  i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += arr[i];		//*arr
	}

	avg = (double)sum / size;
	return avg;
}


// ==================== PERCORRER ARRAYS =====================

/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArray(int v[], int size) {

	int i;
	
	for (i = 0; i < size; i++) {
		printf("v[%d]=%d\n", i, v[i]);
	}
}




/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayPtr(int v[], int size) {
	int *pt = &v[0];	//pt=v;
	int i;
	for (i = 0; i < size; i++) {
		//printf("*(p+%d)=%d\n", i, *(v + i));
		printf("Endereço de v[%d] = %x\n", i, pt);
		printf("Valor de v[%d] = %d\n", i, *pt);
		pt++;
	}
}

/*
Mostra o conteúdo de um array de inteiros em ordem inversa
*/
void ShowArrayPtrInv(int v[], int size) {

	int *pt = &v[size-1];	
	int i;
	
	for (i = size; i >0; i--) {
		//printf("*(p+%d)=%d\n", i, *(v + i));
		printf("Endereço de v[%d] = %x\n", i-1, pt);
		printf("Valor de v[%d] = %d\n", i-1, *pt);
		pt--;
	}
}


//================== Testar Apontadores e Arrays ====================

//struct A **Inicia(struct A *v[]) {
struct A **Inicia(struct A *v[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		//v[i]->next = NULL;
		//v[i]->x = 2;
		v[i] = (struct A*) malloc(sizeof(struct A));
		v[i]->x = i * 2;
		v[i]->next = NULL;
	}
	return *v;
}

void Destroy(struct A *f[], int s) {
	int i;
	for ( i = 0; i < s; i++)
	{
		free(f[i]);
	}	
}

/*
Devolve array de apontadores
*/
int **IniciaInt(int *v[]) {
	int i;
	for (i = 0; i < 10; i++) {
		//v[i]->next = NULL;
		//v[i]->x = 2;
		//v[i] = NULL;
		v[i] = (int*)malloc(sizeof(int));
		*v[i] = i + 1;
	}
	return *v;
}

/*
Mostra array
*/
//void printArray(int **iXArray, int iSize) { //evitar quando são arrays!!!
void printArray(int *iXArray[], int iSize) {
	int iCntr;
	for (iCntr = 0; iCntr < iSize; iCntr++) {
		printf("%d ", *iXArray[iCntr]);
	}
	printf("\n");
}

int **IniciaArr(int *iXArray[], int iSize) {
	int iCntr;
	for (iCntr = 0; iCntr < iSize; iCntr++) {
		//printf("%d ", *iXArray[iCntr]);
		iXArray[iCntr] = (int*)malloc(sizeof(int));
		*iXArray[iCntr] = iCntr;
	}
	return *iXArray;
}

//=====================================================


// =============== ARRAYS COMO PARÂMATEROS ============

int v[] = { 2,3,4 };

int k[2][2] = { { 2,3 },{ 7,8 } };


void G1(int *v) {
	int i;
	for (i = 0; i<3; i++)
		v[i] += 1;
}

void H1(int v[][2]) {
	int i, j;
	for (i = 0; i<2; i++)
		for (j = 0; j<2; j++)
			v[i][j] += 1;
}

//chamar: 	G1(v);
//			H1(k);