/*
Revisões sobre Recursividade
lufer
*/
#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "Recurs.h"

int main() {

	setlocale(LC_ALL, "Portuguese");


	printf("Factorial de %d = %d", 5, Factorial(5));

	int arr[1] = { 1 };
	int v = ProcuraArray2(3, arr, 1);

	return 0;
}