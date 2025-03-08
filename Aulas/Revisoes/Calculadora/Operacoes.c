/*
* autor:lufer
* UC: Programação
* email:lufer@ipca.pt
* data: Fev 2025
* versao: 1
* Descricao: Operações básicas de uma calculadora
*/

/// <summary>
/// Calcula a soma de dois valores inteiros
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int soma1(int x, int y) {
	return x + y;
}


/*
* Função que calcula a soma de dois valores inteiros
*/
int sub(int x, int y) {
	return (x - y);
}

/// <summary>
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int mul(int x, int y) {
	return (x * y);
}

/// <summary>
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
float div(int x, int y) {
	if (y != 0)
	{
		return ((float)x / y);
	}
	return (x);
}

/// <summary>
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int maior(int x, int y) {
	int aux;

	//if (x > y)
	//	aux= x;
	//else
	//	aux = y;

	//return aux;

	//(condição) ? acc1_Verdade : acc2_Falso	// if (x>y) acc1 else acc2

	aux = (x > y) ? x : y;
	return aux;

	//return (x < y ? y : x);	// ?:
}


