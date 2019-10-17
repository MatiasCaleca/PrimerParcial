/*
 ============================================================================
 Name        : primerParcial.c
 Author      : M.Caleca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "eCliente.h"
#include "ePedidos.h"
#include "utn.h"
#include "informes.h"

#define eClienteSize 6 // 100
#define ePedidosSize 9 // 1000

int main(void)
{
	int opcion;
	int contadorIdCliente=0;
	int contadorIdPedidos=0;

	eCliente eClienteArray[eClienteSize] = {
			{1,"Telefonica","30112233445","Lima1234","CABA"},
			{2,"DATASOFT","30445566776","Corrientes2547","CABA"},
			{3,"NESTLE","3088995521","CuchaCucha555","LANUS"},
			{4,"TERRABUSI","30567814235","Rocha784","QUILMES"},
			{5,"DIA","31545812533","Mitre750","AVELLANEDA"},
			{6,"QUILMES","31514857596","Rocha741","QUILMES"}
	};

	//eCliente eClienteArray[eClienteSize];
	//eClienteInicializar(eClienteArray,eClienteSize);

	ePedidos ePedidosArray[ePedidosSize] = {
			{1,1,1000,200,145,230,1},
			{2,1,800,210,45,30,1},
			{3,2,100,0,0,0,0},
			{4,2,300,0,0,0,0},
			{5,3,1500,500,150,270,1},
			{6,4,750,100,50,70,1},
			{7,1,200,0,0,0,0},
			{8,5,30,10,5,3,1},
			{9,6,456,0,0,0,0}

	};

	//ePedidos ePedidosArray [ePedidosSize];
	//ePedidosInicializar(ePedidosArray,ePedidosSize);

	do
	{
		utn_getIntNumber("\n\n1) Alta Cliente: \n2) Modificar datos de Cliente: \n3) Baja Cliente: \n4) Crear pedido de recoleccion:  \n5) Procesamiento de residuos:  \n6) Mostrar lista clientes: \n7) Mostrar pedidos pendientes \n8) Mostrar pedidos procesados \n9)Informes \n10)Salir\n",                   //cambiar
				                      "\nError. Opcion no valida ",1,sizeof(int),1,9,3,&opcion);
		switch(opcion)
		{
			case 1: // Alta Cliente
				eClienteAlta(eClienteArray,eClienteSize,&contadorIdCliente);
				break;
			case 2: // Modificar Cliente
				eClienteModificar(eClienteArray,eClienteSize);
				break;
			case 3: // Baja Cliente
				eClienteBaja(eClienteArray,eClienteSize);
				break;
			case 4: // Alta Pedido de Recoleccion
				ePedidosAlta(ePedidosArray,eClienteSize,eClienteArray,ePedidosSize,&contadorIdPedidos);
				break;
			case 5: // Alta Procesamiento de Reciduos
				ePedidosAltaProcesado(ePedidosArray,eClienteSize,eClienteArray,1000,&contadorIdPedidos);
				break;
			case 6: // Imprimir Clientes
				eClienteListar(eClienteArray,eClienteSize);
				break;
			case 7: // Imprimir Pedidos Pendientes
				ePedidosListar(ePedidosArray,ePedidosSize,eClienteArray,eClienteSize);
				break;
			case 8: // Imprimir Pedidos Procesado
				ePedidosProcesadosListar(ePedidosArray,eClienteSize,eClienteArray,ePedidosSize);
				break;
			case 9:
				break;
			case 10: // Exit/Salir
				break;
			default:
				printf("\nOpcion no valida");
		}


	}while(opcion!=10);
	return 0;
}
