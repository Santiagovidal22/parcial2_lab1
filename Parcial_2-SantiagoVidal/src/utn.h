/*
 * memoriaDinamica.h
 *
 *  Created on: 8 jun. 2022
 *      Author: Santiago Vidal
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief
///
/// @pre
/// @post
/// @param cadenaDeCaracteres
/// @return int: 1 si la cadena es nula o si tiene el signo - o + en alguna posicion que no sea la primera o si hay algun caracterer no numerico y retorna
/// 0 si el cadena si esta conformada puramente por numeros
int utn_verificarSerInt(char* cadenaDeCaracteres);

/// @brief
///
/// @pre
/// @post
/// @return int: 1 si la cadena es nula o si tiene el signo - o + en alguna posicion que no sea la primera o si hay algun caracterer no numerico o si tienen 2 o mas puntos
/// o si el punto esta antes del signo de valor o si hay algun caracter no numerico y retorna 0 si el cadena si esta conformada puramente por numeros
int utn_verificarSerFloat(char* cadenaDeCaracteres);

/// @brief
///
/// @pre
/// @post
/// @param caracter: Es un puntero a una sola letra
/// @return int: 1 si el puntero es nulo o si no es una letra minuscula de la primera version de ASCII, o 0 si si lo es
int utn_VerificarSerMinuscula(char* caracter);

/// @brief
///
/// @pre
/// @post
/// @param caracter: Es un puntero a una sola letra
/// @return int: 1 si el puntero es nulo o si no es una letra mayuscula de la primera version de ASCII, o 0 si si lo es
int utn_VerificarSerMayuscula(char* caracter);

/// @brief
///
/// @pre
/// @post
/// @param caracter: Es un puntero a una sola letra
/// @return int: 1 si el puntero es nulo o si no es una letra de la primera version de ASCII, o 0 si si lo es
int utn_VerificarSerLetra(char* caracter);

/// @brief
///
/// @pre
/// @post
/// @param caracter: Es un puntero a una sola letra
/// @return int: 1 si el puntero es nulo o si no es una vocal que posea acento y que sea mayuscula o minuscula , o 0 si si lo es
int utn_VerificarSerLetra_ASCII_EXTEND(char* caracter);

/// @brief
///
/// @pre
/// @post
/// @param caracter: Es un puntero a una sola letra
/// @return int: 1 si el puntero es nulo o si no es letra, o 0 si si lo es
int utn_VerificarSerLetraEspanol(char* caracter);

/// @brief
///
/// @pre
/// @post
/// @param cadenaDeCaracteres:
/// @return int: 0 si cumple con todas las condiciones o 1 si no lo hace o si el puntero es nulo. Condiciones:
/// - Poseer solo letras, con algunas excepciones
/// - Puede poseer espacios y guiones medios, pero no pueden estar ni en la primer ni ultima posicion
int utn_verificarSerNombre(char* cadenaDeCaracteres);

/// @brief
///
/// @pre
/// @post
/// @return int: 0 si cumple con todas las condiciones o 1 si no lo hace o si la cadena es nula. Condiciones:
/// - Poseer solo letras y numeros
int utn_verificarSerCadenaAlfanumerica(char* cadenaCaracteres);

/// @brief Transforma todas las letras de la cadena de caracteres en mayusculas
///
/// @pre
/// @post
/// @param direccionCadena
/// @return int: 1 si el puntero recibido es nulo o 0 si no lo es
int utn_trasnformarCadenaAMayuscula(char* direccionCadena);

/// @brief Transforma la primer letra de cada nombre en minuscula, y todas las demas en minusculas
///
/// @pre
/// @post
/// @param direccionPalabra
/// @return int: 1 si el puntero es nulo o 0 si no lo es
int utn_CorregirNombre(char* direccionPalabra);

/// @brief Con esta funcion se puede obtener un numero de tipo int que este entre el minimo y maximo especificados
///
/// @pre
/// @post
/// @param direccionInt: puntero a la variable int donde se guardara el numero que cumpla con las condiciones
/// @param mensaje: Aparece solamente al inicio y una vez
/// @param mensajeError: Aparecera cada vez que se ingrese un dato incorrecto
/// @param minimo
/// @param maximo
/// @param cantidadDeCifras
/// @return int: 0 si cumple las condiciones o 1 si no lo hace. Condiciones
/// - direccionInt != NULL
/// - mensaje != NULL
/// - mensajeError != NULL
/// - minimo <=maximo
/// -cantidadDeCifras > 0
///
/// Cuenta a los signos como cifras
int utn_GetIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int cantidadDeCifras);

/// @brief Con esta funcion se puede obtener un numero de tipo float que este entre el minimo y maximo especificados
///
/// @pre
/// @post
/// @param direccionFloat: puntero a la variable float donde se guardara el numero que cumpla con las condiciones
/// @param mensaje: Aparece solamente al inicio y una vez
/// @param mensajeError: Aparecera cada vez que se ingrese un dato incorrecto
/// @param minimo
/// @param maximo
/// @param cantidadDeCifras
/// @return int: 0 si cumple las condiciones o 1 si no lo hace. Condiciones
/// - direccionInt != NULL
/// - mensaje != NULL
/// - mensajeError != NULL
/// - minimo <=maximo
/// -cantidadDeCifras > 0
///
/// Cuenta a los signos y puntos como cifras
int utn_GetFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int cantidadDeCifras);


/// @brief Permite ingresar un nombre con una determinada cantidad de caracteres, teniendo en cuenta el caracter \0, puede tener espacios y guiones medios, ademas
/// de corregir los nombres si se han escrito mal
///
/// @pre
/// @post
/// @param direccionPalabra: Puntero de la variable char en donde se guardara el nombre ingresado
/// @param mensaje: Aparece solamente al inicio y una vez
/// @param mensajeError: Aparecera cada vez que se ingrese un dato incorrecto
/// @param mensajeErrorNull: Aparece solo si no hay espacio en memoria suficiente
/// @param cantidadMinimaCaracteres
/// @param cantidadMaximaCaracteres
/// @param cantidadDeCaracteres
/// @return int: 0 si cumple las condiciones o 1 si no lo hace. Condiciones
/// - direccionPalabra != NULL
/// - mensaje != NULL
/// - mensajeError != NULL
/// - mensajeErrorNull != NULL
/// - cantidadMinimaCaracteres <=cantidadMaximaCaracteres
/// cantidadMaximaCaracteres<=cantidadDeCaracteres
/// -cantidadDeCaracteres > 0
///- Tener espacio en memoria suficiente
int utn_GetNombreRango(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);


/// @brief Permite ingresar una cadena alfanumerica, dentro de una cantidad de caracteres que tiene en cuenta el \0
///
/// @pre
/// @post
/// @param direccionCadenaAlfanumerica: Puntero a una variable tipo char en donde se almacenara la cadena de caracteres solo en caso de cumplir las condiciones
/// @param mensajeError: Aparecera cada vez que se ingrese un dato incorrecto
/// @param mensajeError: Aparecera cada vez que se ingrese un dato incorrecto
/// @param mensajeErrorNull: Aparece solo si no hay espacio en memoria suficiente
/// @param cantidadMinimaCaracteres
/// @param cantidadMaximaCaracteres
/// @param cantidadDeCaracteres
/// @return int: 0 si cumple con todas las condiciones o 1 si no lo hace o si la cadena es nula. Condiciones:
/// - Poseer solo letras y numeros
/// - direccionCadenaAlfanumerica != NULL
/// - mensaje != NULL
/// - mensajeError != NULL
/// - mensajeErrorNull != NULL
/// - cantidadMinimaCaracteres <=cantidadMaximaCaracteres
/// - cantidadMaximaCaracteres<=cantidadDeCaracteres
/// - cantidadDeCaracteres > 0
/// - Tener espacio en memoria suficiente
int utn_GetCadenaAlfanumericaRango(char* direccionCadenaAlfanumerica, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);

int utn_GetCadenaCaracteres(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);

#endif /* UTN_H_ */
