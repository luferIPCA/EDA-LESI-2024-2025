/*!
 *  @file Dados.h
 *  @author mustl
 *  @date 2025-03-07
 *  @project Aula 5 - Memoria Dinamic
 *
 *  Declares the dados.
 */
#pragma once

#define N 20
#define NP 30

/*!
 *  Descreve um aluno
 */
typedef struct Aluno {
	int num;
	char nome[N];
}Aluno;

/*!
 *  Descreve um aluno Erasmus
 */
typedef struct AlunoErasmus {
	Aluno a;
	char pais[NP];
	struct AlunoErasmus* next;
}Erasmus;