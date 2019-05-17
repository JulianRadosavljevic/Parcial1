#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "orquesta.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int li_salida=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int li_salida=-1;
    int posicion;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;
            array[posicion].isEmpty=0;
            utn_getNombre("Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("Lugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
            utn_getTexto("Tipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);

            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n lugar: %s\n tipo: %s",
                   posicion, array[posicion].idOrquesta,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);
            li_salida=0;
        }
    }
    return li_salida;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray)
{
    int li_salida=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idOrquesta=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");
            strcpy(array[posicion].tipo,"");
            printf("Registro eliminado!");
            li_salida=0;
        }
    }
    return li_salida;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado)
{
    int li_salida=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idOrquesta=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].lugar,"");
                strcpy(array[i].tipo,"");
            }
        }
        li_salida=0;
    }
    return li_salida;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
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
                printf("\n ID: %d\n nombre: %s\n lugar: %s\n lugar: %s",
                       array[i].idOrquesta,array[i].nombre,array[i].lugar,array[i].tipo);
        }
        li_salida=0;
    }
    return li_salida;
}
