/*
* author: lufer
* email: lufer@ipca.pt
* date: 27.02.2022
* desc: Assinaturas e Dados Globais
*/

///@Funcoes.h

//#pragma once
//ou

#include <stdio.h>

#ifndef FUNC
#pragma warning(disable : 4996)		//ignorar avisos 4996

#pragma region Globais

/**
* Total de Objetos
*/
#define N 40
/**
* Número de caracteres de um nome
*/
#define MAXNOME 40	

typedef enum { F, T } bool;	///Boolean

/**
 * The enumeration of space dimension
 */
typedef enum
{
  UND,    /**< 1D */
  DEUXD,  /**< 2D */
  TROISD  /**< 3D */
} dimensions;

/**
* Definição de um Objeto
*/
typedef struct Objeto {
	/*@{*/
	char nome[MAXNOME];	/**< Designação do Objeto*/
	float dist;			/**< Distancia do objeto */
	/*@}*/
}Objeto;

typedef struct AlineaD {
	float alinea;
	Objeto alineab;
	Objeto alineac;
}AlineaD;

/**
* Estrutura de dados com todos os objetos da Ficha de Diagnóstico
*/
extern Objeto objetos[N];				//extern: variável definida algures

#pragma endregion

#pragma region Assinaturas

double MediaArray(double v[], int n);

//a)
float MediaDistanciaObjetos(Objeto v[], int n);

//c
Objeto QualMaisLonge(Objeto v[], int n);

//f
bool GravaDados(char*nomeFicheiro, Objeto v[], int n);

//Ler Dados do ficheiro
long LeDados(char* nomeFicheiro, Objeto v[]);


//d
AlineaD CalculaABC(Objeto v[], int n);


#pragma endregion

#define FUNC
#endif

