/*
 * arrayf.h
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#ifndef ARRAYF_H_
#define ARRAYF_H_

#include <stdio.h>
#include <stdio_ext.h>
#include "utn.h"

int arrayCalcMin(int *pArray, int *pResultado, int lenght);
int arrayCalcMax(int *pArray, int *pResultado, int lenght);
int arrayCalcProm(int *pArray, int *pResultado, int lenght);
int arrayCalcSuma(int *pArray, int *pResultado, int lenght);

int orderIntArray(int *pArray, int limite);
int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

#endif /* ARRAYF_H_ */
