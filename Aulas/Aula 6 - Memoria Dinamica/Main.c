/*!
 *  @file Main.c
 *  @author mustl
 *  @date 2025-03-10
 *  @project Hoje
 *
 *  Implements the main.
 *      
 */
#include "Funcoes.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>	//rand()

void main() {

#pragma region Clubes

	//Clubes

	//Clube* novo = NewClub(2, "Benfica");
	Clube* novo = NewClubData(200, "Gil Vicente","200/12/01");

	ShowClube(*novo);

	int ns = novo->ns;

	ns = NumSocios(*novo);

	//Socios
	Socio *s1 = CriaSocio(12, 23.5);

	//ClubesSocios

	SociosClube* sc = CriaClubeSocios(*novo);

	bool b = InsereNovoSocio(s1, sc);

	MostraSociosClube(sc);

	s1 = CriaSocio(1, 43.5);
	b = InsereNovoSocio(s1, sc);
	
	MostraSociosClube(sc);

#pragma endregion

#pragma region Element

	Element *a1;
	Element *a2 = (Element*)malloc(sizeof(Element));
	a2->value = 123;
	Element *a3;

	/*a1->prox = a2;
	a2->prox = a3;
	a3->prox = a1;*/

	Element a4 = { 12,NULL };
	Element a5 = { 23,a2 };
	a1 = &a4;
	a2 = &a5;
	a3 = a1->prox;
	//a3 = a1->prox->prox;			//ERRO...porquê?
	//a3->value = a2->prox->value;	//ERRO...porquê?
	a3 = a2->prox;
	//free(a2);				//ERRO...porquê?

#pragma endregion

#pragma region MatrizesApontadores

	//Cria matriz
	int n = 5;
	int** ptMatriz = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		ptMatriz[i] = (int*)malloc(n * sizeof(int));
		//ou em anotação "apontadores"
		// *(ptMatriz+i) = (int*)malloc(n * sizeof(int));
		if (ptMatriz[i]==NULL) return;
	}

	//coloca valores na matriz
	for (int i = 0; i <n ; i++) {
		if (ptMatriz[i]) {			//verifica se existe memoria criada
			for (int j = 0; j < n; j++)
				ptMatriz[i][j] = rand();
		}
	}
	// ou
	// em notação "apontadores"
	//for (int i = 0; i < n; i++) {
	//	if (*(ptMatriz + i)) {		// mesmo que (ptMatriz[i])
	//		for (int j = 0; j < n; j++) {
	//			*(*(ptMatriz + i) + j) = rand();  // mesmo que ptMatriz[i][j]
	//		}
	//	}
	//}

	//mostra matriz

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("[%d,%d]=%d\t", i, j, ptMatriz[i][j]);
		}
		printf("\n");
	}

	//liberta memoria criada para a matriz
	for (int i = 0; i < n; i++) {
		free(ptMatriz[i]);
	}
	free(ptMatriz);
#pragma endregion

}