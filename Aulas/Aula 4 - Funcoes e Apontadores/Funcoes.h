/*!
 *  @file Funcoes.h
 *  @author mustl
 *  @date 2025-02-28
 *  @project Hoje
 *
 *  Declares the funcoes.
 */
#pragma once

typedef struct Pessoa {
	int idade;
	struct Pessoa* colega;
}Pessoa;

/*
*/
int Soma(int* x, int * y);

int Maior(int v[], int n);

int MaiorPt(int* v[], int n);

int SomaMaiorArray(int v[], int a, int* r);

int SomaMaiorArrayPtr(int *v[], int a, int* r);
