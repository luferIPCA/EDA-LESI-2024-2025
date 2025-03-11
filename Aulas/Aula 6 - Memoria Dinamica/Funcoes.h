/*!
 *  @file Funcoes.h
 *  @author mustl
 *  @date 2025-03-11
 *  @project Aula 6 - Memória Dinamica
 *
 *  Implementação  de funções.
 */

#include "Dados.h"
#include <stdbool.h>

#pragma once

#pragma region clube
/*!
 *
 *  @clube: Nome do clube 
 */
void ShowClube(Clube c);

Clube* NewClub(int numSocios, char* nomeClube);

int NumSocios(Clube c);

#pragma endregion

#pragma region Socio

Socio* CriaSocio(int num, float cota);

void MostraSocio(Socio* h);

#pragma endregion

#pragma region SociosClube

SociosClube* CriaClubeSocios(Clube c);

void MostraSociosClube(SociosClube *h);

bool InsereNovoSocio(Socio *c, SociosClube* sc);

#pragma endregion

