/*
Funções para manipular arrays de structs
lufer@ipca.pt

Ver: 
	https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
	http://www.geeksforgeeks.org/sorting-algorithms/#Basic
*/

#include "funcoes.h"
/*
Apresenta array no ecra
*/
void mostraArray(struct pessoa v[], int t) {
	for (int i = 0; i < t; i++) {
		printf("Idade= %d Nome= %s\n", v[i].idade, v[i].nome);
	}
}

void mostraArraySimples(int v[], int t) {
	for (int i = 0; i < t; i++) {
		printf("v[%d]=%d\n ", i, v[i]);
	}
}

/*
Calcula a idade da pessoa mais velha
*/
int maiorIdade(pessoa p[], int t) {
	int idade = p[0].idade;
	for (int i = 1; i < t; i++) {
		if (idade < p[i].idade) 
			idade = p[i].idade;
	}
	return idade;
}

/*
Identifica a pessoa mais velha
*/
pessoa pessoaMaisVelha(pessoa p[], int t) {
	int idade = p[0].idade;
	pessoa aux = p[0];
	for (int i = 1; i < t; i++) {
		if (aux.idade < p[i].idade) 
			aux = p[i];
	}
	return aux;
}

/*
Devolve a posição onde se encontra a pessoa mais velha
*/
int posicaoPessoaMaisVelha(pessoa p[], int t) {
	int idade = p[0].idade;
	int pos = 0;

	pessoa aux = p[0];
	for (int i = 1; i < t; i++) {
		if (aux.idade < p[i].idade)
			pos = i;
	}
	return pos;
}

/*
	Identifica o nome da pessoa mais velha
	Reutilizar funções existentes
*/
char* nomePessoaMaisVelha(pessoa p[], int t) {	
	pessoa aux = pessoaMaisVelha (p, t);
	return (aux.nome);
}


/*
Ordena um array
*/
void ordenaArrayInteiros(int valores[], int s)
{
	int aux;
	for (int i = 0; i < s-1;i++) {
		for (int j = i + 1; j < s;j++ ) {
			if (valores[i] > valores[j]) {
				//trocar
				aux = valores[i];
				valores[i] = valores[j];
				valores[j] = aux;
			}
		}
	}
}

/*
Ordena um array de structs (pessoa)
*/
void ordenaArrayPessoas(pessoa p[], int s)
{
	pessoa aux;
	for (int i = 0; i < s - 1; i++) {
		for (int j = i + 1; j < s; j++) {
			if (p[i].idade > p[j].idade){
				//troca
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
		}
	}
}


//ANALISAR
/* insere um elemento (x) num array ordenado. Assuma que as N primeiras
posições do array estão ordenadas e que por isso, após a inserção o
vector terá as primeiras N+1 posições ordenadas */
void insereOrdenadoArray(int v[], int N, int x) {
	int i = 0, k;
	/* 1º Passo: avançar enquanto v[i] <= x */
	while ((i < N) && (v[i] <= x)) {
		i++;
	}
	/* ao sair do ciclo: v[i] > x */
	/* 2º Passo: passar os elementos para a posição seguinte... */
	k = N-1;
	while (k >= i + 1) {
		v[k] = v[k - 1];
		k--;
	}
	//3ªpasso
	v[i] = x;
}
