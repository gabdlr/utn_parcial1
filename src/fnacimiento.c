/*
 * fnacimiento.c
 *
 *  Created on: 15 may. 2022
 *      Author: gabde
 */
#include "fnacimiento.h"
#define ANIO_ACTUAL 2022
#define ANIO_BISIESTO 2020

int anioMayoriaDeEdad = (ANIO_ACTUAL - 18);
int anioMuyAncianos = (ANIO_ACTUAL - 90);

int fnacimiento_setAnio(Fnacimiento* fnacimiento){
	int retorno;
	retorno = 0;
	int anio;
	if(utn_getInt(&anio, "Ingrese su año de nacimiento (ej: 1999, debe ser mayor de edad): ",
		"Dato inválido", anioMuyAncianos, anioMayoriaDeEdad, 3)){
		fnacimiento->anio = anio;
		retorno = 1;
		printf("%d\n", fnacimiento->anio);
		printf("Guardado!\n");
	}
	return retorno;
}

int fnacimiento_setMes(Fnacimiento* fnacimiento){
	int retorno;
	retorno = 0;
	int mes;
	if(utn_getInt(&mes, "Ingrese su mes de nacimiento (ej: 1, para el mes de enero): ",
		"Dato inválido", 1, 12, 3)){
		fnacimiento->mes = mes;
		retorno = 1;
		printf("%d\n", fnacimiento->mes);
		printf("Guardado!\n");
	}
	return retorno;
}

int fnacimiento_setDia(Fnacimiento* fnacimiento){
	int retorno;
	retorno = 0;
	int dia;
	int tipoMes;
	tipoMes = tipoDeMes(fnacimiento->mes);
	switch(tipoMes){
		case 1:
			if(utn_getInt(&dia, "Ingrese su dia de nacimiento: ",
				"Dato inválido", 1, 31, 3)){
				fnacimiento->dia = dia;
				retorno = 1;
				printf("%d\n", fnacimiento->dia);
				printf("Guardado!\n");
			}
			break;
		case 2:
			if(utn_getInt(&dia, "Ingrese su dia de nacimiento: ",
				"Dato inválido", 1, 30, 3)){
				fnacimiento->dia = dia;
				retorno = 1;
				printf("%d\n", fnacimiento->dia);
				printf("Guardado!\n");
			}
			break;
		case 3:
			if(isBisiesto(fnacimiento->anio)){
				if(utn_getInt(&dia, "Ingrese su dia de nacimiento: ",
					"Dato inválido", 1, 29, 3)){
					fnacimiento->dia = dia;
					retorno = 1;
					printf("%d\n", fnacimiento->dia);
					printf("Guardado!\n");
					}
				}
				else{
				if(utn_getInt(&dia, "Ingrese su dia de nacimiento: ",
					"Dato inválido", 1, 28, 3)){
					fnacimiento->dia = dia;
					retorno = 1;
					printf("%d\n", fnacimiento->dia);
					printf("Guardado!\n");
					}
				}
			break;
		case 4:
			printf("Unhandled Exception");
			break;
	}
	return retorno;
}

int isBisiesto(int anio){
	int retorno;
	retorno = 0;
	if(!((ANIO_BISIESTO - anio) % 4)){
		retorno = 1;
	}
	return retorno;
}

int tipoDeMes(int mes){
	int meses30Dias[4] = {4,6,9,11};
	int meses31Dias[7] = {1,3,5,7,8,10,12};
	int tipoMes;
	tipoMes = 0;

	for(int i = 0; i < 7; i++){
		if(mes == meses31Dias[i]){
			tipoMes = 1;
			break;
		}
	}
	if(!tipoMes){
		for(int i = 0; i < 4; i++){
			if(mes == meses30Dias[i]){
				tipoMes = 2;
				break;
			}
		}
		if(!tipoMes){
			tipoMes = 3;
		}
	}

	return tipoMes;
}
