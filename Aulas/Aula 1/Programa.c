/**
* Author: lufer
* Email: lufer@ipca.pt
* Date: 18-02-2025
* Desc: Organização de projetos
* 
*/

#include <stdio.h>
#include "Globais.h"

/**
* Programa Principal
*/
int main() {

	Carro y;
	
	int x = Soma(12, 34);
	printf("Soma: %d\n", x);

	strcpy(objetos[0].designacao,"Porto");
	objetos[0].distancia = 70;

	strcpy(objetos[1].designacao, "Lisboa");
	objetos[1].distancia = 350;

	float media = AvgDistObject(objetos, 2);
	
	printf("Media: %0.2f\n", media);

	_getche();
}