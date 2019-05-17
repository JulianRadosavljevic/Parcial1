#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int utn_getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int li_salida=-1;
    char bufferStr[max+100];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                li_salida=0;
                break;
            }
            else
            {
                printf("%s 1",msgError);
                (*reintentos)--;
            }

        }
        while((*reintentos)>=0);
    }
    return li_salida;
}

int utn_validGetFloat(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            li_salida=0;
            break;
        }
    }

    return li_salida;
}

int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input)
{
    int li_salida = -1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetFloat(bufferStr) == 1)
                {
                    *input=atof(bufferStr);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetInt(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            li_salida=0;
            break;
        }
    }

    return li_salida;
}


int utn_getInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetInt(bufferStr)==1)
                {
                    *input=atoi(bufferStr); // atoi array to int
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}


int utn_validGetChar(char charRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error

    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
    {
        li_salida=0;
    }

    return li_salida;
}

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int li_salida=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,1,3,&reintentos,bufferChar)) //==0
            {
                if(utn_validGetChar(bufferChar[0])==1)
                {
                    printf("OK");
                    *resultado=bufferChar[0];
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetTexto(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetAlfanumerico(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetAlfanumerico(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

char utn_getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
    {
       srand (time(NULL));
    }

    return desde + (rand() % (hasta + 1 - desde)) ;
}

int utn_validGetNombre(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        //printf("%d",i);
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getNombre(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int li_salida = -1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(utn_validGetNombre(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    li_salida = 0;
                    break;
                }
                else
                {
                    printf("%s 2\n",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetApellido(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        //printf("%d",i);
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getApellido(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int li_salida = -1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(utn_validGetApellido(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    li_salida = 0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetDNI(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    maxSize = 11; //con puntos
    minSize = 8;  // sin puntos
    int li_salida = -1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetDNI(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida = 0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetTelefono(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetTelefono(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetCUIT(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            li_salida=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        li_salida=0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return li_salida;
}

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14; //con guiones 13 elementos
    int minSize=11;  // sin puntos
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetCUIT(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetEmail(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetEmail(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetDireccion(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            li_salida=0;
            break;
        }
    }
    return li_salida;
}

int utn_getDireccion(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int li_salida=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetDireccion(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}

int utn_validGetValor(char* stringRecibido)
{
    int li_salida=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            li_salida=0;
            break;
        }
    }

    return li_salida;
}

int utn_getValor(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input)
{
    int li_salida = -1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_validGetValor(bufferStr)==1)
                {
                    *input=atof(bufferStr); // atof array to float
                    li_salida=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return li_salida;
}
