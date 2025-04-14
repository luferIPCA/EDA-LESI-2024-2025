/*****************************************************************//**
 * @file   Jogos.h
 * @brief  Listas Ligadas Genéricas
 * 
 * @author lufer
 * @date   April 2025
 *********************************************************************/
#pragma once

#pragma region JOGOS
// Estruturas de Dados

typedef struct
{
	char arma[50]; // arma de combate
	int pontuacao; // 0 a 100
} Preferencias;

typedef struct Dados
{
	int numero;
	char nome[50];
	Preferencias preferencias[5]; // ordem de preferências (máximo de 5)
}*Jogador;

void show(Jogador* j);
int igual(void* data1, void* data2);
int compararNomes(void* data1, void* data2);
int comparar(void* data1, void* data2);
int igual(void* data1, void* data2);
#pragma endregion

