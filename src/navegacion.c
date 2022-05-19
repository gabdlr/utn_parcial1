/*
 * navegacion.c
 *
 *  Created on: 18 may. 2022
 *      Author: gabde
 */
#include "navegacion.h"

void printMenuPrincipal(){
	//App init
	Censista censistasArray[LEN_CENSISTAS];
	censista_inicializarArrayCensista(censistasArray, LEN_CENSISTAS);
	Zona zonasArray[LEN_ZONAS];
	zona_inicializarArrayZonas(zonasArray, LEN_ZONAS);
	int opcion;
	do{
	printf("Estado Nacional *Censo 2022* \n"
			"******************************\n"
			"Seleccione entre las siguientes opciones\n"
			"1. Censistas\n"
			"2. Zonas\n"
			"3. Carga forzada\n"
			"4. Listados\n"
			"5. Salir\n");
	if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 5, 3)){
				fflush(stdin);
	switch(opcion){
		case 1:
			do{
				printf("Censistas *Censo 2022* \n"
						"******************************\n"
						"Seleccione entre las siguientes opciones\n"
						"1. Añadir nuevo censista\n"
						"2. Listar censistas\n"
						"3. Editar censista\n"
						"4. Eliminar censista\n"
						"5. Volver\n");
				if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 5, 3)){
					switch(opcion){
					case 1:
						censista_newCensista(censistasArray);
						break;
					case 2:
						censista_getListado(censistasArray);
						break;
					case 3:
						if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
							int censistaId;
							if(utn_getInt(&censistaId, "Ingrese el id del censista que desea modificar: ",
							"El valor ingresado es inválido", 1, LEN_CENSISTAS, 3)){
								int index;
								if((index = censista_findById(censistasArray, LEN_CENSISTAS, censistaId)) >= 0){
									Censista censistaAux = censistasArray[index];
									do{
										printf("Editar censistas *Censo 2022* \n"
												"******************************\n"
												"Seleccione entre las siguientes opciones\n"
												"1. Editar nombre del censista\n"
												"2. Editar apellido del censista\n"
												"3. Editar edad del censista\n"
												"4. Editar fecha de nacimiento del censista\n"
												"5. Editar dirección del censista\n"
												"6. Volver\n");
										if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 6, 3)){
										switch(opcion){
											case 1:
												if(censista_setNombre(&censistaAux)){
													censistasArray[index] = censistaAux;
												}
												break;
											case 2:
												if(censista_setApellido(&censistaAux)){
													censistasArray[index] = censistaAux;
												}
												break;
											case 3:
												if(censista_setEdad(&censistaAux)){
													censistasArray[index] = censistaAux;
												}
												break;
											case 4:
												do{
													printf("Editar censistas *Censo 2022* \n"
															"******************************\n"
															"Seleccione entre las siguientes opciones\n"
															"1. Editar dia\n"
															"2. Editar mes\n"
															"3. Editar año\n"
															"4. Volver\n");
													if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 6, 3)){
														switch(opcion){
														case 1:
															if(censista_setFnacimientoDia(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														case 2:
															if(censista_setFnacimientoMes(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														case 3:
															if(censista_setFnacimientoAnio(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														}
													}
												}while(opcion != 4);
												break;
											case 5:
												do{
													printf("Editar censistas *Censo 2022* \n"
															"******************************\n"
															"Seleccione entre las siguientes opciones\n"
															"1. Editar calle\n"
															"2. Editar altura\n"
															"3. Editar depto\n"
															"4. Editar código postal\n"
															"5. Volver\n");
													if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 5, 3)){
														switch(opcion){
														case 1:
															if(censista_setDireccionCalle(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														case 2:
															if(censista_setDireccionAltura(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														case 3:
															if(censista_setDireccionDepartamento(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														case 4:
															if(censista_setDireccionCodigoPostal(&censistaAux)){
																censistasArray[index] = censistaAux;
															}
															break;
														}
													}
												}while(opcion != 5);
												break;
											}
										}
									}while(opcion != 6);
								}
								else{
									printf("No se encontro ningún usuario con ese id %d", censistaId);
								}
							}
						}
						break;
					case 4:
						censista_eliminarCensista(censistasArray, LEN_CENSISTAS, zonasArray, LEN_ZONAS);
						break;
					}
				}
			}while(opcion != 5);
			opcion = 0;
			break;
		case 2:
			do{
				printf("Zonas *Censo 2022* \n"
						"******************************\n"
						"Seleccione entre las siguientes opciones\n"
						"1. Añadir zona\n"
						"2. Listar zonas\n"
						"3. Editar zona\n"
						"4. Asignar zona\n"
						"5. Completar zona\n"
						"6. Eliminar zona\n"
						"7. Volver\n");
				if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 7, 3)){
					switch(opcion){
					case 1:
						zona_newZona(zonasArray, LEN_ZONAS);
						break;
					case 2:
						if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
							printf("  ID|Censista responsable|Calles|Localidad|Estado|R. In Situ|R. Virtual|R. Virtual\n");
							for(int i = 0; i < LEN_ZONAS; i++){
								if(!zonasArray[i].isEmpty){
									char censistaResponsable[102];
									utn_purifyString(censistaResponsable, 102);
									if(zonasArray[i].censistaId){
										strncpy(censistaResponsable,censistasArray[i].nombre,51);
										censistaResponsable[strlen(censistaResponsable)] = ' ';
										censistaResponsable[strlen(censistaResponsable)+1] = '\0';
										strcat(censistaResponsable,censistasArray[i].apellido);
									}else{
										char noAsignada[14] = "NO ASIGNADA";
										strncpy(censistaResponsable,noAsignada,51);
									}
									printf("%4d|%s|",
											zonasArray[i].id,
											censistaResponsable
											);
									for(int j = 0; j < 4; j++){
										zona_getCalle(zonasArray[i], j);
										if(j < 3){
											printf(", ");
										}else{
											printf(" ");
										}

									}
									printf("|");
									zona_getLocalidad(zonasArray[i]);
									printf("|");
									zona_getEstado(zonasArray[i]);

									if(zonasArray[i].estado){
										printf("|");
										for(int k = 0; k < 3; k++){
											printf("%d", zonasArray[i].resultadoCenso[k]);
											if(k < 2){
												printf("|");
											}
										}
									}
									printf("\n");
								}
							}
						}
						break;
					case 3:
						if(zona_isZonaActiva(zonasArray, LEN_CENSISTAS)){
							int zonaId;
							if(utn_getInt(&zonaId, "Ingrese el id de la zona que desea modificar: ",
								"El valor ingresado es inválido", 1, LEN_ZONAS, 3)){
								int index;
								if((index = zona_findById(zonasArray, LEN_ZONAS, zonaId)) >= 0){
									Zona zona;
									zona = zonasArray[index];
									do{
									printf("Zonas *Censo 2022* \n"
											"******************************\n"
											"Seleccione entre las siguientes opciones\n"
											"1. Cambiar localidad\n"
											"2. Renombrar calles\n"
											"3. Volver\n");
									if(utn_getInt(&opcion, "Opción: ", "Opción inválida", 1, 3, 3)){
										switch(opcion){
										case 1:
											zona_printLocalidadesDisponibles();
											if(zona_setLocalidad(&zona)){
												zonasArray[index] = zona;
											}
											break;
										case 2:
											for(int i = 0; i < 4; i++){
												printf("%d. %s\n", i+1, zonasArray[index].calles[i]);
											}
											if(utn_getInt(&opcion, "Ingrese el digito correspondiente a la calle que desea renombrar: ",
													"Opción inválida", 1, 4, 3)){
												if(zona_setCalle(&zona, opcion-1)){
													zonasArray[index] = zona;
												}
											}
											break;
										}
									}
									}while(opcion != 3);
								}else{
									printf("No se encontro ninguna zona con ese id: %d\n", zonaId);
								}
							}
						}
						break;
					case 4:
						if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
							if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
								zona_listarZonasSinAsignar(zonasArray, LEN_ZONAS);
								censista_listarCensistasSinZonaAsignada(censistasArray, LEN_CENSISTAS);
								int idCensista;
								int idZona;
								if(utn_getInt(&idCensista, "Ingrese el ID del censista al que desea asignar una nueva zona: "
										, "El dato ingresado es inválido ", 0, LEN_CENSISTAS, 3)){
									int indexCensista;
									if((indexCensista = censista_findById(censistasArray, LEN_CENSISTAS, idCensista)) >= 0){
										if(!(censistasArray[indexCensista].zona)){
											if(utn_getInt(&idZona, "Ingrese el ID de la zona que desea asignar a este censista: ",
													"El dato ingresado es inválido ", 0, LEN_ZONAS, 3)){
												int indexZona;
												if((indexZona = zona_findById(zonasArray, LEN_ZONAS, idZona)) >= 0){
													if(!(zonasArray[indexCensista].censistaId)){
														if(censista_setZona(&censistasArray[indexCensista], &zonasArray[indexCensista])){
															printf("La zona con id: %d ha sido asignada correctamente al censista con id: %d\n", censistasArray[indexCensista].id, zonasArray[indexCensista].id);
														}
													}else{
														printf("Esta zona ya tiene un censista asignado!");
													}
												}
											}
										}else{
											printf("Este censista ya tiene una zona asignada!");
										}
									}
								}
							}
						}
						break;
					case 5:
						if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
							int idZona;
							if(utn_getInt(&idZona, "Ingrese el id de la zona que desea completar: ",
									"El valor ingresado es inválido", 1, LEN_ZONAS, 3)){
								int index;
								if((index = zona_findById(zonasArray, LEN_ZONAS, idZona)) >= 0){
									if(zonasArray[index].censistaId){
										Zona zona;
										zona = zonasArray[index];
										int asignacionesExitosas;
										asignacionesExitosas = 0;
										for(int i = 0; i < 3; i++){
											if(zona_setResultadoCenso(&zona, i)){
												asignacionesExitosas++;
											}
										}
										if(asignacionesExitosas == 3){
											int indexCensista;
											if((indexCensista = censista_findById(censistasArray, LEN_CENSISTAS, zona.censistaId)) >= 0){
												censistasArray[indexCensista].estado = 0;
												censistasArray[indexCensista].zona = 0;
												zona.estado = 1;
												zonasArray[index] = zona;
												printf("Datos guardados.\nLa zona con id: %d ha sido completada exitosamente.\n", idZona);
											}
										}
									}else{
										printf("La zona con id: %d aun no ha sido asignada a ningún censista\n", idZona);
									}
								}
							}
						}
						break;
					case 6:
						if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
							int idZona;
							if(utn_getInt(&idZona, "Ingrese el id de la zona que desea eliminar: ",
									"El valor ingresado es inválido", 1, LEN_ZONAS, 3)){
								int indexZona;
								if((indexZona = zona_findById(zonasArray, LEN_ZONAS, idZona)) >= 0){
									if(!(zonasArray[indexZona].censistaId) && !(zonasArray[indexZona].estado)){
										zonasArray[indexZona].isEmpty = 1;
										printf("La zona con id: %d ha sido eliminada\n", idZona);
									}else{
										printf("No es posible eliminar una zona asignada a un censista ni una zona finalizada\n");
									}
								}
							}
						}
						break;
					}


				}
			}while(opcion != 7);
			break;
		case 3:
			if(utn_getInt(&opcion, "Esto sobreescribira todos los registros actuales en la aplicación, ¿desea contontinuar?\n1. Si\n2. No\nOpcion: ",
					"Debe ingresar un valor válido", 1, 2, 3)){
				if(opcion == 1){
					zona_inicializarArrayZonas(zonasArray, LEN_ZONAS);
					censista_inicializarArrayCensista(censistasArray, LEN_CENSISTAS);
					zona_cargaForzada(zonasArray, LEN_ZONAS);
					censista_cargaForzada(censistasArray, LEN_CENSISTAS);
					printf("Carga exitosa.\n");
				}
			}
			break;
		case 4:
			do{
			printf("Informes *Censo 2022* \n"
					"******************************\n"
					"Seleccione entre las siguientes opciones\n"
					"1. Cantidad de censistas en estado activo con zona pendiente\n"
					"2. Listar censistas alfabeticamente segun localidad\n"
					"3. Localidad con mas casas ausentes\n"
					"4. Volver\n");
				if(utn_getInt(&opcion, "Opción: ", "Debe ingresar una opción válida", 1, 6, 3)){
					switch(opcion){
					case 1:
						if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
							if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
								printf("La cantidad de censistas activos con zona pendiente es de: %d\n",
								censista_cantidadCensistasActivosConZonaPendiente(censistasArray, LEN_CENSISTAS, zonasArray, LEN_ZONAS));
							}
						}
						break;
					case 2:
						if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
							if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
							printf("Ingrese el digito correspondiente a la localidad de su interés: \n");
							zona_printLocalidadesDisponibles();
							int localidad;
							if(utn_getInt(&localidad, "Opción: ", "Debe ingresar una localidad válida", 1, 4, 3)){
								censista_ListarCensistasAlfabeticamenteSegunLocalidad(censistasArray, LEN_CENSISTAS, localidad);
								}
							}
						}
						break;
					case 3:
						if(censista_isCensistaActivo(censistasArray, LEN_CENSISTAS)){
							if(zona_isZonaActiva(zonasArray, LEN_ZONAS)){
								zona_LocalidadMasAusentes(zonasArray, LEN_ZONAS);
							}
						}
						break;
					}
				}
			}while(opcion != 4);
			break;
	}
	}
	}while(opcion != 5);
}

