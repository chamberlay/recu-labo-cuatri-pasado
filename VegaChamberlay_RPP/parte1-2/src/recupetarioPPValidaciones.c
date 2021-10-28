#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

int validarArrayLetras(char* aux, int max)
{
	int respuesta = 1;
	int tam;

	tam = strlen(aux);

	if(isalpha(*aux) != 0 && tam < max)
	{
		respuesta = 0;
	}

	return respuesta;
}

int validarArrayNumeros(sPerro perros[], int auxIdPerro, int tam, int min, int max)
{
	int respuesta = 1;
	int i;

	for(i=0; i<tam; i++)
	{
		if(isalpha(auxIdPerro) == 0 && perros[i].id == auxIdPerro && auxIdPerro > min && auxIdPerro < max)
		{
			respuesta= 0;
			break;
		}
	}


	return respuesta;
}
