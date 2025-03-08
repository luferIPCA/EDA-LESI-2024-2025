
#include "tinscricao.h"


// void escreverInscricao(char nome[], int dia, int mes, int ano) {
void escreveInscricao(TINSC insc) {
            printf("%-30s\t", insc.nome);
            // printf("%d/%d/%d\t", insc.dataNasc.dia,
            //                     insc.dataNasc.mes,
            //                     insc.dataNasc.ano);
            escreverData( insc.dataNasc );
            printf("\t");
            printf("%3d\n", calcularIdade(insc.dataNasc));
}


TESCALAO determinaEscalao(TINSC insc) {
	TESCALAO r;

	r = JUNIOR;
	return r;
}

//Ficheiros

/* guarda os dados das inscrições num ficheiro binário */
bool gravarInscricoesBinario(char *nomeFicheiro, TINSC prova[], int n) {
	FILE *af;
	int nescritos;
	/* abertura do ficheiro em modo binário para escrita*/
	af = fopen(nomeFicheiro, "wb");
	if (af == NULL)
		//printf("Erro na abertura do ficheiro %s.\n", nomeFicheiro);
		return false;
	else {
		// guardar o número de registos
		fwrite(&n, sizeof(int), 1, af);
		//h1:  guardar todos os registos de uma só vez
		nescritos = fwrite(&prova[0], sizeof(TINSC), n, af);
		if (nescritos == 0)
			//printf("Nao foi escrito nenhum elemento!\n");
			return false;
		else {
			if (nescritos < n)
				//printf("Escritos apenas %d elementos!\n", nescritos);
				return true;
		}

		////h2: guardar um registo de cada vez!
		//for (int i = 0; i < n; i++) {

		//}

		fclose(af);
	}
}

/* ler inscricoes de um ficheiro binario */
int lerInscricoesBinario(char *nomeFicheiro, TINSC prova[]) {
	FILE *af;
	int nRegistos, nlidos = 0;
	/* abertura do ficheiro em modo binario para leitura*/
	af = fopen(nomeFicheiro, "rb");
	if (af == NULL)
		//printf("Erro na abertura do ficheiro %s.\n", nomeFicheiro);
		return -1;
	else {
		// ler o número de registos
		fread(&nRegistos, sizeof(int), 1, af);
		// ler os registos para memória
		nlidos = fread(&prova[0], sizeof(TINSC), nRegistos, af);
		if (nlidos == 0)
			//printf("Nao foi lido nenhum elemento!\n");
			return 0;
		else {
			if (nlidos < nRegistos)
				//printf("Lidos apenas %d elementos!\n", nlidos);
				return nlidos;
		}
		fclose(af);
	}
	return nlidos; // nRegistos
}

