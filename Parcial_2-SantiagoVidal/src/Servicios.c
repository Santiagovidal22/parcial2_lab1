#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Servicios.h"

#define CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO 50
#define CANTIDAD_CIFRAS_ID_SERVICIO 15
#define CANTIDAD_CARACTERES_TIPO 20
#define CANTIDAD_CIFRAS_PRECIO_UNITARIO 30
#define CANTIDAD_CIFRAS_CANTIDAD 20
#define CANTIDAD_CIFRAS_TOTAL_SERVICIO 50

eServicios* Servicios_new()
{
	eServicios* this;
	this =NULL;

	this = (eServicios*) malloc(sizeof(eServicios));

	if(this != NULL)
	{
		Servicios_setAll(this, -1, "", -1, -1, -1, -1);
	}

	return this;
}

eServicios* Servicios_newParametros(int id_Servicio, char* descripcion, int tipo, float precioUnitario, int cantidad, float totalServicio)
{
	eServicios* this;

	this =NULL;

	this = Servicios_new();

	if(this != NULL)
	{
		if(descripcion == NULL || Servicios_setAll(this, id_Servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio) ==1)
		{
			Servicios_delete(this);
		}
	}

	return this;
}

int Servicios_delete(eServicios* servicioAEliminar)
{
	int retorno;

	retorno=1;
	if(servicioAEliminar != NULL)
	{
		free(servicioAEliminar);
		servicioAEliminar= NULL;
		retorno=0;
	}

	return retorno;
}

int Servicios_setId(eServicios* this,int id_Servicio)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->id_Servicio = id_Servicio;
		retorno=0;
	}

	return retorno;
}

int Servicios_getId(eServicios* this,int* id_Servicio)
{
	int retorno;

	retorno=1;

	if(this != NULL && id_Servicio != NULL)
	{
		*id_Servicio = this->id_Servicio;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setDescripcion(eServicios* this,char* descripcion)
{
	int retorno;

	retorno=1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		retorno=0;
	}

	return retorno;
}

int Servicios_getDescripcion(eServicios* this,char* descripcion)
{
	int retorno;

	retorno=1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion, this->descripcion);
		retorno=0;
	}

	return retorno;
}

int Servicios_setTipo(eServicios* this,int tipo)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->tipo = tipo;
		retorno=0;
	}

	return retorno;
}

int Servicios_getTipo(eServicios* this,int* tipo)
{
	int retorno;

	retorno=1;

	if(this != NULL && tipo != NULL)
	{
		*tipo  = this->tipo;
		retorno=0;
	}

	return retorno;
}

int Servicios_setPrecioUnitario(eServicios* this,float precioUnitario)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->precioUnitario = precioUnitario;
		retorno=0;
	}

	return retorno;
}

int Servicios_getPrecioUnitario(eServicios* this,float* precioUnitario)
{
	int retorno;

	retorno=1;

	if(this != NULL && precioUnitario != NULL)
	{
		*precioUnitario = this->precioUnitario;
		retorno=0;
	}

	return retorno;
}

int Servicios_setCantidad(eServicios* this,int cantidad)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->cantidad = cantidad;
		retorno=0;
	}

	return retorno;
}

int Servicios_getCantidad(eServicios* this,int* cantidad)
{
	int retorno;

	retorno=1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno=0;
	}

	return retorno;
}

int Servicios_setTotalServicio(eServicios* this,float totalServicio)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->totalServicio = totalServicio;
		retorno=0;
	}

	return retorno;
}

int Servicios_getTotalServicio(eServicios* this,float* totalServicio)
{
	int retorno;

	retorno=1;

	if(this != NULL && totalServicio != NULL)
	{
		*totalServicio = this->totalServicio;
		retorno=0;
	}

	return retorno;
}

int Servicios_setAll(eServicios* this, int id_Servicio, char* descripcion, int tipo, float precioUnitario, int cantidad, float totalServicio)
{
	int retorno;

	retorno =1;

	if(this != NULL && descripcion != NULL)
	{
		retorno =0;

		if(Servicios_setId(this, id_Servicio) ||
		Servicios_setDescripcion(this, descripcion) ||
		Servicios_setTipo(this, tipo) ||
		Servicios_setPrecioUnitario(this, precioUnitario) ||
		Servicios_setCantidad(this, cantidad) ||
		Servicios_setTotalServicio(this, totalServicio))
		{
			retorno = 2;
		}
	}

	return retorno;
}

int Servicios_getAll(eServicios* this, int* id_Servicio, char* descripcion, int* tipo, float* precioUnitario, int* cantidad, float* totalServicio)
{
	int retorno;

	retorno =1;

	if(this != NULL && descripcion != NULL && id_Servicio != NULL && tipo != NULL && precioUnitario != NULL && cantidad != NULL && totalServicio != NULL)
	{
		retorno =0;

		if(Servicios_getId(this, id_Servicio) ||
		Servicios_getDescripcion(this, descripcion) ||
		Servicios_getTipo(this, tipo) ||
		Servicios_getPrecioUnitario(this, precioUnitario) ||
		Servicios_getCantidad(this, cantidad) ||
		Servicios_getTotalServicio(this, totalServicio))
		{
			retorno = 2;
		}
	}

	return retorno;
}

