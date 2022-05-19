/*
 * fnacimiento.h
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */

#ifndef FNACIMIENTO_H_
#define FNACIMIENTO_H_
#include "utn_library.h"

typedef struct {
	int dia;
	int mes;
	int anio;
} Fnacimiento;

/// @param fnacimiento
/// @return 0 error 1 ok
/// asigna el dia a un fnacimiento
int fnacimiento_setDia(Fnacimiento* fnacimiento);
/// @param fnacimiento
/// @return 0 error 1 ok
/// asigna el mes a un fnacimiento
int fnacimiento_setMes(Fnacimiento* fnacimiento);
/// @param fnacimiento
/// @return 0 error 1 ok
/// asigna el año a un fnacimiento
int fnacimiento_setAnio(Fnacimiento* fnacimiento);
/// @param anio
/// @return 1 en años bisiestos 0 en no bisiesto
int isBisiesto(int anio);
/// @param mes
/// @return devuelve si el mes es de 30,31 o es febrero
int tipoDeMes(int mes);
#endif /* FNACIMIENTO_H_ */
