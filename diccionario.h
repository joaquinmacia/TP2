#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

#include <stdio.h>

typedef const int (*matriz_coordenadas_t)[2];

#define TIPOGRAFIA_MAX_ELEMENTOS 41

const char juego_tipografia_ascii[TIPOGRAFIA_MAX_ELEMENTOS];
const size_t juego_tipografia_longitud[TIPOGRAFIA_MAX_ELEMENTOS];
const matriz_coordenadas_t juego_tipografia_matriz[TIPOGRAFIA_MAX_ELEMENTOS];

matriz_coordenadas_t matriz_coordenadas_obtener(char ascii, size_t *matriz_tam);
/* La funcion recibe un caracter ascii y devuelve por interfaz un puntero al tamano de la matriz
que lo representa, y por nombre un nuevo tipo de datos: puntero a un arreglo de pares de ints */

#endif //_DICCIONARIO_H_
