/*
* author: lufer
* email: lufer@ipca.pt
* date: 27.02.2022
* desc: Resolução da Ficha de Diagnóstico
*/

#include <stdio.h>
#include <conio.h>
#include "Funcoes.h"
#include <locale.h>		//caracteres portugueses

/**
 * The main procedure. It can do the following:
 *  - ...
 *  - ...
 *
 * @code
 * Objeto x = QualMaisLonge(aux, 2);
 * @endcode
 * 
 * @param argc the command line
 * @param argv the number of options in the command line.
 * @return 0
 * @author lufer LuisFerreita
 */
int main(char** argc, int argv){

	setlocale(LC_ALL, "Portuguese");
	puts("Resolução da Ficha de Diagnóstico");

	//-------------
#pragma region TesteArray

	double valores[N] = { 2,3,4.5,6.7,18,9,-12 };	//N definido em Funcoes.h

	double avg = MediaArray(valores, 7);

	printf("Média do Array: %0.2f\n\n", avg);

#pragma endregion

#pragma region TestaFichaDiagnostico

	//objetos foi declarado em "Funcoes.h"
	Objeto objetos[N] = { {"Porto",40},{"Lisboa",350} };

	printf("Média Distancias: %0.2f\n", MediaDistanciaObjetos(objetos, 2));

	//gravar em ficheiro
	bool f = GravaDados("Dados.bin", objetos, 2);

	//testar leitura de ficheiro
	Objeto aux[20];
	long g = LeDados("Dados.bin", aux);

	Objeto x = QualMaisLonge(aux, 2);
	printf("Objeto Mais longe: %s - %0.2f\n", x.nome, x.dist);

#pragma endregion

	getche();
	return 0;
}