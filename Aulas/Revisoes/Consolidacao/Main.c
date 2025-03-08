
#include <stdio.h>
#include "Funcoes.h"


//2ª Funcões

///**
//Calcula a media ..... 
// */
//float mediaReal(int v[], int n) {
//
//	int soma = 0;
//	float media;
//
//	for (int i = 0; i < n; i++) {
//		soma += v[i];
//	}
//	media = soma / (float)n;
//	return (media);
//
//}


#define N 5

/*
* Programa para ....
*/
int main(){

	int n = 5;

	//H1ª tudo no main

	//int x=10, y=11, z=21;	//valores assumidos!


	//float media = (x + y + z) /(float) 3;

	//printf("Media: %f", media);


	//H2

	int valores[] = { 1,2,3,4,56 };
	printf("Media = %f", mediaReal(valores, n));


	//H3
}
