/*
 * pedidoPendiente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef EPEDIDOPENDIENTE_H_
#define EPEDIDOPENDIENTE_H_

struct
{
	int idPedidoPendiente;
	int idCliente;
	int cantidadKilos;
	char estadoPedido;
	int isEmpty;

}typedef ePedidosPendiente;

int ePedidosPendienteInicializar(ePedidosPendiente ePedidosPendienteArray [], int size);
int ePedidosPendienteBuscarEmpty(ePedidosPendiente ePedidosPendienteArray[], int size, int *posicion);
int ePedidosPendienteBuscarId(ePedidosPendiente ePedidosPendienteArray[], int size, int valorBuscado, int *posicion);

#endif /* EPEDIDOPENDIENTE_H_ */
