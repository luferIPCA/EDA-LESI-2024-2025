#pragma once
//-----------------------------------------------------------------------
// <copyright file="Varios.h" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>2025</date>
// <author></author>
// <email></email>
// <version></version>
// <desc>Bibliotecas</desc>
//-----------------------------------------------------------------------


#ifndef  LIB
#define LIB

#define PI 3.1415

__declspec(dllexport) float Soma(float x, float y);

__declspec(dllexport) float Prod(float x, float y);
//ou
//#define DllExport   __declspec( dllexport ) 
//DllExport float Prod(float x, float y);

#endif

