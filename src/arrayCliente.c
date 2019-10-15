#include "arrayCliente.h"

int cliente_clear_all(Cliente array[], int size)
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

int cliente_checkIfDbHasEntries(Cliente array[], int size)
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

int cliente_findEmpty(Cliente array[], int size, int* posicion)
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

int cliente_findId(Cliente array[], int size, int valorBuscado, int* posicion)
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

int cliente_searchInt(Cliente array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].cuit==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_searchString(Cliente array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].empresa,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int cliente_signup(Cliente array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tCuit: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].cuit);
            utn_getName("\t\t\t\t\t\tEmpresa: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].empresa);
            utn_getTexto("\t\t\t\t\t\tDireccion: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].direccion);
            utn_getTexto("\t\t\t\t\t\tLocalidad: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].localidad);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tCuit: %d"
            		"\n\t\t\t\t\t\tEmpresa: %s"
            		"\n\t\t\t\t\t\tDireccion: %s"
            		"\n\t\t\t\t\t\tLocalidad: %s"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idUnico,
				   array[posicion].cuit,
				   array[posicion].empresa,
				   array[posicion].direccion,
				   array[posicion].localidad);

            stuff_sleep(3);
            retorno=0;
        }
    }
    return retorno;
}

int cliente_destroy(Cliente array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(cliente_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n");
            stuff_sleep(2);
        }
        else
        {
        	//antes del borrado, copio los datos para luego mostrar que es lo que se borro
        	Cliente arrayAux[sizeArray];
        	arrayAux[posicion].idUnico = array[posicion].idUnico;
        	arrayAux[posicion].cuit = array[posicion].cuit;
        	strcpy(arrayAux[posicion].empresa,array[posicion].empresa);
        	strcpy(arrayAux[posicion].direccion,array[posicion].direccion);
        	strcpy(arrayAux[posicion].localidad,array[posicion].localidad);

        	//inicio borrado
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].cuit=0;
            strcpy(array[posicion].empresa,"");
            strcpy(array[posicion].direccion,"");
            strcpy(array[posicion].localidad,"");
            retorno=0;

            //informe de borrado
            stuff_clearScreen();
            stuff_employeeGoneAway();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tBORRADO SATISFACTORIO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tCuit: %d"
            		"\n\t\t\t\t\t\tEmpresa: %s"
            		"\n\t\t\t\t\t\tDireccion: %s"
            		"\n\t\t\t\t\t\tLocalidad: %s"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   arrayAux[posicion].idUnico,
				   arrayAux[posicion].cuit,
				   arrayAux[posicion].empresa,
				   arrayAux[posicion].direccion,
				   arrayAux[posicion].localidad);
            stuff_sleep(6);
        }
    }
    return retorno;
}

int cliente_destroyMatchedInt(Cliente array[], int sizeArray, int valorBuscado)
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
                array[i].cuit=0;
                strcpy(array[i].empresa,"");
                strcpy(array[i].direccion,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

int cliente_modify(Cliente array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\t\t\t\t\t Ingrese el ID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(cliente_findId(array,sizeArray,id,&posicion)==-1)
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
            do
            {
            	stuff_clearScreen();
            	stuff_showModifyBanner();

                printf(	"\n\n\n\t\t\t\t\t\t######################"
                		"\n\t\t\t\t\t\tSE HA ENCONTRADO EL EMPLEADO"
                		"\n\t\t\t\t\t\t######################"
                		"\n\t\t\t\t\t\tPosicion: %d"
                		"\n\t\t\t\t\t\tID: %d"
                		"\n\t\t\t\t\t\tCuit: %d"
                		"\n\t\t\t\t\t\tEmpresa: %s"
                		"\n\t\t\t\t\t\t######################"
                		"\n\t\t\t\t\t\tA - Direccion: %s"
                		"\n\t\t\t\t\t\tB - Localidad: %s"
                		"\n\t\t\t\t\t\t######################\n",
                       posicion,
    				   array[posicion].idUnico,
    				   array[posicion].cuit,
    				   array[posicion].empresa,
    				   array[posicion].direccion,
    				   array[posicion].localidad);

                utn_getChar(MSG_PROCESS_ID, MSG_ERROR_CHOOSE_RECOLECCION,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                    	utn_getTexto(MSG_MODIFY_DIRECCION,MSG_ERROR_MODIFY_DIRECCION,1,TEXT_SIZE,1,array[posicion].direccion);
                        break;
                    case 'B':
                    	utn_getName(MSG_MODIFY_LOCALIDAD,MSG_ERROR_MODIFY_LOCALIDAD,1,TEXT_SIZE,1,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf(MSG_DEFAULT_ERROR);
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int cliente_sortByString(Cliente array[],int size)
{
    int retorno=-1;
    int i, j;

    char lastnameAux[TEXT_SIZE];
    int idAux;
    int isemptyAux;
    int sectorAux;
    char nameAux[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].empresa);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].cuit;
            strcpy(nameAux,array[i].direccion);


            j = i - 1;
            while ((j >= 0) && sectorAux < array[j].cuit)
            {
                strcpy(array[j + 1].empresa,array[j].empresa);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].cuit=array[j].cuit;
                strcpy(array[j + 1].direccion,array[j].direccion);

                j--;
            }
            strcpy(array[j + 1].empresa,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].cuit=sectorAux;
            strcpy(array[j + 1].direccion,nameAux);
        }

        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].empresa);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].cuit;

            strcpy(nameAux,array[i].direccion);


            j = i - 1;
            while ((j >= 0) && strcmp(lastnameAux,array[j].empresa)<0)
            {
                strcpy(array[j + 1].empresa,array[j].empresa);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].cuit=array[j].cuit;
                strcpy(array[j + 1].direccion,array[j].direccion);

                j--;
            }
            strcpy(array[j + 1].empresa,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].cuit=sectorAux;
            strcpy(array[j + 1].direccion,nameAux);
        }
        retorno=0;
    }
    return retorno;
}

