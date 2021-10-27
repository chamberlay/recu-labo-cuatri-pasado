#ifndef RECUPERATORIOPPINPUTS_H_
#define RECUPERATORIOPPINPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void pedirString(char* cadena, char* mensaje, char* mensajeError, int max);


int verificarConfirmacion(char* mensaje);

int pedirCaracter(char* caracter, char* mensaje);

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

float pedirFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);

#endif /* RECUPERATORIOPPINPUTS_H_ */
