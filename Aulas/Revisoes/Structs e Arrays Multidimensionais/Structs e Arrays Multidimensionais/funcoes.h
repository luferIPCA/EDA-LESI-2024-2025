/*
	Funções para manipular Arrays
	lufer
	Ver: https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
*/
#ifndef DADOS
#define DADOS 

#include <stdio.h>

typedef struct pessoa {
	int idade;
	char nome[10];
}pessoa;


//Cabeçalhos de funções e métodos
void mostraArray(pessoa v[], int t);
void mostraArraySimples(int v[], int t);

//idade da pessoa mais velha
int maiorIdade(pessoa p[], int t);

//TPC:
//Nome da pessoa mais velha
//Calcular a média das idades de todas as pessoas

//Identifica a pessoa mais velha
pessoa pessoaMaisVelha(pessoa p[], int t);
//Devolve a posição onde se encontra a pessoa mais velha
int posicaoPessoaMaisVelha(pessoa p[], int t);
//Calcula a idade da pessoa mais velha
int maiorIdade(pessoa p[], int t);
//Identifica o nome da pessoa mais velha
char* nomePessoaMaisVelha(pessoa p[], int t);

//TPC
int calculaMaximoArray(int v[]);
int quantosExistem(int v[], int valor);
int posicaoValorArray(int v[], int valor);


//Ordenar array
void ordenaArrayInteiros(int v[], int s);
void ordenaArrayPessoas(pessoa p[], int s);
#endif // !DADOS