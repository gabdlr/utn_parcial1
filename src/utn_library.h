/*
 * utn_library.h
 *
 *  Created on: 7 may. 2022
 *      Author: gabde
 */

#ifndef UTN_LIBRARY_H_
#define UTN_LIBRARY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @param pResultado Dir. de memoria donde se guarda el resultado
/// @param mensaje Mensaje que se mostrara al usuario
/// @param mensajeError Mensaje que se mostrara al usuario en caso de error
/// @param reintentos Limite de respuestas erradas
/// @return 0 en caso de no completarse la tarea y 1 si fue completada
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int reintentos);

/// @param pResultado Dir. de memoria donde se guarda el resultado
/// @param mensaje Mensaje que se mostrara al usuario
/// @param mensajeError Mensaje que se mostrara al usuario en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor m�ximo aceptado
/// @param reintentos Limite de respuestas erradas
/// @return 0 en caso de no completarse la tarea y 1 si fue completada
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/// @param pResultado Dir. de memoria donde se guarda el resultado
/// @param mensaje Mensaje que se mostrara al usuario
/// @param mensajeError Mensaje que se mostrara al usuario en caso de error
/// @param minimo Valor minimo aceptado
/// @param maximo Valor m�ximo aceptado
/// @param reintentos Limite de respuestas erradas
/// @return 0 en caso de no completarse la tarea y 1 si fue completada
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/// @param pResultado  Dir. de memoria donde se guarda el resultado
/// @param mensaje Mensaje que se mostrara al usuario
/// @param mensajeError Mensaje que se mostrara al usuario en caso de error
/// @param minLen Valor minimo aceptado
/// @param maxLen Valor m�ximo aceptado
/// @param reintentos Limite de respuestas erradas
/// @param stringType
/// Tipo de verificaci�n 0 solo caracteres,
/// 1 caracteres y maximo 2 espacios,
/// 2 digitos,
/// 3 alfanumerico sin espacios,
/// 4 caracteres y espacios (sin limite de espacios)
/// @return 0 en caso de no completarse la tarea y 1 si fue completada
int utn_getString(char* pResultado, char* mensaje,char* mensajeError, int minLen, int maxLen, int reintentos, int stringType);

/// @param Dir. de memoria donde se guarda el resultado
/// Valida formato
void utn_getDNI(int* pResultado);

/// @param pResultado Dir. de memoria donde se guarda el resultado
/// Valida formato
void utn_getTelefono(char* pResultado[]);

/// @param input Caracter que se desea v�lidar
/// @return 0 si no es un caracter alfabetico 1 en caso contrario
int utn_isValidChar(char input);

/// @param input Cadena de caracteres que se desea v�lidar
/// @param len Longitud de la cadena
/// @return 0 si alg�n caracter es no alfabetico, espacio o si la cadena contiene mas de 2 espacios, 1 en caso contrario
int utn_isValidCharWithSpaces(char input[], int len);

/// @param input Cadena de caracteres que se desea v�lidar
/// @param len Longitud de la cadena
/// @return 0 si alg�n caracter es no alfabetico o espacio, 1 en caso contrario
int utn_isValidCharWithSpacesUnrestricted(char input[], int len);

/// @param input Cadena de caracteres que se desea v�lidar
/// @param len Longitud de la cadena
/// @return 0 si alg�n caracter es no alfabetico o n�merico, 1 en caso contrario
int utn_isValidCharWithDigits(char input[], int len);

/// @param input
/// @return Undeveloped
int utn_isValidCharExtended(char input);

/// @param buffer Numero convertido a cadena de caracteres
/// @param auxResultado Dir. de memoria donde se guarda el resultado (como entero)
/// @return 0 si algun caracter no es digito o la cadena esta vacia, 1 en caso contrario
int utn_isValidInt(char* buffer, int* auxResultado);

/// @param buffer Numero convertido a cadena de caracteres
/// @param auxResultado Dir. de memoria donde se guarda el resultado (como flotante)
/// @return 0 si algun caracter no es digito o la cadena esta vacia, 1 en caso contrario
float utn_isValidFloat(char* buffer, float* auxResultado);

/// @param string arreglo de caracteres
/// @param len largo del arreglo
/// Remplaza la basura con null terminator en un array
void utn_purifyString(char string[],int len);

#endif /* UTN_LIBRARY_H_ */
