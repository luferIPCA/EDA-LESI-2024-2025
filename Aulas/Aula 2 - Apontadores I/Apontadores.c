/*!
 *  @file Source.c
 *  @author lufer
 *  @date 2025-02-21
 *  @project Aula 2 - Apontadores I
 *
 *  Pointers arithmetic
 */

#include <stdio.h>

int main() {

	int x;
	int* q;	//declarar apontador para int

#pragma region Aritmetica Apontadores

	x = 7;

	printf("\int *q ------------\n");

	printf("x=%d\n", x);
	printf("&x=%p\n", &x);

	q = &x;	//q aponta para x

	printf("x=%d\n", *q);	//apresenta o apontado por q, ie., 7
	printf("&q=%p\n", &q);	//apresenta a posição de memória, ie, endereço, de q
	printf("q=%p\n", q);
	// ++*p: Precedence of prefix ++ and * is same and both are right to left associative. 
	// *p++: Precedence of postfix ++ is higher than both prefix ++ and * and is left to right
	
	*q++;	//altera o valor de x? Não, neste caso ++ tem maior predecência que *; 
			//incrementa o valor que está em q...
	printf("New x=%d\n", x);
	printf("New &q=%p\n", &q);
	printf("New q=%p\n", q);
	printf("New *q=%d\n", *q);		//aponta para área "perdida"
	//correto: *(q++) ou (*q)++

	printf("\nchar *ptChar++ ------------\n");
	char c = 'a';
	char* ptChar = &c;
	printf("c=%c\n", c);
	printf("&c=%p\n", &c);
	printf("ptChar=%p\n", ptChar);
	printf("*ptChar=%c\n", *ptChar);

	//*ptChar++;
	//printf("\nDepois de *ptChar++\n");
	//printf("New c=%c\n", c);
	//printf("New &c=%p\n", &c);
	//printf("New ptChar=%p\n", ptChar);
	//printf("New *ptChar=%c\n", *ptChar);	//aponta para área "perdida"

	//melhor
	(*ptChar)++;
	printf("\nDepois de (*ptChar)++ ------------\n");
	printf("New c=%c\n", c);
	printf("New &c=%p\n", &c);
	printf("New ptChar=%p\n", ptChar);
	printf("New *ptChar=%c\n", *ptChar);	//aponta para área "perdida"
	//ou *(ptChar++) - testar!

	++*ptChar;		//não precisa de parênteses pois ++ tem maior predecência
	printf("\nDepois de ++*ptChar ------------\n");
	printf("New c=%c\n", c);
	printf("New &c=%p\n", &c);
	printf("New ptChar=%p\n", ptChar);
	printf("New *ptChar=%c\n\n", *ptChar);
	printf("New ++*ptChar=%c\n\n", ++*ptChar);

	q = &x;
	if (*q < 10) {
		printf("*q=%d\n", *q);
	}

	int j = 2 * *q;		//j = 2 * x
	printf("j=%d\n", j);

#pragma endregion

#pragma region DuploApontador

	int var = 10;
	int* ptr1 = &var;

	// Apontador de apontador (double pointer)
	int** ptr2 = &ptr1;

	printf("\nvar: %d\n", var);
	printf("*ptr1: %d\n", *ptr1);
	printf("**ptr2: %d\n", **ptr2);
	printf("var após ++ **ptr2: %d\n", ++ **ptr2);

#pragma endregion

#pragma region Arrays e Apontadores

	int arr[] = { 20, 30, 40 };
	int* p = arr;
	int r;
	//valor apontado por p (20) é incrementado de 1
	r = ++ *p;
	printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d\n",
		arr[0], arr[1], *p, r);
	//valor de p (20) é devolvido
	//apontador incrementado de 1
	r = *p++;
	printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d\n",
		arr[0], arr[1], *p, r);
	//apontador incrementado de 1
	//novo valor devolvido
	r = *++p;
	printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d\n",
		arr[0], arr[1], *p, r);

#pragma endregion

	getche();
}