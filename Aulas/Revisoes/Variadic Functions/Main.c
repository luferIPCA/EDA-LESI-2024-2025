/*****************************************************************//**
 * @file   Main.c
 * @brief  Variadic Functions
 * Funções com número variável de parâmetros
 * 
 * int function_name(data_type variable_name, ...);
 * 
 * @author lufer
 * @see https://en.cppreference.com/w/c/variadic
 * @date   May 2022
 *********************************************************************/
#include <stdarg.h>
#include <stdio.h>
#pragma warning (disable:4996)

/// <summary>
/// Add several integer numbers
/// </summary>
/// <param name="n"></param>
/// <param name=""></param>
/// <returns></returns>
int AddNumbers(int n, ...)
{
    int sum = 0;

    // Declaring pointer to the argument list
    va_list ptr;

    // Initializing argument to the list pointer
    va_start(ptr, n);

    for (int i = 0; i < n; i++)
        // Accessing current variable and pointing to next one
        sum += va_arg(ptr, int);

    // Ending argument list traversal
    va_end(ptr);

    return sum;
}

/**
 * @brief Show N strings.
 * 
 * @param s
 * @param 
 */
char* ShowAny(char* dest, const char* f,...) {
    char *str="";

    // Declaring pointer to the argument list
    va_list pArgs;

    // Initializing argument to the list pointer
    va_start(pArgs, f);

    int nChars = vsprintf(dest, f, pArgs);

    // Ending argument list traversal
    va_end(pArgs);

    return str;
}

int main(){

    int x = AddNumbers(3, 2, 4, -7);

    char str[50];
    ShowAny(str, "%d - %s - %d", 12, "ola", 13);

}
