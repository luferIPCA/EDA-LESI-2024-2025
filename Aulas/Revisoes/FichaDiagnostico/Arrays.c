/**
* Author: lufer
* Email: lufer@ipca.pt
* Date: 27-02-2022
* Desc: Módulo para gerir Arrays
* ????
*/

#include "Funcoes.h"

#pragma region Arrays

/**
* Procura o maior valor de uma array...
*/
int FindMaxArray(int valores[], int n) {

	int aux = valores[0];
	for (int i = 1; i < n; i++) {
		if (aux < valores[i]) aux = valores[i];
	}
	return aux;
}

/**
 * Calcula média de um array de valores reais
 * @param[in] Valores
 * @param[in] Numero de Valores
 * @param[out] Média
*/
double MediaArray(double v[], int n) {
	double avg = 0.0;		///auxiliar

	for (int i = 0; i < n; i++) {	//calcula a soma de todos os valores
		avg += v[i];
	}
	return (avg / n);				//calcula e devolve a média
}

#pragma endregion


