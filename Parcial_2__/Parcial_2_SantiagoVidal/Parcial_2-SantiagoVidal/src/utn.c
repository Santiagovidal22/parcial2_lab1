#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "memoriaDinamica.h"

int static myGets(char* direccionCadenaCaracteres, int longitud)
{
	int retorno;
	char* bufferString;

	retorno = 1;
	if(longitud>1 && direccionCadenaCaracteres != NULL && !memoria_NewCharConTamanio(&bufferString, longitud))
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(char)* longitud, stdin) != NULL)
		{
			if(*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) == '\n')
			{
				*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) = '\0';
			}
			if(strnlen(bufferString, sizeof(char)* longitud) < longitud)
			{
				strncpy(direccionCadenaCaracteres, bufferString, longitud);
				retorno = 0;
			}
		}
		free(bufferString);
	}
	return retorno;
}

int utn_verificarSerInt(char* cadenaDeCaracteres)
{
	int retorno;
	retorno = 1;

	if(cadenaDeCaracteres != NULL && (*cadenaDeCaracteres != '0' || *(cadenaDeCaracteres+1) == '\0'))
	{
		retorno=0;

		if(*cadenaDeCaracteres == '-' ||
				*cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}

		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				retorno =1;
				break;
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');
	}
	return retorno;
}

int utn_verificarSerFloat(char* cadenaDeCaracteres)
{
	int retorno;
	int contadorPuntos;

	retorno = 1;
	contadorPuntos =0;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres!='\0')
	{
		retorno=0;
		if(*cadenaDeCaracteres == '-' || *cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}
		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				if(*cadenaDeCaracteres== '.')
				{
					if(contadorPuntos<1)
					{
						contadorPuntos++;
					}
					else
					{
						retorno=1;
						break;
					}
					if(*(cadenaDeCaracteres+1)=='\0')
					{
						retorno=1;
						break;
					}
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');
	}
	return retorno;
}

int utn_VerificarSerMinuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=NULL && (islower(*caracter)||
			*caracter == 'á' ||
			*caracter == 'é' ||
			*caracter == 'í' ||
			*caracter == 'ó' ||
			*caracter == 'ú' ||
			*caracter == 'ñ' ))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerMayuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=NULL && (isupper(*caracter)||
			*caracter == 'Á' ||
			*caracter == 'É' ||
			*caracter == 'Í' ||
			*caracter == 'Ó' ||
			*caracter == 'Ú' ||
			*caracter == 'ñ' ||
			*caracter == 'Ñ'))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetra(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter!=NULL && isalpha(*caracter))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetra_ASCII_EXTEND(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter != NULL && (*caracter == 'á' ||
			*caracter == 'é' ||
			*caracter == 'í' ||
			*caracter == 'ó' ||
			*caracter == 'ú' ||
			*caracter == 'Á' ||
			*caracter == 'É' ||
			*caracter == 'Í' ||
			*caracter == 'Ó' ||
			*caracter == 'Ú' ||
			*caracter == 'ñ' ||
			*caracter == 'Ñ'))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetraEspanol(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter!=NULL && utn_VerificarSerLetra(caracter) && utn_VerificarSerLetra_ASCII_EXTEND(caracter))
	{
		retorno=0;
	}

	return retorno;
}

int utn_verificarSerNombre(char* cadenaDeCaracteres)
{
	int retorno;

	retorno=1;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres !=' ' && *cadenaDeCaracteres != '-')
	{
		retorno =0;

		do{
			if(utn_VerificarSerLetra(cadenaDeCaracteres) == 0 && utn_VerificarSerLetra_ASCII_EXTEND(cadenaDeCaracteres) == 0)
			{
				if(*cadenaDeCaracteres == ' ' || *cadenaDeCaracteres == '-')
				{
					if(*(cadenaDeCaracteres+1)=='\0')
					{
						retorno=1;
						break;
					}
				}
				else
				{
					retorno=1;
					break;
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres != '\0');
	}
	return retorno;
}

int utn_verificarSerCadenaAlfanumerica(char* cadenaCaracteres)
{
	int retorno;
	int banderaDigito;
	int banderaLetra;

	banderaDigito=0;
	banderaLetra=0;
	retorno=1;

	if(cadenaCaracteres != NULL)
	{
		do
		{
			if(isdigit(*cadenaCaracteres))
			{
				banderaDigito=1;
			}
			else
			{
				if(isalpha(*cadenaCaracteres))
				{
					banderaLetra=1;
				}
				else
				{
					break;
				}
			}
			cadenaCaracteres++;
		}while(*cadenaCaracteres != '\0');

		if(*cadenaCaracteres == '\0' && banderaDigito && banderaLetra)
		{
			retorno=0;
		}
	}
	return retorno;
}

int static getInt(int* direccionInt, int cantidadDeCifras)
{
	int retorno;
	char* bufferInt;

	retorno=1;

	cantidadDeCifras+=2;
	if(direccionInt !=NULL && cantidadDeCifras>2 && !memoria_NewCharConTamanio(&bufferInt,cantidadDeCifras))
	{
		if(!(myGets(bufferInt, cantidadDeCifras)) && !(utn_verificarSerInt(bufferInt)))
		{
			*direccionInt = atoi(bufferInt);
			retorno =0;
		}
		free(bufferInt);
	}
	return retorno;
}

int static getFloat(float* direccionFloat, int cantidadDeCifras)
{
	int retorno;
	char* bufferFloat;

	retorno=1;

	cantidadDeCifras+=2;
	if(direccionFloat !=NULL && cantidadDeCifras>2 && !memoria_NewCharConTamanio(&bufferFloat,cantidadDeCifras))
	{
		if(!(myGets(bufferFloat, cantidadDeCifras)) && !(utn_verificarSerFloat(bufferFloat)))
		{
			*direccionFloat = atof(bufferFloat);
			retorno =0;
		}
		free(bufferFloat);
	}
	return retorno;
}

int static getNombre(char* direccionPalabra, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionPalabra!=NULL && cantidadDeCaracteres>2 && !memoria_NewCharConTamanio(&bufferPalabra, cantidadDeCaracteres))
	{
		if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerNombre(bufferPalabra)))
		{
			retorno=0;
			strncpy(direccionPalabra, bufferPalabra, cantidadDeCaracteres);
		}
		free(bufferPalabra);
	}
	return retorno;
}


