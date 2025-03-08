//#pragma once

#ifndef BOOLEAN
#define BOOLEAN

typedef enum { FALSE, TRUE } boolean;

#endif // !BOOLEAN


#ifndef RECUR
#define RECUR

int Factorial(int n);
int Potencia(int base, int exp);
int Fibonacci(int x);
boolean procuraArray(int n, int *arr, int size);
int procuraArray2(int n, int *arr, int size);

int maiorValor(int i, int array[], int size);


#endif // !RECUR

