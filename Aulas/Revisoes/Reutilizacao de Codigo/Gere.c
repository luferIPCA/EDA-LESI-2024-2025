/*****************************************************************//**
 * \file   Gere.c
 * \brief  Manipular Estruturas Dinâmicas de Dados
 *			Inserir
 *			Eliminar
 *			Procurar
 *			Alterar
 *			Preservar (Guardar em ficheiro, por exemplo!)
 * H1: Abordagem com duplicação de código
 * H2: Abordagem com reutilização: definição e chamada de funções
 * \author lufer
 * \date   April 2022
 *********************************************************************/

#include <stdio.h>

#include "Dados.h"





/// <summary>
/// Guardar informação num array
/// Guardar informação numa Lista (Estrutura Dinâmica de Dados - ETD)
/// </summary>
/// <returns></returns>
int main() {

#pragma region ARRAYS_VERSUS_LISTAS

#pragma region ARRAYS

	int valor[N] = { 2,4,6,8,0,123,-4,5};
	int tot = 8;						//inicio tenho 8 elementos no array
	int novo = 98;

	//no inicio
	valor[0] = novo;

	//inserir valor no final do array
	valor[tot] = novo; tot++;

	//EXERCÍCIO
	//inserir valor no final do array se não existir
			//verificar se esse valor existe
			//se não existe, inserir valor no final do array

	//H1	
	//Verificar se esse valor existe
	bool encontrou = false;
	for (int i = 0; i < tot; i++) {
		if (valor[i] == novo) {
			encontrou = true;
			break; 
		}
	}
	//se não existe, inserir valor no final do array
	if (encontrou==false) {
		valor[tot] = novo; tot++;
	}

	novo = 980;

	//Verificar se esse valor existe
	//Repete-se todo o código anterior
	encontrou = false;
	for (int i = 0; i < tot; i++) {
		if (valor[i] == novo) {
			encontrou = true;
			break;
		}
	}
	if (encontrou == false) {
		valor[tot] = novo; tot++;
	}

	//H2 - Reutilização de código implementado em funções: Existe | InsereFinal
	novo = 200;
	//Verificar se esse valor existe
	if (Existe(valor, tot, novo) != true) {
		//se não existe, inserir valor no final do array
		tot = InsereFinal(valor, tot, novo);
	}

	novo = 230;
	if (Existe(valor, tot, novo) != true) {
		tot = InsereFinal(valor, tot, novo);
	}
#pragma endregion

#pragma region LISTAS

	//Valor varios[N];	//array de structs

	Valor* head;		//inicio da lista de structs

	//Cria uma struct
	Valor v1;
	v1.v = 12;
	strcpy(v1.nome, "Porto");
	v1.proximo = NULL;

	head = &v1;			//inserir Valor na lista...no início da lista!
	printf("Numero: %d\n", head->v);

	
	Valor* novoValor;								//Criar um apontador para struct
	novoValor = (Valor*)calloc(1,sizeof(Valor));	//Necessário criar espaço em memória para conter os dados
	novoValor->v = v1.v*2;							//Colocar dados na struct
	strcpy(novoValor->nome,v1.nome);				//Colocar dados na struct

	//EXERCÍCIO
	//Inserir novo Valor na Lista
			//verificar se esse valor existe
			//se não existe, inserir valor na lista
	//H1
	//verificar se esse valor existe
	encontrou = false;
	if (head!=NULL)
	{ 
		Valor* auxLista = head;
		while (auxLista != NULL) {
			if (auxLista->v == novoValor->v) {
				encontrou = true;
				break;
			}
			auxLista = auxLista->proximo;
		}
	}
	//se não existe, inserir valor na lista
	if (encontrou == false) {
		//inserir no inico da lista
		novoValor->proximo = head;
		head = novoValor;
	}

	//H2 - Reutilização
	if (ExisteLista(novoValor->v, head) == false) {
		head = InsereInicioLista(novoValor, head);
	}
	if (ExisteLista(v1.v, head) == false) {
		head = InsereInicioLista(&v1, head);
	}

	//Apresentar elementos da Lista
	MostraLista(head);




#pragma endregion

#pragma endregion

#pragma region LISTAS_FICHEIRO_BINÁRIO

	FILE* fp;
	ValorFicheiro aux;

	//EXERCICIO
	//Guardar informação da memória em ficheiro

	//H1 - Escrever código necessário
	//Criar ficheiro e gravar dados
	fp = fopen("Dados.bin", "wb");
	if (fp != NULL) {
		//copiar dados de novoValor para celula do ficheiro
		aux.v = novoValor->v;
		strcpy(aux.nome, novoValor->nome);
		fwrite(&aux, sizeof(ValorFicheiro), 1, fp);
		fclose(fp);
	}
	//fseek(fp, 0, SEEK_SET);
	//novoValor = (Valor*)calloc(sizeof(Valor));
	//fread(novoValor, sizeof(Valor), 1, fp);
	//fclose(fp);

	//Abrir ficheiro e ler dados
	//head = NULL;
	fp = fopen("Dados.bin", "rb");
	if (fp != NULL) {
		fread(&aux, sizeof(ValorFicheiro), 1, fp);
		//Copiar dados do ficheiro para célula em memória
		novoValor = (Valor*)calloc(sizeof(Valor));
		novoValor->v = aux.v;
		strcpy(novoValor->nome, aux.nome);
		if (ExisteLista(novoValor->v, head) == false) {
			head = InsereInicioLista(novoValor, head);
		}
		fclose(fp);
	}
	MostraLista(head);

	//H2 - Chamar funções 
	GravaFicheiro("Dados.bin", head);
	head = NULL;			//anuar a lista
	head = LeFicheiro("Dados.bin", head);

	MostraLista(head);
#pragma endregion

}

