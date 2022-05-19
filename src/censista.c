/*
 * censista.c
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */

#include "censista.h"
#include "zona.h"
const char estadoCensista[3][10] = {"LIBERADO", "ACTIVO","INACTIVO"};

int censista_newCensista(Censista censistasArray[]){
	Censista censista;
	int retorno;
	retorno = 0;
	int index;
	index = censista_findIndiceDisponibleCensista(censistasArray, LEN_CENSISTAS);

	if(index >= 0 && index <= LEN_CENSISTAS){
		if(censista_setNombre(&censista)){
			if(censista_setApellido(&censista)){
				if(censista_setEdad(&censista)){
					if(censista_setFnacimientoAnio(&censista)){
						if(censista_setFnacimientoMes(&censista)){
							if(censista_setFnacimientoDia(&censista)){
								if(censista_setDireccionCalle(&censista)){
									if(censista_setDireccionAltura(&censista)){
										if(censista_setDireccionDepartamento(&censista)){
											if(censista_setDireccionCodigoPostal(&censista)){
												if(censista_setEstado(&censista,0)){
													censistasArray[index] = censista;
													censistasArray[index].isEmpty = 0;
													censistasArray[index].zona = 0;
													censistasArray[index].id = uuid(1);
													retorno = 1;
													printf("Nuevo censista añadido exitosamente!\n");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//censista_devPrintCensista(censistasArray[index]);
	return retorno;
}

//setters
int censista_setNombre(Censista* censista){
	int retorno;
	retorno = 0;
	char nombre[51];
	if(utn_getString(nombre, "Ingrese el nombre del censista (máx. 40 carácteres): ",
		"El nombre ingresado es inválido.", 1, 40, 3, 1)){
		strncpy(censista->nombre,nombre,51);
		retorno = 1;
		printf("%s\n", censista->nombre);
		printf("Guardado!\n");
	}
	return retorno;
}

int censista_setApellido(Censista* censista){
	int retorno;
	retorno = 0;
	char apellido[51];
	if(utn_getString(apellido, "Ingrese el apellido del censista (máx. 40 carácteres): ",
		"El apellido ingresado es inválido.", 1, 40, 3, 1)){
		strncpy(censista->apellido,apellido,51);
		retorno = 1;
		printf("%s\n", censista->apellido);
		printf("Guardado!\n");
	}
	return retorno;
}

int censista_setEdad(Censista* censista){
	int retorno;
	retorno = 0;
	int edad;
	if(utn_getInt(&edad, "Ingrese la edad del censista (mayores de 18 años): ",
		"La edad ingresada es inválida", 18, 90, 3)){
		censista->edad = edad;
		retorno = 1;
		printf("%d años\n", censista->edad);
		printf("Guardado!\n");
	}
	return retorno;
}

int censista_setDireccionCalle(Censista* censista){
	int retorno;
	retorno = 0;

	if(direccion_setCalle(&censista->direccion)){
		retorno = 1;
	}

	return retorno;
}
int censista_setDireccionAltura(Censista* censista){
	int retorno;
	retorno = 0;

	if(direccion_setAltura(&censista->direccion)){
		retorno = 1;
	}

	return retorno;
}
int censista_setDireccionDepartamento(Censista* censista){
	int retorno;
	retorno = 0;

	if(direccion_setDepartamento(&censista->direccion)){
		retorno = 1;
	}

	return retorno;
}
int censista_setDireccionCodigoPostal(Censista* censista){
	int retorno;
	retorno = 0;

	if(direccion_setCodigoPostal(&censista->direccion)){
		retorno = 1;
	}

	return retorno;
}

int censista_setFnacimientoAnio(Censista* censista){
	int retorno;
	retorno = 0;
	if(fnacimiento_setAnio(&censista->fnacimiento)){
		retorno = 1;
	}
	return retorno;
}

int censista_setFnacimientoMes(Censista* censista){
	int retorno;
	retorno = 0;
	if(fnacimiento_setMes(&censista->fnacimiento)){
		retorno = 1;
	}
	return retorno;
}

int censista_setFnacimientoDia(Censista* censista){
	int retorno;
	retorno = 0;
	if(fnacimiento_setDia(&censista->fnacimiento)){
		retorno = 1;
	}
	return retorno;
}

int censista_setEstado(Censista* censista,int estado){
	int retorno;
	retorno = 0;
	if(censista != NULL && (estado >=  0 && estado <= 2)){
		censista->estado = estado;
		retorno = 1;
	}
	return retorno;
}

int censista_setZona(Censista* censista, Zona* zona){
	int retorno;
	retorno = 0;

	if(censista != NULL && zona != NULL){
		if(!(censista->isEmpty) && !(censista->zona) && !(censista->estado)){
			zona->censistaId = censista->id;
			censista->zona = zona->id;
			censista_setEstado(censista,1);
			retorno = 1;
		}
	}
	return retorno;
}



void censista_getEstado(Censista censista){
	int estado;
	estado = censista.estado;
	printf("%s", estadoCensista[estado]);
}

void censista_getListado(Censista censistasArray[]){
	if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
		printf("  ID|Nombre|Apellido|Edad|Fecha nacimiento|Direccion|Estado\n");
		for(int i = 0; i < LEN_CENSISTAS; i++){
			if(!censistasArray[i].isEmpty){
				printf("%4d|%s|%s|%d|%d/%d/%d|%s %s %s|",
						censistasArray[i].id,
						censistasArray[i].nombre,
						censistasArray[i].apellido,
						censistasArray[i].edad,
						censistasArray[i].fnacimiento.dia,
						censistasArray[i].fnacimiento.mes,
						censistasArray[i].fnacimiento.anio,
						censistasArray[i].direccion.calle,
						censistasArray[i].direccion.altura,
						censistasArray[i].direccion.departamento
						);
				censista_getEstado(censistasArray[i]);
				printf("\n");
			}
		}
	}
}

int censista_findIndiceDisponibleCensista(Censista censistasArray[],int len){
	int indice;
	indice = -1;

	if(censistasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(censistasArray[i].isEmpty){
				indice = i;
				break;
			}
		}
	}
	if(indice == -1){
		printf("No se encontraron espacios disponibles para agregar un nuevo censista!\n");
	}
	return indice;
}

int censista_findById(Censista censistasArray[], int len, int id){
	int index;
	index = -1;
	if(censistasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(censistasArray[i].id == id && !censistasArray[i].isEmpty){
				index = i;
				break;
			}
		}
	}
	return index;
}

void censista_eliminarCensista(Censista censistasArray[],int len, Zona zonasArray[],int zonasLen){

	if(censista_isCensistaActivo(censistasArray, len)){
		int index;
		int censistaId;
		if(utn_getInt(&censistaId, "Ingrese el id del censista que desea eliminar: ",
				"El valor ingresado es inválido", 1, LEN_CENSISTAS, 3)){
			if((index = censista_findById(censistasArray, len, censistaId)) >= 0){
				int asignacionZona;
				asignacionZona = 0;
				for(int i = 0; i < zonasLen; i++){
					if(!zonasArray[i].isEmpty && zonasArray[i].censistaId == censistaId){
						asignacionZona = 1;
						break;
					}
				}
				if(!asignacionZona){
					censistasArray[index].isEmpty = 1;
					printf("El censista %s %s con id %d ha sido dado de baja",
							censistasArray[index].nombre,
							censistasArray[index].apellido,
							censistasArray[index].id);
				}else{
					censistasArray[index].estado = 2;
					printf("El censista %s %s con id %d no puede ser dado de baja porque posee una zona asignada, ha sido marcado como ",
							censistasArray[index].nombre,
							censistasArray[index].apellido,
							censistasArray[index].id);
					censista_getEstado(censistasArray[index]);
					printf("\n");
				}
			}
		}
	}
}

int censista_isCensistaActivo(Censista censistasArray[],int len){
	int retorno;
	retorno = 0;

	if(censistasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(!(censistasArray[i].isEmpty)){
				retorno = 1;
				break;
			}
		}
	}

	if(!retorno){
		printf("Aún no ha añadido ningún censista.\n");
	}
	return retorno;
}

int censista_inicializarArrayCensista(Censista censistasArray[], int len){
	int retorno = -1;
	if(censistasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			censistasArray[i].isEmpty = 1;
			//Evita que la basura retorne mal el index (...)
			censistasArray[i].id = 0;
		}
		retorno = 0;
	}
	return retorno;
}

void censista_listarCensistasSinZonaAsignada(Censista censistasArray[], int len){
	printf("LISTADO DE CENSISTAS DISPONIBLES PARA ASIGNAR UNA ZONA\n");
	printf("  ID|Nombre\n");
	for(int i = 0; i < len; i++){
		if(!(censistasArray[i].isEmpty) && !(censistasArray[i].zona) && !(censistasArray[i].estado)){
			printf("%4d|", censistasArray[i].id);
			printf("%s %s\n", censistasArray[i].nombre,censistasArray[i].apellido);
		}
	}
}

void censista_cargaForzada(Censista censistasArray[],int len){
	char nombre[45] = "Nombre";
	char apellido[45] = "Apellido";
	char calle[49] = "Calle generica";
	char altura[4] = "1000";
	char depto[4] = "1A";
	char cPostal[6] = "1080";
	for(int i = 0; i < 4; i++){
		censistasArray[i].id = uuid(1);
		censistasArray[i].isEmpty = 0;
		censistasArray[i].edad = 31;
		strncpy(censistasArray[i].nombre,nombre,45);
		strncpy(censistasArray[i].apellido,apellido,45);
		censistasArray[i].fnacimiento.anio = 1990;
		censistasArray[i].fnacimiento.mes = 12;
		censistasArray[i].fnacimiento.dia = 30;
		strncpy(censistasArray[i].direccion.calle,calle,48);
		strncpy(censistasArray[i].direccion.altura,altura,4);
		strncpy(censistasArray[i].direccion.departamento,depto,4);
		strncpy(censistasArray[i].direccion.codigoPostal,cPostal,4);

	}
}

int censista_cantidadCensistasActivosConZonaPendiente(Censista censistasArray[], int lenCensistas, Zona zonasArray[], int lenZonas){
	int contador;
	contador = 0;
	if(censistasArray != NULL && lenCensistas > 0 && zonasArray != NULL && lenZonas > 0){
		for(int i =0; i < lenCensistas; i++){
			if(!(censistasArray[i].isEmpty) && censistasArray[i].estado == 1){
				if(!zonasArray[censistasArray[i].zona].estado){
					contador++;
				}
			}
		}
	}
	return contador;
}

void censista_ListarCensistasAlfabeticamenteSegunLocalidad(Censista censistasArray[], int len, int localidad){
	int isOrdered;
	Censista censista1;
	Censista censista2;
	Censista auxCensista;
	localidad = localidad - 1;
	do{
		isOrdered = 1;
		len--;
		for(int i = 0; i < len; i++){
			censista1 = censistasArray[i];
			censista2 = censistasArray[i+1];
			if(stricmp(censista1.apellido,censista2.apellido) > 0){
				auxCensista = censistasArray[i];
				censistasArray[i] = censistasArray[i+1];
				censistasArray[i+1] = auxCensista;
				isOrdered = 0;
			}else if(stricmp(censista1.apellido,censista2.apellido) == 0
					&& censista1.nombre > censista2.nombre){
				auxCensista = censistasArray[i];
				censistasArray[i] = censistasArray[i+1];
				censistasArray[i+1] = auxCensista;
				isOrdered = 0;
			}
		}
	}while(!isOrdered);
	printf("  ID|Apellido|Nombre\n");
	for(int i = 0; i < LEN_CENSISTAS; i++){
		if(!(censistasArray[i].isEmpty) && censistasArray[i].zona == localidad){
			printf("%d|%s|%s\n", censistasArray[i].id,censistasArray[i].apellido,censistasArray[i].nombre);
		}
	}
}

void censista_devPrintCensista(Censista censista){
	printf("Id: %d\n", censista.id);
	printf("Nombre: %s\n", censista.nombre);
	printf("Apellido: %s\n", censista.apellido);
	printf("Edad: %d\n", censista.edad);
	printf("Estado: %d\n", censista.estado);
	censista_getEstado(censista);
	printf("\n");
	printf("Año de nacimiento: %d\n", censista.fnacimiento.anio);
	printf("Mes de nacimiento: %d\n", censista.fnacimiento.mes);
	printf("Mes de nacimiento: %d\n", censista.fnacimiento.dia);
	printf("Calle: %s\n", censista.direccion.calle);
	printf("Altura: %s\n", censista.direccion.altura);
	printf("Departamento: %s\n", censista.direccion.departamento);
	printf("Codigo postal: %s\n", censista.direccion.codigoPostal);
}
