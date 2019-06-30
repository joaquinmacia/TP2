#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define CANT_SPRITES_ARCHIVO 6
#define CANT_COLS 2
#define MAX_NOMBRE 10


typedef struct sprite
{
	char nombre[10];
	uint16_t n;
	float **coords;
}sprite_t;

sprite_t * sprite_crear(char* nombre, uint16_t cantidad, float (*coords)[CANT_COLS], size_t col)
{
	sprite_t * p;
	p = malloc(sizeof(sprite_t));

	strcpy(p->nombre, nombre);
	p->n = cantidad;
	p->coords = malloc(sizeof(float *) * (p->n));

	size_t i, j;

	for(i = 0; i < cantidad; i++)
		for(j = 0; j < col; j++)
				p->coords[i][j] = coords[i][j];

	return p;
}


sprite_t* sprite_levantar(FILE *fp)
{
	char nombre[MAX_NOMBRE];

	if(fread(nombre, sizeof(char), MAX_NOMBRE, fp) != MAX_NOMBRE)
				return NULL;

	uint16_t cant_coord;
	if(!fread(&cant_coord, sizeof(uint16_t), 1, fp))
				return NULL;

	float coords[cant_coord][CANT_COLS];
	if(fread(coords, sizeof(float), cant_coord * CANT_COLS, fp)  != (cant_coord * CANT_COLS))
				return NULL;

	sprite_t * psprite = sprite_crear(nombre, cant_coord, coords, CANT_COLS);
	if (psprite == NULL)
		return NULL;


	return psprite;
}


sprite_t** sprites_desde_archivo(int* sprites_cant)
{
	sprite_t** v_sprite = malloc(sizeof(sprite_t*) * CANT_SPRITES_ARCHIVO);
	if(v_sprite == NULL)
		return NULL;

	FILE* pfread;
	pfread = fopen("sprites.bin", "r");
	if(pfread == NULL)
		return NULL;

	size_t i;
	for(i = 0; i < CANT_SPRITES_ARCHIVO; i++)
	{
		v_sprite[i] = sprite_levantar(pfread);
	}


	*sprites_cant = i;

	return v_sprite;
}
