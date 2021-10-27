#include "sPerro_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

/*validaciones: 1 si sale mal y 0 si sale bien
 accion: -1 si da error y 0 si esta bien
 */

void sPerro_inicializarArray(sPerro perros[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		perros[i].estado = VACIO;
	}
}

void sPerro_mostrarPerro(sPerro perros)
{
	printf("%-20d %-20s %-20s %-20d\n", perros.id, perros.nombre, perros.raza, perros.edad);
}

void sPerro_mostrarPerros(sPerro perros[], int tam)
{
	int i;

	printf("%-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0; i<tam; i++)
	{
		if(perros[i].estado == OCUPADO)
		{
			sPerro_mostrarPerro(perros[i]);
		}

	}
}

void sPerro_hardCodear(sPerro perros[], int tam)
{
	int i;
	int ids[] = {7000, 7001, 7002};
	char nombre[][51] = {"Lobo", "Sheila", "Reina"};
	char raza[][51] = {"Sharpei", "Golden", "Galgo"};
	int edad[] = {2, 12, 13};

	for(i=0; i<tam; i++)
	{
		perros[i].id = ids[i];
		strcpy(perros[i].nombre, nombre[i]);
		strcpy(perros[i].raza, raza[i]);
		perros[i].edad = edad[i];
		perros[i].estado = OCUPADO;
	}
}





int sPerro_calcularTotalEdad(sPerro perros[], int tam)
{
	int totalEdad = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		totalEdad += perros[i].edad;
	}

	return totalEdad;
}

int sPerro_calcularPromedioEdad(sPerro perros[], int tam)
{
	int promedioEdad;

	promedioEdad = sPerro_calcularTotalEdad(perros, tam) / TAM_PERROS;

	return promedioEdad;
}
