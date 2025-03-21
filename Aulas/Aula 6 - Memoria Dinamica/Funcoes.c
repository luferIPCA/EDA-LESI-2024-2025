

#include "Funcoes.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>


#pragma region Clube

/*!
 *  Devolve
 *
 *      @param [in] c 
 */
int NumSocios(Clube c) {
	return c.ns;
}

/*!
 *  Shows the clube.
 *
 *      @param [in] c 
 */
void ShowClube(Clube c) {
	printf("Nome: %s - Nume Socos: %d\n", c.nome, c.ns);
}

/*!
 *  News the club.
 *
 *      @param [in]     numSocios 
 *      @param [in,out] nomeClube 
 *
 *      @return Endereço novo clube
 */
Clube* NewClub(int numSocios, char* nomeClube) {
	Clube* aux;
	aux=(Clube*) malloc(1 * sizeof(Clube));
	if (aux != NULL)		//se foi criada memória
	{
		aux->ns = numSocios;
		strcpy(aux->nome, nomeClube);
	}
	return aux;
}

Clube* NewClubData(int numSocios, char* nomeClube, char* data) {
	Clube* aux = NewClub(numSocios, nomeClube);
	aux->data = *GetDate(data);
	return aux;
}

#pragma endregion

#pragma region Socio

/*!
 *  Crias the socio.
 *
 *      @param [in,out] nome 
 *      @param [in]     cota 
 *
 *      @return Socio
 */
Socio* CriaSocio(int num, float cota) {
	Socio* aux = (Socio*)malloc(1 * sizeof(Socio));
	if (aux) {
		aux->cota = cota;
		aux->numSocio = num;
	}
	return aux;
}

void MostraSocio(Socio* h) {
	if (!h) return;
	printf("Numero de Socio: %d\n", h->numSocio);
	printf("Valor da Cota: %f\n", h->cota);
}
#pragma endregion

#pragma region SociosClube

SociosClube* CriaClubeSocios(Clube c) {
	SociosClube* aux = (SociosClube*)malloc(sizeof(SociosClube));
	if (aux) {
		aux->c = c;			//Associa clube
		aux->socios = (Socio*)malloc(c.ns * sizeof(Socio));	//cria array para total de socios
		aux->numSocios = 0;
	}
	return aux;
}

void MostraSociosClube(SociosClube* h) {

	if (h == NULL) return;
	Socio* aux = h->socios;		//acede ao array de socios
	int i = 0;
	while (i < h->numSocios) {
		MostraSocio(&aux[i]);
		i++;
	}
}

bool InsereNovoSocio(Socio* c, SociosClube* sc) {
	if (sc == NULL || c==NULL) return false;	//Não há socio para inserir
	if (sc->numSocios > sc->c.ns) return false;	//Não há espaço para mais socios

	Socio* aux = sc->socios;
	//h1 - não verifica se já existe
	aux[sc->numSocios] = *c;
	sc->numSocios++;
	return true;
	//h2 - Verifica se já existe: MELHOR OPÇÃO
	//int i = 0;
	//while (i < sc->numSocios && aux[i].numSocio != c->numSocio) i++;
	//if (i == sc->numSocios) {	//não existe, pode inserir
	//	aux[sc->numSocios++] = *c;
	//	return true;
	//}
	//return false;
}
#pragma endregion

#pragma region Auxiliares
/*!
 * Constroi uma data a partir de uma string 
 */
struct tm *GetDate(const char* d) {
	struct tm* date = malloc(sizeof(struct tm)); // reserva memory
	if (!date) return NULL; // algo corre mal

	memset(date, 0, sizeof(struct tm)); // limpa eventual "lixo" na memória alocada!

	char format[] = "%y/%m/%d"; // Segue formato "yy/mm/dd" ...isto pode entrar como parâmetro

	int year, month, day;
	if (sscanf(d, "%d/%d/%d", &year, &month, &day) != 3) {
		free(date); // liberta memória se o parsing falha
		return NULL;
	}
	date->tm_year = year; // 
	date->tm_mon = month; // 
	date->tm_mday = day;

	return date;
}
#pragma endregion