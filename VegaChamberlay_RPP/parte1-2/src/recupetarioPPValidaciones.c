#include "sPerro_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

int validarIdPerro(sEstadiaDiaria estadias[], int tam, int i)
{
	int respuesta = 1;
	int j;

	for(j=0; j<tam; j++)
	{
		if(i == estadias[j].id)
		{
			printf("entro\n");
			printf("id ingresado: %d\n", i);
			printf("id encontrado: %d\n", j);
			respuesta = 0;
			break;
		}
	}

	return respuesta;
}
