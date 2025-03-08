/*
* author: lufer
* email: lufer@ipca.pt
* date: 27.02.2022
* desc: Módulo de Implementação
* vers: Documentação de código para DoxyGen
* https://wiki.scilab.org/Doxygen%20documentation%20Examples
*/

#include "Funcoes.h"

#pragma region ImplementacaoFicha

/**
a) Calcula média de um array de objetos
 * @param[in] v Arrays Objetos
 * @param[in] n Numero de Objetos
 * @param[out] Média
*/
float MediaDistanciaObjetos(Objeto v[], int n) {
	float avg = 0.0;

	//int n = sizeof(v)/sizeof(v[0]);	//calcula o tamanho do array...

	for (int i = 0; i < n; i++) {	//calcula a soma de todos os valores
		avg += v[i].dist;
	}
	return (avg/n);				//calcula e devolve a média
}

//b)Qual a distância e designação do objeto que se encontra mais longe
//1º Calcular a maior distância
//2º Devolver os dados
Objeto QualMaisLonge(Objeto v[], int n) {
	int indiceMaisLonge = 0;		//no  início é o 1º objeto
	
	for (int i = 0; i < n; i++) {	//calcula a soma de todos os valores
		if (v[indiceMaisLonge].dist < v[i].dist) {
			indiceMaisLonge = i;
		}
	}
	return v[indiceMaisLonge];
}


//f)	Preservar os dados num ficheiro
bool GravaDados(char* nomeFicheiro, Objeto v[], int n) {
	FILE* af;
	int i;

	af = fopen(nomeFicheiro, "wb");		//abre ficheiro em modo binario para escrita
	if (af == NULL)
		return F;
	else {
		for (int i = 0; i < n; i++) {
			fwrite(&v[i], sizeof(v[i]), 1, af);
		}
		fclose(af);
		return T;
	}
}

/**
* Le dados de um ficheiro
* @param[in] Nome do Ficheiro a ler
* @param[out] Valores lidos do Ficheiro
 */ 
long LeDados(char* nomeFicheiro, Objeto v[]) {
	FILE* f;
	long size=0;

	f = fopen(nomeFicheiro, "rb");

	//Caso seja necessáario determinar o tamanho do ficheiro
	//fseek(f, 0, SEEK_END);		// seek to end of file
	//size = ftell(f);			// get current file pointer
	//fseek(f, 0, SEEK_SET);		// seek back to beginning of file
	if (f == NULL)
		return -1;
	else {
		int i = 0;
		while (fread(&v[i++], sizeof(Objeto), 1, f) == 1);
		size = i - 1;
		fclose(f);
		}
	return size;
}

/**
* Calcula as alineas a, c e c
*/
AlineaD CalculaABC(Objeto v[], int n) {
	AlineaD res;
	res.alinea= MediaDistanciaObjetos(v, n);
	res.alineab = QualMaisLonge(v, n);
	//res.alineac=QualMaisProximo(v, n);
	return res;
}
#pragma endregion


