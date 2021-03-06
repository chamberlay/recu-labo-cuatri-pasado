/*
 ============================================================================
 Name        : recupetarioPPParteUno.c
 Author      : Vega chamberlay (D)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int cantidadEstadias = 0;
	int opcion;

	sPerro perros[TAM_PERROS];
	sEstadiaDiaria estadias[TAM_ESTADIAS];
	sDuenio duenios[TAM_DUENIOS];

	sEstadiaDiaria_inicializar_Array(estadias, TAM_ESTADIAS);

	sPerro_inicializarArray(perros, TAM_PERROS);
	sPerro_hardCodear(perros, TAM_PERROS);
	sDuenio_hardCodear(duenios, TAM_DUENIOS);

	do
	{
		pedirEntero(&opcion, "-------------------------------------\n"
							"1. RESERVAR ESTADIA\n"
							"2. MODIFICAR ESTADIA\n"
							"3. CANCELAR ESTADIA\n"
							"4. LISTAR ESTADIAS\n"
							"5. LISTAR PERROS\n"
							"6. PROMEDIO DE EDAD DE LOS PERROS\n"
							"7. EL PERRO CON MAS ESTADIAS\n"
							"8. LISTADO DE PERROS POR ESTADIAS\n"
							"9. SALIR\n"
							"--------------------------------------\n"
							"Ingrese una opcion: \n",
							"-------------------------------------\n"
							"1. RESERVAR ESTADIA\n"
							"2. MODIFICAR ESTADIA\n"
							"3. CANCELAR ESTADIA\n"
							"4. LISTAR ESTADIAS\n"
							"5. LISTAR PERROS\n"
							"6. PROMEDIO DE EDAD DE LOS PERROS\n"
							"7. EL PERRO CON MAS ESTADIAS\n"
							"8. LISTADO DE PERROS POR ESTADIAS\n"
							"9. SALIR\n"
							"--------------------------------------\n"
							"Error, ingrese una opcion valida: \n", 1, 9);

		switch(opcion)
		{
			case 1:
				if(sEstadiaDiaria_cargarEstadias(estadias, perros, duenios, TAM_ESTADIAS) == 0)
				{
					cantidadEstadias ++;
				}
			break;

			case 2:
				if(cantidadEstadias > 0)
				{
					sEstadiaDiaria_mostrarEstadias(estadias, duenios, perros, TAM_ESTADIAS);
					sEstadiaDiaria_modificarEstadia(estadias, perros, duenios, TAM_ESTADIAS);
				}
				else
				{
					printf("No hay estadias cargadas.\n");
				}
			break;

			case 3:
				if(cantidadEstadias > 0)
				{
					sEstadiaDiaria_mostrarEstadias(estadias, duenios, perros, TAM_ESTADIAS);
					sEstadiaDiaria_cancelarEstadia(estadias, perros, duenios, TAM_ESTADIAS);
					cantidadEstadias --;
				}
				else
				{
					printf("No hay estadias cargadas.\n");
				}
			break;

			case 4:
				if(cantidadEstadias > 0)
				{
					sEstadiaDiaria_mostrarEstadias(estadias, duenios, perros, TAM_ESTADIAS);
				}
				else
				{
					printf("No hay estadias cargadas.\n");
				}
			break;

			case 5:
					sPerro_mostrarPerros(perros, TAM_PERROS);
			break;

			case 6:
				printf("El promedio de edad de los perros es de: %d\n", sPerro_calcularPromedioEdad(perros, TAM_PERROS));
			break;

			case 7:
				if(cantidadEstadias > 0)
				{
					printf("Perrito triste xq no pudo terminar el examen :(\n");
				}
				else
				{
					printf("No hay estadias cargadas.\n");
				}
			break;

			case 8:
				if(cantidadEstadias > 0)
				{
					printf("Perrito triste xq no pudo terminar el examen :(\n");
				}
				else
				{
					printf("No hay estadias cargadas.\n");
				}
			break;

			case 9:
				printf("Terminando...\nPrograma terminado.\n");
			break;
		}
	}while(opcion != 9);

	return EXIT_SUCCESS;
}
