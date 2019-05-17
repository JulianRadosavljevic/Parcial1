#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "musico.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
{
    int li_salida=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)
            {
                li_salida=0;
                *posicion=i;
                break;
            }
        }
    }
    return li_salida;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)
{
    int li_salida=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID)
{
    int li_salida=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);
            utn_getNombre("Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getApellido("Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);

            printf("\n Posicion: %d\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idMusico,array[posicion].edad,array[posicion].nombre,array[posicion].apellido);
            li_salida=0;
        }
    }
    return li_salida;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int li_salida=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;
            array[posicion].edad=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            printf("Registro eliminado!");
            li_salida=0;
        }
    }
    return li_salida;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado)
{
    int li_salida=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;
                array[i].edad=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].apellido,"");
            }
        }
        li_salida=0;
    }
    return li_salida;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)
{
    int li_salida=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s",
                       posicion, array[posicion].idMusico,array[posicion].edad,array[posicion].nombre,array[posicion].apellido);
                utn_getTexto("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);
                        break;
                    case 'C':
                        utn_getNombre("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            li_salida=0;
        }
    }
    return li_salida;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico array[],int size)
{
    int li_salida=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);
            bufferId=array[i].idMusico;
            bufferIsEmpty=array[i].isEmpty;
            bufferInt=array[i].edad;
            strcpy(bufferLongString,array[i].apellido);

            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombre)<0)
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idMusico=array[j].idMusico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;
                strcpy(array[j + 1].apellido,array[j].apellido);

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString);
            array[j + 1].idMusico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].edad=bufferInt;
            strcpy(array[j + 1].apellido,bufferLongString);
        }
        li_salida=0;
    }
    return li_salida;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
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
                printf("\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s",
                       array[i].idMusico,array[i].edad,array[i].nombre,array[i].apellido);
        }
        li_salida=0;
    }
    return li_salida;
}
