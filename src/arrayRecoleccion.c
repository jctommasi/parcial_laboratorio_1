#include "arrayRecoleccion.h"

int recoleccion_clear_all(Recoleccion array[], int size)
{
    int retorno=-1;
    if(array != NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int recoleccion_checkIfDbHasEntries(Recoleccion array[], int size)
{
	int retorno=-1;
	int i;
	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].isEmpty==0)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int recoleccion_findEmpty(Recoleccion array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int recoleccion_findId(Recoleccion array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int recoleccion_searchInt(Recoleccion array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].id_cliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int recoleccion_signup(Recoleccion array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(recoleccion_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID del cliente: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].id_cliente);
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tCant. en KG de Residuos: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].kg_residuos_a_procesar);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID del pedido: %d"
            		"\n\t\t\t\t\t\tID del cliente: %d"
            		"\n\t\t\t\t\t\tKG de Residuos: %d"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idUnico,
				   array[posicion].id_cliente,
				   array[posicion].kg_residuos_a_procesar);

            stuff_sleep(3);
            retorno=0;
        }
    }
    return retorno;
}


int recoleccion_destroyMatchedInt(Recoleccion array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].id_cliente=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

int recoleccion_process(Recoleccion array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\t\t Ingrese el ID del pedido a procesar: ","\nError",1,9999,1,sizeArray,1,&id);
        if(recoleccion_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\033[0;31m"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n"
            		"\033[0m");
            stuff_sleep(2);
        }
        else
        {
        	int kg_pedido = array[posicion].kg_residuos_a_procesar;
        	int kg_HDPE = 0;
        	int kg_LDPE = 0;
        	int kg_PP = 0;
            stuff_clearScreen();
            stuff_showFichaje();
            printf("\n\n\n"
            		"\033[0;31m"
            		"\t\t\t\t\t########################################################\n"
            		"\t\t\t\t\tESPECIFIQUE LA CANTIDAD DE PLASTICO QUE SE PROCESO\n"
            		"\t\t\t\t\t########################################################\n"
            		"\n\n\t\t\t\t\n"
            		"\033[0m");

            //KG DE PLASTICO A SEPARAR

            printf("\t\t\t\t\t\tCant. de kg a procesar restantes: %d", kg_pedido);
            utn_getUnsignedInt("\n\t\t\t\t\t Ingrese los kg de HDPE: ","\nError",1,kg_pedido,1,kg_pedido,1,&kg_HDPE);
            kg_pedido = kg_pedido - kg_HDPE;
            printf("\t\t\t\t\t\tCant. de kg a procesar restantes: %d", kg_pedido);
            utn_getUnsignedInt("\n\t\t\t\t\t Ingrese los kg de LDPE: ","\nError",1,kg_pedido,1,kg_pedido,1,&kg_LDPE);
            kg_pedido = kg_pedido - kg_LDPE;
            printf("\t\t\t\t\t\tCant. de kg a procesar restantes: %d", kg_pedido);
            utn_getUnsignedInt("\n\t\t\t\t\t Ingrese los kg de PP: ","\nError",1,kg_pedido,1,kg_pedido,1,&kg_PP);
            kg_pedido = kg_pedido - kg_PP;
            printf("\t\t\t\t\t\tSe desecharan: %d kg de este pedido", kg_pedido);

            //GUARDANDO LOS DATOS Y COMPLETANDO PEDIDO

            array[posicion].kg_HDPE = kg_HDPE;
            array[posicion].kg_LDPE = kg_LDPE;
            array[posicion].kg_PP = kg_PP;
            array[posicion].estado = 1; //pedido completado -- 1 = true


            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPEDIDO COMPLETADO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID del pedido: %d"
            		"\n\t\t\t\t\t\tID del cliente: %d"
            		"\n\t\t\t\t\t\tKG de Residuos desechados: %d"
            		"\n\t\t\t\t\t\tKG de Residuos HDPE: %d"
            		"\n\t\t\t\t\t\tKG de Residuos LDPE: %d"
            		"\n\t\t\t\t\t\tKG de Residuos PP: %d"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idUnico,
				   array[posicion].id_cliente,
				   array[posicion].kg_residuos_a_procesar,
				   array[posicion].kg_HDPE,
				   array[posicion].kg_LDPE,
				   array[posicion].kg_PP);

            stuff_printAndSleep(5, "\n\t\t\t\t\t\tvolviendo al menu principal..\n");
            retorno=0;
        }
    }
    return retorno;
}


int recoleccion_paginate_pendiente(Recoleccion array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|\tID\t|\tCUIT\t|\t\tKG A PROCESAR\t\t|\tESTADO\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1 || array[i].estado==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%d\t\t\t|\tPENDIENTE\t|\n",
                       array[i].idUnico,
					   array[i].id_cliente,
					   array[i].kg_residuos_a_procesar);
        }
        retorno=0;
    }
    return retorno;
}


