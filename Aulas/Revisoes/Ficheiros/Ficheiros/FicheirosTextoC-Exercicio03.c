/*
Name:
Author: lufer & oribeiro
Date: 
Description:
- Manipulação de Ficheiros
- Exercício:

	- Ler dados formatados de um ficheiro
	- Considerar notas a LP, separadas por 1 espaço
		nomeAluno, numeroAluno, nota1, nota2

		Manuel 14325 12 16
		Maria 12345 10 17
	- Mostrar notas dos alunos
	- Calcular a média do aluno
	- Calcular a média da turma

Ver:
http://www.cprogressivo.net/2013/11/Como-ler-arquivos-em-C-As-funcoes-fgetc-fscanf-fgets.html
*/
#include <stdio.h>
#include <locale.h>
#pragma warning (disable: 4996)
#define TAM 40			//define uma "constante"

int main(void)
{
	//variáveis
	char url[] = "notas.txt";
	char nome[TAM];
	int numero;

	float nota1, nota2, media;

	//float totalTurmaNota1 = 0, mediaTurmaNota1;
	//int totAlunos = 0;
	FILE *arq;

	//corpo do programa
	arq = fopen(url, "r");
	if (arq == NULL)
		printf("Atenção, erro ou notas ainda por lançar\n");
	else
	{
		while ((fscanf(arq, "%s %d %f %f\n", nome, &numero, &nota1, &nota2)) != EOF) {
			printf("%s teve media %.2f\n", nome, (nota1 + nota2) / 3);
			//totalTurmaNota1 += nota1;
			//totAlunos++;
		}
		//mediaTurmaNota1 = totalTurmaNota1 / totAlunos;
		//printf("Media da turma= %f\n", mediaTurmaNota1);
	}
	fclose(arq);
	getche();
	return 0;
}

