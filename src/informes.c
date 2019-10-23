#include "informes.h"



int informes_contKgClientComp(Recoleccion array[], int size, int idCliente)
{
	int i;
	int kgAcum = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].id_cliente==idCliente && array[i].estado==1)
			{
				kgAcum = kgAcum + array[i].kg_residuos_a_procesar;
			}
		}
	}
	return kgAcum;
}

int informes_clienteConMasKg(Recoleccion array[], int size)
{
	int i, actualKgRecic;
	int cantKg = 0;
	int idClienteMasKg;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].estado == 1)
			{
				actualKgRecic = array[i].kg_HDPE + array[i].kg_LDPE + array[i].kg_PP;

				if(cantKg < actualKgRecic)
				{
					cantKg = actualKgRecic;
					idClienteMasKg = array[i].id_cliente;
				}
			}
		}
	}
	return idClienteMasKg;
}

int informes_clienteConMasKgCant(Recoleccion array[], int size)
{
	int i;
	int cantKg = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(cantKg < informes_contKgClientComp(array, size, array[i].id_cliente))
			{
				cantKg = informes_contKgClientComp(array, size, array[i].id_cliente);
			}
		}
	}
	return cantKg;
}

int informes_enumPedidosPend(Recoleccion array[], int size, int idCliente)
{
	int i;
	int pedidosAcum = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].estado==0 && array[i].id_cliente==idCliente)
			{
				pedidosAcum++;
			}
		}
	}
	return pedidosAcum;
}

int informes_enumPedidosComp(Recoleccion array[], int size, int idCliente)
{
	int i;
	int pedidosAcum = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].estado==1 && array[i].id_cliente==idCliente)
			{
				pedidosAcum++;
			}
		}
	}
	return pedidosAcum;
}

int informes_enumPedidosCliente(Recoleccion array[], int size, int idCliente)
{
	int i;
	int pedidosAcum = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].id_cliente==idCliente)
			{
				pedidosAcum++;
			}
		}
	}
	return pedidosAcum;
}

int informes_clienteConMasPedidosPend(Recoleccion array[], int size)
{
	int i;
	int cantPedidos = 0;
	int idClienteMasPedidos;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(cantPedidos < informes_enumPedidosPend(array, size, array[i].id_cliente))
			{
				cantPedidos = informes_enumPedidosPend(array, size, array[i].id_cliente);
				idClienteMasPedidos = array[i].id_cliente;
			}
		}
	}
	return idClienteMasPedidos;
}

int informes_clienteConMasPedidosComp(Recoleccion array[], int size)
{
	int i;
	int cantPedidos = 0;
	int idClienteMasPedidos;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(cantPedidos < informes_enumPedidosComp(array, size, array[i].id_cliente))
			{
				cantPedidos = informes_enumPedidosPend(array, size, array[i].id_cliente);
				idClienteMasPedidos = array[i].id_cliente;
			}
		}
	}
	return idClienteMasPedidos;
}

int informes_clienteConMasPedidos(Recoleccion array[], int size)
{
	int i;
	int cantPedidos = 0;
	int idClienteMasPedidos;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(cantPedidos < informes_enumPedidosCliente(array, size, array[i].id_cliente))
			{
				cantPedidos = informes_enumPedidosPend(array, size, array[i].id_cliente);
				idClienteMasPedidos = array[i].id_cliente;
			}
		}
	}
	return idClienteMasPedidos;
}

int informes_clienteConMenosKg(Recoleccion array[], int size)
{
	int i, actualKgRecic;
	int cantKg = informes_clienteConMasKgCant(array, size);
	int idClienteMenosKg = 0;

	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].estado == 1)
			{
				actualKgRecic = array[i].kg_HDPE + array[i].kg_LDPE + array[i].kg_PP;

				if(cantKg > actualKgRecic)
				{
					cantKg = actualKgRecic;
					idClienteMenosKg = array[i].id_cliente;
				}
			}
		}
	}
	return idClienteMenosKg;
}

int informes_sortPedidosRecoleccion(Recoleccion array[], int size)
{
	//sort = 1 ASCENDENT -- sort = 0 DESCENDENT
	int callback = -1;
	int i,a,j;
	int issorted = 0;

	if(array != NULL && size > 0)
	{
		while(issorted == 0)
		{
			issorted = 1;
	        for (i = 0; i < size; ++i)
	        {
	        	j =i+1;
				if (array[i].id_cliente > array[j].id_cliente)
				{
					a =  array[i].id_cliente;
					array[i].id_cliente = array[j].id_cliente;
					array[j].id_cliente = a;
					issorted = 0;
				}
	        }
		}

        callback = 0;
	}

	return callback;
}

int informes_cantClienteConMas1000Kg(Recoleccion array[], int size)
{
	int i,lastId, actualKgRecic;
	int cantKg = 1000;
	int cantClientes = 0;

	if(array!= NULL && size>=0)
	{
		informes_sortPedidosRecoleccion(array, size);

		for(i=0;i<size;i++)
		{
			if (array[i].estado == 1)
			{
				actualKgRecic = array[i].kg_HDPE + array[i].kg_LDPE + array[i].kg_PP;
				if(cantKg < actualKgRecic && lastId != array[i].id_cliente)
				{
					lastId = array[i].id_cliente;
					cantClientes++;
				}
			}
		}
	}
	return cantClientes;
}
int informes_cantClienteConMenos100Kg(Recoleccion array[], int size)
{
	int i,lastId, actualKgRecic;
	int cantKg = 100;
	int cantClientes = 0;

	if(array!= NULL && size>=0)
	{
		informes_sortPedidosRecoleccion(array, size);

		for(i=0;i<size;i++)
		{
			if (array[i].estado == 1)
			{
				actualKgRecic = array[i].kg_HDPE + array[i].kg_LDPE + array[i].kg_PP;
				if(cantKg > actualKgRecic && lastId != array[i].id_cliente)
				{
					lastId = array[i].id_cliente;
					cantClientes++;
				}
			}
		}
	}
	return cantClientes;
}

int informes_paginateAndPorcentaje(Recoleccion array[], int size, Cliente arrayCliente[], int sizeCliente)
{
    int retorno=-1;
    int i,kg_reciclados,porcentaje,cuit_cliente;
    if(array!=NULL && size>=0)
    {
    	printf(	"############################################################################################################################################\n"
    			"|ID\t|CUIT\t|PORC. PLASTICO RECICLADO\t\t\t|\n"
    			"############################################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1 || array[i].estado == 0)
                continue;
            else

				kg_reciclados = array[i].kg_HDPE + array[i].kg_LDPE + array[i].kg_PP;
				porcentaje = (kg_reciclados * 100) / array[i].kg_residuos_a_procesar;
				cuit_cliente = getCuitByIdCliente(arrayCliente,sizeCliente, array[i].id_cliente);

				printf("|%d\t|%d\t|%d\t\t|\n",array[i].idUnico,cuit_cliente,porcentaje);
        }
        retorno=0;
        stuff_sleep(1);
    }
    return retorno;
}

int getCuitByIdCliente(Cliente array[], int size, int id)
{
	int i,cuit;
	if(array!= NULL && size>=0)
		{
			for(i=0;i<size;i++)
			{
				if(id == array[i].idUnico)
				{
					cuit = array[i].cuit;
				}
			}
		}
	return cuit;
}

