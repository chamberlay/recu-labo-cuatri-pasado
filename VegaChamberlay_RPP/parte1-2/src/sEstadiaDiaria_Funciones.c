#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"


void sEstadiaDiaria_mostrarEstadia(sEstadiaDiaria estadias, sPerro perros, sDuenio duenios)
{
	printf("%-20d %-20s %-20s %-20d %-20d %-20d %-20d\n", estadias.id, duenios.nombre, perros.nombre, duenios.telefono, estadias.fecha.dia, estadias.fecha.mes, estadias.fecha.anio);
}

void sEstadiaDiaria_mostrarEstadias(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tam)
{
	int i;

	printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Id estadia", "Nombre del dueño", "Nombre de mascota", "Telefono", "Dia", "Mes", "Año");

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			sEstadiaDiaria_mostrarEstadia(estadias[i], perros[i], duenios[i]);
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




int sEstadiaDiaria_cargarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int i)
{
	int retorno = -1;
	int auxIdPerro;
	char auxNombreDuenio[41];

	pedirEntero(&auxIdPerro, "Ingrese el id de su mascota (hasta 4 digitos): ", "Error, ingrese el id de su mascota (hasta 4 digitos): ", 7000, 7002);
	while(validarIdPerro(perros, auxIdPerro, TAM_PERROS, 6999, 7003) != 0)
	{
		printf("Id no encontrado, reingrese el id de su mascota: ");
		fflush(stdin);
		scanf("%d", &auxIdPerro);
	}
	auxIdPerro = estadias[i].idPerro;

	pedirString(auxNombreDuenio, "Ingrese el nombre del dueño del perro: ", "Nombre invalido, reingrese hasta 40 letras: ", 41);
	while(validarNombreDuenio(duenios, auxNombreDuenio, TAM_DUENIOS,  41) != 0)
	{
		printf("Nombre invalido, reingrese hasta 40 letras: ");
		fflush(stdin);
		scanf("%s", auxNombreDuenio);
	}
	strcpy(duenios[i].nombre, auxNombreDuenio);

	pedirEntero(&duenios[i].telefono, "Ingrese el telefono de contacto (hasta 11 digitos): ", "Error, ingrese un telefono de contacto valido (hasta 11 digitos): ", 1100000000, 1199999999);
	cargarFecha(&estadias[i].fecha, i);

	printf("\nEstadia a agregar:\n\n%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Id estadia", "Nombre del dueño", "Nombre de mascota", "Telefono", "Dia", "Mes", "Año");
	sEstadiaDiaria_mostrarEstadia(estadias[i], perros[i], duenios[i]);

	if(verificarConfirmacion("\nIngrese 's' para confirmar el alta de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

int sEstadiaDiaria_cargarEstadias(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam)
{
	int retorno = -1;
	int index = sEstadiaDiaria_iniciarEstadias(estadias, tam);

	if(index != -1)
	{
		printf("Agregando una estadia...\n\n");

		if(sEstadiaDiaria_cargarEstadia(estadias, perros, duenios, index) == 0)
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
	int j = 99999;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estado == VACIO)
		{
			estadias[i].id = j+1;
			index = i;
			break;
		}

		j ++;
	}

	return index;
}

int sEstadiaDiaria_cancelarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el id de la estadia a borrar (100000-200000)", "Error. Reingrese el id de la estadia a borrar (100000-200000)", 100000, 200000);

	index = sEstadiaDiaria_buscarEstadiaPorId(estadias, TAM_ESTADIAS, idIngresado);

	if(index != -1)
	{
		printf("\nEstadia a eliminar:\n\n%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre del dueño", "Nombre de mascota", "Telefono", "Dia", "Mes", "Año");
		sEstadiaDiaria_mostrarEstadia(estadias[index], perros[index], duenios[index]);

		if(!verificarConfirmacion("\nIngrese 's' para confirmar la baja de la estadia: "))
		{
			estadias[index].estado = VACIO;
			printf("\nEstadia dada de baja correctamente.\n");
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja de la estadia.\n\n");
		}
	}
	else
	{
		printf("\nNo se encontro la estadia!!");
	}

	return retorno;
}

int sEstadiaDiaria_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estado == OCUPADO && estadias[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int sEstadiaDiaria_modificarEstadia(sEstadiaDiaria estadias[], sPerro perros[], sDuenio duenios[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	sDuenio auxDuenio;
	sPerro auxPerro;

	pedirEntero(&idIngresado, "Ingrese el id de la estadia a modificar (100000-200000)", "Error. Reingrese el id de la estadia a modificar (100000-200000)", 100000, 200000);
	index = sEstadiaDiaria_buscarEstadiaPorId(estadias, TAM_ESTADIAS, idIngresado);

	if(index != -1)
	{
		auxDuenio = duenios[index];
		do{
			pedirEntero(&opcion, "-------------------------------------\n"
										"1. Modificar telefono de contacto\n"
										"2. Modificar perro\n"
										"3. Atras\n"
										"--------------------------------------\n"
										"Ingrese una opcion: \n",
										"-------------------------------------\n"
										"1. Modificar telefono de contacto\n"
										"2. Modificar perro\n"
										"3. Atras\n"
										"--------------------------------------\n"
										"Error, ingrese una opcion valida: \n", 1, 3);

			switch(opcion)
			{
				case 1:
					printf("\nEstadia a modificar:\n\n%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Id", "Nombre del dueño", "Nombre de mascota", "Telefono", "Dia", "mes", "Año");
					sEstadiaDiaria_mostrarEstadia(estadias[index], perros[index], duenios[index]);

					pedirEntero(&auxDuenio.telefono, "Ingrese el nuevo telefono de contacto (hasta 11 digitos): ", "Error. Reingrese el nuevo telefono de contacto (hasta 11 digitos): ", 1100000000, 1199999999);
					printf("\nEstadia luego de la modificacion:\n\n%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Id", "Nombre del dueño", "Nombre de mascota", "Telefono", "Dia", "mes", "Año");
					sEstadiaDiaria_mostrarEstadia(estadias[index], perros[index], auxDuenio);

					if(verificarConfirmacion("\nIngrese 's' para confirmar el cambio: ") == 0)
					{
						duenios[index].telefono = auxDuenio.telefono;
						printf("\nTelefono modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del telefono.\n\n");
					}
				break;

				case 2:
					printf("\nPerro a modificar:\n\n%-20s %-20s %-20s %-20s\n", "Id", "Nombre", "Raza", "Edad");
					sPerro_mostrarPerro(perros[index]);

					pedirEntero(&auxPerro.id, "Ingrese el id de su mascota (hasta 4 digitos): ", "Error, ingrese el id de su mascota (hasta 4 digitos): ", 7000, 7002);

					printf("\nPerro luego de la modificacion:\n\n%-20s %-20s %-20s %-20s\n", "Id", "Nombre", "Raza", "Edad");
					sPerro_mostrarPerro(auxPerro);

					if(verificarConfirmacion("\nIngrese 's' para confirmar el cambio: ") == 0)
					{
						perros[index]= auxPerro;
						printf("\nPerro modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del perro.\n\n");
					}
				break;

				case 3:
				break;
			}

		}while(opcion != 3);
	}
	else
	{
		printf("\nNo se encontro la estadia!!");
	}

	return retorno;
}
