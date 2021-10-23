/*
 ============================================================================
 Name        : recupetarioPPParteUno.c
 Author      : Vega chamberlay (D)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "sPerroFunciones.h"
#include "recuperatorioPPInputs.h"
#include "recuperatorioPPValidaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int cantidadDePerritos = 3;

	sPerro perritos[TAM_PERRITOS];

	sPerro_inicializarArray(perritos, TAM_PERRITOS);
	sPerro_hardCodear(perritos, TAM_PERRITOS);

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
					if(sPerro_cargarPerritos(perritos, TAM_PERRITOS) == 0)
					{
						cantidadDePerritos ++;
					}
				break;

				case 2:
						printf("hago algo");
				break;

				case 3:
						printf("hago algo");
				break;

				case 4:
						printf("hago algo");
				break;

				case 5:
					if(cantidadDePerritos > 0)
					{
						sPerro_mostrarPerritos(perritos, TAM_PERRITOS);
					}
				break;

				case 6:
					printf("El promedio de edad de los perros es de: %d\n", sPerro_calcularPromedioEdad(perritos, TAM_PERRITOS));
				break;

				case 7:
					printf("Terminando...\nPrograma terminado.\n");
				break;
			}
		}while(opcion != 7);

	return EXIT_SUCCESS;
}
