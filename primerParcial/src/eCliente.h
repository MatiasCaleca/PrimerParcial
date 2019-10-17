/*
 * eCliente.h
 *
 *  Created on: 13 oct. 2019
 *      Author: mati
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

#define TEXT_SIZE 50
#define TEXT_CUIT 13

struct
{
	int idCliente;
	char nombreEmpresa[TEXT_SIZE];
	char cuit [TEXT_CUIT];
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	int isEmpty;

}typedef eCliente;

int eClienteInicializar(eCliente eClienteArray[], int eClienteSize);
int eClienteBuscarEmpty(eCliente eClienteArray[], int eClienteSize, int *posicion);
int eClienteBuscarId(eCliente eClienteArray[], int eClienteSize, int valorBuscado, int *posicion);
int eClienteAlta(eCliente eClienteArray[], int eClienteSize, int *contadorID);
int eClienteModificar(eCliente eClienteArray[], int eClienteArraySize);
int eClienteBaja(eCliente eClienteArray[], int eClienteArraySize);
int eClienteListar(eCliente eClienteArray[], int eClienteSize);


#endif /* ECLIENTE_H_ */
