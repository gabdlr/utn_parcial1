/*
 * util.c
 *
 *  Created on: 16 may. 2022
 *      Author: gabde
 */

#include "util.h"

int uuid(int entity){
	int id;
	static int censistaId = 0;
	static int zonaId = 0;

	switch(entity){
		case 1:
			censistaId++;
			id = censistaId;
			break;
		case 2:
			zonaId++;
			id = zonaId;
			break;
		default:
			printf("Unhandled Exception");
			break;
	}
	return id;
}
