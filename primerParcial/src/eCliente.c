/*
 * eCliente.c
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


#define TEXT_SIZE 50

int eClienteInicializar(eCliente eClienteArray[], int size)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
        	eClienteArray[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int eClienteBuscarEmpty(eCliente eClienteArray[], int size, int *posicion)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(eClienteArray[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int eClienteBuscarId(eCliente eClienteArray[], int size, int valorBuscado, int *posicion)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(eClienteArray[i].isEmpty==1)
                continue;
            else if(eClienteArray[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int eClienteAlta(eCliente eClienteArray[], int size, int *contadorID)
{
    int retorno=-1;
    int posicion;
    if(eClienteArray!=NULL && size>0 && contadorID!=NULL)
    {
        if(eClienteBuscarEmpty(eClienteArray,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            eClienteArray[posicion].idCliente=*contadorID;
            utn_getName("\nIngrese nombre de la empresa: ","\nError. Nombre de la empresa no valido",1,TEXT_SIZE,3,eClienteArray[posicion].nombreEmpresa);
            utn_getCUIT("\nIngrese Cuit: ","\nError. Cuit no valido",3,eClienteArray[posicion].cuit);
            utn_getAlfanumerico("\nIngrese direccion: ","\nError. Direccion no valida",1,TEXT_SIZE,3,eClienteArray[posicion].direccion);
            utn_getString("\nIngrese localidad: ","\nError. Localidad no valido",1,TEXT_SIZE,3,eClienteArray[posicion].localidad);
            eClienteArray[posicion].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

int eClienteModificar(eCliente eClienteArray[], int eClienteArraySize)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(eClienteArray!=NULL && eClienteArraySize>0)
    {
        utn_getIntNumber("\nID a modificar: ","\nError",1,sizeof(int),1,eClienteArraySize,1,&id);
        if(eClienteBuscarId(eClienteArray,eClienteArraySize,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\nModificar: \nA-Direccion \nB-Localidad \nS-Salir","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre: ","\nError. Nombre no valido",1,TEXT_SIZE,3,eClienteArray[posicion].direccion);
                        break;
                    case 'B':
						 utn_getLastName("\nIngrese nuevo Apellido: ","\nError. Apellido no valido",1,TEXT_SIZE,3,eClienteArray[posicion].localidad);
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

int eClienteBaja(eCliente eClienteArray[], int eClienteArraySize)
{
    int retorno=-1;
    int posicion;
    int id;
    if(eClienteArray!=NULL && eClienteArraySize>0)
    {
        utn_getIntNumber("\nID a cancelar: ","\nError",1,sizeof(int),1,eClienteArraySize,1,&id);
        if(eClienteBuscarId(eClienteArray,eClienteArraySize,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	eClienteArray[posicion].isEmpty=1;
        	eClienteArray[posicion].idCliente=0;
            strcpy(eClienteArray[posicion].nombreEmpresa,"");
            eClienteArray[posicion].cuit=0;
            strcpy(eClienteArray[posicion].direccion,"");
            strcpy(eClienteArray[posicion].localidad,"");

            retorno=0;
        }
    }
    return retorno;
}

int eClienteListar(eCliente eClienteArray[], int eClientesize)
{
    int retorno=-1;
    int i;
    if(eClienteArray!=NULL && eClientesize>=0)
    {
        for(i=0;i<eClientesize;i++)
        {
            if(eClienteArray[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n Nombre de la empresa: %s\n Cuit: %d\nDireccion: %s\n Direccion: %s\n Localidad: %s",
                		eClienteArray[i].idCliente,eClienteArray[i].nombreEmpresa, eClienteArray[i].cuit, eClienteArray[i].direccion, eClienteArray[i].localidad);
        }
        retorno=0;
    }
    return retorno;
}
