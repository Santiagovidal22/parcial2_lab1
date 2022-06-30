#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_

/// @brief Con esta funcion se pueden parsear los datos de un archivo de texto en donde estan almacenados los servicios
///
/// @pre
/// @post
/// @param pFile: Es el puntero al archivo del cual queremos obtener los datos
/// @param pArrayListServicios: Es el puntero a la LinkedList en la cual queremos cargar los datos
/// @return int: 1 si alguno de los punteros es nulo, 2 si no se pudieron cargar algunos archivos y 0 si se pudieron cargar todos los archivos
int parser_ServiciosFromText(FILE* pFile , LinkedList* pArrayListServicios);


#endif /* PARSER_H_ */
