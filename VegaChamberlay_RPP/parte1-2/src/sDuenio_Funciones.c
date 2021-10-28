#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

void sDuenio_hardCodear(sDuenio duenios[], int tam)
{
	int i;
	int ids[] = {30000, 30001, 30002, 30003, 30004,};
	char nombre[][51] = {"carlos", "juan", "silvia", "isabel", "lupita"};
	int telefono[] = {1121910810, 1121910811, 1121910812, 1121910813, 1121910814};

	for(i=0; i<tam; i++)
	{
		duenios[i].id = ids[i];
		strcpy(duenios[i].nombre, nombre[i]);
		duenios[i].telefono = telefono[i];
	}
}
