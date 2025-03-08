
/*
Manipular Arrays Multidimensionais
lufer
Ver: https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
*/

#ifndef ARRAYDUP
#define ARRAYDUP 

#include <stdio.h>

#define N 10

//Cabeçalhos de funções e métodos

//apresenta array bidimensional
void mostraArrayBidimensional(int v[][N], int t);

//inicializa array bidimensional com determinado valor
void inicalizaArrayBidimensional(int v[][N], int t, int valor);

//procura valor num array bidimensional...devolve posição
int procuraArrayBidimensional(int v[][N], int t, int valor);

#pragma region Arrays_Duplos_Pointers


void ShowArrayDuplo(int rows, int cols, int* a);

void ShowArrayDuploII(int(*v)[][2], int n, int m);

void ShowArrayDuploIII(int(*a)[2], int n, int m);

void ShowArrayDuploIV(int**a, int n, int m);

void ChangeValue(int(*a)[2], int n, int m, int v);

#pragma endregion

//Array duplo com pointers
int** ArrAlloc(size_t x, size_t y);
int** ArrFill(int** pp, size_t x, size_t y);

#endif // !ARRAYDUP
