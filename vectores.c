#include "vectores.h"
#include "terreno.h"
#include <math.h>


bool vector_esta_arriba (float **v, size_t n, float x, float y){
	
	float aux;
	aux = terreno_distancia (v, n, x, y);
	return aux > 0 ? true : false;
}


void vector_trasladar (float **v, size_t n, float dx, float dy) {
	
	size_t i = 0;
	for (i = 0; i < n; i++){
		v[i][0] += dx;
		v[i][1] += dy;
	}	
}


void vector_rotar (float **v, size_t n, double rad){
	
	size_t i; 
	float coord_x, coord_y;
	float coseno = cos(rad);
	float seno = sin(rad);
	for (i = 0; i < n; i++){
		coord_x = v[i][0];
		coord_y = v[i][1];
		v[i][0] = coord_x * coseno - coord_y * seno;
		v[i][1] = coord_x * seno + coord_y * coseno;
	}
}


void vector_destruir (float **v, size_t n, size_t m){

	size_t i;

	for (i = 0; i < n; i ++)
		free (v[i]);
	free(v);
}


float** vector_desde_matriz (const float m[][CANT_COLUMNAS], size_t n){

	float ** matriz_dinam;
	size_t i;
	size_t j;

	//Creacion de la matriz dinamica.
	matriz_dinam = vector_dinam_crear(n, CANT_COLUMNAS);
		
	if(matriz_dinam == NULL)
		return NULL;
	
	//Copiado de la matriz estatica recibida al vector dinamico creado.
	for(i = 0; i < n; i++)
		for(j = 0; j < CANT_COLUMNAS; j++)
			matriz_dinam[i][j] = m[i][j];

	return matriz_dinam;
}


float** vector_dinam_crear (size_t fil, size_t col){

	float ** d_matriz;
	size_t i;

	d_matriz = (float **) malloc (sizeof(float *) * fil);

	if(d_matriz == NULL)
		return NULL;

	for(i = 0; i < fil; i++){
		d_matriz[i] = (float *) malloc (sizeof(float) * col);
		
		if(d_matriz[i] == NULL){
			vector_destruir(d_matriz, i, CANT_COLUMNAS);
			return NULL;
		}
	}
	return d_matriz;
}


void vector_imprimir (float **m, size_t fil, size_t col){
	
	for(size_t i = 0; i < fil; i++){
		for(size_t j = 0; j < col; j++)
			printf("[%f] \t", m[i][j]);
		printf("\n");
	}
}


float** vector_densificar (float **v, size_t nv, size_t nn, float margen){

	float ** aux;
	size_t i, posicion_nuevo_elemento;
	size_t coord_iniciales;
	float numero_aleatorio;
	float x0, x1, x, y0, y1;

	if(nn < nv)
		return NULL;

	aux = vector_dinam_crear (nn, CANT_COLUMNAS);
	
	if (aux == NULL)
		return NULL;

	aux = vector_copiar(v, aux, nv, CANT_COLUMNAS);

	coord_iniciales = nv;

	for (i = nv; i < nn; i++){
		numero_aleatorio = generar_elemento_aleatorio(aux[0][0], aux[coord_iniciales - 1][0]);
		posicion_nuevo_elemento = agregar_elemento_ordenado(aux, &coord_iniciales, numero_aleatorio);
		x0 = aux[posicion_nuevo_elemento - 1][0];
		x1 = aux[posicion_nuevo_elemento + 1][0];
		x = aux[posicion_nuevo_elemento][0];
		y0 = aux[posicion_nuevo_elemento - 1][1];
		y1 = aux[posicion_nuevo_elemento + 1][1];
		aux[posicion_nuevo_elemento][1] = ajustar_al_segmento(x0, x1, x, y0, y1);
		aux[posicion_nuevo_elemento][1] += aplicar_desplazamiento_vertical(margen);
	}

	return aux;
}


float generar_elemento_aleatorio (float limite_inf, float limite_sup){

	float aleatorio = ((float) rand()) / (float) RAND_MAX;
	float diferencia = limite_sup - limite_inf;
	float r = aleatorio * diferencia;

	return limite_inf + r;
	
}


size_t agregar_elemento_ordenado (float **v, size_t *n, float elemento){

	size_t i, j;

	for(i = 0; i < *n; i++){
		if(elemento < v[i][0])
			break;
	}

	for(j = *n; j > i; j--){
		v[j][0] = v[j-1][0];
		v[j][1] = v[j-1][1];
	}

	v[i][0] = elemento;

	(*n)++;

	return i;
}


float ajustar_al_segmento(float x0, float x1, float x, float y0, float y1){

	return (float) y0 + (x - x0) / (x1 - x0) * (y1 - y0);
}


float aplicar_desplazamiento_vertical(float margen){

	float limite_inf = - margen;
	float limite_sup = margen;

	return generar_elemento_aleatorio(limite_inf, limite_sup);

}


float ** vector_copiar (float ** viejo, float ** nuevo, size_t n, size_t m){

	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < m; j++){
			nuevo[i][j] = viejo[i][j];
		}
	}
	
	return nuevo;
}

