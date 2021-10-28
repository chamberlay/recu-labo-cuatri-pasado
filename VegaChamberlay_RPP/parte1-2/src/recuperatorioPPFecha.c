#include "sPerro_Funciones.h"
#include "sDuenio_Funciones.h"
#include "recuperatorioPPFecha.h"
#include "recuperatorioPPInputs.h"
#include "sEstadiaDiaria_Funciones.h"
#include "recupetarioPPValidaciones.h"

void cargarFecha(sFecha fechas[], int i)
{
	pedirEntero(&fechas[i].dia, "Ingrese el dia (01/31): ", "Error, ingrese el dia (01/31): ", 01, 31);
	pedirEntero(&fechas[i].mes, "Ingrese el mes (01/12): ", "Error. ingrese el mes (01/12): ", 01, 12);
	pedirEntero(&fechas[i].anio, "Ingrese el año (2020/2021): ", "Error. Reingrese el año (2020/2021): ", 2020, 2021);
}
