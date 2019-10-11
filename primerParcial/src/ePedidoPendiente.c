/*
 * pedidoPendiente.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "eCliente.h"
#include "ePedidoPendiente.h"
#include "utn.h"

int ePedidosPendienteInicializar(ePedidosPendiente ePedidosPendienteArray [], int size)
{
    int retorno=-1;
    int i;
    if(ePedidosPendienteArray!= NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
        	ePedidosPendienteArray[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int ePedidosPendienteBuscarEmpty(ePedidosPendiente ePedidosPendienteArray[], int size, int *posicion)
{
    int retorno=-1;
    int i;
    if(ePedidosPendienteArray!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(ePedidosPendienteArray[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int ePedidosPendienteBuscarId(ePedidosPendiente ePedidosPendienteArray[], int size, int valorBuscado, int *posicion)
{
    int retorno=-1;
    int i;
    if(ePedidosPendienteArray!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(ePedidosPendienteArray[i].isEmpty==1)
                continue;
            else if(ePedidosPendienteArray[i].idPedidoPendiente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}



