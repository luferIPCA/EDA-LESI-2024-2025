/*
Funções para manipular arrays de apontadores para structs
lufer@ipca.pt

Ver:
https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#include "Dados.h"



/*
Auxiliar: apresenta toda a informação sobre cada jogo
*/
void MostraJogos(Jogo jogos[], int t) {
	for (int i = 0; i < t; i++) {
			printf("Jogo= %d | Nome= %s | Ano: %d\n", jogos[i].cod, jogos[i].nome, jogos[i].data.ano);
	}
}

/*
Auxiliar: apresenta toda a informação sobre cada jogo
*/
void MostraJogosII(Jogo *jogos[], int t) {
	for (int i = 0; i < t; i++) {
		if (jogos[i]!=NULL)
		printf("Jogo= %d | Nome= %s | Ano: %d\n", jogos[i]->cod, jogos[i]->nome, jogos[i]->data.ano);
	}
}


/**
* Inicializa o array de apontadores
*/
bool InicializaArray(Jogo* jogos[], int n) {
	if (n < 0) return false;
	for (int i = 0; i < n;i ++) {
		jogos[i] = NULL;
	}
	return true;
}
/*
Insere novo jogo numa determinada posição
Jogo passa por parâmetro
*/
int InsereJogo(Jogo* jogos[], Jogo j, int pos) {
	//0º Verificar se o array tem capacidade e a posição é válida
	if (pos < 0 || pos > MAX) return -1;

	// Ver se o jogo já existe
	if (ExisteJogo(jogos, j.cod, MAX) == true) return -1;

	//1º criar espaço em memoria para um jogo
	jogos[pos] = (Jogo*) malloc(sizeof(Jogo));

	//2ª coloco array a apontar para esse espaço
	jogos[pos]->cod = j.cod;
	strcpy(jogos[pos]->nome,j.nome);
	jogos[pos]->data = j.data;
	pos++;
	return pos;
}

/*
Insere novo jogo.
Endereço de jogo passa por parâmetro
*/
int InsereJogoII(Jogo* jogos[], Jogo *j, int pos) {
	//ATENÇÃO: Verificar se jogo já existe
	jogos[pos] = j;
	pos++;
	return pos;
}
/*
Verifica se determinado jogo existe
*/
bool ExisteJogo(Jogo* jogos[], int cod, int n) {
	for (int i = 0; i < n; i++) {
		if (jogos[i]!=NULL && jogos[i]->cod == cod) return true;
	}
	return false;
}

/**
* Aloca espaço em memória para um jogo
*/
Jogo* criaJogo(int cod, char* nome, char tipo) {
	Jogo* novoJogo = (Jogo*)malloc(sizeof(Jogo));
	novoJogo->cod = cod;
	novoJogo->tipo = tipo;
	strcpy(novoJogo->nome, nome);
	return novoJogo;
}