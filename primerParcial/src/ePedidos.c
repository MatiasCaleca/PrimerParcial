/*
 * ePedido.c
 *
 *  Created on: 13 oct. 2019
 *      Author: mati
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "eCliente.h"
#include "ePedidos.h"
#include "utn.h"
#include "informes.h"

int ePedidosInicializar(ePedidos ePedidosArray [], int ePedidosSize)
{
    int retorno=-1;
    int i;
    if(ePedidosArray!= NULL && ePedidosSize>0)
    {
        for(i=0;i<ePedidosSize;i++)
        {
        	ePedidosArray[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int ePedidosBuscarEmpty(ePedidos ePedidosArray[], int ePedidosSize, int *posicion)
{
    int retorno=-1;
    int i;
    if(ePedidosArray!= NULL && ePedidosSize>=0 && posicion!=NULL)
    {
        for(i=0;i<ePedidosSize;i++)
        {
            if(ePedidosArray[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int ePedidosBuscarId(ePedidos ePedidosArray[], int ePedidosSize, int valorBuscado, int *posicion)
{
    int retorno=-1;
    int i;
    if(ePedidosArray!= NULL && ePedidosSize>=0)
    {
        for(i=0;i<ePedidosSize;i++)
        {
            if(ePedidosArray[i].isEmpty==1)
                continue;
            else if(ePedidosArray[i].idPedido==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int ePedidosAlta(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int sizeCliente, int *contadorID)
{
    int retorno=-1;
    int posicion;
    int idCliente;
    int idClienteEncontrado;
    if(ePedidosArray!=NULL && ePedidosSize>0 && contadorID!=NULL)
    {
        if(ePedidosBuscarEmpty(ePedidosArray,ePedidosSize,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;

            ePedidosArray[posicion].idPedido=*contadorID;
            utn_getIntNumber("\nIngrese Id cliente: ","\nError. Id cliente no valido",1,sizeof(int),1,100,3,&idCliente);
            if(eClienteBuscarId(eClienteArray,sizeCliente,idCliente,&idClienteEncontrado)==0)
			{
            	eClienteArray[posicion].idCliente=idCliente;
			}
            else
			{
            	printf("Id del cliente no existente");
            	return -1;
            }
            utn_getFloatNumber("\nIngrese cantidad total de kilos a reciclar:","\nError. Reingrese cantidad de kilos a reciclar:",1,sizeof(float),1,1000,3,&ePedidosArray[posicion].cantidadKilos);
            utn_getIntNumber("\nIngrese estado del pedido siendo: \n0) PENDIENTE (Estado obligado al inciar pedido): \n1) PROCESADO (Estado al que pasa una vez procesado los palsticos)","\nError. Reingrese estado",1,sizeof(int),0,1,3,&ePedidosArray[posicion].estadoPedido);
            ePedidosArray[posicion].isEmpty=0;
			retorno=0;
        }
    }
    return retorno;
}

int ePedidosAltaProcesado(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int sizeCliente, int *contadorID)
{
    int retorno=-1;
    int posicion;
    int idCliente;
    int idClienteEncontrado;
    if(ePedidosArray!=NULL && ePedidosSize>0 && contadorID!=NULL)
    {
        if(ePedidosBuscarEmpty(ePedidosArray,ePedidosSize,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;

            ePedidosArray[posicion].idPedido=*contadorID;
            utn_getIntNumber("\nIngrese Id cliente: ","\nError. Id cliente no valido",1,sizeof(int),1,100,3,&idCliente);
            if(eClienteBuscarId(eClienteArray,sizeCliente,idCliente,&idClienteEncontrado)==0)
			{
            	eClienteArray[posicion].idCliente=idCliente;
			}
            else
			{
            	printf("Id del cliente no existente");
            	return -1;
            }
            utn_getFloatNumber("\nIngrese la cantidad de kilos de HDPE (Polietileno de alta densidad): ","\nError. Reingrese cantidad de kilos a reciclar",1,sizeof(float),1,1000,3,&ePedidosArray[posicion].kilosHdpe);
            utn_getFloatNumber("\nIngrese la cantidad de kilos de LDPE (Polietileno de baja densidad): ","\nError. Reingrese cantidad de kilos a reciclar",1,sizeof(float),1,1000,3,&ePedidosArray[posicion].kilosLdpe);
            utn_getFloatNumber("\nIngrese la cantidad de kilos de PP (Polipropileno): ","\nError. Reingrese cantidad de kilos a reciclar",1,sizeof(float),1,1000,3,&ePedidosArray[posicion].kilosPp);
            utn_getIntNumber("\nIngrese estado del pedido siendo: \n0) PENDIENTE ( estado obligado al inciar pedido): \n1) PROCESADO (estado al que pasa una vez procesado los palsticos)","\nError. Reingrese estado",1,sizeof(int),0,1,3,&ePedidosArray[posicion].estadoPedido);
            ePedidosArray[posicion].isEmpty=0;
			retorno=0;
        }
    }
    return retorno;
}

int ePedidosModificar(ePedidos ePedidosArray[], int ePedidosArraySize)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(ePedidosArray!=NULL && ePedidosArraySize>0)
    {
        utn_getIntNumber("\nID a modificar: ","\nError",1,sizeof(int),1,ePedidosArraySize,1,&id);
        if(ePedidosBuscarId(ePedidosArray,ePedidosArraySize,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\nModificar: \nA-Ingrese nueva cantidad de kilos totales a reciclar: \nS-Salir","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getFloatNumber("\nIngrese nueva cantidad de kilos totales: ","\nError. kilos ingresados no valido",1,sizeof(float),1,1000,3,&ePedidosArray[posicion].cantidadKilos);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int ePedidosBaja(ePedidos ePedidosArray[], int ePedidosArraySize)
{
    int retorno=-1;
    int posicion;
    int id;
    if(ePedidosArray!=NULL && ePedidosArraySize>0)
    {
        utn_getIntNumber("\nID a cancelar: ","\nError",1,sizeof(int),1,ePedidosArraySize,1,&id);
        if(ePedidosBuscarId(ePedidosArray,ePedidosArraySize,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	ePedidosArray[posicion].isEmpty=1;
        	ePedidosArray[posicion].idPedido=0;
        	ePedidosArray[posicion].cantidadKilos=0;
            retorno=0;
        }
    }
    return retorno;
}

int ePedidosListar(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int eClienteSize)
{
    int retorno=-1;
    int i;
    if(ePedidosArray!=NULL && ePedidosSize>=0)
    {
        for(i=0;i<ePedidosSize;i++)
        {
            if(ePedidosArray[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                printf("\nID Pedido: %d\nCuit Cliente: %s\nDireccion Cliente: %s\n Cantidad de kilos totales: %f\n Estado Pedido: %i",
                	ePedidosArray[i].idPedido, eClienteArray[i].cuit, eClienteArray[i].direccion, ePedidosArray[i].cantidadKilos, ePedidosArray[i].estadoPedido);
            }
        }
        retorno=0;
    }
    return retorno;
}

int ePedidosProcesadosListar(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int eClienteSize)
{
    int retorno=-1;
    int i;
    if(ePedidosArray!=NULL && ePedidosSize>=0)
    {
        for(i=0;i<ePedidosSize;i++)
        {
            if(ePedidosArray[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                printf("\nID Pedido: %d\nCuit Cliente: %s\nDireccion Cliente: %s\n Cantidad de kilos HDPE: %f\n Cantidad de kilos LDPE: %f\n Cantidad de kilos PP: %f\n Estado Pedido: %i",
                	ePedidosArray[i].idPedido, eClienteArray[i].cuit, eClienteArray[i].direccion, ePedidosArray[i].kilosHdpe, ePedidosArray[i].kilosLdpe, ePedidosArray[i].kilosPp, ePedidosArray[i].estadoPedido);
            }
        }
        retorno=0;
    }
    return retorno;
}

