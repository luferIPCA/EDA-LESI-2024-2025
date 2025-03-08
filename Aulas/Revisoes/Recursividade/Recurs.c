
#include "Recurs.h"

/*
Calcula o Factorial de N
*/
int Factorial(int n) {
	if (n == 0) return 1;			//0!
	return (n*Factorial(n - 1));	//n * (n-1)!
}

/*
Calcula a a^b
*/
int Potencia(int base, int exp) {
	if(exp == 0) {
		return 1;							//expoente igual a zero, retorna 1
	}
	return base * Potencia(base, exp - 1); //Se o expoente for diferente de zero, multiplica a base
										   //com a Potência do expoente atual menos 1
}

/*
Calcula A sequência Fibonacci de N
*/
int Fibonacci(int x) {
	if (x == 0) {
		return 0;							//Se for igual a zero, retorna apenas o próprio zero
	}
	if (x == 1 || x == 2) {
		return 1; //Como o Fibonacci é a soma dos dois valores anteriores, tanto x = 1 quanto x = 2 dá 1
	}
	return Fibonacci(x - 1) + Fibonacci(x - 2); //soma do primeiro valor anterior com o segundo valor anterior
}

/*
procura no array(arr) um determinado numero(n). 
Retorna um bool
*/
boolean ProcuraArray(int n, int *arr, int size)
{
	if (size == 0)
		return FALSE;
	else if (arr[size-1] == n)
		return TRUE;
	else
		return ProcuraArray(n, arr, --size);
}

/*
procura no array(arr) um determinado numero(n).
retorna -1 se n encontrar e a posicao se encontrar
*/
int ProcuraArray2(int n, int *arr, int size)
{
	if (size == 0)
		return -1;
	else if (arr[size-1] == n)
		return size;
	else
		return ProcuraArray2(n, arr, --size);
}

//i é o valor inicial onde começa a procurar

int maiorValor(int i, int array[], int size) {
	if (i == size) {
		return 0;
	}
	if (array[i] > maiorValor(i + 1, array, size)) {
		return array[i];
	}
	return maiorValor(i + 1, array, size);
}