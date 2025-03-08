/*
	author: oribeiro & lufer
	Estruturas de dados
*/
#ifndef DADOS2
#define DADOS2
 

#include <stdio.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

/* definição do tipo de dados TDATA  */

typedef struct TDATA {
               int dia, mes, ano; 
} TDATA;



void escreverData(TDATA data) ;
/* ler uma data do teclado (stdin) */
TDATA lerData() ;

/* ---------------------------------------
    funções com cálculos acerca datas
   --------------------------------------- */
/* função que dada uma data calcula o número
   de anos que já passaram  */
// int calcularIdade(int dia, int mes, int ano) {
int calcularIdade(TDATA data) ;

#endif //
