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
		{ 0, 0, 144, "SUTEBA SOC.A", "San Luis 301", "CABA"},
		{ 1, 0, 251, "UTN AVELLANEDA", "9 de Julio 20", "Avellaneda"},
		{ 2, 0, 144, "KIOSKO CARLITOS", "Lavalle 200", "General Rodriguez"},
		{ 3, 0, 413, "UBA SOCIALES", "Carlos Calvo 200", "CABA"},
		{ 4, 0, 420, "PERTUTTI AV", "Peru 1500", "Avellaneda"},
		{ 5, 0, 111, "GOMEZ SOC.A", "Independencia 1013", "Temperley"},
	};

	Recoleccion arrayRecoleccion[DB_LENGHT_RECOLECCION]=
	{
		{ 0, 0, 1, 251, 0, 0, 0, 0},
		{ 1, 0, 2, 144, 0, 0, 0, 0},
		{ 2, 0, 3, 413, 0, 0, 0, 0},
	};

	do
	{
		stuff_displayMainBanner();
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
					stuff_showModifyBanner();
					recoleccion_process(arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			case 6:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					stuff_clearScreen();
					stuff_showModifyBanner();
					cliente_print_with_pend(arrayCliente, DB_LENGHT_CLIENTE, arrayRecoleccion, DB_LENGHT_RECOLECCION);
				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			default:
				printf(MSG_ERROR);
				break;
		}
	}	while (opNumber != 9);

	return EXIT_SUCCESS;
}
