#ifndef RECOLECCION_H_INCLUDED
#define RECOLECCION_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "stuff.h"


typedef struct
{
    int idUnico;
    int isEmpty;
    int id_cliente;
    int kg_residuos_a_procesar;
    int estado;
    int kg_HDPE;
    int kg_LDPE;
    int kg_PP;

}Recoleccion;

#endif

int recoleccion_clear_all(Recoleccion array[], int size);
int recoleccion_checkIfDbHasEntries(Recoleccion array[], int size);
int recoleccion_findEmpty(Recoleccion array[], int size, int* posicion);
int recoleccion_findId(Recoleccion array[], int size, int valorBuscado, int* posicion);
int recoleccion_searchInt(Recoleccion array[], int size, int valorBuscado, int* posicion);
int recoleccion_signup(Recoleccion array[], int size, int* contadorID);
int recoleccion_destroy(Recoleccion array[], int sizeArray);
int recoleccion_destroyMatchedInt(Recoleccion array[], int sizeArray, int valorBuscado);
int recoleccion_process(Recoleccion array[], int sizeArray);
int recoleccion_sortByString(Recoleccion array[],int size);
int recoleccion_paginate_pendiente(Recoleccion array[], int size);
