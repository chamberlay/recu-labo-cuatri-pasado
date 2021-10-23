#ifndef SPERRO_FUNCIONES_H_
#define SPERRO_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PERROS 3

typedef struct{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estado;
}sPerro;

void sPerro_mostrarPerro(sPerro perros);
void sPerro_mostrarPerros(sPerro perros[], int tam);
void sPerro_inicializarArray(sPerro perros[], int tam);
void sPerro_hardCodear(sPerro perros[], int tam);


int sPerro_calcularTotalEdad(sPerro perros[], int tam);
int sPerro_calcularPromedioEdad(sPerro perros[], int tam);


#endif /* SPERRO_FUNCIONES_H_ */
