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
LinkedList* ll_newLinkedList(void)//
{
    LinkedList* this= NULL;
    this=((LinkedList*)malloc(sizeof(LinkedList)));
    if(this==NULL)
      {
	//text("No se encontro espacio.");
      }else{
	  (*(this)).size=0;
	  (*(this)).pFirstNode=NULL;
      }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)//
{
    int returnAux = -1;
    if(this!=NULL)
      {
	returnAux = (*(this)).size;

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
    int i;
	if(this!=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	  {
	    pNode = this->pFirstNode;
	    for(i=0;i<nodeIndex;i++)
	      {
		 pNode = pNode->pNextNode;
	      }
	  }
	else if(nodeIndex >= ll_len(this))
	  {
	    return NULL;
	  }
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
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
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* aux_n = NULL;
    Node* aux_o = NULL;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && new_node!=NULL)
      {
	    new_node->pElement = pElement; //Elemento del parametro
	    new_node->pNextNode = NULL;//Null para ser pisado

	if(nodeIndex == 0 )
	  {
	    new_node->pNextNode = this->pFirstNode;
	    this->pFirstNode = new_node;
	  }
	else if (nodeIndex >= 0 && nodeIndex <= ll_len(this))
	  {
	    aux_n = getNode(this,(nodeIndex-1));
	    aux_o = getNode(this,(nodeIndex));

	    new_node->pNextNode = aux_o;
	    aux_n->pNextNode = new_node;
	  }
	else
	  {
	    aux_n = getNode(this,nodeIndex);
	    aux_n->pNextNode = new_node;
	  }
	this->size++;//Agranda la lista
	returnAux = 0;
      }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
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
    int tam =  ll_len(this);
    if(this!=NULL)
      {
	if(tam == 0)
	  {
	    addNode(this,0,pElement);
	    returnAux = 0;
	  }
	else
	  {
	    addNode(this,tam,pElement);
	    returnAux = 0;
	  }
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
    void* returnAux = NULL;
    Node* Aux;
    int tam =  ll_len(this); // Tamaño de la lista
       if(this!=NULL && index >=0 && index < tam)
         {
	   Aux = getNode(this,index);// Buffea el nodo con los parametros
	   returnAux = Aux->pElement; // retorna el buffer cargado
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
    int returnAux = -1;
    Node* Aux;
    int tam =  ll_len(this);// Tamaño de la lista
      if(this!=NULL && index >=0 && index < tam)
	{
	  Aux = getNode(this,index);// Buffea el nodo con los parametros
	  Aux->pElement = pElement; // Guarda el buffer en el elemento pasado como parametro
	  returnAux = 0;
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
    int returnAux = -1;
    Node* R_Node=NULL;
    Node* Aux;
    int tam =  ll_len(this);

      if(this!=NULL && index >=0 && index < tam)
    {
      R_Node = getNode(this,index); //Nodo a eliminar
      if(index==0)
	{
	  this->pFirstNode = R_Node->pNextNode;//Nullea el FirstNode
	}
      Aux = getNode(this,index-1);//Nodo Anterior
      Aux->pNextNode = R_Node->pNextNode;//Reemplaza
      free(R_Node);//Limpia la memoria
      this->size--;//Achica la lista
      returnAux = 0;
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
    int returnAux = -1;
    int i;
    int tam = ll_len(this);
    Node* R_node;
    if(this!=NULL && tam>0)
      {
	for(i=0;i<tam;i++)
	  {
	    R_node=getNode(this,i);//Nodos a eliminar
	    this->size--;//Achicar la lista
	    free(R_node);//libera memoria
	    returnAux=0;
	    if(this->size==0)//LLego al minimo de la lista
	    {
	      returnAux=0;
	      break;
	    }
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
    int returnAux = -1;
    if(this!=NULL)
      {
	ll_clear(this);//Pasa this como parametro a la iteracion que libera todas sus pos.
	free(this);// Libera la lista
	returnAux=0;
      }
    /*if(this==NULL)
      {
	returnAux=0;
      }*/
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
    int returnAux = -1;
    int i;
    Node* node;
    if(this!=NULL)
      {
	for(i=0;i<ll_len(this);i++)
	  {
	    node = getNode(this,i);// Igualo a la pos. i de la lista
	    if(pElement == node->pElement)//Busco el nodo con el elemento igual al buscado
	      {
		returnAux= i;//Indice del elemento encontrado
		break;
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
int ll_isEmpty(LinkedList* this)//
{
    int returnAux = -1;
    if(this!= NULL && ll_len(this) == 0) // Si el tamaño de la lista es 0, la lista esta vacia.
      {
	returnAux=1;
      }
    else if(this!=NULL && ll_len(this) > 0) // Si el tamaño de la lista es mayor a 0, la lista tiene lementos.
      {
	returnAux=0;
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
    int returnAux = -1;
    //int tam = this->size;
    //En los errores me pedia verificar que el estado del size haya aumentado, pero nunca me permite hacer esta comprobacion
    if(this!=NULL && index >= 0 && index <= ll_len(this))
      {
	addNode(this,index,pElement);//Agrega un nodo en el index pasado como parametro
	returnAux = 0;
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
    void* returnAux = NULL;
    if(this!=NULL && index >= 0 && index <= ll_len(this))
      {
	returnAux = ll_get(this,index); // Ubicacion del elemento a eliminar
	ll_remove(this,index); //Elimina el elemento

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
    int returnAux = -1;
    int is;
    if(this!=NULL)
      {
	is = ll_indexOf(this,pElement); // Itera en busca del elemento y retorna su pos. en caso de existir
	if(is >= 0) // si el retorno de index es 0 o mayor signidica que existe.
	  {
	    returnAux = 1;
	  }
	else if (is == -1) // Si no contiene el elemento
	  {
	    returnAux = 0;
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
    int returnAux = -1;
    int i,contador;
    Node* Aux;
    if(this!=NULL && this2!=NULL)
      {

	for(i=0;i<this2->size;i++)
	  /*
	   * recorro la longitud de la segunda lista,
	   * con la que tomo como parametro el elemento
	   * a comprar con los elementos de la lista1
	   */
	  {
	    Aux = ll_get(this2,i);// get del nodo iterado

	    if(ll_contains(this,Aux))//si la lista contiene el elemento,
	      {
		contador++;//aumenta el contador
	      }
	  }
	  if(contador==this2->size)//
	    /*
	     * si el contador es igual que ,
	     * el tamaño de elementos de la lista 2
	     * significa que TODOS los elementos
	     * estan contenidos
	     */
	  {
	    returnAux=1;

	  }
	else
	  {
	    returnAux=0;

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
    LinkedList* cloneArray = NULL;
    Node* Aux=NULL;
    int i;

    if(this!=NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
      {
	cloneArray = ll_newLinkedList();
	/*
	 * Creo una nueva lista
	 */
	  if(cloneArray!=NULL)
	    {
	      for(i=0;i<to;i++)
		{
		  Aux=getNode(this,i);
		  /*
		   * Uso el Auxiliar para tomar los nodos en la pos i
		   */
		  addNode(cloneArray,i,Aux->pElement);
		  /*
		   * Envio la nueva lista al addNode para
		   * agregarle uno a uno los nodos de la
		   * lista a clonar
		   */
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
    LinkedList* cloneArray = NULL;
    if(this!=NULL)//Si el la lista es distinta de NULL
      {
	cloneArray=ll_subList(this,0,ll_len(this));
	/*
	 * La subList devuelve una lista igual a
	 * la que se le pasa como parametros
	 */
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
    int returnAux =-1;
    void* Aux;
    void* Aux_2;
    void* Aux_3;
    int i,j;
    if(this!=NULL &&  (order == 1 || order == 0) && pFunc!=NULL)
      {
	for(i=0;i<this->size-1;i++)
	  {
	    for(j=i+1;j<this->size;j++)
	      {
		Aux_2 = ll_get(this,i);//Hace un get de los elementos en la pos
		Aux_3 = ll_get(this,j);
		if(order == 0 )
		  {
		    if(pFunc(Aux_2,Aux_3)==-1)
		      {
		      Aux = Aux_2;
		      ll_set(this,i,Aux_3);
		      ll_set(this,j,Aux);
		      }
		  }
		else if(order == 1)
		  {
		    if(pFunc(Aux_2,Aux_3)==1){
		    Aux = Aux_2;
		    ll_set(this,i,Aux_3);
		    ll_set(this,j,Aux);}
		  }
	      }
	  }
	returnAux= 0;
      }
    return returnAux;

}
/**
* \brief permite modificar un elemento y volver a guardarlo en la lista
* \param this es la lista a ser llamada, y pFunc es una funcion que modifica el elemento
* \return retorna la lista modificada
*
*/
LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))
{
  LinkedList* Aux = NULL;
  void* element= NULL;
  int i;
  int tam = ll_len(this);
    if(this!=NULL && tam>0 )
      {
	Aux = ll_newLinkedList();
	if(Aux!=NULL)
	  {
	    for(i=0;i<tam;i++)
	      {
		element = ll_get(this,i);
		  if(element!=NULL)
		    {
		      element = pFunc(element);
		      ll_add(Aux,element);
		    }
	      }
	  }
      }
    return Aux;
}
/**
* \brief crea un contador de elementos
* \param this es la lista a ser llamada, y pFunc es una funcion que devuelve 1 si el elemento corresponde al criterio
* \return retorna el contador de elementos
*
*/
int ll_count(LinkedList* this, int (*fn)(void*))
{
  int i;
  int cont=0;
  int tam = ll_len(this);
  void* element= NULL;
  if(this!=NULL && tam>0)
    {
      for(i=0;i<tam;i++)
	{
	  element = ll_get(this,i);
	  cont = cont + fn(element);
	}
    }
  return cont;
}
LinkedList* ll_filter(LinkedList* this,int (*pfunc)(void*))
{
  //retorna una lista
  //itera el objeto para filtrar por medio de la funcion pasada como parametro
  LinkedList* aux = NULL;
  void* element = NULL;
  int i;
  int tam;

  if(this!=NULL)
    {
      aux = ll_newLinkedList();
      tam = ll_len(this);
      if(aux!=NULL)
	{
	  for(i=0;i<tam;i++)
	    {
	      element = ll_get(this,i);
	      if(pfunc(element)==1)
		{
		  ll_add(aux,element);
		}
	    }
	}
    }
  return aux;
}
