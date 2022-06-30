#include "LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/// @brief Con esta fucnion se cargan los servicios de un archivo de texto, en memoria en una linkedList
///
/// @pre
/// @post
/// @param this: Es el puntero a la linkedList en donde se van a cargar todos los servicios
/// @param nombreArchivo: El nombre del archivo que vamos a abrir para extraer los datos
/// @return int: 1 si alguno de los punteros es nulo, 2 si no se pudieron cargar algunos archivos y 0 si se pudieron cargar todos los archivos
int Controller_loadFromText(LinkedList* this, char* nombreArchivo);

/// @brief Con esta funcion se pueden guardar todos los eServicios presentes en la linkedList, en un archivo.
///
/// @pre
/// @post
/// @param this: Es el puntero a la linkedList en donde de donde se obtendran los archivos a guardar
/// @param nombreArchivo: El nombre del archivo que vamos a abrir para almacenar los datos
/// @return int: 1 si alguno de los punteros es nulo, 2 si no se pudieron guardar algunos archivos y 0 si se pudieron guardar todos los archivos
int Controller_SaveTxt(LinkedList* this, char* nombreArchivo);

/// @brief Con esta funcion se puede abrir un archivo que vamos a elejir una vez se entra a la funcion, con el fin de cargarlo en una linkedList
///
/// @pre
/// @post
/// @param this: Puntero a la linkedList en donde vamos a cargar los servicios leidos del archivo
/// @return int: 1 si el puntero es nulo, 2 si no se pudieron guardar algunos archivos y 0 si se pudieron guardar todos los archivos
int controller_AbrirArchivoElejido(LinkedList* this);


/// @brief Con esta funcion se mostrara una lista de los servicios
///
/// @pre
/// @post
/// @param this: Puntero a la linkedList donde estan los servicios que quieren ser mostrados
/// @return int: 1 si el puntero es nulo, 2 si no se pudieron mostrar algunos datos o se mostraron erroneamente, o 0 si se mostraron todos los datos de manera correcta
int Controller_ListServicios(LinkedList* this);

/// @brief Con esta funcion se puede asignar el precio total de los servicios cargados en una linkedList
///
/// @pre
/// @post
/// @param this: Puntero a la linkedList en donde estan los servicios que queremos calcularles el precio total
/// @return Puntero a linkedList: Nulo si recibe un nulo por parametros, o el mismo puntero con el precio total siempre y cuando este presente el precio unitario y la cantidad
LinkedList* Controller_AsignarTotales(LinkedList* this);

/// @brief Con esta funcino se puede crear un archivo en donde se guarden solo los servicios de un mismo tipo
///
/// @pre
/// @post
/// @param this: Puntero a la linkedList donde estan los servicios que quieren ser filtrados
/// @return int: 1 si el puntero es nulo, 2 si no se pudieron guardar algunos archivos y 0 si se pudieron guardar todos los archivos
int Controller_FiltrarPorTipo(LinkedList* this);

/// @brief Con esta funcion se pueden ordenar los servicios de manera alfabeticamente ascendente en base a su descripcion
///
/// @pre
/// @post
/// @param this: Puntero a la linkedList donde estan los servicios que quieren ser ordenados
/// @return int: 1 si el puntero es nulo, 0 si se pudo ordenar
int Controller_SortPorDescripcion(LinkedList* this);

#endif /* CONTROLLER_H_ */
