/*
 ============================================================================
 Name        : recupetarioPPParteUno.c
 Author      : Vega chamberlay (D)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "sPerro_Funciones.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int cantidadEstadias = 0;
	int opcion;

	sPerro perros[TAM_PERROS];
	sEstadiaDiaria estadias[TAM_ESTADIAS];

	sEstadiaDiaria_inicializar_Array(estadias, TAM_ESTADIAS);

	sPerro_inicializarArray(perros, TAM_PERROS);
	sPerro_hardCodear(perros, TAM_PERROS);

		do
		{
			pedirEntero(&opcion, "-------------------------------------\n"
								"1. RESERVAR ESTADIA\n"
								"2. MODIFICAR ESTADIA\n"
								"3. CANCELAR ESTADIA\n"
								"4. LISTAR ESTADIAS\n"
								"5. LISTAR PERROS\n"
								"6. PROMEDIO DE EDAD DE LOS PERROS\n"
								"7. SALIR\n"
								"--------------------------------------\n"
								"Ingrese una opcion: \n",
								"-------------------------------------\n"
								"1. RESERVAR ESTADIA\n"
								"2. MODIFICAR ESTADIA\n"
								"3. CANCELAR ESTADIA\n"
								"4. LISTAR ESTADIAS\n"
								"5. LISTAR PERROS\n"
								"6. PROMEDIO DE EDAD DE LOS PERROS\n"
								"7. SALIR\n"
								"--------------------------------------\n"
								"Error, ingrese una opcion valida: \n", 1, 7);

			switch(opcion)
			{
				case 1:
					if(sEstadiaDiaria_cargarEstadias(estadias, TAM_ESTADIAS) == 0)
					{
						cantidadEstadias ++;
					}
				break;

				case 2:
					if(cantidadEstadias > 0)
					{
						printf("En construcción");
					}
					else
					{
						printf("No hay estadias cargadas.\n");
					}
				break;

				case 3:
					if(cantidadEstadias > 0)
					{
						printf("En construcción");
					}
					else
					{
						printf("No hay estadias cargadas.\n");
					}
				break;

				case 4:
					if(cantidadEstadias > 0)
					{
						sEstadiaDiaria_mostrarEstadias(estadias, TAM_ESTADIAS);
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
					printf("Terminando...\nPrograma terminado.\n");
				break;
			}
		}while(opcion != 7);

	return EXIT_SUCCESS;
}