int Servicios_verificarYTransfomarTipoStringAInt(char* tipoString, int* tipoNumerico)
{
	int retorno;

	retorno=-1;

	if(tipoString != NULL && tipoNumerico != NULL)
	{
		retorno=0;
		if(!strcmp(tipoString, "MINORISTA"))
		{
			*tipoNumerico=1;
		}
		else
		{
			if(!strcmp(tipoString, "MAYORISTA"))
			{
				*tipoNumerico=2;
			}
			else
			{
				if(!strcmp(tipoString, "EXPORTAR"))
				{
					*tipoNumerico=3;
				}
				else
				{
					retorno=-1;
				}
			}
		}
	}
	return retorno;
}

int Servicios_verificarYTransfomarTipoIntAString(char* tipoString, int tipoNumerico)
{
	int retorno;

	retorno=1;

	if(tipoString != NULL)
	{
		retorno=0;
		switch(tipoNumerico)
		{
			case 1:
				strcpy(tipoString, "MINORISTA");
				break;

			case 2:
				strcpy(tipoString, "MAYORISTA");
				break;

			case 3:
				strcpy(tipoString, "EXPORTAR");
				break;

			default:
				retorno=1;
				break;
		}
	}
	return retorno;
}

int Servicios_MostrarUnServicio(eServicios* this)
{
	int retorno;
	int id_Servicio;
	char descripcion[CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO];
	int tipo;
	char tipoCaracter[CANTIDAD_CARACTERES_TIPO];
	float precioUnitario;
	int cantidad;
	float totalServicio;

	int estadoGetAll;
	int estadoTransformar;

	retorno=-1;

	if(this != NULL)
	{
		estadoGetAll =Servicios_getAll(this, &id_Servicio, descripcion, &tipo, &precioUnitario, &cantidad, &totalServicio);

		estadoTransformar= Servicios_verificarYTransfomarTipoIntAString(tipoCaracter, tipo);

		if(estadoGetAll != 1)
		{
			if(estadoGetAll == 0 && estadoTransformar == 0)
			{
				retorno=0;
			}
			else
			{
				if(estadoGetAll == 1 || estadoTransformar == 1)
				{
					retorno=1;
				}

				if(estadoGetAll == 2 || estadoTransformar == 2)
				{
					retorno=2;
				}
			}
			printf("|%*d|%*s|%*s|$%*.2f|%*d|%*.2f|\n", -CANTIDAD_CIFRAS_ID_SERVICIO, id_Servicio, -CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO, descripcion, -CANTIDAD_CARACTERES_TIPO, tipoCaracter, -CANTIDAD_CIFRAS_PRECIO_UNITARIO, precioUnitario, -CANTIDAD_CIFRAS_CANTIDAD, cantidad, -CANTIDAD_CIFRAS_TOTAL_SERVICIO, totalServicio);
		}
	}

    return retorno;
}

void Servicios_CalcularPrecioTotal(void* peServicios)
{
	eServicios* pServiciosAuxiliar;

	if(peServicios != NULL)
	{
		pServiciosAuxiliar = ((eServicios*)peServicios);
		pServiciosAuxiliar->totalServicio = pServiciosAuxiliar->cantidad * pServiciosAuxiliar->precioUnitario;
	}
}

int Servicios_FiltrarPorMinorista(void* peServicios)
{
	int retorno;
	eServicios* pServicioAuxiliar;

	retorno=0;

	if(peServicios != NULL)
	{
		pServicioAuxiliar = (eServicios*) peServicios;

		if(pServicioAuxiliar->tipo == 1)
		{
			retorno =1;
		}
	}
	return retorno;
}

int Servicios_FiltrarPorMayorista(void* peServicios)
{
	int retorno;
	eServicios* pServicioAuxiliar;

	retorno=0;

	if(peServicios != NULL)
	{
		pServicioAuxiliar = (eServicios*) peServicios;

		if(pServicioAuxiliar->tipo == 2)
		{
			retorno =1;
		}
	}
	return retorno;
}

int Servicios_FiltrarPorExportador(void* peServicios)
{
	int retorno;
	eServicios* pServicioAuxiliar;

	retorno=0;

	if(peServicios != NULL)
	{
		pServicioAuxiliar = (eServicios*) peServicios;

		if(pServicioAuxiliar->tipo == 3)
		{
			retorno =1;
		}
	}
	return retorno;
}

int Servicios_SaveTxt(FILE* pFile, LinkedList* listaServicios, int guardarEncabezado)
{
	int retorno;
	int cantidadServicios;
	int id;
	char descripcion[CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	eServicios* pServicioAGuardar;

	pServicioAGuardar = NULL;
	retorno=1;

	if(pFile != NULL && listaServicios != NULL  && (guardarEncabezado == 1 || guardarEncabezado==0))
	{
		retorno=0;
		if(guardarEncabezado)
		{
			fprintf(pFile,"id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");
		}
		cantidadServicios = ll_len(listaServicios);

		for(int i=0; i<cantidadServicios; i++)
		{
			pServicioAGuardar = (eServicios*) ll_get(listaServicios,i);
			if(Servicios_getAll(pServicioAGuardar, &id, descripcion, &tipo, &precioUnitario, &cantidad, &totalServicio))
			{
				retorno =2;
			}
			else
			{
				fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n", id, descripcion, tipo, precioUnitario, cantidad, totalServicio);
			}
		}
	}

    return retorno;
}

int Servicios_OrdernarPorDescripcion(void* pPrimerServicio, void* pSegundoServicio)
{
	int retorno;

	retorno=0;

	if(pPrimerServicio != NULL && pSegundoServicio != NULL)
	{
		retorno = strcmp((((eServicios*)pPrimerServicio)->descripcion), (((eServicios*)pSegundoServicio)->descripcion));
	}

	return retorno;
}






