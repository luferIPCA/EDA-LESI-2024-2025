/*****************************************************************//**
 * @file   more.h
 * @brief  Arrays bidimensionais como parâmetros
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/

#ifndef ALL
#define ALL
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

typedef struct Varios {
	int maior;
	int menor;
} Varios;

#define tamanhoArray(x)  (sizeof(x) / sizeof((x)[0]))

int maiorElementoArray(int[], int size);
Varios maiorElementoArrayII(int[], int size);
int* GetWhat();
int* GetEvenArray(int* v, int size);
double GetAverage(int* arr, int size);
void ShowArray(int v[], int size);
void ShowArrayII(int* v, int size);

/*
Mostra o conteúdo de um array de inteiros
*/
void ShowArrayPtr(int v[], int size);
/*
Mostra o conteúdo de um array de inteiros em ordem inversa
*/
void ShowArrayPtrInv(int v[], int size);

//================== Testar Apontadores e Arrays ====================

struct A {
	int x;
	struct A* next;
};

//struct A **Inicia(struct A *v[]) {
struct A** Inicia(struct A* v[], int size);
void Destroy(struct A* f[], int s);
/*
Devolve array de apontadores
*/
int** IniciaInt(int* v[]);
/*
Mostra array
*/
//void printArray(int **iXArray, int iSize) { //evitar quando são arrays!!!
void printArray(int* iXArray[], int iSize);

int** IniciaArr(int* iXArray[], int iSize);

//=====================================================


// =============== ARRAYS COMO PARÂMATEROS ============

void G1(int* v);

void H1(int v[][2]);

//chamar: 	G1(v);
//			H1(k);
#endif // !ALL
