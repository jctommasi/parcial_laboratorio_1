/*
 * arrayf.c
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */


#include "arrayf.h"

int arrayCalcMin(int *pArray, int *pResultado,int lenght)
{
	int traceback = -1;
	int i;
	int buffer = pArray[0];

	for (i = 1; i <= lenght; ++i)
	{
		if(pArray[i] < buffer)
		{
			buffer = pArray[i];
		}
	};

	*pResultado = buffer;
	traceback = 0;

	return traceback;
}
int arrayCalcMax(int *pArray, int *pResultado, int lenght)
{
	int traceback = -1;
	int i;
	int buffer = pArray[0];
	for (i = 1; i <= lenght; ++i)
	{
		if(pArray[i] > buffer)
		{
			buffer = pArray[i];
		}
	}
	traceback = 0;
	*pResultado = buffer;
	return traceback;
}
int arrayCalcProm(int *pArray, int *pResultado , int lenght)
{
	int traceback = -1;
	int i;
	int buffer = pArray[0];
	for (i = 1; i <= lenght; ++i)
	{

		buffer = buffer + pArray[i];

	}
	buffer = buffer / lenght;
	traceback = 0;
	*pResultado = buffer;
	return traceback;
}
int arrayCalcSuma(int *pArray, int *pResultado , int lenght)
{
	int traceback = -1;
	int i;
	int buffer = pArray[0];
	for (i = 1; i <= lenght; ++i)
	{
		buffer = buffer + pArray[i];
	}
	traceback = 0;
	*pResultado = buffer;
	return traceback;
}
int initArrayInt(int *pArray , int limite, int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		retorno = 0;
	}
	return retorno;
}
int orderIntArray(int *pArray, int limite)
{
	//sort = 1 ASCENDENT -- sort = 0 DESCENDENT
	int callback = -1;
	int i,a,j;

	if(pArray != NULL && limite > 0)
	{
        for (i = 0; i < limite; ++i)
        {
            for (j = i + 1; j < limite; ++j)
            {
                if (pArray[i] > pArray[j])
                {
                    a =  pArray[i];
                    pArray[i] = pArray[j];
                    pArray[j] = a;
                }
            }
        }
        callback = 0;
	}

	return callback;
}

int printArrayInt(int *pArray , int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int getArrayInt(int *pArray,
				int limite,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continue? (y/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}
