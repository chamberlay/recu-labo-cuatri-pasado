#ifndef SESTADIADIARIA_FUNCIONES_H_
#define SESTADIADIARIA_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_ESTADIAS 1000

#define VACIO 0
#define OCUPADO 1

typedef struct{
	int id;
	int idPerro;
	sFecha fecha;
	int estado;
}sEstadiaDiaria;

void sEstadiaDiaria_mostrarEstadia(sEstadiaDiaria estadias, sPerro perros, sDuenio duenios);
void sEstadiaDiaria_mostrarEstadias(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tam);
void sEstadiaDiaria_inicializar_Array(sEstadiaDiaria estadias[], int tam);


int sEstadiaDiaria_cargarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int i);
int sEstadiaDiaria_cargarEstadias(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam);
int sEstadiaDiaria_iniciarEstadias(sEstadiaDiaria estadias[], int tam);
int sEstadiaDiaria_cancelarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam);
int sEstadiaDiaria_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tam, int id);
int sEstadiaDiaria_modificarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam);

#endif /* SESTADIADIARIA_FUNCIONES_H_ */
