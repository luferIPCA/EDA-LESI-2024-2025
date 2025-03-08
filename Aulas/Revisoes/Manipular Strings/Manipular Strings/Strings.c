/*
Name:  Modelo
Author: oribeiro & lufer
Description:
	Manipular Strings
		- ler
		- mostrar
		- tamanho
		- comparar
		- string == array (conjunto) de caracteres


Obs: Ver mais informação e https://www.tutorialspoint.com/c_standard_library/string_h.htm
*/

#include <stdio.h>;
#include <locale.h>

#define TAMANHONOME 20
#define NUMEROVEZES 3


int main(){
	setlocale(LC_ALL, "Portuguese");

	//declarar variáveis
	char nome[TAMANHONOME];
	char clube1[30];
	char clube2[40];
	char ori[40];
	char dest[40] = "";

	//manipular strings
	char maiorNome[TAMANHONOME];	//armazena o maior nome
	int max;						//armazena o maior tamanho
	int auxTamanho;					//auxiliar para comparar strings
	int n;							//auxiliar controlar ciclo

	//---------- ler strings ---------
	printf("\n----- Ler strings----\n");
	printf("\nNome:");
	//gets(nome);				
	//fgets(nome, TAMANHONOME, stdin);
	//strlen = devolve o tamanho de uma string
	fgets(nome, strlen(nome), stdin);
	nome[strlen(nome) - 1] = '\0';		//NOTA: limpa \n"
	//scanf_s("%s", nome);	
	printf("\nOlá %s\n", nome);

	//---------- Manipular strings ---------
	//tamanho: strlen
	//juntar strings: strcat
	//copiar strings: strcy
	printf("\n----- Manipular strings----\n");
	strcpy(clube1, "Benfica ");
	strcpy(clube2, clube1);
	strcat(clube2, "é o  maior\n");
	printf("\nClube 1: %s \nClube 2: %s\n", clube1,clube2);

	//comparar
	//int strcmp (s1,s2)
	//	0 : s1==s2
	// >0 : s1 > s2
	// <0 : s1 < s2

	auxTamanho = strcmp(clube1, clube1);
	printf("clube 1 e clube 1 -> aux= %d\n", auxTamanho);
	printf("[clube 1 %s clube 1]\n", (auxTamanho==0)? "igual a" : (auxTamanho>0)?"maior que":"menor que");


	auxTamanho = strcmp(clube1, clube2);
	printf("clube 1 e clube 2 -> aux= %d\n", auxTamanho);
	printf("[clube 1 %s clube 2]\n", (auxTamanho == 0) ? "igual a" : (auxTamanho>0) ? "maior que" : "menor que");

	auxTamanho = strcmp(clube2, clube1);
	printf("clube 2 e clube 1 -> aux= %d\n", auxTamanho);
	printf("[clube 2 %s clube 1]\n", (auxTamanho == 0) ? "igual a" : (auxTamanho>0) ? "maior que" : "menor que");

	//atribuir(copiar) strings: strncpy
	//memset(dest, '\0', sizeof(dest));	//limpar memória da string
	printf("\n----- Copiar parcialmente strings----\n");
	strcpy(ori, "Realmente o Benfica é o maior");
	strncpy(dest, ori, 20);
	printf("\nOrigem : %s \nDestino : %s\n", ori, dest);
	
	//----------------- Exercicio ------------------
	//Ler 5 nomes de apresentar qual o maior deles
	//V0: ler e mostrar nomes lidos
	
	printf("\n----- Exercicio: Mostrar N nomes lidos----\n");
	n = 1;		//controlar numero de vezes de leitura
	do{				
		printf("\n%dº Nome:",n);
		gets(nome);
		//fgets(nome, TAMANHONOME, stdin);
		//nome[strlen(nome) - 1] = '\0';
		printf("\n%dº Nome lido= %s\n", n,nome);
		n++;
	} while (n <= NUMEROVEZES);


	//V1: ler e mostrar o maior tamanho
	printf("\n----- Exercicio: Mostrar maior tamanho dos nomes lidos----\n");
	max = -1;	//inicializa variável
	n = 1;		//controlar numero de vezes de leitura
	do{
		printf("\n%dº Nome:", n);
		//gets(nome);
		fgets(nome, TAMANHONOME, stdin);
		nome[strlen(nome) - 1] = '\0';
		//printf("Nome lido= %s\n", nome);
		if (strlen(nome) > max) 
			max = strlen(nome);		
		n++;
	} while (n <= NUMEROVEZES);

	printf("\nMaior tamanho dos nomes lidos= %d\n", max);
	


	//V2: ler e mostrar o maior tamanho e qual o nome
	printf("\n----- Exercicio: Mostrar maior tamanho e maior nome lido----\n");
	max = -1;				//inicializa
	strcpy(maiorNome, "");	//inicializa
	n = 1;		//controlar numero de vezes de leitura
	do{		
		printf("\n%dº Nome:", n);
		//gets(nome);
		fgets(nome, TAMANHONOME, stdin);	//ler do "teclado"
		nome[strlen(nome) - 1] = '\0';		//limpa o "\n"
		if (strlen(nome) > max){
			max = strlen(nome);
			strcpy(maiorNome, nome);
		}
		n++;
	} while (n <= NUMEROVEZES);
	printf("\nMaior tamanho lido= %d e maior nome=%s\n", max, maiorNome);
	

	getche();
	return 0;

}