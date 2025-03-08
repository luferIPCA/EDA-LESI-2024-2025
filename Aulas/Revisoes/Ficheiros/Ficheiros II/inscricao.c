
#include "inscricao.h"
#pragma warning (disable: 4996)

/* -------------------------------------------
   assinatura das funções auxiliares (apenas utilizadas em inscricao.c)
   ---------------------------------------------   */
void escreverCabecalho();
void mostraInscricao(char nome[], int dia, int mes, int ano);
int calcularIdade(int dia, int mes, int ano);
void listarInscricaoN(FILE *af, int nInscricao);
void lerLinhaN(char *nomeFicheiro, int linha, char conteudo[] );


/* ----------------------------------------
   implementação das funções principais (assinatura colocada em inscricao.h)
   ----------------------------------------   */
void inserirInscricoes(char *nomeFicheiro) {
    FILE *af;
    char frase[TAM] ;
    int dia, mes, ano;
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
            // ler a data: dia, mes e ano
            printf("data nascimento? (dd/mm/aaaa)  ");
            scanf("%d/%d/%d", &dia, &mes, &ano );
            getchar(); // limpar \n
             // acrescentar uma inscrição ao ficheiro
            fprintf(af, "%s\n", frase); // escrever o nome lido no ficheiro
            fprintf(af, "%d/%d/%d\n", dia, mes, ano ); // escrever o nome lido no ficheiro

            // ler o segundo nome e seguintes
            printf("nome?");
            fgets(frase,TAM,stdin);
            frase[strlen(frase)-1] = '\0';
        }
        printf("--- FIM das inscrições  -- \n\n");
        fclose(af); // fechar o descritor de ficheiro
    }

}

/*
Lista todas as inscrições existentesno ficheiro
*/
void listarInscricoes(char *nomeFicheiro) {
    FILE *af; // apontador para descritor de ficheiro
    char nome[TAM] ;
    int dia, mes, ano ;
    // abrir  ficheiro em modo leitura (r)
    af = fopen(nomeFicheiro, "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("\n--  lista de inscrições: \n\n");
        escreverCabecalho();
        // leitura do ficheiro linha a linha
        while (fgets(nome, TAM, af) != NULL){
            nome[strlen(nome)-1] = '\0'; // limpar \n
            // ler data de nascimento
            fscanf(af, "%d/%d/%d\n", &dia, &mes, &ano);
            // escrever valores lidos
			mostraInscricao(nome, dia,mes, ano);
        }
        printf("--------------------------------  \n\n");
        fclose(af); // fechar o descritor de ficheiro
    }
}

/*
Mostra apenas uma inscrição em particular
*/
void listarUmaInscricao(char *nomeFicheiro){
    FILE *af; // apontador para descritor de ficheiro

    int n = 0;
    // abrir  ficheiro em modo leitura (r)
    af = fopen(nomeFicheiro, "r") ;
    // testar se ocorreu erro na abertura do ficheiro
    if (af == NULL)
        printf("Erro na abertura do ficheiro %s !\n", nomeFicheiro);
    else {
        printf("Qual o nº da inscrições que pretende ver? ");
        scanf("%d", &n);
        while (getchar()!='\n'); // limpa o buffer do teclado

        listarInscricaoN(af, n);

        fclose(af); // fechar o descritor de ficheiro
    }
}


/* -------------------------------------------
 implementação das funções auxiliares (apenas utilizadas em inscricao.c)
   ---------------------------------------------   */
/*
Mostra N Fichas
*/
void listarInscricaoN(FILE *af, int nInscricao) {
    char nome[TAM];
    int dia, mes, ano;
    int contaInscricoes= 0;
    while ((contaInscricoes < nInscricao) && (fgets(nome, TAM, af) != NULL) ) {
            nome[strlen(nome)-1] = '\0'; // limpar \n
            fscanf(af, "%d/%d/%d\n", &dia, &mes, &ano);
			mostraInscricao(nome, dia, mes, ano);
            contaInscricoes += 1;
    }

   if (contaInscricoes < nInscricao)
   {
       printf("inscrição %d não existe (existem apenas %d inscrições)...\n", nInscricao, contaInscricoes);
   } else {
       printf("------------------------------\ninscrição %d:   \n", nInscricao);
       escreverCabecalho();
	   mostraInscricao(nome, dia, mes, ano);
       printf("--------------------------------  \n\n");
    }
}

void escreverCabecalho() {
    char tituloNome[5] = "Nome";
    char tituloDN[11] = "Data Nasc.";
    char tituloIdade[6] = "Idade";
    printf("%-30s\t%-10s\t%s\n", tituloNome, tituloDN, tituloIdade);
}

void mostraInscricao(char nome[], int dia, int mes, int ano) {
            printf("%-30s\t", nome);
            printf("%d/%d/%d\t", dia, mes, ano);
            printf("%3d\n", calcularIdade(dia, mes, ano));
}

int calcularIdade(int dia, int mes, int ano) {
    int resultado;
    resultado = 2017 - ano; // se nasc. antes (ou em) 30.10.2017
    if (mes > 10 )
        resultado = resultado -1;
    else if (mes == 10) {
        if (dia > 30) {
                resultado = resultado -1;
        }
    }
    return resultado;
}
