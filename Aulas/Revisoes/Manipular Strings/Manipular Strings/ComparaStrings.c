/*
	Name:  Modelo
	Author: oribeiro & lufer
	Description:
*/
#include <stdio.h>
#include <string.h>

// declaração ou assinatura das funções locais
void indicaMaiorAlfabetica(char *frase1, char *frase2);

// função principal
int main_2() {
	// declaração e inicialização de variáveis
    char frase1[20];
    char frase2[20];
    int opcao ;
    int comprimento;
	// dados de entrada
    printf("primeira frase? ");
    fgets(frase1,20,stdin);
    frase1[strlen(frase1)-1] = '\0'; // limpa \n

    printf("segunda frase? ");
    fgets(frase2,20,stdin);
    frase2[strlen(frase2)-1] = '\0';

    // mostrar os valores lidos
	printf("conteúdo de frase1: [%s] tam=%d \n", frase1, strlen(frase1));
	printf("conteúdo de frase2: [%s] tam=%d \n", frase2, strlen(frase2));

	// opções para ordenação
	printf("indicar maior palavra pelo:\n");
	printf("\t 1. comprimento \n");
    printf("\t 2. ordem alfabética \n");
    printf("opção? ");
    scanf("%d",&opcao);

    switch (opcao) {
        case 1: // indicaMaiorComprimento(frase1, frase2);
                break;
        case 2: indicaMaiorAlfabetica(frase1, frase2);
                break;
        default:
            printf("opção desconhecida.");
            break;
        }

	// cálculos

	// resultados


	return 0;
}

// definição das funções

void indicaMaiorAlfabetica(char *frase1, char *frase2){
    int rc;
    char maior[20];

    rc = strcmp(frase1, frase2);
    if (rc == 0) {
        printf("[%s] é igual a [%s]\n",frase1, frase2);
    }else {
        if (rc < 0) {
            strncpy(maior, frase2, 20);
        } else { // rc > 0
            strncpy(maior, frase1, 20);
        }
        printf("maior palavra: %s \n", maior);
    }

}
