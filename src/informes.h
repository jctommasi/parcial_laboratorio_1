#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arrayCliente.h"
#include "arrayRecoleccion.h"
#include "utn.h"

int informes_enumPedidosPend(Recoleccion array[], int size, int idCliente);
int informes_enumPedidosComp(Recoleccion array[], int size, int idCliente);
int informes_enumPedidosCliente(Recoleccion array[], int size, int idCliente);
int informes_clienteConMasPedidosPend(Recoleccion array[], int size);
int informes_clienteConMasPedidosComp(Recoleccion array[], int size);
int informes_clienteConMasPedidos(Recoleccion array[], int size);
int informes_contKgClientComp(Recoleccion array[], int size, int idCliente);
int informes_clienteConMasKg(Recoleccion array[], int size);
int informes_clienteConMenosKg(Recoleccion array[], int size);
int informes_clienteConMasKgCant(Recoleccion array[], int size);
int informes_sortPedidosRecoleccion(Recoleccion array[], int size);
int informes_cantClienteConMas1000Kg(Recoleccion array[], int size);
int informes_cantClienteConMenos1000Kg(Recoleccion array[], int size);
int getCuitByIdCliente(Cliente array[], int size, int id);
int informes_paginateAndPorcentaje(Recoleccion array[], int size, Cliente arrayCliente[], int sizeCliente);

#endif // INFORMES_H_INCLUDED
