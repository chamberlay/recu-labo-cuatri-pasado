#ifndef RECUPERATORIOPPFECHA_H_
#define RECUPERATORIOPPFECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int dia;
	int mes;
	int anio;
}sFecha;

void cargarFecha(sFecha fechas[], int i);

#endif /* RECUPERATORIOPPFECHA_H_ */
