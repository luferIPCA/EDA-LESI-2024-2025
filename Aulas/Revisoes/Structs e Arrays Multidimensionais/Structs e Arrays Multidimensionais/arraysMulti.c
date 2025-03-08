/*
Funções para manipular arrays multidimensionais
lufer@ipca.pt
Ver: 
	https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
	https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
*/

#include "arraysMulti.h"
#include <assert.h>



/*
Mostra o conteúdo de um array bidimensional
*/
void mostraArrayBidimensional(int v[][2], int t) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			printf("v[%d][%d]=%d | ", i, j, v[i][j]);
		}
		printf("\n");
	}
}

/*
inicializa array bidimensional com determinado valor
*/
void inicalizaArrayBidimensional(int v[][2], int t, int valor) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			v[i][j] = valor;
		}
	}
}

void ShowArrayDuplo(int rows, int cols, int* a) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
				printf("%d ", a[i * cols + j]);
		}
		printf("\n");	
	}
}

/**
 * @brief Mostar array duplo, passado como pointer.
 * 
 * @param v
 * @param n
 * @param m
 */
void ShowArrayDuploII(int(*v)[][2], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d\n", (*v)[i][j]);
}

/**
 * @brief Mostar array duplo.
 * 
 * @param a
 * @param n
 * @param m
 */
void ShowArrayDuploIII(int(*a)[2], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("array[%d][%d]=%d\n", i, j, a[i][j]);
		}
	}
}

void ShowArrayDuploIV(int **a, int n, int m){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
/**
 * @brief Altera o valor de uma posição do array.
 * 
 * @param a
 * @param n
 * @param m
 * @param v
 */
void ChangeValue(int(*a)[2], int n, int m, int v)
{
	//a[n][m] = v;
	*(a)[m]= v;
}

#pragma region Mais

int** ArrAlloc(size_t x, size_t y)
{
	int** pp = malloc(sizeof(*pp) * x);
	assert(pp != NULL);
	for (size_t i = 0; i < x; i++)
	{
		pp[i] = malloc(sizeof(**pp) * y);
		assert(pp[i] != NULL);
	}
	return pp;
}

int** ArrFill(int** pp, size_t x, size_t y)
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			pp[i][j] = (int)j + 1;
		}
	}

	return pp;
}

void ArrPrint(int** pp, size_t x, size_t y)
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			printf("%d ", pp[i][j]);
		}
		printf("\n");
	}
}

void ArrFree(int** pp, size_t x, size_t y)
{
	(void)y;

	for (size_t i = 0; i < x; i++)
	{
		free(pp[i]);
		pp[i] = NULL;
	}
	free(pp);
	pp = NULL;
}

///**
// * @brief Código para testar estes métodos.
// * 
// * @return 
// */
//int main(void)
//{
//	size_t x = 2;
//	size_t y = 3;
//	int** pp;
//
//	pp = ArrAlloc(x, y);
//	pp = ArrFill(pp, x, y);
//	AarrPrint(pp, x, y);
//	ArrFree(pp, x, y);
//
//	return 0;
//}

#pragma endregion
