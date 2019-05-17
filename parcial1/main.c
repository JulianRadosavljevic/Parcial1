#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_TIPO_ORQUESTA 50
#define QTY_TIPO_INSTRUMENTO 20
#define QTY_TIPO_MUSICO 1000

int main()
{
    int opcion;
    int contadorIdorquesta=0;
    int contadorIdmusico=0;
    int contadorIdinstrumento=0;

    Orquesta arrayOrquesta[QTY_TIPO_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO_ORQUESTA);

    Musico arrayMusico[QTY_TIPO_MUSICO];
    musico_Inicializar(arrayMusico,QTY_TIPO_MUSICO);

    Instrumento arrayInstrumento[QTY_TIPO_INSTRUMENTO];
    instrumento_Inicializar(arrayInstrumento,QTY_TIPO_INSTRUMENTO);

    do
    {
        utn_getInt("\n\n1) Alta Orquesta \n2) Baja Orquesta \n3) Listar Orquesta \n\n4) Alta instrumento \n5) Listar instrumento \n\n6) Alta musico \n7) Modificar musico \n8) Baja musico \n9) Listar musico \n\n10) Salir\n\nIngrese una opcion: ",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta orquesta
                orquesta_alta(arrayOrquesta,QTY_TIPO_ORQUESTA,&contadorIdorquesta);
                break;

            case 2: //Baja orquesta
                orquesta_baja(arrayOrquesta,QTY_TIPO_ORQUESTA);
                break;

            case 3://Listar orquesta
                orquesta_listar(arrayOrquesta,QTY_TIPO_ORQUESTA);
                break;

            case 4://Alta Instrumento
                instrumento_alta(arrayInstrumento,QTY_TIPO_INSTRUMENTO,&contadorIdinstrumento);
                break;

            case 5: //Lista instrumento
                instrumento_listar(arrayInstrumento,QTY_TIPO_INSTRUMENTO);
                break;

            case 6: //Alta musico
                musico_alta(arrayMusico,QTY_TIPO_MUSICO,&contadorIdmusico);
                break;

            case 7: //Modificar musico
                musico_modificar(arrayMusico,QTY_TIPO_MUSICO);
                break;

            case 8://Baja musico
                musico_baja(arrayMusico,QTY_TIPO_MUSICO);
                break;

            case 9://Listar
                musico_listar(arrayMusico,QTY_TIPO_MUSICO);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
