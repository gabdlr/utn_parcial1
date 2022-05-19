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

int direccion_setCalle(Direccion* direccion);
int direccion_setAltura(Direccion* direccion);
int direccion_setDepartamento(Direccion* direccion);
int direccion_setCodigoPostal(Direccion* direccion);
#endif /* DIRECCION_H_ */
