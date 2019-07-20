#include "graficador.h"

struct sprite
{
	char nombre[MAX_NOMBRE];
	uint16_t n;
	float **coords;
};

lista_t* sprite_crear_lista(const char *archivo)
{
	FILE* pfread;
	pfread = fopen(archivo, "rb");
	if(pfread == NULL)
		return NULL;

	sprite_t* sprite_nuevo;
	lista_t* sprite_lista = lista_crear();

	while(sprite_nuevo = sprite_levantar(pfread) != NULL)
	{
			lista_insertar_final(sprite_lista, sprite_nuevo);
	}
}

sprite_t* sprite_levantar(FILE *fp)
{
	char nombre[MAX_NOMBRE];
	if(!fread(nombre, sizeof(char), MAX_NOMBRE, fp))
		return NULL;

	uint16_t cant_coord;
	if(!fread(&cant_coord, sizeof(uint16_t), 1, fp))
		return NULL;

	float coords[cant_coord][CANT_COLS];
	if(fread(coords, sizeof(float), cant_coord * CANT_COLS, fp)  != (cant_coord * CANT_COLS))
		return NULL;

	sprite_t * psprite = sprite_crear_estructura(nombre, cant_coord, coords, CANT_COLS);
	if (psprite == NULL)
		return NULL;

	return psprite;
}

sprite_t * sprite_crear_estructura(char* nombre, uint16_t cantidad, float (*coords)[CANT_COLS], size_t col)
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



bool graficador_inicializar(const char *fn, SDL_Renderer *r)
{
	sprite_crear_lista(fn);
}
//
//
// void graficador_finalizar()
// {
//
//
// }
//
//
// bool graficador_dibujar(const char *nombre, float escala, float x, float y, float angulo)
// {
//
//
//
// }
//
//
// void graficador_ajustar_variables(float *x, float *y)
// {
// 	float ventana_ancho;
// 	float ventana_alto;
//
// 	SDL_GetRendererOutputSize(renderer, &ventana_ancho, &ventana_alto);
//
// 	if(*x > ventana_ancho)
// 		*x = 0.0;
//
// 	if(*x < 0.0)
// 		*x = ventana_ancho;
//
// 	if(*y > ventana_alto)
// 		*y = 0.0;
//
// 	if(*y < 0.0)
// 		*y = ventana_alto;
//
// }
