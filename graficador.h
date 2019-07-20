#ifndef _GRAFICADOR_H_
#define _GRAFICADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "lista.h"

#define CANT_COLS 2
#define MAX_NOMBRE 10

typedef struct sprite sprite_t;

lista_t* sprite_crear_lista(const char *archivo);
sprite_t* sprite_levantar(FILE *fp);
sprite_t * sprite_crear_estructura(char* nombre, uint16_t cantidad, float (*coords)[CANT_COLS], size_t col);
// bool graficador_inicializar(const char *fn, SDL_Renderer *r);
// void graficador_finalizar();
// bool graficador_dibujar(const char *nombre, float escala, float x, float y, float angulo);
// void graficador_ajustar_variables(float *x, float *y);

#endif //_GRAFICADOR_H_
