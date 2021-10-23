#ifndef SPERROFUNCIONES_H_
#define SPERROFUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PERRITOS 3

//isEmpty
#define VACIO 0
#define OCUPADO 1

typedef struct{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estado;
}sPerro;

void sPerro_mostrarPerrito(sPerro perritos);
void sPerro_mostrarPerritos(sPerro perritos[], int tam);
void sPerro_inicializarArray(sPerro perritos[], int tam);
void sPerro_hardCodear(sPerro perritos[], int tam);


int sPerro_cargarPerrito(sPerro perritos[], int i);
int sPerro_cargarPerritos(sPerro perritos[], int tam);
int sPerro_iniciarPerritos(sPerro perritos[], int tam);
int sPerro_calcularTotalEdad(sPerro perritos[], int tam);
int sPerro_calcularPromedioEdad(sPerro perritos[], int tam);


#endif /* SPERROFUNCIONES_H_ */
