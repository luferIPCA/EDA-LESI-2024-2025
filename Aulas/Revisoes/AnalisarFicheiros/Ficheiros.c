/*
	Name:
	Author: lufer
	Date: 2022
	Description:
		- Manipulação de Ficheiros
		- Exploração para Trabalho Prático
	
	Parsing de ficheiros de texto:
		fscanf
		sscanf
		strtok
		"regex.h"
	Ver: 
	https://www.tutorialspoint.com/cprogramming/c_file_io.htm
	https://users.informatik.haw-hamburg.de/~krabat/FH-Labor/gnupro/4_GNUPro_Libraries/a_GNUPro_C_Library/libcscanf_fscanf_sscanfscan_and_form.html

	Algoritmo:
	- Repetir
		- Ler frase inteira do ficheiro (com fscanf)
		- Analisar frase na memória com: sscanf e strtok
	- Enquanto não chegar ao fim do ficheiro
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

#define TAM 1000	
#define N 20

//-------------------------------------------------------------------------

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Portuguese");

#pragma region VERSAO1
	//Ficheiro formatado
	char c[TAM] = "";
	char fileName[N] = "FicheiroDados.txt";
	FILE* fp = NULL;					//handler de ficheiro de entrada
	
	if (argc == 2) {
		strcpy(fileName, argv[1]);
	}
	fp = fopen(fileName, "r"); // abrir frases.txt em modo leitura
	//se houve algum problema com a abertura do ficheiro...
	if (fp == NULL) {
		perror("Erro ao abrir o ficheiro\n");
		getche();
		return(-1);
	}
	//se consegiu aceder ao ficheiro
	int l = 1;		//conta linhas lidas
	int linOper=0;
	while (fscanf(fp, "%[^\n] ", c) != EOF) {	//lê até ao fim da linha
		printf("File Data:\n%s\n", c);
		if (l == 1)	//tem valores do tipo "8x7x8"
		{
			int proc, maq, oper;
			int x = sscanf(c, "%dx%dx%d", &proc, &oper, &maq);
			printf("Proc: %d, Oper: %d, Maq: %d\n", proc,oper, maq);
			l++;
			continue;
		}
		//valores sobre job e número de operações
		if (l == 2) { //tem valores do tipo "1.1 4"
			char s[40];
			int numOper;
			int x = sscanf(c, "%s%*c%d",s , &numOper);	//%*c...encontra o char e não guarda!!!
			printf("Proc: %s, Oper: %d\n", s, numOper);
			l++;
			linOper= numOper;
			continue;
		}
		//Restantes linhas são maquinas para operações
		if (linOper > 0) { //
			int m, t;
			/*char *token;
			token = strtok(c, "-");
			while (token != NULL) {
				printf("%s\n", token);
				token = strtok(NULL, "-");
			}*/
			/*sscanf(c, "%*c%d%*c%d", &m, &t);
			printf("Maq: %d, Tempo: %d\n", m, t);*/

			char str[] = "Geeks-for-Geeks";

			// Returns first token
			char* token = strtok(str, "-");

			// Keep printing tokens while one of the
			// delimiters present in str[].
			while (token != NULL) {
				printf("%s\n", token);
				token = strtok(NULL, "-");
			}

			linOper--;
			if (linOper == 0) {
				l = 1;			//preparar para ler proximo grupo de linhas
			}
			continue;
		}
	}
	fclose(fp);

#pragma endregion

#pragma region VERSAO2

	//Ficheiro formatado como csv
	//usar fgets()+strok()
	//FILE* fp;
	char c1[TAM];
	char* token;
	fp = fopen("FicheiroDados.csv", "r");
	if (fp==NULL) exit(1); 
	while (fgets(c1, TAM, fp)!=NULL){
		c1[strlen(c1) - 1] = '\0';
		token = strtok(c1, ";");
		while (token != NULL) {
			printf("%s\n", token);
			token = strtok(NULL, ";");
		}
	}
	fclose(fp);

	
#pragma endregion

}
