/*
 * censista.h
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_
#define LEN_CENSISTAS 1000
#include "direccion.h"
#include "fnacimiento.h"
#include "zona.h"
#include "util.h"
#include "utn_library.h"

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	Fnacimiento fnacimiento;
	int edad;
	Direccion direccion;
	int zona;
	int estado;
	int isEmpty;
} Censista;

int censista_newCensista(Censista censistasArray[]);

//setters
int censista_setNombre(Censista* censista);
int censista_setApellido(Censista* censista);
int censista_setEdad(Censista* censista);
int censista_setEstado(Censista* censista,int estado);
int censista_setDireccionCalle(Censista* censista);
int censista_setDireccionAltura(Censista* censista);
int censista_setDireccionDepartamento(Censista* censista);
int censista_setDireccionCodigoPostal(Censista* censista);
int censista_setFnacimientoAnio(Censista* censista);
int censista_setFnacimientoMes(Censista* censista);
int censista_setFnacimientoDia(Censista* censista);
int censista_setZona(Censista* censista, Zona* zona);

//getters
void censista_getEstado(Censista censista);
void censista_getListado(Censista censistasArray[]);

//Censistas Array
int censista_inicializarArrayCensista(Censista censistasArray[], int len);
int censista_findIndiceDisponibleCensista(Censista censistasArray[],int len);
int censista_isCensistaActivo(Censista censistasArray[],int len);
int censista_findById(Censista censistasArray[], int len, int id);
void censista_eliminarCensista(Censista censistasArray[],int len, Zona zonasArray[],int zonasLen);
void censista_listarCensistasSinZonaAsignada(Censista censistasArray[], int len);
void censista_cargaForzada(Censista censistasArray[],int len);

//Dev
void censista_devPrintCensista(Censista censista);

#endif /* CENSISTA_H_ */