int static getCadenaCaracteres(char* direccionPalabra, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionPalabra!=NULL && cantidadDeCaracteres>2 && !memoria_NewCharConTamanio(&bufferPalabra, cantidadDeCaracteres))
	{
		if(!myGets(bufferPalabra, cantidadDeCaracteres))
		{
			retorno=0;
			strncpy(direccionPalabra, bufferPalabra, cantidadDeCaracteres);
		}
		free(bufferPalabra);
	}
	return retorno;
}

int static getCadenaAlfanumerica(char* direccionCadena, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionCadena!=NULL && cantidadDeCaracteres>2 && !memoria_NewCharConTamanio(&bufferPalabra, cantidadDeCaracteres))
	{
		if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerCadenaAlfanumerica(bufferPalabra)))
		{
			retorno=0;
			strncpy(direccionCadena, bufferPalabra, cantidadDeCaracteres);
		}
		free(bufferPalabra);
	}
	return retorno;
}

int utn_trasnformarCadenaAMayuscula(char* direccionCadena)
{
	int retorno;

	retorno=1;

	if(direccionCadena!=NULL)
	{
		retorno= 0;
		do{
			if(!utn_VerificarSerLetra(direccionCadena))
			{
				*direccionCadena = toupper(*direccionCadena);
			}
			direccionCadena++;
		}while(*direccionCadena != '\0');
	}

	return retorno;
}

int utn_CorregirNombre(char* direccionPalabra)
{
	int retorno;
	int banderaEspacio;

	retorno=1;
	banderaEspacio=0;

	if(direccionPalabra !=NULL)
	{
		retorno =0;
		*direccionPalabra = toupper(*direccionPalabra);
		direccionPalabra++;

		while(*direccionPalabra !='\0')
		{
			if(utn_VerificarSerLetraEspanol(direccionPalabra))
			{
				if(banderaEspacio)
				{
					*direccionPalabra = toupper(*direccionPalabra);
					banderaEspacio=0;
				}
				else
				{
					*direccionPalabra = tolower(*direccionPalabra);
				}
			}
			else
			{
				if(isspace(*direccionPalabra))
				{
					banderaEspacio=1;
				}

			}
			direccionPalabra++;
		}
	}
	return retorno;
}

int utn_GetIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int cantidadDeCifras)
{
	int retorno;
	int bufferInt;

	retorno=1;

	if(direccionInt!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<=maximo
			&& cantidadDeCifras > 0)
	{
		printf("%s", mensaje);
		while(getInt(&bufferInt,cantidadDeCifras) || bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionInt = bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_GetFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int cantidadDeCifras)
{
	int retorno;
	float bufferFloat;

	retorno=1;

	if(direccionFloat!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<=maximo &&
			cantidadDeCifras>0)
	{
		printf("%s", mensaje);
		while(getFloat(&bufferFloat, cantidadDeCifras) || bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionFloat = bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_GetNombreRango(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > 0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			!memoria_NewCharConTamanio(&bufferAuxiliar, cantidadDeCaracteres))
	{
		printf("%s", mensaje);
		while(getNombre(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionPalabra, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}
	return retorno;
}

int utn_GetCadenaAlfanumericaRango(char* direccionCadenaAlfanumerica, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;

	if(direccionCadenaAlfanumerica != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > 0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			!memoria_NewCharConTamanio(&bufferAuxiliar, cantidadDeCaracteres))
	{
		printf("%s", mensaje);
		while(getCadenaAlfanumerica(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionCadenaAlfanumerica, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}
	return retorno;
}


int utn_GetCadenaCaracteres(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > 0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			!memoria_NewCharConTamanio(&bufferAuxiliar, cantidadDeCaracteres))
	{
		printf("%s", mensaje);
		while(getCadenaCaracteres(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		strcpy(direccionPalabra, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}
	return retorno;
}

