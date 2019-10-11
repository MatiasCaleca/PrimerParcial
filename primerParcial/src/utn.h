/*
 * utn.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getIntNumber(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int minimo, int maximo, int reintentos, int *input);
int utn_isValidIntNumber(char *stringRecibido);
int utn_getFloatNumber(char *mensaje, char* mensajeError, int minimoSize, int maximoSize, int minimo, int maximo, int reintentos, float *input);
int utn_isValidFloatNumber(char *stringRecibido);
int utn_getString(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);
int utn_isValidString(char *stringRecibido);
int utn_getChar(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);
int utn_isValidChar(char *charRecibido);
int utn_getName(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);
int utn_isValidName(char *stringRecibido);
int utn_getLastName(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, char *resultado);
int utn_isValidLastName(char *stringRecibido);
int utn_getDNI(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input);
int utn_isValidDNI(char *stringRecibido);
int utn_getCUIT(char *mensaje, char *mensajeError, int reintentos, char *input);
int utn_isValidCUIT(char *stringRecibido);
int utn_getEmail(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input);
int utn_isValidEmail(char *stringRecibido);
int utn_getTexto(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input);
int utn_isValidTexto(char *stringRecibido);
int utn_getAlfanumerico(char *mensaje, char *mensajeError, int minimoSize, int maximoSize, int reintentos, char *input);
int utn_isValidAlphanumeric(char* stringRecibido);

#endif /* UTN_H_ */
