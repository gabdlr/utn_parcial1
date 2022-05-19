/*
 * direccion.h
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */
#include "utn_library.h"
#ifndef DIRECCION_H_
#define DIRECCION_H_

typedef struct {
	char calle[51];
	char altura[6];
	char departamento[6];
	char codigoPostal[6];
} Direccion;

/// @param direccion
/// @return 0 en caso de error 1 si esta ok
/// cambia la calle de una estructura dirección
int direccion_setCalle(Direccion* direccion);
/// @param direccion
/// @return 0 en caso de error 1 si esta ok
/// cambia la altura de una estructura dirección
int direccion_setAltura(Direccion* direccion);
/// @param direccion
/// @return 0 en caso de error 1 si esta ok
/// cambia el departamento de una estructura dirección
int direccion_setDepartamento(Direccion* direccion);
/// @param direccion
/// @return 0 en caso de error 1 si esta ok
/// cambia el cód. postal de una estructura dirección
int direccion_setCodigoPostal(Direccion* direccion);
#endif /* DIRECCION_H_ */
