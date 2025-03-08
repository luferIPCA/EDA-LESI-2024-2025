#include <stdio.h>

/**
Calcula a media .....
 */
float mediaReal(int v[], int n) {

	int soma = 0;
	float media;

	for (int i = 0; i < n; i++) {
		soma += v[i];
	}
	media = soma / (float)n;
	return (media);

}

/*
*CalculaLa a dist....
*/
float maiorDistancia(int v[], int n){

	int maior = v[0];
	for (int i = 0; i < n; i++) {
		if (maior < v[i]) maior = v[i];
	}
	return maior;
}

float devolveTresResultados(int v[], int n, int* maior, int* menor) {

}

