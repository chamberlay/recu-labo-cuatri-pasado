#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

int validarNombreDuenio(sDuenio duenios[], char* aux, int tam, int max)
{
	int respuesta = 1;
	int i;

	for(i=0; i<tam; i++)
	{
		if(isalpha(*aux) && strcmp(aux, duenios[i].nombre) == 0 && tam < max)
		{
			respuesta = 0;
			break;
		}
	}

	return respuesta;
}

int validarIdPerro(sPerro perros[], int aux, int tam, int min, int max)
{
	int respuesta = 1;
	int i;

	for(i=0; i<tam; i++)
	{
		if(isalpha(aux) == 0 && aux == perros[i].id && aux > min && aux < max)
		{
			respuesta= 0;
			break;
		}
	}


	return respuesta;
}
