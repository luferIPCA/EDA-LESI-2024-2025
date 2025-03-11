/*!
 *  @file Dados.h
 *  @author mustl
 *  @date 2025-03-10
 *  @project Hoje
 *
 *  Declares the dados.
 */

#pragma once

#pragma warning (disable:4996)

#define N 10
#define M 100

/*!
 *  Descri��o...
 *  
 */
typedef struct Clube{
	char nome[N];	//nome do clube
	int ns;			//numero de socios do clube
}Clube;


/*!
 *  
 */
typedef struct Socio {
	int numSocio;
	float cota;
}Socio;



typedef struct SociosClube {
	Clube c;			//Dados do clube
	Socio* socios;		//conjunto de todos os socios
	int numSocios;		//auxiliar
}SociosClube;


//Metodo alternativo ao stdbool.h para definir booleanos
//#define bool int
//#define false 0
//#define true 1

typedef struct Element {
	int value;
	struct Element* prox;
}Element;
