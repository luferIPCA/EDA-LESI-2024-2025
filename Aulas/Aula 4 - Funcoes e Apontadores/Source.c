/*!
 *  @file Source.c
 *  @author mustl
 *  @date 2025-03-03
 *  @project Hoje
 *
 *  Implements the Functions
 */

#include "Funcoes.h"

/*!
 *  
 *
 *      @param [in,out] a 
 *      @param [in,out] b 
 *
 *      @return 
 */
int Soma(int* a, int* b) {
	return (*a + *b);
}

/*!
 *  
 *
 *      @param [in] v 
 *      @param [in] n 
 *
 *      @return 
 */
int Maior(int v[], int n) {
	int mv = v[0];
	for (int i = 1; i < n; i++) {
		if (mv < v[i]) mv = v[i];
	}

}

/*!
 *  Maiors the pt.
 *
 *      @param [in,out] v 
 *      @param [in]     n 
 *
 *      @return 
 */
int MaiorPt(int* v[], int n) {
	int mv = *v[0];
	for (int i = 1; i < n; i++) {
		if (mv < *v[i]) mv = *v[i];
	}

	return mv;
}

/*!
 *  Calcula....
 *
 *      @param [in]     v 
 *      @param [in]     a 
 *      @param [in,out] r 
 *
 *      @return 
 */
int SomaMaiorArray(int v[], int a, int* r) {
	int s = v[0];
	int m = s;
	for (int i = 1; i < a; i++) {
		if (m < v[i]) m = v[i];	//atualiza o maior
		s += v[i];
	}
	*r = m;		//coloca o  maior em r
	return(s);	//devolve a soma
}


/*!
 *  ...
 *
 *      @param [in,out] v 
 *      @param [in]     a 
 *      @param [in,out] r 
 *
 *      @return 
 */
int SomaMaiorArrayPtr(int* v[], int a, int* r) {
	int s = *v[0];
	int m = s;
	for (int i = 1; i < a; i++) {
		if (m < *v[i]) m = *v[i];	//atualiza o maior
		s += *v[i];
	}
	*r = m;		//coloca o  maior em r
	return(s);	//devolve a soma
}

