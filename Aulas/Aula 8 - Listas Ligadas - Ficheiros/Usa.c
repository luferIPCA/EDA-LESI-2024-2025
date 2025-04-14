/*!
 *  @file Usa.c
 *  @author mustl
 *  @date 2025-03-25
 *  @project Aula 8 - Listas Ligadas - Ficheiros
 *
 *  Implements the usa.
 *      
 */
#include "Dados.h"
#include "Funcoes.h"
#include <stdio.h>

int main() {

	Element* aux;		//auxiiar para criar elementos
	Element* inicio=NULL;	//auxiliar para conter a lista!!!

#pragma region CRIA_LISTA

	aux = CriaElemento(12, "ola");//cria um novo  elemento

	inicio = InsereOrdenado(inicio, aux);		//

	aux = CriaElemento(120, "ola2");

	inicio = InsereOrdenado(inicio, aux);

#pragma endregion

#pragma region GERE_LISTA
#pragma endregion

#pragma region PRESERVA
#pragma endregion

}