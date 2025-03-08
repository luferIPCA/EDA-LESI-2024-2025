
#include <stdbool.h>

#ifndef X
#define X 1

#define MAX 50

typedef enum Sexo {M,F} Sexo;

typedef struct Pessoa {
	int numero;
	Sexo sexo;
	char nome[MAX];
	struct Pessoa* next;
}Pessoa;

int ProcuraPosicao(Pessoa alunos[], int n, int numero);
Pessoa RemovePessoa(Pessoa alunos[], int* n, int numero);
Pessoa* CriaPessoa(int numero, char nome[], Sexo s);

#endif // !X
