#include "sPerro_Funciones.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"

/*validaciones: 1 si sale mal y 0 si sale bien
 accion: -1 si da error y 0 si esta bien
 */

void sEstadiaDiaria_mostrarEstadia(sEstadiaDiaria estadias)
{
	printf("%-20s %-20s %-20s\n", estadias.nombreDuenio, estadias.telefonoContacto, estadias.fecha);
}

void sEstadiaDiaria_mostrarEstadias(sEstadiaDiaria estadias[], int tam)
{
	int i;

	printf("%-20s %-20s %-20s\n", "Nombre dueño", "Telefono", "Fecha");

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			sEstadiaDiaria_mostrarEstadia(estadias[i]);
		}
	}
}

void sEstadiaDiaria_inicializar_Array(sEstadiaDiaria estadias[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		estadias[i].estado = VACIO;
	}
}




int sEstadiaDiaria_cargarEstadia(sEstadiaDiaria estadias[], int i)
{
	int retorno = -1;

	pedirString(estadias[i].nombreDuenio, "Ingrese el nombre del dueño del perro: ", "Nombre invalido, hasta 21 caracteres, reingrese: ", 21);
	pedirString(estadias[i].telefonoContacto, "Ingrese el telefono de contacto (hasta 11 digitos): ", "Error, ingrese un telefono de contacto valido (hasta 11 digitos): ", 11);
	pedirString(estadias[i].fecha, "Ingrese la fecha de la estadia (DD/MM/AAAA): ", "Error, reingrese una fecha valida (DD/MM/AAAA): ", 21);

	printf("\nEstadia a agregar:\n\n%-20s %-20s %-20s\n", "Nombre Dueño", "Telefono", "Fecha");
	sEstadiaDiaria_mostrarEstadia(estadias[i]);

	if(verificarConfirmacion("\nIngrese 's' para confirmar el alta de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

int sEstadiaDiaria_cargarEstadias(sEstadiaDiaria estadias[], int tam)
{
	int retorno = -1;
	int index = sEstadiaDiaria_iniciarEstadias(estadias, tam);

	if(index != -1)
	{
		printf("Agregando una estadia...\n\n");

		if(sEstadiaDiaria_cargarEstadia(estadias, index) == 0)
		{
			printf("\nSe agrego la estadia!!\n");
			printf("----------------------------------\n\n");
		}
		else
		{
			printf("\nSe cancelo el alta de la estadia!!\n");
		}
		retorno = 0;
	}
	else
	{
		printf("Error, no hay espacio disponible.\n");
	}

	return retorno;
}

int sEstadiaDiaria_iniciarEstadias(sEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estado == VACIO)
		{
			//estadias[i].id = i+1;
			index = i;
			break;
		}
	}

	return index;
}
