/*!
 *  @file Dados.h
 *  @author mustl
 *  @date 2025-03-21
 *  @project Aula 8
 *
 *  Declares the dados.
 *
 */

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#pragma warning (disable:4996)

#define M 100

/*!
 *  Elemento da lista
 */
typedef struct Element {
	int value;
	char nome[M];
	struct Element* prox;
}Element;

/*!
 *  Gere a lista de elementos
 */
typedef struct Elements {
	struct Element* head;
	int totalElements;
}Elements;


typedef struct ElementFile {
	int value;
	char nome[M];
}ElementFile;

