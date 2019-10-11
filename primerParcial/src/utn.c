/*
 * utn.c
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


int utn_getIntNumber(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int minimo, int maximo, int reintentos, int *input)
{
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && minimo < maximo && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidIntNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidIntNumber(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getFloatNumber(char *mensaje, char* mensajeError, int minimoSize, int maximoSize, int minimo, int maximo, int reintentos, float *input)
{
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && minimo < maximo && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidFloatNumber(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getString(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno=-1;
    char bufferStr[maximo+10];

    if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && resultado != NULL)
    {
        do
        {
            printf("%s", mensaje);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo) // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno=0;
                break;
            }
            printf("%s 1",mensajeError);
            (reintentos)--;
        }
        while((reintentos)>=0);
    }
    return retorno;
}

int utn_isValidString(char *stringRecibido) //si fuera un numero se necesitara parametros para validar maximo y minimo
{
    int retorno=1; // para las funciones isValid empiezo con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
		if((stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z'))
		{
			retorno=0;
			break;
		}
    }
    return retorno;
}

int utn_getChar(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno=-1;
    char bufferChar[256];

   if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && resultado != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,1,3,reintentos,bufferChar)) //==0
			{
				if(utn_isValidChar(bufferChar)==1)
				{
				   printf("OK");
					strncpy(resultado,bufferChar,maximo);
					retorno=0;
					break;
				}
				else
				{
					printf("%s 2",mensajeError);
					reintentos--;
				}
			}
       }
       while(reintentos>=0);
   }
   return retorno;
}

int utn_isValidChar(char *charRecibido)
{
	int retorno=1;
	int i;
	for(i=0;charRecibido[i]!='\0';i++)
	{
		if((charRecibido[i]<'A' || (charRecibido[i]>'Z' && charRecibido[i]<'a') || charRecibido[i]>'z'))
		{
			retorno=0;
			break;
		}
    }
    return retorno;
}

int utn_getName(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno=-1;
    char bufferStr[maximo];

    if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && resultado !=NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr))
            {
                if(utn_isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidName(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
		if((stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z'))
		{
			retorno=0;
			break;
		}
    }
    return retorno;
}

int utn_getLastName(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno=-1;
    char bufferStr[maximo];

    if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && resultado !=NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimo,maximo,reintentos,bufferStr))
            {
                if(utn_isValidLastName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidLastName(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
		if((stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z'))
		{
			retorno=0;
			break;
		}
    }
    return retorno;
}

int utn_getDNI(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input)
{
    maximoSize=11; // (dni con puntos)
    minimoSize=8;  // (dni sin puntos)
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidDNI(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximoSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidDNI(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getCUIT(char *mensaje, char *mensajeError, int reintentos, char *input)
{
    int maximoSize=13; // cuit con guiones
    int minimoSize=11;  // cuit sin guinoes
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidCUIT(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximoSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidCUIT(char *stringRecibido)
{
    int retorno=1;
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }
    return retorno;
}

int utn_getEmail(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input)
{
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidEmail(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximoSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidEmail(char *stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getTexto(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input)
{
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && reintentos >= 0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximoSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidTexto(char *stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getAlfanumerico(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input)
{
    int retorno=-1;
    char bufferStr[maximoSize];

    if(mensaje != NULL && mensajeError != NULL && minimoSize < maximoSize && reintentos >=0 && input != NULL)
    {
        do
        {
            if(! utn_getString(mensaje,mensajeError,minimoSize,maximoSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maximoSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

