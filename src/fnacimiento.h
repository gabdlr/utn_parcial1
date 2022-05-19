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

int fnacimiento_setDia(Fnacimiento* fnacimiento);
int fnacimiento_setMes(Fnacimiento* fnacimiento);
int fnacimiento_setAnio(Fnacimiento* fnacimiento);
int isBisiesto(int anio);
int tipoDeMes(int mes);
#endif /* FNACIMIENTO_H_ */
