#ifndef SDUENIO_FUNCIONES_H_
#define SDUENIO_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_DUENIOS 5

typedef struct{
	int id;
	char nombre[41];
	int telefono;
}sDuenio;

void sDuenio_hardCodear(sDuenio duenios[], int tam);

#endif /* SDUENIO_FUNCIONES_H_ */
