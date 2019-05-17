#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "instrumento.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)
{
    int li_salida=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        li_salida=0;
    }
    return li_salida;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
{
    int li_salida=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                li_salida=0;
                *posicion=i;
                break;
            }
        }
    }
    return li_salida;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int li_salida=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)
            {
                li_salida=0;
                *posicion=i;
                break;
            }
        }
    }
    return li_salida;
}

//String
/** \brief Busca un string en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)
{
    int li_salida=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                li_salida=0;
                break;
            }
        }
    }
    return li_salida;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int li_salida=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;
            array[posicion].isEmpty=0;
            utn_getNombre("getName: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("getTexto: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);
            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n tipo: %s",
                   posicion, array[posicion].idInstrumento,array[posicion].nombre,array[posicion].tipo);
            li_salida=0;
        }
    }
    return li_salida;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)
{
    int li_salida=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n nombre: %s\n tipo: %s",
                       array[i].idInstrumento,array[i].nombre,array[i].tipo);
        }
        li_salida=0;
    }
    return li_salida;
}
