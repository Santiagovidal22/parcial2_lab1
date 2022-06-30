/*
 * memoriaDinamica.h
 *
 *  Created on: 8 jun. 2022
 *      Author: Santiago Vidal
 */

#ifndef MEMORIADINAMICA_H_
#define MEMORIADINAMICA_H_

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo int
///
/// @pre
/// @post
/// @param punteroAPunteroIntEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @return int: 1 Si punteroAPunteroIntEstatico es nulo o si no hay espacio en memoria disponible, caso contrario devuelve un 0
int memoria_NewInt(int** punteroAPunteroIntEstatico);

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo float
///
/// @pre
/// @post
/// @param punteroAPunteroFloatEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @return int: 1 Si punteroAPunteroFloatEstatico es nulo o si no hay espacio en memoria disponible, caso contrario devuelve un 0
int memoria_NewFloat(float** punteroAPunteroFloatEstatico);

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo char
///
/// @pre
/// @post
/// @param punteroAPunteroCharEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @return int: 1 Si punteroAPunteroCharEstatico es nulo o si no hay espacio en memoria disponible, caso contrario devuelve un 0
int memoria_NewChar(char** punteroAPunteroCharEstatico);

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo int que apunta a un array de determinado tamanio
///
/// @pre
/// @post
/// @param punteroAPunteroIntEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroIntEstatico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_NewIntConTamanio(int** punteroAPunteroIntEstatico ,int longitud);

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo float que apunta a un array de determinado tamanio
///
/// @pre
/// @post
/// @param punteroAPunteroFloatEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroFloatEstatico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_NewFloatConTamanio(float** punteroAPunteroFloatEstatico ,int longitud);

/// @brief Esta funcion es el constructor de un puntero dinamico de tipo char que apunta a un array de determinado tamanio
///
/// @pre
/// @post
/// @param punteroAPunteroCharEstatico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroCharEstatico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_NewCharConTamanio(char** punteroAPunteroCharEstatico ,int longitud);

/// @brief Con esta funcion se puede modificar el tamanio de un array en memoria dinamica al que apunta un puntero de tipo int
///
/// @pre
/// @post
/// @param punteroAPunteroIntEstatico:Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroIntEstatico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_ReSizeInt(int** punteroAPunteroIntEstatico ,int nuevaLongitud);

/// @brief Con esta funcion se puede modificar el tamanio de un array en memoria dinamica al que apunta un puntero de tipo float
///
/// @pre
/// @post
/// @param punteroAPunteroFloatDinamico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroFloatEstatico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_ReSizeFloat(float** punteroAPunteroFloatDinamico ,int nuevaLongitud);

/// @brief Con esta funcion se puede modificar el tamanio de un array en memoria dinamica al que apunta un puntero de tipo char
///
/// @pre
/// @post
/// @param punteroAPunteroCharDinamico: Es la direccion de memoria del puntero que apuntara a la memoria dinamica en caso de que todo salga bien, caso contrario apuntara a nulo
/// @param longitud: Es el tamanio array creado en memoria dinamica
/// @return int: 1 Si punteroAPunteroCharDinamico es nulo o si no hay espacio en memoria disponible o si longitud es menor a 1, caso contrario devuelve un 0
int memoria_ReSizeChar(char** punteroAPunteroCharDinamico ,int nuevaLongitud);

#endif /* MEMORIADINAMICA_H_ */
