/*
	author: oribeiro & lufer
	Uso de structs e arrays
*/
#include <stdbool.h>
#include "tdata.h"
#include <time.h>

/* ---------------------------------------
    funções ler / escrever datas
   --------------------------------------- */
/* escrever uma data no ecran (stdout):
   formato dd/mm/aaaa */
void escreverData(TDATA data) {
    printf("%d/%d/%d",data.dia, data.mes, data.ano);
}

/* ler uma data do teclado (stdin) */
TDATA lerData() {
    TDATA data;
    printf("data (dd/mm/aaaa)? ");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

/* ---------------------------------------
    funções com cálculos acerca datas
   --------------------------------------- */
/* função que dada uma data calcula o número
   de anos que já passaram  */
// int calcularIdade(int dia, int mes, int ano) {
int calcularIdade(TDATA data) {
    int resultado;
    resultado = 2017 - data.ano; // se nasc. antes (ou em) 30.10.2017
    if (data.mes > 10 )
        resultado = resultado -1;
    else if (data.mes == 11) {
        if (data.dia > 30) {
                resultado = resultado -1;
        }
    }
    return resultado;
}


bool comparaDatas(TDATA data1, TDATA data2) {
	//completar
	return (data1.ano > data2.ano);
}


/* determinar a data de hoje devolvendo uma struct tdata, através da
data do sistema guardada numa "struct tdata". Ver mais detalhes
no seguinte URL: http://devdocs.io/c/chrono/tm  */
TDATA dataHoje() {
	TDATA hoje;
	time_t t = time(NULL);
	struct tm tmHoje = *localtime(&t);
	hoje.dia = tmHoje.tm_mday;
	hoje.mes = tmHoje.tm_mon + 1;
	hoje.ano = tmHoje.tm_year + 1900;

	return hoje;
}


