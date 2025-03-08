
/*
Manipular arrays de apontadores para structs
lufer@ipca.pt

Ver:
https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#include <stdio.h>
#include "Dados.h"

int main() {

#pragma region Array_Structs
	//Jogo jogos[MAX];
	//jogos[0].cod = 12
	//mostraJogos(jogos, 1);
	
	//Array de Jogos: Revisão
	Jogo arrayJogos[MAX] = { { 12,"XXX",'T' } };
	MostraJogos(arrayJogos, 1);

#pragma endregion

#pragma region Array_Apontadores_Structs

	//Array de Apontadores para jogos
	Jogo* jogos[MAX];
	//jogos[0] = NULL;	//deve-se inicializar o array todo a NULL
	InicializaArray(jogos, MAX);
	MostraJogosII(jogos,MAX);

	int numJogos = 0;

	Jogo j = { 13,"Jogo",'A',{12,12,2017} };

	numJogos = InsereJogo(jogos, j, numJogos);
	numJogos = InsereJogo(jogos, arrayJogos[0], numJogos);
	MostraJogosII(jogos, MAX);
	/*
	numJogos = InsereJogoII(jogos, &j, numJogos);
	*/
#pragma endregion

	return 1;
}