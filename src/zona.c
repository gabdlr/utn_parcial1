/*
 * zona.c
 *
 *  Created on: 17 may. 2022
 *      Author: gabde
 */
#include "zona.h"

const char localidades[4][10] = {"Belgrano", "Almagro", "Palermo", "Recoleta"};
const char estados[2][14] = {"Pendiente", "Finalizado"};
const char tipoCensados[3][10] = {"In Situ", "Virtual", "Ausente"};

int zona_newZona(Zona zonasArray[], int len){
	Zona zona;

	int retorno;
	retorno = 0;
	int index;
	index = zona_findIndiceDisponibleZona(zonasArray, len);
	if(index >= 0 && index <= len){
		zona_printLocalidadesDisponibles();
		if(zona_setLocalidad(&zona)){
			if(zona_setCalles(&zona)){
				zona.id = uuid(2);
				zona.estado = 0;
				zona.censistaId = 0;
				zona.resultadoCenso[0] = 0;
				zona.resultadoCenso[1] = 0;
				zona.resultadoCenso[2] = 0;
				zona.isEmpty = 0;
				zonasArray[index] = zona;
				retorno = 1;
				printf("Nueva zona añadida exitosamente!\n");
			}
		}
	}
	return retorno;
}

//setters
int zona_setCalle(Zona* zona, int posicionCalle){
	int retorno;
	retorno = 0;
	char nombreCalle[50];
	if(zona != NULL){
		if(utn_getString(nombreCalle, "Ingrese el nombre de la calle: ", "El nombre ingresado es inválido", 1, 20, 3, 4)){
			strncpy(zona->calles[posicionCalle],nombreCalle,51);
			retorno = 1;
			printf("%s\n", zona->calles[posicionCalle]);
			printf("Guardado!\n");
		}
	}
	return retorno;
}

int zona_setCalles(Zona* zona){
	int retorno;
	retorno = 0;
	int callesCompletadas;
	callesCompletadas = 0;
	printf("Indique las calles que delimitan esta zona\n");
	for(int i = 0; i < 4; i++){
		printf("Calle %d\n", i+1);
		if(!zona_setCalle(zona, i)){
			break;
		}else{
			callesCompletadas++;
		}
	}
	if(callesCompletadas == 4){
		retorno = 1;
	}
	return retorno;
}

int zona_setLocalidad(Zona* zona){
	int retorno;
	retorno = 0;
	int localidad;
	if(zona != NULL){
		if(utn_getInt(&localidad, "Ingrese el digito correspondiente a la localidad que desea asignar: ", "Valor inválido", 1, 4, 3)){
			zona->localidad = localidad - 1;
			retorno = 1;
			zona_getLocalidad(*zona);
			printf("\nGuardado!\n");
		}
	}
	return retorno;
}

int zona_setEstado(Zona* zona){
	int retorno;
	retorno = 0;
	int estado;
	if(zona != NULL){
		if(utn_getInt(&estado, "Ingrese el digito correspondiente al estado que desea asignar: ", "Valor inválido", 1, 2, 3)){
			zona->estado = estado - 1;
			retorno = 1;
			zona_getEstado(*zona);
			printf("\nGuardado!\n");
		}
	}
	return retorno;
}

int zona_setResultadoCenso(Zona* zona, int tipoCenso){
	int retorno;
	retorno = 0;
	if(zona != NULL && (tipoCenso >= 0 && tipoCenso <= 2)){
		int cantidadPorTipo;
		char mensaje[50] = "Ingrese el numero de censados ";
		char endingMensaje[4] = ": ";
		strcat(mensaje, tipoCensados[tipoCenso]);
		strcat(mensaje, endingMensaje);
		if(utn_getInt(&cantidadPorTipo, mensaje, "Valor inválido", 0, MAX_INT, 3)){
			zona->resultadoCenso[tipoCenso] = cantidadPorTipo;
			retorno = 1;
			printf("Cantidad %s:%d\n", tipoCensados[tipoCenso],zona->resultadoCenso[tipoCenso]);

		}
	}
	return retorno;
}

//getters
void zona_getLocalidad(Zona zona){
	int localidad;
	localidad = zona.localidad;
	printf("%s", localidades[localidad]);
}

void zona_getEstado(Zona zona){
	int estado;
	estado = zona.estado;
	printf("%s", estados[estado]);
}

//Crear metodo get_Calles
void zona_getCalle(Zona zona,int calle){
	printf("%s", zona.calles[calle]);
}

void zona_printLocalidadesDisponibles(){
	printf("Las localidades disponibles son\n");
	for(int i = 0; i < 4; i++){
		printf("%d. %s\n", i+1,localidades[i]);
	}
}

