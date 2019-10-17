/*
 * eCliente.c
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


#define TEXT_SIZE 50
#define TEXT_CUIT 13

int eClienteInicializar(eCliente eClienteArray[], int eClienteSize)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && eClienteSize>0)
    {
        for(i=0;i<eClienteSize;i++)
        {
        	eClienteArray[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int eClienteBuscarEmpty(eCliente eClienteArray[], int eClienteSize, int *posicion)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && eClienteSize>=0 && posicion!=NULL)
    {
        for(i=0;i<eClienteSize;i++)
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

int eClienteBuscarId(eCliente eClienteArray[], int eClienteSize, int valorBuscado, int *posicion)
{
    int retorno=-1;
    int i;
    if(eClienteArray!= NULL && eClienteSize>=0)
    {
        for(i=0;i<eClienteSize;i++)
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

int eClienteAlta(eCliente eClienteArray[], int eClienteSize, int *contadorID)
{
    int retorno=-1;
    int posicion;
    if(eClienteArray!=NULL && eClienteSize>0 && contadorID!=NULL)
    {
        if(eClienteBuscarEmpty(eClienteArray,eClienteSize,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            eClienteArray[posicion].idCliente=*contadorID;
            utn_getName("\nIngrese nombre de la empresa: ","\nError. Nombre de la empresa no valido",1,TEXT_SIZE,3,eClienteArray[posicion].nombreEmpresa);
            utn_getCUIT("\nIngrese su Cuit (sin guiones ni espacios): ","\nError. Cuit no valido",3,eClienteArray[posicion].cuit);
            utn_getAlfanumerico("\nIngrese direccion: ","\nError. Direccion no valida",1,TEXT_SIZE,3,eClienteArray[posicion].direccion);
            utn_getString("\nIngrese localidad: ","\nError. Localidad no valido",1,TEXT_SIZE,3,eClienteArray[posicion].localidad);
            eClienteArray[posicion].isEmpty=0;

            printf("\nSu ID es: %d,\nEmpresa: %s", eClienteArray[posicion].idCliente,eClienteArray[posicion].nombreEmpresa);

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
            	printf("\nDireccion: %s\nLocalidad: %s\n",eClienteArray[posicion].direccion,eClienteArray[posicion].localidad);
				utn_getChar("\nIngrese variable a modificar: \nA-Direccion \nB-Localidad \nS-Salir: ","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getAlfanumerico("\nIngrese nueva direccion: ","\nError. Nombre no valido",1,TEXT_SIZE,3,eClienteArray[posicion].direccion);
                        break;
                    case 'B':
						 utn_getString("\nIngrese nueva localdad: ","\nError. Apellido no valido",1,TEXT_SIZE,3,eClienteArray[posicion].localidad);
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
            strcpy(eClienteArray[posicion].cuit,"");
            strcpy(eClienteArray[posicion].direccion,"");
            strcpy(eClienteArray[posicion].localidad,"");

            retorno=0;
        }
    }
    return retorno;
}

int eClienteListar(eCliente eClienteArray[], int eClienteSize)
{
    int retorno=-1;
    int i;
    if(eClienteArray!=NULL && eClienteSize>=0)
    {
        for(i=0;i<eClienteSize;i++)
        {
            if(eClienteArray[i].isEmpty==1)
            {
            	continue;
			}
            else
            {
                printf("\nID: %d\nNombre de la empresa: %s\nCuit: %s\nDireccion: %s\nDireccion: %s\nLocalidad: %s",
                		eClienteArray[i].idCliente,eClienteArray[i].nombreEmpresa, eClienteArray[i].cuit, eClienteArray[i].direccion, eClienteArray[i].localidad);
            }
		}
        retorno=0;
    }
    return retorno;
}
