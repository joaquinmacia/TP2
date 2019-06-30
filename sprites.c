#include <stdio.h>

typedef struct sprite
{
	char nombre[10];
	uint16_t n;
	float (*coords)[2];
}sprite_t;

sprite_t * sprite_crear(uint16_t cantidad)
{
	sprite_t * p;
	p = malloc(sizeof(punto_t));

	p -> n = cantidad;
	p -> coords = malloc(sizeof(float *) * (p->n));

	return p;
}


bool levantar_un_sprite(sprite_t *p)
{
	FILE * fp;
	fp = fopen (sprites.bin, "r");
	if(fp == NULL)
		return false;

	if(fread(p -> nombre, sizeof(char), MAX, f) != MAX)
				return false;

	if(!fread(&(p -> n), sizeof(uint16_t), 1, f))
				retrun false;

	if(!fread(p -> coords, sizeof(float *), (p -> n), f))
				return false;

	return true;
}
