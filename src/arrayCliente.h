#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#define MSG_ERROR_CHOOSE_RECOLECCION  "\nError al elegir"
#define MSG_PROCESS_ID "\n\t\t\t\t\t(choose: A B # S = Salir)\n\n\t\t\t\t\tQue dato desea modificar?:"

#define MSG_ERROR_MODIFY_CUIT  "\nError al modificar el cuit"
#define MSG_MODIFY_CUIT  "\nIngrese el cuit, por favor:"

#define MSG_ERROR_MODIFY_EMPRESA  "\nError al modificar la empresa"
#define MSG_MODIFY_EMPRESA "\nIngrese el nuevo nombre de la empresa, por favor:"

#define MSG_ERROR_MODIFY_DIRECCION  "\nError al modificar la direccion"
#define MSG_MODIFY_DIRECCION "\nIngrese la direccion, por favor:"

#define MSG_ERROR_MODIFY_LOCALIDAD  "\nError al modificar la localidad"
#define MSG_MODIFY_LOCALIDAD "\nIngrese la localidad, por favor:"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "stuff.h"
#include "arrayRecoleccion.h"


typedef struct
{
    int idUnico;
    int isEmpty;
    int cuit;
    char empresa[TEXT_SIZE];
    char direccion[TEXT_SIZE];
    char localidad[TEXT_SIZE];

}Cliente;

#endif

int cliente_clear_all(Cliente array[], int size);
int cliente_checkIfDbHasEntries(Cliente array[], int size);
int cliente_findEmpty(Cliente array[], int size, int* posicion);
int cliente_findId(Cliente array[], int size, int valorBuscado, int* posicion);
int cliente_searchInt(Cliente array[], int size, int valorBuscado, int* posicion);
int cliente_searchString(Cliente array[], int size, char* valorBuscado, int* indice);
int cliente_signup(Cliente array[], int size, int* contadorID);
int cliente_destroy(Cliente array[], int sizeArray);
int cliente_destroyMatchedInt(Cliente array[], int sizeArray, int valorBuscado);
int cliente_modify(Cliente array[], int sizeArray);
int cliente_sortByString(Cliente array[],int size);
int cliente_paginate(Cliente array[], int size);
int cliente_print_with_pend(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec);
int cliente_print_pend(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec);
int cliente_print_comp(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec);
