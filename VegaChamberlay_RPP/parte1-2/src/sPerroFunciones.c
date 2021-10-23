#include "sPerroFunciones.h"
#include "recuperatorioPPInputs.h"
#include "recuperatorioPPValidaciones.h"

/*validaciones: 1 si sale mal y 0 si sale bien
 accion: -1 si da error y 0 si esta bien
 */

void sPerro_inicializarArray(sPerro perritos[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		perritos[i].estado = VACIO;
	}
}

void sPerro_mostrarPerrito(sPerro perritos)
{
	printf("%-20d %-20s %-20s %-20d\n", perritos.id, perritos.nombre, perritos.raza, perritos.edad);
}

void sPerro_mostrarPerritos(sPerro perritos[], int tam)
{
	int i;

	printf("%-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0; i<tam; i++)
	{
		if(perritos[i].estado == OCUPADO)
		{
			sPerro_mostrarPerrito(perritos[i]);
		}

	}
}

void sPerro_hardCodear(sPerro perritos[], int tam)
{
	int i;
	int ids[] = {7000, 7001, 7002};
	char nombre[][51] = {"Lobo", "Sheila", "Reina"};
	char raza[][51] = {"Sharpei", "Golden", "Galgo"};
	int edad[] = {2, 12, 13};

	for(i=0; i<tam; i++)
	{
		perritos[i].id = ids[i];
		strcpy(perritos[i].nombre, nombre[i]);
		strcpy(perritos[i].raza, raza[i]);
		perritos[i].edad = edad[i];
		perritos[i].estado = OCUPADO;
	}
}


int sPerro_cargarPerrito(sPerro perritos[], int i)
{
	int resultado = 1;

	pedirString(perritos[i].nombre, "Ingrese el nombre del perrito. (Max 20 letras)", "Invalido. Reingrese el nombre del perrito. (Max 20 letras)", 20);
	pedirString(perritos[i].raza, "Ingrese la raza del perrito. (Max 20 letras)", "Invalido. Reingrese la raza del perrito. (Max 20 letras)", 20);
	pedirEntero(&perritos[i].edad, "Ingrese la edad del perrito (1/20)", "Error. edad no valida, reingrese la edad del perrito (1/20)", 1, 20);

	printf("\nPerrito a agregar:\n\n%-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");
	sPerro_mostrarPerrito(perritos[i]);

	if(verificarConfirmacion("\nIngrese 's' para confirmar el alta del empleado: ") == 0)
	{
		perritos[i].estado = OCUPADO;
		resultado = 0;
	}

	return resultado;
}

int sPerro_cargarPerritos(sPerro perritos[], int tam)
{
	int resultado = -1;
	int index = sPerro_iniciarPerritos(perritos, TAM_PERRITOS);

	if(index != -1)
	{
		printf("Agregando un perrito...\n\n");

		if(sPerro_cargarPerrito(perritos, index) == 0)
		{
			printf("\nSe agrego el perrito!!\n");
			printf("----------------------------------\n\n");
		}
		else
		{
			printf("\nSe cancelo el alta del perrito!!\n");
		}

		resultado = 0;
	}
	else
	{
		printf("Error, no hay espacio disponible.\n");
	}

	return resultado;
}

int sPerro_iniciarPerritos(sPerro perritos[], int tam)

{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(perritos[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int sPerro_calcularTotalEdad(sPerro perritos[], int tam)
{
	int totalEdad = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		totalEdad += perritos[i].edad;
	}

	return totalEdad;
}

int sPerro_calcularPromedioEdad(sPerro perritos[], int tam)
{
	int promedioEdad;

	promedioEdad = sPerro_calcularTotalEdad(perritos, tam) / TAM_PERRITOS;

	return promedioEdad;
}
