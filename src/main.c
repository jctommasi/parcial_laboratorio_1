/*
 ============================================================================
 Author      : Juan Cruz Tommasi
 ============================================================================
*/

#include "global.h"

int main(void)
{

	int opNumber;
	int id_autoinc_cliente = 0;
	int id_autoinc_recoleccion = 1000;
/*
	Cliente arrayCliente[DB_LENGHT];
	cliente_clear_all(arrayCliente,DB_LENGHT_CLIENTE);
*/

	Cliente arrayCliente[DB_LENGHT_CLIENTE]=
	{
		//idUnico,isEmpty,cuit,empresa,direccion,localidad
		{ 0, 0, 144, "SUTEBA SOC.A", "San Luis 301", "B.A. -- CABA"},
		{ 1, 0, 251, "UTN AVELLANEDA", "9 de Julio 20", "Avellaneda"},
		{ 2, 0, 144, "MIX CARLITOS", "Lavalle 200", "Gral Rodriguez"},
		{ 3, 0, 413, "UBA SOCIALES", "Carlos C. 200", "B.A. -- CABA"},
		{ 4, 0, 420, "PERTUTTI AV", "Peru 1500", "Avellaneda"},
		{ 5, 0, 111, "GOMEZ SOC.A", "Av. Indep. 13", "Temperley"},
	};

	Recoleccion arrayRecoleccion[DB_LENGHT_RECOLECCION]=
	{
		//idUnico,isEmpty,id_cliente,kg_residuos_a_procesar,estado,kg_HDPE,kg_LDPE,kg_PP
		{ 1000, 0, 1, 651, 0, 0, 0, 0},
		{ 1001, 0, 2, 444, 0, 0, 0, 0},
		{ 1002, 0, 3, 101, 0, 0, 0, 0},
	};

	do
	{
		stuff_clearScreen();
		stuff_displayMainBanner();
		stuff_showMenu();
		utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);

		switch (opNumber)
		{
			case 1:
				stuff_clearScreen();
				stuff_showSignUpBanner();
				cliente_signup(arrayCliente, DB_LENGHT_CLIENTE, &id_autoinc_cliente);
				break;
			case 2:
				if(cliente_checkIfDbHasEntries(arrayCliente, DB_LENGHT_CLIENTE) >= 0)
				{
					stuff_clearScreen();
					stuff_showDestroyBanner();
					cliente_destroy(arrayCliente, DB_LENGHT_CLIENTE);
				} else {stuff_printAndSleep(2, NO_CLIENTS_ERROR);}
				cliente_destroy(arrayCliente, DB_LENGHT_CLIENTE);
				break;
			case 3:
				if(cliente_checkIfDbHasEntries(arrayCliente, DB_LENGHT_CLIENTE) >= 0)
				{
					stuff_clearScreen();
					stuff_showModifyBanner();
					cliente_modify(arrayCliente, DB_LENGHT_CLIENTE);
				} else {stuff_printAndSleep(2, NO_CLIENTS_ERROR);}
				break;
			case 4:
					stuff_clearScreen();
					stuff_showSignUpBanner();
					cliente_paginate(arrayCliente, DB_LENGHT_CLIENTE);
					recoleccion_signup(arrayRecoleccion, DB_LENGHT_RECOLECCION,&id_autoinc_recoleccion);
				break;
			case 5:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					stuff_clearScreen();
					stuff_showProcesarPedido();
					recoleccion_paginate_pendiente(arrayRecoleccion, DB_LENGHT_RECOLECCION);
					recoleccion_process(arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			case 6:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					stuff_clearScreen();
					stuff_showClientePendientes();
					cliente_print_with_pend(arrayCliente, DB_LENGHT_CLIENTE, arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			case 7:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					stuff_clearScreen();
					stuff_showRecoleccionesPendientes();
					cliente_print_pend(arrayCliente, DB_LENGHT_CLIENTE, arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			case 8:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					stuff_clearScreen();
					stuff_showRecoleccionesCompletas();
					cliente_print_comp(arrayCliente, DB_LENGHT_CLIENTE, arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			default:
				printf(MSG_ERROR);
				break;
		}
	}	while (opNumber != 9);

	return EXIT_SUCCESS;
}
