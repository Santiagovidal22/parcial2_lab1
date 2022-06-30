#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int memoria_NewInt(int** punteroAPunteroIntEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroIntEstatico!=NULL)
	{
		*punteroAPunteroIntEstatico=NULL;
		*punteroAPunteroIntEstatico= (int*) malloc(sizeof(int));
		if(*punteroAPunteroIntEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewFloat(float** punteroAPunteroFloatEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroFloatEstatico!=NULL)
	{
		*punteroAPunteroFloatEstatico=NULL;
		*punteroAPunteroFloatEstatico= (float*) malloc(sizeof(float));
		if(*punteroAPunteroFloatEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewChar(char** punteroAPunteroCharEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=NULL)
	{
		*punteroAPunteroCharEstatico=NULL;
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char));
		if(*punteroAPunteroCharEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewIntConTamanio(int** punteroAPunteroIntEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroIntEstatico!=NULL && longitud>0)
	{
		*punteroAPunteroIntEstatico=NULL;
		*punteroAPunteroIntEstatico= (int*) malloc(sizeof(int) * longitud);
		if(*punteroAPunteroIntEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewFloatConTamanio(float** punteroAPunteroFloatEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroFloatEstatico!=NULL && longitud>0)
	{
		*punteroAPunteroFloatEstatico=NULL;
		*punteroAPunteroFloatEstatico= (float*) malloc(sizeof(float) * longitud);
		if(*punteroAPunteroFloatEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewCharConTamanio(char** punteroAPunteroCharEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=NULL && longitud>0)
	{
		*punteroAPunteroCharEstatico=NULL;
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char) * longitud);
		if(*punteroAPunteroCharEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeInt(int** punteroAPunteroIntDinamico ,int nuevaLongitud)
{
	int retorno;
	int* punteroAIntAuxiliar;

	retorno=1;

	if(punteroAPunteroIntDinamico!=NULL && nuevaLongitud>0 && !memoria_NewInt(&punteroAIntAuxiliar))
	{
		punteroAIntAuxiliar = (int*)realloc(*punteroAPunteroIntDinamico,sizeof(int)* nuevaLongitud);

		if(punteroAIntAuxiliar!=NULL)
		{
			*punteroAPunteroIntDinamico = punteroAIntAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeFloat(float** punteroAPunteroFloatDinamico ,int nuevaLongitud)
{
	int retorno;
	float* punteroAFloatAuxiliar;

	retorno=1;

	if(punteroAPunteroFloatDinamico!=NULL && nuevaLongitud>0 && !memoria_NewFloat(&punteroAFloatAuxiliar))
	{
		punteroAFloatAuxiliar = (float*)realloc(*punteroAPunteroFloatDinamico,sizeof(float)* nuevaLongitud);

		if(punteroAFloatAuxiliar!=NULL)
		{
			*punteroAPunteroFloatDinamico = punteroAFloatAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeChar(char** punteroAPunteroCharDinamico ,int nuevaLongitud)
{
	int retorno;
	char* punteroAFloatAuxiliar;

	retorno=1;

	if(punteroAPunteroCharDinamico!=NULL && nuevaLongitud>0 && !memoria_NewChar(&punteroAFloatAuxiliar))
	{
		punteroAFloatAuxiliar = (char*)realloc(*punteroAPunteroCharDinamico,sizeof(char)* nuevaLongitud);

		if(punteroAFloatAuxiliar!=NULL)
		{
			*punteroAPunteroCharDinamico = punteroAFloatAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}