int cliente_paginate(Cliente array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	printf(	"############################################################################################################################################\n"
    			"|\tID\t|\tCUIT\t|\t\tEMPRESA\t\t\t|\tDIRECCION\t\t|\tLOCALIDAD\t\t|\n"
    			"############################################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%s\t\t|\t%s\t\t|\t%s\t\t|\n",
                       array[i].idUnico,
					   array[i].cuit,
					   array[i].empresa,
					   array[i].direccion,
					   array[i].localidad);
        }
        retorno=0;
        stuff_sleep(1);
    }
    return retorno;
}

int cliente_print_with_pend(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec)
{
    int retorno=-1;
    int i;
    if(arrayCliente!=NULL && sizeCliente>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|ID\t|CUIT\t|EMPRESA\t\t|DIRECCION\t\t\t|LOCALIDAD\t\t\t|CANT. PENDIENTES\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<sizeCliente;i++)
        {

        	if(arrayCliente[i].isEmpty==1)
                continue;
            else
            {
            	int contPend = 0;
            	int j;
				for(j=0;j<sizeRec;j++)
					{
						if (arrayCliente[i].idUnico == arrayRecoleccion[j].id_cliente)
						{
							contPend++;
						}
					}
				//fin cont de pendientes
            	printf("|%d\t|%d\t|%s\t\t|%s\t\t\t|%s\t\t\t|%d\t\t|\n",
            			arrayCliente[i].idUnico,
						arrayCliente[i].cuit,
						arrayCliente[i].empresa,
						arrayCliente[i].direccion,
						arrayCliente[i].localidad,
						contPend);
            }
        }
        retorno=0;
        stuff_sleep(1);
    }
    return retorno;
}

int cliente_print_pend(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec)
{
    int retorno=-1;
    int i,j;

    if(arrayCliente!=NULL && sizeCliente>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|CUIT\t|DIRECCION\t|KG A RECOLECTAR\t\t|\n"
    			"#########################################################################################################################\n");

        for(i=0;i<sizeRec;i++)
        {
        	if(arrayRecoleccion[i].estado != 0)
                continue;
            else
            {
            	for(j=0;j<sizeCliente;j++)
            	{
            		if(arrayRecoleccion[i].id_cliente == arrayCliente[j].idUnico)
            		{
        				//fin cont de pendientes
                    	printf("|%d\t|%s\t|%d\t\t\n",
        						arrayCliente[j].cuit,
        						arrayCliente[j].direccion,
        						arrayRecoleccion[i].kg_residuos_a_procesar);
            		}
            	}
            }
        }
        retorno=0;
        stuff_sleep(1);
    }
    return retorno;
}

int cliente_print_comp(Cliente arrayCliente[], int sizeCliente, Recoleccion arrayRecoleccion[], int sizeRec)
{
    int retorno=-1;
    int i,j;

    if(arrayCliente!=NULL && sizeCliente>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|CUIT\t|DIRECCION\t|kg_HDPE\t|kg_LDPE\t|kg_PP\t|\n"
    			"#########################################################################################################################\n");

        for(i=0;i<sizeRec;i++)
        {
        	if(arrayRecoleccion[i].estado != 1)
                continue;
            else
            {
            	for(j=0;j<sizeCliente;j++)
            	{
            		if(arrayRecoleccion[i].id_cliente == arrayCliente[j].idUnico)
            		{
        				//fin cont de pendientes
                    	printf("|%d\t|%s\t|%d\t|%d\t|%d\t\n",
        						arrayCliente[j].cuit,
        						arrayCliente[j].direccion,
        						arrayRecoleccion[i].kg_HDPE,
								arrayRecoleccion[i].kg_LDPE,
								arrayRecoleccion[i].kg_PP);
            		}
            	}
            }
        }
        retorno=0;
    }
    return retorno;
}

