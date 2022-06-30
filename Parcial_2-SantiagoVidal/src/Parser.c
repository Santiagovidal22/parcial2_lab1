#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Servicios.h"

#define CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO 50
#define CANTIDAD_CARACTERES_ID_SERVICIO 15
#define CANTIDAD_CARACTERES_TIPO 20
#define CANTIDAD_CARACTERES_PRECIO_UNITARIO 30
#define CANTIDAD_CARACTERES_CANTIDAD 20
#define CANTIDAD_CARACTERES_TOTAL_SERVICIO 50

#define CANTIDAD_CARACTERES_NOMBRE_ARCHIVO 20

int parser_ServiciosFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int retorno;
	char id_ServicioCaracter[CANTIDAD_CARACTERES_ID_SERVICIO];
	char descripcionCaracter[CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO];
	char tipoCaracter[CANTIDAD_CARACTERES_TIPO];
	char precioUnitarioCaracter[CANTIDAD_CARACTERES_PRECIO_UNITARIO];
	char cantidadCaracter[CANTIDAD_CARACTERES_CANTIDAD];
	char totalServicioCaracter[CANTIDAD_CARACTERES_TOTAL_SERVICIO];

	int tipoNumerico;
	eServicios* nuevoServicio;

	retorno=1;

	if(pFile != NULL && pArrayListServicios != NULL)
	{
		retorno=0;
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_ServicioCaracter, descripcionCaracter, tipoCaracter, precioUnitarioCaracter, cantidadCaracter, totalServicioCaracter);

		while(6 == fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_ServicioCaracter, descripcionCaracter, tipoCaracter, precioUnitarioCaracter, cantidadCaracter, totalServicioCaracter))
		{
			tipoNumerico= atoi(tipoCaracter);
			Servicios_verificarYTransfomarTipoStringAInt(tipoCaracter, &tipoNumerico);
			nuevoServicio = Servicios_newParametros(atoi(id_ServicioCaracter), descripcionCaracter, tipoNumerico, atof(precioUnitarioCaracter), atoi(cantidadCaracter), atof(totalServicioCaracter));
			if(nuevoServicio == NULL ||
					ll_add(pArrayListServicios, nuevoServicio))
			{
				retorno=2;
			}

			if(feof(pFile))
			{
				break;
			}
		}
	}

    return retorno;
}
