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
		{ 1, 0, 445, "Telefonica", "Lima 1234", "CABA"},
		{ 2, 0, 776, "DATASOFT", "Corrientes 2547", "CABA"},
		{ 3, 0, 219, "NESTLE", "Cucha Cucha 555", "LANUS"},
		{ 4, 0, 235, "TERRABUSI", "Rocha 784", "QUILMES"},
		{ 5, 0, 533, "DIA", "Mitre 750", "AVELLANEDA"},
		{ 6, 0, 596, "QUILMES", "Rocha 741", "QUILMES"},
	};

	Recoleccion arrayRecoleccion[DB_LENGHT_RECOLECCION]=
	{
		//idUnico,isEmpty,id_cliente,kg_residuos_a_procesar,estado,kg_HDPE,kg_LDPE,kg_PP
		{ 1000, 0, 1, 1000, 1, 200, 145, 230},
		{ 1001, 0, 1, 800, 1, 210, 45, 30},
		{ 1002, 0, 2, 100, 0, 0, 0, 0},
		{ 1003, 0, 2, 300, 0, 0, 0, 0},
		{ 1004, 0, 3, 1500, 1, 500, 150, 270},
		{ 1005, 0, 4, 750, 1, 100, 50, 70},
		{ 1006, 0, 1, 200, 0, 0, 0, 0},
		{ 1007, 0, 5, 30, 1, 10, 5, 3},
		{ 1008, 0, 6, 456, 0, 0, 0, 0}
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
			case 9:
				if(recoleccion_checkIfDbHasEntries(arrayRecoleccion, DB_LENGHT_RECOLECCION) >= 0)
				{
					int opInfNumber;

					stuff_clearScreen();
					stuff_showInformesMenu();
					utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opInfNumber);

					switch (opInfNumber)
					{
					int clienteMasPedidosPend,
						clienteMasPedidosComp,
						clienteMasPedidos,
						clienteMasKg,
						clienteMenosKg,
						clienteMas1000Kg,
						clienteMenos1000Kg;
					case 1:
						clienteMasPedidosPend = informes_clienteConMasPedidosPend(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("el id del cliente con mas pedidos pendientes es %d", clienteMasPedidosPend);
						break;
					case 2:
						clienteMasPedidosComp = informes_clienteConMasPedidosComp(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("el id del cliente con mas pedidos completados es %d", clienteMasPedidosComp);
						break;
					case 3:
						clienteMasPedidos = informes_clienteConMasPedidos(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("el id del cliente con mas pedidos es %d", clienteMasPedidos);
						break;
					case 4:
						clienteMasKg = informes_clienteConMasKg(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("el id del cliente con mas kg es %d", clienteMasKg);
						break;
					case 5:
						clienteMenosKg = informes_clienteConMenosKg(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("el id del cliente con menos kg es %d", clienteMenosKg);
						break;
					case 6:
						clienteMas1000Kg = informes_cantClienteConMas1000Kg(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("cant de clientes con mas de 1000 kg es %d", clienteMas1000Kg);
						break;
					case 7:
						clienteMenos1000Kg = informes_cantClienteConMenos1000Kg(arrayRecoleccion, DB_LENGHT_RECOLECCION);
						printf("cant de clientes con menos de 1000 kg es %d", clienteMenos1000Kg);
						break;
					case 8:
						informes_paginateAndPorcentaje(arrayRecoleccion, DB_LENGHT_RECOLECCION, arrayCliente, DB_LENGHT_CLIENTE);
						break;
					case 9:
						break;
					case 10:
						break;
					case 11:
						break;
					default:
						printf(MSG_ERROR);
						break;
					};

				} else {stuff_printAndSleep(2, NO_RECOLECCION_ERROR);}
				break;
			default:
				printf(MSG_ERROR);
				break;
		}
	}	while (opNumber != 10);

	return EXIT_SUCCESS;
}
