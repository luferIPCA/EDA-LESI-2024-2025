/*
autor:lufer
UC: Programação
desc: Calculadora básica: usa funções de biblioteca e funções locais
date
email
vers
*/
#include <stdio.h>
#include <conio.h>
#include "Funcoes.h"
#include "Libs/CalcFuncs.h"

#pragma comment(lib,"Libs/CalcLib.lib")


int main() {
	int x, y;

	//simular dados
	x = 23;
	y = 34;

	//mostrar resultados
	printf("%d + %d = %d\n", x, y, Soma(x, y));
	
	printf("Maior entre %d e %d = %d\n", x, y, maior(x, y));

}
