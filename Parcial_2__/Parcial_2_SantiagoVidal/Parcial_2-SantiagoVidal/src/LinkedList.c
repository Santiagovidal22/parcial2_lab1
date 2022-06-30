#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size=0;
    	this->pFirstNode =NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;

	pNode =NULL;

	if(this != NULL && nodeIndex >-1 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int tamanioLinkedList;
    Node* pNuevoNodo;
    Node* pNodoAuxiliar;

    pNuevoNodo = NULL;
    pNodoAuxiliar = NULL;
    tamanioLinkedList = ll_len(this);

    if(this != NULL && nodeIndex >-1 && nodeIndex <= tamanioLinkedList)
    {
    	pNuevoNodo = (Node*) malloc(sizeof(Node*));

    	if(pNuevoNodo != NULL)
    	{
        	pNuevoNodo->pElement = pElement;
        	this->size++;

        	if(nodeIndex != 0)
        	{
        		if(nodeIndex < tamanioLinkedList)
        		{
        			pNodoAuxiliar = getNode(this, nodeIndex);
            		pNuevoNodo->pNextNode = pNodoAuxiliar;
        		}
        		else
        		{
        			pNuevoNodo->pNextNode = NULL;
        		}
       			pNodoAuxiliar = getNode(this, nodeIndex-1);
    			pNodoAuxiliar->pNextNode = pNuevoNodo;
        	}
        	else
        	{
    			pNuevoNodo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNuevoNodo;
        	}

			returnAux =0;
    	}
    }

    return returnAux;
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    Node* pNodoAuxiliar;

    returnAux =NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNodoAuxiliar = getNode(this, index);

    	if(pNodoAuxiliar != NULL)
    	{
        	returnAux = pNodoAuxiliar->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
    Node* pNodoAModificar;

    returnAux =-1;
    pNodoAModificar =NULL;

    if(this != NULL && index>-1 && index < ll_len(this))
    {
    	pNodoAModificar = getNode(this,index);

    	if(pNodoAModificar != NULL)
    	{
    		pNodoAModificar->pElement = pElement;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    int tamanioLinkedList;
    Node* pNodoAEliminar;
    Node* pNodoAuxiliar;

    tamanioLinkedList = ll_len(this);
    returnAux =-1;
    pNodoAEliminar = NULL;
    pNodoAuxiliar = NULL;

    if(this != NULL && index > -1 && index < tamanioLinkedList)
    {
    	pNodoAEliminar = getNode(this,index);
    	if(pNodoAEliminar != NULL)
    	{
        	if(index != 0)
        	{
        		pNodoAuxiliar = getNode(this,index-1);
        		if(pNodoAuxiliar != NULL)
        		{
            		pNodoAuxiliar->pNextNode= pNodoAEliminar->pNextNode;
        		}
        	}
        	else
        	{
        		this->pFirstNode = pNodoAEliminar->pNextNode;
        	}
        	if(pNodoAEliminar->pElement != NULL)
        	{
            	free(pNodoAEliminar->pElement);
        	}
        	free(pNodoAEliminar);
        	this->size--;
        	returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux;;
    int tamanioLinkedList;
    returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	tamanioLinkedList = ll_len(this);

    	if(tamanioLinkedList >0)
    	{
    		tamanioLinkedList--;
    	}

    	for(int i=tamanioLinkedList ; i> -1; i--)
    	{
    		ll_remove(this, i);
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;

    returnAux=-1;

    if(this != NULL)
    {
    	returnAux =0;
    	ll_clear(this);
    	free(this);
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    int tamanioLinkedList;
    void* pElementoAuxiliar;

    returnAux=-1;
    pElementoAuxiliar = NULL;
    if(this != NULL)
    {
        tamanioLinkedList = ll_len(this);

    	for(int i=0;i< tamanioLinkedList;i++)
    	{
    		pElementoAuxiliar =ll_get(this,i);
    		if(pElementoAuxiliar == pElement)
    		{
    			returnAux=i;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux;

    returnAux=-1;

    if(this != NULL)
    {
    	if(ll_len(this))
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;

    returnAux=-1;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}




/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;

    returnAux = NULL;

    if(this != NULL && index < ll_len(this) && index > -1)
    {
    	returnAux= ll_get(this, index);
    	ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement)>-1)
    	{
    		returnAux =1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int tamanioPrimerThis;
    int tamanioSegundoThis;

    returnAux = -1;

    if(this != NULL && this2 !=NULL)
    {
    	returnAux = 1;
    	tamanioPrimerThis = ll_len(this);
    	tamanioSegundoThis = ll_len(this2);

    	for(int i=0; i < tamanioPrimerThis && i < tamanioSegundoThis;i++)
    	{
    		if(!ll_contains(this, ll_get(this2,i)))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray;

	cloneArray =NULL;

    if(this != NULL && from>-1 && to<=ll_len(this) && from <to)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
        	for(int i= from; i<to; i++)
        	{
        		ll_add(cloneArray, ll_get(this,i));
        	}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray;

    cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
    int tamanioThis;
    int estadoSwap;
    int estadoComparacion;
    int banderaActivarSwap;
    void* pElementoUno;
    void* pElementoDos;

    tamanioThis = ll_len(this);
    returnAux =-1;
    banderaActivarSwap=0;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	returnAux=0;
    	do{
    		estadoSwap =0;
    		tamanioThis--;
        	for(int i=0;i< tamanioThis;i++)
        	{
        		pElementoUno = ll_get(this,i);
        		pElementoDos = ll_get(this,i+1);
        		estadoComparacion = pFunc(pElementoUno,pElementoDos);

        		if(order)
        		{
        			if(estadoComparacion>0)
        			{
        				banderaActivarSwap=1;
        			}
        		}
        		else
        		{
        			if(estadoComparacion<0)
        			{
        				banderaActivarSwap=1;
        			}
        		}

        		if(banderaActivarSwap)
        		{
            		ll_set(this,i+1, pElementoUno);
            		ll_set(this,i, pElementoDos);
        			banderaActivarSwap=0;
    				estadoSwap=1;
        		}
        	}

    	}while(estadoSwap);
    }

    return returnAux;
}

/* Completa un campo del elemento, recibiendo como parámetro
* la función que sera la encargada de calcular el valor de ese campo.
* Verificando que tanto el puntero this como el puntero a la funcion
* fn sean distintos de NULL. Retorna la lista completa.
*/
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
	int tamanioThis;

	if(this != NULL && fn != NULL)
	{
		tamanioThis = ll_len(this);

		for(int i=0; i<tamanioThis;i++)
		{
			fn(ll_get(this,i));
		}
	}
	return this;
}

/* Filtra la lista con una condición, recibiendo como parámetro
 * la función que sera la encargada de decidir si cada elemento
 * cumple la condición (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista nueva lista filtrada.
 */
LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{
	int tamanioThis;
	LinkedList* listaFiltrada;
	void* pElemento;

	listaFiltrada=NULL;
	pElemento =NULL;

	if(this != NULL && fn != NULL)
	{
		listaFiltrada = ll_newLinkedList();
		if(listaFiltrada != NULL)
		{
			tamanioThis = ll_len(this);

			for(int i=0;i<tamanioThis; i++)
			{
				pElemento = ll_get(this, i);
				if(fn(pElemento))
				{
					ll_add(listaFiltrada, pElemento);
				}
			}
		}
	}

	return listaFiltrada;
}

