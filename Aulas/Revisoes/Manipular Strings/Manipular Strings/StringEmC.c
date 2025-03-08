/*
	Name:  Modelo
	Author: oribeiro & lufer
	Description:
*/
#include <stdio.h>
#include <string.h>
// declaração ou assinatura das funções locais

// função principal
int main_1() {
	// declaração e inicialização de variáveis
    char a[5] = {'L', 'P', '1', '\0'};
    char b[15] = "Ling Prog 1";
    char c[15] = "LP1\0AED";
    char d[15];

    int comprimento;
	// dados de entrada

	// cálculos
    // atribuir o conteúdo de b a d
     // d = b; // errado: seria a atribuição dos endereços
     strncpy(d, b, 15);
     // alterar d para LP2
     d[10] = '2';

    // calcular comprimento da string
    comprimento = strlen(c); // "string length" definida em string.h

    // comparar uma string (ordem lexicográfica / Alfabética)
    // funcao strcmp "string compare"

	// resultados
    //printf("conteúdo de a: [%s] (endereço %d) *a = %c\n", a, a, *a);
    printf("conteúdo de b: [%s] \n",b );
    printf("conteúdo de c: [%s] comprimento: %d \n", c, comprimento );
    printf("conteúdo de d: [%s] \n",d );

	return 0;
}

// definição das funções
/* procedimento (função que não devolve nada, tipo void)
    para testar a função strcmp de string.h
    */
void testaComparacao(char *lesq, char *ldir){
    int rc; // resultado da comparação

    // strcmp "string compare" (definida em string.h)
    // permite comparar (ordem alfabética) duas strings, devolvendo:
    //   < 0 : a primeira aparece primeiro (menor) do que a segunda
    //   == 0: são iguais
    //   > 0 : a primeira aparece depois (maior) do que a segunda

    rc = strcmp(lesq, ldir);
    if (rc < 0) {
        printf("[%s] aparece primeiro (menor) do que  [%s]", lesq, ldir);
    } else if (rc == 0) {
        printf("[%s] é igual a [%s]", lesq, ldir);
    } else { // rc > 0
        printf("[%s] aparece depois (maior) do que  [%s]", lesq, ldir);
    }

}

