#pragma once
#include "Dados.h"

Element* CriaElement(int v);

Element* InsereInicio(Element* inicio, Element* novo);

Element* InsereFim(Element* inicio, Element* novo);

Element* InsereOrdenado(Element* inicio, Element* novo);

Element* ProcuraElemento(Element* h, int v);
bool ExisteElementRecursivo(Element* h, int v);

#pragma region A

Element* CriaElemento(int v, char* nome);
int MostraLista(Element* h);


Element* InsereOrdenadoII(Element* inicio, Element* novo);

#pragma endregion



