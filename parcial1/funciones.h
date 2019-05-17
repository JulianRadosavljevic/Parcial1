#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int utn_getInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
char utn_getNumeroAleatorio(int desde , int hasta, int iniciar);
int utn_getNombre(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_getApellido(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input);
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input);
int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_getDireccion(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getValor(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);

int utn_validGetFloat(char* stringRecibido);
int utn_validGetInt(char* stringRecibido);
int utn_validGetChar(char charRecibido);
int utn_validGetTexto(char* stringRecibido);
int utn_validGetAlfanumerico(char* stringRecibido);
int utn_validGetNombre(char* stringRecibido);
int utn_validGetApellido(char* stringRecibido);
int utn_validGetDNI(char* stringRecibido);
int utn_validGetTelefono(char* stringRecibido);
int utn_validGetCUIT(char* stringRecibido);
int utn_validGetEmail(char* stringRecibido);
int utn_validGetDireccion(char* stringRecibido);
int utn_validGetValor(char* stringRecibido);

#endif // FUNCIONES_H_INCLUDED
