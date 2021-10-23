#include "sPerroFunciones.h"
#include "recuperatorioPPInputs.h"
#include "recuperatorioPPValidaciones.h"

int verificarConfirmacion(char* mensaje)
{
	int retorno = 1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}
	return retorno;
}
