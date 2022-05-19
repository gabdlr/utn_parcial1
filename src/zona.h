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

/// @param zonasArray
/// @param len
/// @return 1 ok 0 error
/// genera una nueva zona
int zona_newZona(Zona zonasArray[], int len);

//setters
/// @param zona
/// @param posicionCalle
/// @return 1 ok 0 error
/// asigna el nombre a una calle dentro de la estructura zona
int zona_setCalle(Zona* zona, int posicionCalle);
/// @param zona
/// @return 1 ok 0 error
/// obliga a asignar todas las calles a una zona
int zona_setCalles(Zona* zona);
/// @param zona
/// @return 1 ok 0 error
/// asigna el id de una localidad a una zona
int zona_setLocalidad(Zona* zona);
/// @param zona
/// @return 1 ok 0 error
/// asigna el estado a una zona
int zona_setEstado(Zona* zona);
/// @param zona
/// @param tipoCenso 0 presencial 1 virtual 3 ausentes
/// @return 1 ok 0 error
/// asigna el resultado a un tipo de censo en una zona
int zona_setResultadoCenso(Zona* zona, int tipoCenso);

//getters
/// @param zona
/// imprime el nombre de la localidad a la que pertenece una zona
void zona_getLocalidad(Zona zona);
/// @param zona
/// imprime el estado de una zona
void zona_getEstado(Zona zona);
/// @param zona
/// @param calle
/// imprime el nombre de una calle dentro de una zona
void zona_getCalle(Zona zona,int calle);
/// imprime las localidades disponibles
void zona_printLocalidadesDisponibles();

//Array
/// @param zonasArray
/// @param len
/// @return -1 error 0 ok
/// Incializa el arreglo de zonas limpiando la basura seteando isEmpty etc
int zona_inicializarArrayZonas(Zona zonasArray[], int len);
/// @param zonasArray
/// @param len
/// @return
/// devuelve un indice disponible en el array de zonas y -1 si no encuentra ninguno
int zona_findIndiceDisponibleZona(Zona zonasArray[], int len);
/// @param zonasArray
/// @param len
/// @return 1 si hay zonas añadidas 0 en caso contrario
int zona_isZonaActiva(Zona zonasArray[],int len);
/// @param zonasArray
/// @param len
/// @param id
/// @return indice de una zona correspondiente al id que recibe si esta como !isEmpty en el arreglo
int zona_findById(Zona zonasArray[], int len, int id);
/// @param zonasArray
/// @param len
/// Imprime todas las zonas !isEmpty que no tiene un censista asignado
void zona_listarZonasSinAsignar(Zona zonasArray[], int len);
/// @param zonasArray
/// @param len
/// Inicializa el arreglo de Zonas con algunos valores por defecto
void zona_cargaForzada(Zona zonasArray[],int len);

//Dev
/// @param zonasArray
/// Imprime todos los atributos de una zona
void zona_devPrintZona(Zona zonasArray[]);

#endif /* ZONA_H_ */