void zona_listarZonasSinAsignar(Zona zonasArray[], int len){

	printf("LISTADO ZONAS PENDIENTES SIN ASIGNAR\n");
	for(int i = 0; i < len; i++){
		if(!(zonasArray[i].censistaId) && !(zonasArray[i].isEmpty) && !(zonasArray[i].estado)){
			printf("  ID|Localidad|Calles\n");
			printf("%4d|", zonasArray[i].id);
			zona_getLocalidad(zonasArray[i]);
			printf("|");
			for(int j = 0; j < 4; j++){
				zona_getCalle(zonasArray[i], j);
				if(j < 3){
					printf(", ");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}

//Array
int zona_inicializarArrayZonas(Zona zonasArray[], int len){
	int retorno = -1;
	if(zonasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			zonasArray[i].isEmpty = 1;
			zonasArray[i].id = 0;
			zonasArray[i].estado = 0;
			zonasArray[i].localidad = 0;
			zonasArray[i].resultadoCenso[0] = 0;
			zonasArray[i].resultadoCenso[1] = 0;
			zonasArray[i].resultadoCenso[2] = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int zona_findById(Zona zonasArray[], int len, int id){
	int index;
	index = -1;
	if(zonasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(zonasArray[i].id == id && !zonasArray[i].isEmpty){
				index = i;
				break;
			}
		}
	}
	return index;
}

int zona_findIndiceDisponibleZona(Zona zonasArray[], int len){
	int indice;
	indice = -1;

	if(zonasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(zonasArray[i].isEmpty){
				indice = i;
				break;
			}
		}
	}
	if(indice == -1){
		printf("No se encontraron espacios disponibles para agregar una nueva zona!\n");
	}
	return indice;
}

int zona_isZonaActiva(Zona zonasArray[],int len){
	int retorno;
	retorno = 0;

	if(zonasArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(!(zonasArray[i].isEmpty)){
				retorno = 1;
				break;
			}
		}
	}

	if(!retorno){
		printf("Aún no ha añadido ninguna zona.\n");
	}
	return retorno;
}

void zona_LocalidadMasAusentes(Zona zonasArray[], int len){

	int auxCantidadDeAusentes;
	auxCantidadDeAusentes = 0;
	int cantidadDeAusentes;
	cantidadDeAusentes = 0;
	int zonaConMasAusentes;
	zonaConMasAusentes = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < len; j++){
			if(zonasArray[j].estado == 1 && !(zonasArray[j].isEmpty)){
				cantidadDeAusentes += zonasArray[j].resultadoCenso[2];
			}
		}
		if(cantidadDeAusentes > auxCantidadDeAusentes){
			zonaConMasAusentes = i;
			auxCantidadDeAusentes = cantidadDeAusentes;
		}
		cantidadDeAusentes = 0;
	}
	printf("La localidad con mayor cantidad de ausentes fue: ");
	Zona zona;
	zona.localidad = zonaConMasAusentes;
	zona_getLocalidad(zona);
	printf("\n");

}
void zona_cargaForzada(Zona zonasArray[],int len){
	for(int i = 0; i < 16; i++){
		zonasArray[i].id = uuid(2);
	}
	for(int i = 0; i < 16; i++){
		zonasArray[i].isEmpty = 0;
	}
	for(int i = 0; i <4; i++){
		zonasArray[i].localidad = 0;
	}
	for(int i = 4; i <8; i++){
		zonasArray[i].localidad = 1;
	}
	for(int i = 8; i <12; i++){
		zonasArray[i].localidad = 2;
	}
	for(int i = 12; i <16; i++){
		zonasArray[i].localidad = 3;
	}



	char calles[100][51] = {"Vidal","Franklin D. Roosevelt","Av. Congreso","Conesa","Vidal","Mendoza","Echeverría","O'Higgins","Av. Cabildo",
		"Echeverria","Av. Olazabal","La Pampa","Ramsay","Artilleros","Av. Olazabal","Av. Cordoba","Av. Corrientes","Bulnes","Av. Medrano","Av. Medrano",
		"Av. Corrientes","Av. Díaz Velez","Yatay","Av. Medrano","Av. Corrientes","Av. Díaz Velez","Gallo","Av. Díaz Velez","Venezuela","Colombres",
		"Pringles","Av. Medrano","Av. Sta. Fe","Soler","R. Scalabrini Ortiz","Av. Cnel. Díaz","Av. Gral. Las Heras","Rep. Arabe Siria","Av. Sta. Fe","Av. Cnel. Díaz",
		"Av. Juan B. Justo","Av. Cordoba","Av. Dorrego","Costa Rica","Av. Juan B. Justo","Av. Cordoba","R. Scalabrini Ortiz","Soler","Av. Cordoba",
		"Junin","Av. Sta. Fe","Av. Pueyrredón","Av. Cordoba","Av. Pueyrredón","Av. Sta. Fe","Av. Pueyrredón","Juncal","French","Av. Sta. Fe",
		"Azcuenága","Av. Pueyrredón","Av. Libertador","Av. Sta. Fe","Av. Sarmiento",
	};

	int calle;
	calle = 0;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 4; j++){
			strncpy(zonasArray[i].calles[j],calles[calle],51);
			calle++;
		}
	}

}
//Dev
void zona_devPrintZona(Zona zonasArray[]){
	printf("Id: %d\n", zonasArray[0].id);
	printf("Código localidad: %d\n", zonasArray[0].localidad);
	zona_getLocalidad(zonasArray[0]);
	printf("Censista id: %d\n", zonasArray[0].censistaId);
	printf("Calle 1: %s\n", zonasArray[0].calles[0]);
	printf("Calle 2: %s\n", zonasArray[0].calles[1]);
	printf("Calle 3: %s\n", zonasArray[0].calles[2]);
	printf("Calle 4: %s\n", zonasArray[0].calles[3]);
	printf("Censados presencial: %d\n", zonasArray[0].resultadoCenso[0]);
	printf("Censados virtual: %d\n", zonasArray[0].resultadoCenso[1]);
	printf("Ausentes: %d\n", zonasArray[0].resultadoCenso[2]);

}
