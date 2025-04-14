#pragma once

#include "Dados.h"

//Element* RemoveElement(Element* h, int cod);
Element* RemoveElement(Element* h, int cod, bool* res);
Element* RemoveElementRecursivo(Element* head, int cod);
Element* AlteraElement(Element* h, int v, char* novoNome);
Element* ProcuraElemento(Element* h, int v);
Element* CriaElemento(int v, char* nome);
Element* InsereOrdenado(Element* inicio, Element* novo);

bool GravarElementBinario(char* nomeFicheiro, Element* h);
Element* LerElementsBinario(char* nomeFicheiro);

void DestroiLista(Element** h);
Element* DestroiListaII(Element* h);
Element* OrdenaLista(Element* h);


void MostraLista(Element* h);
