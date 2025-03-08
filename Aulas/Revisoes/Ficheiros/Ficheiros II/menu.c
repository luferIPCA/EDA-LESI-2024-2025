#include "menu.h"
#include "inscricao.h"

// definição das funções
char apresentaMenu(){
    char opcao;
    printf("-- menu --   \n");
    printf("1. inscrever\n");
    printf("2. listar todas as inscrições \n");
    printf("3. listar uma determinada inscrição \n");
    printf("4. sair \n");
    do {
        printf("opcao? ");
        opcao = getchar();
        // limpar texto até ao \n no buffer do teclado
        while (getchar()!='\n');
    } while (!(opcao>='1' && opcao <='4'));
    return opcao;
}

int F() {
	return 0;
}
