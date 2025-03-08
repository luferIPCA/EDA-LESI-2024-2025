/*!
 *  @file Calc.c
 *  @author mustl
 *  @date 2025-02-19
 *  @project UsaDLL
 *
 *  Use DLL functions 
 */

#include <stdio.h>
#include "Lib\Funcs.h"

int main() {

	float x = Soma(2, 3);
	printf("2 + 3 = %2.0f\n2 * 3 = %2.0f\n", x,Prod(3,3));
}