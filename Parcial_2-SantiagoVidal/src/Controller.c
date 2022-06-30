#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Servicios.h"
#include "Parser.h"
#include "LinkedList.h"
#include "utn.h"


#define CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO 50
#define CANTIDAD_CARACTERES_ID_SERVICIO 15
#define CANTIDAD_CARACTERES_TIPO 20
#define CANTIDAD_CARACTERES_PRECIO_UNITARIO 30
#define CANTIDAD_CARACTERES_CANTIDAD 20
#define CANTIDAD_CARACTERES_TOTAL_SERVICIO 50

#define MINIMA_OPCION_FILTRACION 1
#define MAXIMA_OPCION_FILTRACION 3
#define MAXIMA_OPCION_FILTRACION_CIFRAS 1

#define NOMBRE_ARCHIVO_SERVICIOS "data.csv"
#define NOMBRE_ARCHIVO_SERVICIOS_FILTRADO "data_filtrado.csv"

#define CANTIDAD_CARACTERES_NOMBRE_ARCHIVO_ALMACENADOR 20

int Controller_loadFromText(LinkedList* this, char* nombreArchivo)
{
	int retorno;
	FILE* pFile;

	retorno =1;

	if(this != NULL && nombreArchivo != NULL)
	{
		retorno =0;

		pFile = fopen(nombreArchivo, "r");

		retorno = parser_ServiciosFromText(pFile, this);

		while(!fclose(pFile));

	}

	return retorno;
}

int controller_AbrirArchivoElejido(LinkedList* this)
{
	int retorno;
	char nombreDelArchivo[CANTIDAD_CARACTERES_NOMBRE_ARCHIVO_ALMACENADOR];

	retorno =1;

	if(this != NULL)
	{
		retorno = 0;
		do{
			if(utn_GetCadenaCaracteres(nombreDelArchivo, "\nIngrese el nombre del archivo: ", "El nombre ingresado es incorrecto, ingrese uno correcto: ", "\nNo se puede continuar con la operacion debido a un faltante de memoria", 1, CANTIDAD_CARACTERES_NOMBRE_ARCHIVO_ALMACENADOR, CANTIDAD_CARACTERES_NOMBRE_ARCHIVO_ALMACENADOR))
			{
				retorno =1;
				break;
			}
		}while(strcmp(nombreDelArchivo, "data.csv") != 0);

		if(retorno == 0)
		{
			retorno = Controller_loadFromText(this, nombreDelArchivo);
		}
	}

	return retorno;
}

int Controller_SaveTxt(LinkedList* this, char* nombreArchivo)
{
	int retorno;
	FILE* pFile;

	retorno =1;
	pFile= NULL;

	if(this != NULL && nombreArchivo != NULL)
	{
		pFile = fopen(nombreArchivo, "w");

		retorno = Servicios_SaveTxt(pFile, this, 1);

		while(!fclose(pFile));
	}
	return retorno;
}

int Controller_ListServicios(LinkedList* this)
{
	int retorno;
	int cantidadServiciosAMostrar;
	int estadoMostrar;
	int banderaRetorno;
	eServicios* servicioAMostrar;

	retorno =1;
	banderaRetorno =1;

	if(this != NULL)
	{
		cantidadServiciosAMostrar = ll_len(this);

		if(cantidadServiciosAMostrar > 0)
		{
			printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|\n", -CANTIDAD_CARACTERES_ID_SERVICIO, "ID SERVICIO", -CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO, "DESCRIPCION", -CANTIDAD_CARACTERES_TIPO, "TIPO DE SERVICIO", -CANTIDAD_CARACTERES_PRECIO_UNITARIO, "PRECIO UNITARIO", -CANTIDAD_CARACTERES_CANTIDAD, "CANTIDAD", -CANTIDAD_CARACTERES_TOTAL_SERVICIO, "PRECIO TOTAL");
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			for(int i=0; i<cantidadServiciosAMostrar; i++)
			{
				servicioAMostrar = (eServicios*) ll_get(this,i);
				if(servicioAMostrar != NULL)
				{
					estadoMostrar = Servicios_MostrarUnServicio(servicioAMostrar);

					if(banderaRetorno == 1)
					{
						if(estadoMostrar ==2)
						{
							retorno =2;
							banderaRetorno =0;
						}
						else
						{
							retorno = estadoMostrar;
						}
					}
				}
			}

			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		}
	}

	return retorno;
}

LinkedList* Controller_AsignarTotales(LinkedList* this)
{
	if(this != NULL)
	{
		this = ll_map(this, Servicios_CalcularPrecioTotal);
	}

	return this;
}

int Controller_FiltrarPorTipo(LinkedList* this)
{
	int retorno;
	LinkedList* listaFiltrada;
	int opcionFiltracion;
	int (*pFuncFiltradora)(void* pElemento);

	retorno=1;
	listaFiltrada = NULL;
	pFuncFiltradora = NULL;

	if(this != NULL)
	{

		if(!utn_GetIntRango(&opcionFiltracion, "\nOpciones de filtrado:\n 1- Minorista\n 2- Mayorista\n 3- Exportador\nElija una opcion: ", "El dato ingresado es invalido. Ingrese una opcion correcta: ", MINIMA_OPCION_FILTRACION, MAXIMA_OPCION_FILTRACION, MAXIMA_OPCION_FILTRACION_CIFRAS))
		{
			switch(opcionFiltracion)
			{
				case 1:
					pFuncFiltradora = Servicios_FiltrarPorMinorista;
					break;

				case 2:
					pFuncFiltradora = Servicios_FiltrarPorMayorista;
					break;

				case 3:
					pFuncFiltradora = Servicios_FiltrarPorExportador;
					break;
			}
			listaFiltrada = ll_filter(this, pFuncFiltradora);

			retorno = Controller_SaveTxt(listaFiltrada, NOMBRE_ARCHIVO_SERVICIOS_FILTRADO);
		}
	}
	return retorno;
}

int Controller_SortPorDescripcion(LinkedList* this)
{
	int retorno;

	retorno=1;
	if(this != NULL)
	{
		retorno = ll_sort(this, Servicios_OrdernarPorDescripcion,1);
	}

	return retorno;
}
