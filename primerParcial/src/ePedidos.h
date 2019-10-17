/*
 * ePedidos.h
 *
 *  Created on: 13 oct. 2019
 *      Author: mati
 */

#ifndef EPEDIDOS_H_
#define EPEDIDOS_H_

struct
{
	int idPedido;
	int idCliente;
	float cantidadKilos;
	float kilosHdpe; // (1-HDPE:Polietileno de alta densidad)
	float kilosLdpe; // (2-LDPE:Polietileno de baja densidad)
	float kilosPp; // (3-PP:Polipropileno)
	int estadoPedido; // (1-pendiente - 2-completado)
	int isEmpty;
}typedef ePedidos;

int ePedidosInicializar(ePedidos ePedidosArray [], int ePedidosSize);
int ePedidosBuscarEmpty(ePedidos ePedidosArray[], int ePedidosSize, int *posicion);
int ePedidosBuscarId(ePedidos ePedidosArray[], int ePedidosSize, int valorBuscado, int *posicion);
int ePedidosAlta(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int sizeCliente, int *contadorID);
int ePedidosAltaProcesado(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int sizeCliente, int *contadorID);
int ePedidosModificar(ePedidos ePedidosArray[], int ePedidosArraySize);
int ePedidosBaja(ePedidos ePedidosArray[], int ePedidosArraySize);
int ePedidosListar(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int eClienteSize);
int ePedidosProcesadosListar(ePedidos ePedidosArray[], int ePedidosSize, eCliente eClienteArray[], int eClienteSize);


#endif /* EPEDIDOS_H_ */
