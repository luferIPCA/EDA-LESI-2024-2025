/*
* author: lufer
* email: lufer@ipca.pt
* date: 2025
* desc: Apontadores
*/

#include "Dados.h"

//int* changeValue(const int* p) {
int* changeValue(int* p) {
	*p = *p + 1;		//com const não é permitido
	return p;
}

int* Maior(int* p, int* q) {
	if (*p > *q) return p;
	return q;
}

/**
* Verifica se determinado valor existe num array
* @param [in] n
* @param [out] p	//posição do array
*/
bool ExisteValorPosicao(int v[], int n, int valor, int* pos) {

	for (int i = 0; i < n; i++) {
		if (v[i] == valor) {
			*pos = i;		//posição onde existe
			return (true);
		}
	}
	*pos = -1;				//posição errada!
	return (false);
}

/**
* Analisar!!!! Qual o problema?
*/
int get(int* ptr) {
	int a = 10;
	ptr = &a;
	return 0;
}

/**
* Verifica se determinado valor existe num array
*/
bool ExisteValorArray(int* v, int n, int valor) {
	bool existe = false;
	//h1
	/*for (int i = 0; i < n; i++) {
		if (v[i] == valor) return true;
	}*/

	//h2
	//for (int i = 0; i < n; i++) {
	//	if (*(v + i) == valor) return true;
	//}

	//h3
	int* p = v; // ou int* p = &v[0];
	for (int i = 0; i < n; ) {
		if (*p == valor) return true;
		p++;
	}
	return false;
}

/**
* Mostra o conteúdo de um array por ordem inversa
*/
void ShowArrayPtrInv(int v[], int size) {
	int* pt = &v[size - 1];
	int i;

	for (i = size; i > 0; i--) {
		//printf("*(p+%d)=%d\n", i, *(v + i));
		printf("Endereço de v[%d] = %p\n", i - 1, pt);
		printf("Valor de v[%d] = %d\n", i - 1, *pt);
		pt--;
	}
}

