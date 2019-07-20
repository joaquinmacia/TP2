#ifndef _VECTORES_H_
#define _VECTORES_H_

#define CANT_COLUMNAS 2

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool vector_esta_arriba (float **v, size_t n, float x, float y);
/* La funcion recibe un arreglo de floats entendidos como un vector de coordenadas (matriz de n filas y 2 columnas) ordenado 
segun la coordenada X creciente, su tamano, una coordenada X, y una coordenada Y, y devuelve true en caso de que ese punto se
encuentre por arriba del vector de coordenadas, y false de lo contrario. */ 

void vector_trasladar (float **v, size_t n, float dx, float dy);
/* La funcion recibe un arreglo de floats entendidos como un vector de coordenadas (matriz de n filas y 2 columnas), su tamano
y desplaza todos los puntos en un dx y un dy. */

void vector_rotar (float **v, size_t n, double rad);
/* La funcion recibe un arreglo de floats entendidos como un vector de coordenadas (matriz de n filas y 2 columnas), su tamano 
y los rota una determinada cantidad de rad*/

void vector_destruir (float **v, size_t n, size_t m);
/* La funcion recibe la direccion de memoria del primer elemento de un vector dinamico, que en este caso representa una matriz 
de nxm, y libera la memoria asociada al mismo iterando sobre el. */

float** vector_desde_matriz (const float m[][CANT_COLUMNAS], size_t n);
/* La funcion recibe una matriz estatica que no debe ser modificada especificando su cantidad de columnas y su cantidad de 
filas (se suponen ambos enteros positivos), y crea un vector dinamico (llamando a una funcion auxiliar) de iguales dimensiones 
y tipo de datos al cual copia los datos de la matriz. Devolvera NULL en caso de fallar. */

float** vector_dinam_crear (size_t fil, size_t col);
/* La funcion recibe la cantidad de filas y columnas de una matriz (enteros positivos) y la crea dinamicamente utilizando malloc. 
Luego devuelve la direccion de memoria para acceder a la misma. Devolvera NULL en caso de fallar. */

void vector_imprimir(float **m, size_t fil, size_t col);
/* La funcion recibe la direccion de un vector dinamico, el numero de filas y columnas del mismo (enteros positivos) y la imprime 
por el flujo estandard de salida. */

float** vector_densificar (float **v, size_t nv, size_t nn, float margen);
/* La funcion recibe un vector 'v' de R2 ordenado segun valores de abscisas creciente, su cantidad de coordenadas 'nv', una 
cantidad nueva de coordenadas 'nn' y un margen, y devuelve un nuevo vector ordenado de acuerdo al mismo criterio, con la 
nueva cantidad de coordenadas cuyos puntos se encuentran dentro del margen especificado. Devolvera NULL en caso de fallar. */

float generar_elemento_aleatorio (float limite_inf, float limite_sup);
/* La funcion recibe un intervalo definido por un limite inferior y uno superior, y devuelve un numero aleatorio dentro de ese 
rango. */

size_t agregar_elemento_ordenado (float *v[CANT_COLUMNAS], size_t *n, float elemento);
/* La funcion recibe un arreglo de pares de float, la cantidad de elementos del mismo, y un valor a insertar correspondiente a 
una nueva coordenada x de un punto aleatorio. Compara de acuerdo a si el valor es menor o mayor dentro de un intervalo y lo 
inserta donde corresponde. Devuelve la posicion donde se inserto el elemento. La funcion es muy similar a la implementada en 
clase 'agregar_elemento' adaptada a vectores de dos coordenadas. */

float ajustar_al_segmento(float x0, float x1, float x, float y0, float y1);
/* La funcion recibe las coordenadas x e y de dos puntos, y la coordenada x de un punto entre medio de los anteriores, y devuelve 
el valor de coordenada y asociado. */

float aplicar_desplazamiento_vertical(float margen);
/* La funcion recibe un numero el cual es tomado como un intervalo y devuelve un valor aleatorio que se encuentra dentro del valor 
negativo y positivo del mismo. */

float ** vector_copiar (float ** viejo, float ** nuevo, size_t n, size_t m);
/* La funcion recibe punteros a arreglos dinamicos de floats, asi como sus dimensiones y copia uno en otro, elemento a elemento. 
Luego devuelve un puntero a la direccion donde se realizo la copia. */

#endif //_VECTORES_H_