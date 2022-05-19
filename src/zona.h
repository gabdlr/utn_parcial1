/*
 * zona.h
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */
#include "utn_library.h"
#include "censista.h"
#include "util.h"
#define MAX_INT 2147483647
#define LEN_ZONAS 1000
#ifndef ZONA_H_
#define ZONA_H_

typedef struct {
	int id;
	int censistaId;
	char calles[4][51];
	int localidad;
	int estado;
	int resultadoCenso[3];
	int isEmpty;
} Zona;

int zona_newZona(Zona zonasArray[], int len);

//setters
int zona_setCalle(Zona* zona, int posicionCalle);
int zona_setCalles(Zona* zona);
int zona_setLocalidad(Zona* zona);
int zona_setEstado(Zona* zona);
int zona_setResultadoCenso(Zona* zona, int tipoCenso);

//getters
void zona_getLocalidad(Zona zona);
void zona_getEstado(Zona zona);
void zona_getCalle(Zona zona,int calle);
void zona_printLocalidadesDisponibles();

//Array
int zona_inicializarArrayZonas(Zona zonasArray[], int len);
int zona_findIndiceDisponibleZona(Zona zonasArray[], int len);
int zona_isZonaActiva(Zona zonasArray[],int len);
int zona_findById(Zona zonasArray[], int len, int id);
void zona_listarZonasSinAsignar(Zona zonasArray[], int len);
void zona_cargaForzada(Zona zonasArray[],int len);

//Dev
void zona_devPrintZona(Zona zonasArray[]);

#endif /* ZONA_H_ */
