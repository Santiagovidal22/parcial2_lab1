#include "LinkedList.h"

#define CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO 50

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct{

	int id_Servicio;
	char descripcion[CANTIDAD_CARACTERES_DESCRIPCION_SERVICIO];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

} eServicios;

#endif /* SERVICIOS_H_ */

/// @brief Esta funcion es el constructor de datos de tipo eServicios
///
/// @pre
/// @post
/// @return Puntero a eServicios: Nulo si no se pudo crear un nuevo eServicios, pero si se pudo devuelve el puntero a ese eServicios
eServicios* Servicios_new();

/// @brief Con esta funcion se crea una nueva variable de tipo eServicios ademas de cargarle datos que se le son pasados por parametros
///
/// @pre
/// @post
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param statusFlight
/// @return Puntero a eServicio: Nulo si no se pudo crear un nuevo eServicios, o si alguno de los punteros son nulos, o si alguno de los datos no cumplen con sus requisitos.
/// Si no hay problema con esto devuelve el puntero al nuevo eServicios
eServicios* Servicios_newParametros(int id_Servicio, char* descripcion, int tipo, float precioUnitario, int cantidad, float totalServicio);

/// @brief Con esta funcion se puede eliminar a un eServicios
///
/// @pre
/// @post
/// @param servicioAEliminar: Puntero hacia la direccion de memoria del eServicios que se quiere eliminar
/// @return int: 1 si el puntero recibido es nulo o 0 si no lo es
int Servicios_delete(eServicios* servicioAEliminar);


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*Todas las funciones de tipo set asignan el valor recibido en el campo correspondiente en caso de que no hubo inconvenientes
 *Devolviendo 1 si alguno de los punteros es nulo o 0 si todo salio bien
 *
 *Todas las funciones de tipo get depositan el valor de un campo en la variable correspondiente en caso de que no hubo inconvenientes
 *Devolviendo 1 si alguno de los punteros es nulo o 0 si todo salio bien
 *
 *this: Es el puntero a eServicios con el que vamos a trabajar
 *
 */

int Servicios_setId(eServicios* this,int id_Servicio);
int Servicios_getId(eServicios* this,int* id_Servicio);

int Servicios_setDescripcion(eServicios* this,char* descripcion);
int Servicios_getDescripcion(eServicios* this,char* descripcion);

int Servicios_setTipo(eServicios* this,int tipo);
int Servicios_getTipo(eServicios* this,int* tipo);

int Servicios_setPrecioUnitario(eServicios* this,float precioUnitario);
int Servicios_getPrecioUnitario(eServicios* this,float* precioUnitario);

int Servicios_setCantidad(eServicios* this,int cantidad);
int Servicios_getCantidad(eServicios* this,int* cantidad);

int Servicios_setTotalServicio(eServicios* this,float totalServicio);
int Servicios_getTotalServicio(eServicios* this,float* totalServicio);


int Servicios_setAll(eServicios* this, int id_Servicio, char* descripcion, int tipo, float precioUnitario, int cantidad, float totalServicio);
int Servicios_getAll(eServicios* this, int* id_Servicio, char* descripcion, int* tipo, float* precioUnitario, int* cantidad, float* totalServicio);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// @brief A esta funcion le pasamos como parametros puntero a una cadena de caracteres en donde esta almacenada la palabra que representa el tipo de servicio
/// y un puntero al numero correspondiente a ese tipo
/// @pre
/// @post
/// @param tipoString: Puntero a una cadena de caracteres mediante la cual obtendros el tipoNumerico
/// @param tipoNumerico: Puntero al numero correspondiente al tipo
/// @return int: 1 Si alguno de los punteros es nulo o si tipoString no corresponde a ninguna opcion numerica, si nada de esto ocurre devuelve un 0
int Servicios_verificarYTransfomarTipoStringAInt(char* tipoString, int* tipoNumerico);

/// @brief A esta funcion le pasamos como parametros puntero a una cadena de caracteres en donde vamos a guardar el tipo de servicio en forma de palabra
/// y El numero que determinara que la palabra que vamos a asignarle
///
/// @pre
/// @post
/// @param tipoString: Puntero a una cadena de caracteres en donde vamos a guardar el tipo de servicio en forma de palabra
/// @param tipoNumerico: El numero que determinara que la palabra que vamos a asigarle a tipoString
/// @return int: 1 Si el puntero tipoString es nulo o si tipoNumerico no corresponde a ninguna opcion de palabra, si nada de esto ocurre devuelve un 0
int Servicios_verificarYTransfomarTipoIntAString(char* tipoString, int tipoNumerico);

/// @brief Con esta funcion se pueden mostrar los datos de un servicios
///
/// @pre
/// @post
/// @param this: Puntero al servicio que queremos mostrar
/// @return int: 1 si el puntero es nulo, 2 si no se pudieron mostrar algunos datos o se mostraron erroneamente, o 0 si se mostraron todos los datos de manera correcta
int Servicios_MostrarUnServicio(eServicios* this);

/// @brief Funcion auxiliar que le vamos a pasar como parametro a ll_map() para calcular el precio total de cada servicio
///
/// @pre
/// @post
/// @param peServicios: Puntero que recibira la direccion de memoria de un eServicios con el que vamos a trabajar
void Servicios_CalcularPrecioTotal(void* peServicios);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 * Estas son funciones auxiliar para ll_filter()
 * retorno int: 1 si el eServicios recibido por puntero corresponde al tipo mencionado en el nombre de la funcion, de lo contrario devuelve 0
 *  peServicios: Puntero que recibira la direccion de memoria de un eServicios con el que vamos a trabajar
 */


int Servicios_FiltrarPorMinorista(void* peServicios);
int Servicios_FiltrarPorMayorista(void* peServicios);
int Servicios_FiltrarPorExportador(void* peServicios);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// @brief
///
/// @pre
/// @post
/// @param pFile: Puntero al archivo en el cual vamos a guardar los datos de los eServicios
/// @param listaServicios: Puntero a una linkedList donde estan presentes todos loes eServicios
/// @param guardarEncabezado: 1 si se se lo quiere guardar o 0 si no
/// @return int: 1 si alguno de los punteros es nulo o si guardarEncabezado es distinto a 0 y 1, 2 si no se pudieron guardar algunos archivos y 0 si se pudieron guardar todos los archivos
int Servicios_SaveTxt(FILE* pFile, LinkedList* listaServicios, int guardarEncabezado);

/// @brief funcion auxiliar de ll_sort() la cual determinado si se deben intercambiar posiciones o no en base al ordenamiento de manera alfabetica
///
/// @pre
/// @post
/// @param pPrimerServicio: Puntero hacia el primer eServicio a comparar
/// @param pSegundoServicio: Puntero hacia el primer eServicio a comparar
/// @return int: 0 si alguno de los punteros es nulo o si el contenido de sus descripciones es igual, 1 si el primera palabra es mayor a la segunda segun ASCII y -1 si la segunda palabra es mayor a la primera
/// segun ASCII
int Servicios_OrdernarPorDescripcion(void* pPrimerServicio, void* pSegundoServicio);
