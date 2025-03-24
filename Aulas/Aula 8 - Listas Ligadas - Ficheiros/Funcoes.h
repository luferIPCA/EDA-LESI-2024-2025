#pragma once

#include "Dados.h"

Element* RemoveElement(Element* h, int cod);
Element* AlteraElement(Element* h, int v, char* novoNome);
Element* ProcuraElemento(Element* h, int v);

bool GravarElementBinario(char* nomeFicheiro, Element* h);
Element* LerElementsBinario(char* nomeFicheiro);
void DestroiLista(Element** h);
Element* OrdenaLista(Element* h);
