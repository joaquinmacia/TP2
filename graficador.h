#ifndef _GRAFICADOR_H_
#define _GRAFICADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define CANT_SPRITES_ARCHIVO 6
#define CANT_COLS 2
#define MAX_NOMBRE 10

typedef struct sprite sprite_t;

sprite_t * sprite_crear(char* nombre, uint16_t cantidad, float (*coords)[CANT_COLS], size_t col);
sprite_t* sprite_levantar(FILE *fp);
sprite_t** sprites_desde_archivo(int* sprites_cant);
bool graficador_inicializar(const char *fn, SDL_Renderer *r);
void graficador_finalizar();
bool graficador_dibujar(const char *nombre, float escala, float x, float y, float angulo);
void graficador_ajustar_variables(float *x, float *y);

#endif //_GRAFICADOR_H_
