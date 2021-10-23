#ifndef RECUPERATORIOPPINPUTS_H_
#define RECUPERATORIOPPINPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @fn void pedirString(char*, char*, char*, int)
 * @brief request a string
 *
 * @param cadena It is the place where the information entered will be saved
 * @param mensaje is the message that is displayed
 * @param mensajeError is the error message displayed
 * @param max is the maximum number of characters allowed
 */
void pedirString(char* cadena, char* mensaje, char* mensajeError, int max);

/**
 * @fn int pedirCaracter(char*, char*)
 * @brief ask for a character
 *
 * @param caracter It is the place where the information entered will be saved
 * @param mensaje is the message that is displayed
 * @return returns 0 if the message could be loaded or -1 otherwise
 */
int pedirCaracter(char* caracter, char* mensaje);

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief ask for a whole number
 *
 * @param entero It is the place where the information entered will be saved
 * @param mensaje is the message that is displayed
 * @param mensajeError is the error message displayed
 * @param min is the minimum number of characters allowed
 * @param max is the maximum number of characters allowed
 * @return returns the whole number
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn float pedirFloat(float*, char*, char*, float, float)
 * @brief ask for a floating number
 *
 * @param flotante It is the place where the information entered will be saved
 * @param mensaje is the message that is displayed
 * @param mensajeError is the error message displayed
 * @param min is the minimum number of characters allowed
 * @param max is the maximum number of characters allowed
 * @return returns the floating number
 */
float pedirFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);

#endif /* RECUPERATORIOPPINPUTS_H_ */
