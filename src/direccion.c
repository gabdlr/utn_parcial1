/*
 * direccion.c
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */
#include "direccion.h"

int direccion_setCalle(Direccion* direccion){
	int retorno;
	retorno = 0;
	char calle[51];
	if(utn_getString(calle, "Ingrese la calle donde reside el censista (máx. 40 carácteres, no incluya la altura): ",
		"La calle ingresada es inválida", 1, 40, 3, 4)){
		strncpy(direccion->calle,calle,51);
		retorno = 1;
		printf("%s\n", direccion->calle);
		printf("Guardado!\n");
	}
	return retorno;
}

int direccion_setAltura(Direccion* direccion){
	int retorno;
	retorno = 0;
	char altura[6];
	if(utn_getString(altura, "Ingrese a que altura de la calle reside el censista (máx. 5 cifras): ",
		"La altura ingresada es inválida", 1, 6, 3, 2)){
		strncpy(direccion->altura,altura,6);
		retorno = 1;
		printf("%s\n", direccion->altura);
		printf("Guardado!\n");
	}
	return retorno;
}

int direccion_setDepartamento(Direccion* direccion){
	int retorno;
	retorno = 0;
	char departamento[6];
	char casaAux[5] = "CASA";

	if(utn_getString(departamento, "Ingrese el departamento donde reside el censista (máx. 5 caracteres, si es casa, oprima enter): ",
		"Inválido", 0, 5, 3, 3)){
		if(strlen(departamento) == 0){
			strncpy(departamento,casaAux,5);
		}
		strncpy(direccion->departamento,departamento,5);
		retorno = 1;
		printf("%s\n", direccion->departamento);
		printf("Guardado!\n");
	}
	return retorno;
}

int direccion_setCodigoPostal(Direccion* direccion){
	int retorno;
	retorno = 0;
// El caso del arreglo de chars maldito
	char codigoPostal[6];
	if(utn_getString(codigoPostal, "Ingrese el codigo postal del censista (el mismo esta compuesto de 4 numeros): ",
		"El codigo postal ingresado es inválido", 4, 4, 3, 2)){
		strncpy(direccion->codigoPostal,codigoPostal,5);
		retorno = 1;
		printf("%s\n", direccion->codigoPostal);
		printf("Guardado!\n");
	}
	return retorno;
}

