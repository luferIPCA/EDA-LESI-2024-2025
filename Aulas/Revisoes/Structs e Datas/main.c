/*
	Tipos Abstratos de Dados (structs)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//manipular "date"

//  #include "tdata.h"
#include "tinscricao.h"

int main()
{
	//Operação 1

    TDATA dataNasc;
    int idade;

    dataNasc = lerData();
    idade = calcularIdade(dataNasc);
    printf("data nascimento: ");
    escreverData(dataNasc);
    printf("\n");
    printf("idade = %d\n", idade);

    
	//Operação II
    /* Testar TINSC */
    TINSC a = {"AAAA", {20,8,1992} };

	TDATA td = { 12,12,2017 };

	TINSC varios[20] = { {"ola",td}, {"ole",td },{"oli",td} };

	gravarInscricoesBinario("Fichas.bin", varios, 3);

	for (int i = 0; i < 20; i++) {
		strcpy(varios[i].nome,"");
	}

	lerInscricoesBinario("Fichas.bin", varios);

    escreveInscricao(a);

	//manipular date e hora
	//Data de hoje
 	time_t t = time(NULL);

	struct tm tm = *localtime(&t);
	printf("Hoje: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);


	//Enumerados
	meses m=3;

	/*if (m > Janeiro) {

	}*/

	TESCALAO ti;
	ti = M50;


	getche();
    return 0;
}


/*
Exercício
---------

Encontrar a pessoa mais velha

*/