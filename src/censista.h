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
/// @param censistasArray
/// @return 1 ok 0 error
/// genera una nuevo censista
int censista_newCensista(Censista censistasArray[]);

//setters
/// @param censista
/// @return 1 ok 0 error
/// asigna un nombre a un censista
int censista_setNombre(Censista* censista);
/// @param censista
/// @return 1 ok 0 error
/// asigna un apellido a un censista
int censista_setApellido(Censista* censista);
/// @param censista
/// @return 1 ok 0 error
/// estado 1 ok 0 error
int censista_setEdad(Censista* censista);
/// @param censista
/// @param 0 LIBERADO 1 ACTIVO 2 INACTIVO
/// @return estado 1 ok 0 error
/// estado el estado a un censista
int censista_setEstado(Censista* censista,int estado);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna una calle en la direccion a un censista
int censista_setDireccionCalle(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna la altura en la direccion a un censista
int censista_setDireccionAltura(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna el depto en la direccion a un censista
int censista_setDireccionDepartamento(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna el cód. postal en la direccion a un censista
int censista_setDireccionCodigoPostal(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna el año en la f. nacimiento a un censista
int censista_setFnacimientoAnio(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna el mes en la f. nacimiento a un censista
int censista_setFnacimientoMes(Censista* censista);
/// @param censista
/// @return estado 1 ok 0 error
/// asigna el dia en la f. nacimiento a un censista
int censista_setFnacimientoDia(Censista* censista);
/// @param censista
/// @param zona putero a la zona a asignar
/// @return estado 1 ok 0 error
/// asigna una zona a un censista
int censista_setZona(Censista* censista, Zona* zona);

//getters

/// @param censista
/// imprime el estado del censista
void censista_getEstado(Censista censista);

/// @param censistasArray
/// imprime el listado de censistas donde !isEmpty
void censista_getListado(Censista censistasArray[]);

//Censistas Array
/// @param censistasArray
/// @param len
/// @return 0 ok -1 error
/// limpia el array y coloca isEmpty en 1 en todas las posiciones
int censista_inicializarArrayCensista(Censista censistasArray[], int len);
/// @param censistasArray
/// @param len
/// @return indice del primer censista donde isEmpty -1 si no hay ninguno
int censista_findIndiceDisponibleCensista(Censista censistasArray[],int len);
/// @param censistasArray
/// @param len
/// @return 1 si encuenta al menos un censista donde !isEmpty 0 en caso contrario
int censista_isCensistaActivo(Censista censistasArray[],int len);
/// @param censistasArray
/// @param len
/// @param id
/// @return indice del censista del que se pasa el id o -1 si no existe
int censista_findById(Censista censistasArray[], int len, int id);
/// @param censistasArray
/// @param len
/// @param zonasArray
/// @param zonasLen
/// Coloca isEmpty a un censista si el mismo no posee zonas asignadas o estado inactivo en caso contrario
void censista_eliminarCensista(Censista censistasArray[],int len, Zona zonasArray[],int zonasLen);
/// @param censistasArray
/// @param len
/// Lista todos los censistas que tienen estado liberado y !isEmpty
void censista_listarCensistasSinZonaAsignada(Censista censistasArray[], int len);
/// @param censistasArray
/// @param len
/// Carga el array de censistas con valores predefinidos
void censista_cargaForzada(Censista censistasArray[],int len);

//Dev
/// @param censista
/// Imprime todos los atributos de un censista
void censista_devPrintCensista(Censista censista);

#endif /* CENSISTA_H_ */
