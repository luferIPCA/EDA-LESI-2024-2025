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
	printf("&q=%p\n", &q);	//apresenta a posi��o de mem�ria, ie, endere�o, de q
	printf("q=%p\n", q);
	// ++*p: Precedence of prefix ++ and * is same and both are right to left associative. 
	// *p++: Precedence of postfix ++ is higher than both prefix ++ and * and is left to right
	
	*q++;	//altera o valor de x? N�o, neste caso ++ tem maior predec�ncia que *; 
			//incrementa o valor que est� em q...
	printf("New x=%d\n", x);
	printf("New &q=%p\n", &q);
	printf("New q=%p\n", q);
	printf("New *q=%d\n", *q);		//aponta para �rea "perdida"
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
	//printf("New *ptChar=%c\n", *ptChar);	//aponta para �rea "perdida"

	//melhor
	(*ptChar)++;
	printf("\nDepois de (*ptChar)++ ------------\n");
	printf("New c=%c\n", c);
	printf("New &c=%p\n", &c);
	printf("New ptChar=%p\n", ptChar);
	printf("New *ptChar=%c\n", *ptChar);	//aponta para �rea "perdida"
	//ou *(ptChar++) - testar!

	++*ptChar;		//n�o precisa de par�nteses pois ++ tem maior predec�ncia
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
	printf("var ap�s ++ **ptr2: %d\n", ++ **ptr2);

#pragma endregion

#pragma region Arrays e Apontadores

	int arr[] = { 20, 30, 40 };
	int* p = arr;
	int r;
	//valor apontado por p (20) � incrementado de 1
	r = ++ *p;
	printf("arr[0] = %d, arr[1] = %d, *p = %d, q = %d\n",
		arr[0], arr[1], *p, r);
	//valor de p (20) � devolvido
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