/*
	Name:  Modelo
	Author:
	Date: 18/10/17 14:00
	Description:   programa para permitir registar novas inscrições (nome)
                    no ficheiro de texto "inscrições.txt", e listar as inscrições atuais.

*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define TAM 50
#pragma warning (disable: 4996)

// declaração ou assinatura das funções locais
char apresentaMenu();
void inserirInscricoes(char *nomeFicheiro);
void listarInscricoes(char *nomeFicheiro) ;
// função principal
int main2() {
    setlocale(LC_ALL, "Portuguese");
	// declaração e inicialização de variáveis
	char op;
	char *nomeFicheiro = "inscricoes.txt";
    do {
       op = apresentaMenu();
        switch(op) {
            case '1':
                 inserirInscricoes(nomeFicheiro);
                 break;
             case '2': listarInscricoes(nomeFicheiro);
                 break;
             case '3': break;
             default: printf("opcao desconhecida!\n");
                    break;
        }
    } while(op != '3');

	return 0;
}

// definição das funções
char apresentaMenu(){
    char opcao;
    printf("-- menu --   \n");
    printf("1. inscrever\n");
    printf("2. listar\n");
    printf("3. sair \n");
    printf("opcao? ");
    //opcao = getchar();
	//printf("%c\n", opcao);
	while ((opcao = _getch()) < '1' || opcao > '3') { putchar(7); }	//valida entrada de valores
	
    //getchar(); // limpar \n no buffer do teclado
    return opcao;
}

void inserirInscricoes(char *nomeFicheiro) {
    FILE *af;
    char frase[TAM] ;

    // abrir  ficheiro em modo acrescentar ( a )
    af = fopen(nomeFicheiro, "a") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("\n--- inscrição (FIM para terminar) --\n");
        // ler o primeiro nome
        printf("nome? ");
        fgets(frase,TAM,stdin);
        frase[strlen(frase)-1] = '\0';
        while (strcmp(frase,"FIM")!=0) { // frase diferente de FIM
             // acrescentar um linha ao ficheiro
            fprintf(af, "%s\n", frase); // escrever o nome lido no ficheiro

            // ler o segundo nome e seguintes
            printf("nome?");
            fgets(frase,TAM,stdin);
            frase[strlen(frase)-1] = '\0';
        }
        printf("--- FIM das inscrições  -- \n\n");
        fclose(af); // fechar o descritor de ficheiro
    }

}

void listarInscricoes(char *nomeFicheiro) {
    FILE *af; // apontador para descritor de ficheiro
    char frase[TAM] ;
    int nLinhas = 1;
    // abrir  ficheiro em modo leitura (r)
    af = fopen(nomeFicheiro, "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("\n--  lista de inscrições: \n\n");
        // leitura do ficheiro linha a linha
        while (fgets(frase, TAM, af) != NULL){
           printf("%2d: ", nLinhas);
           nLinhas = nLinhas +1;
           printf("%s", frase);
        }
        printf("---  total de %d  inscrições. \n\n", nLinhas - 1);
        fclose(af); // fechar o descritor de ficheiro
    }
}
