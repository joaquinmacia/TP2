#ifndef _CONFIG_H_
#define _CONFIG_H_

#define PI 3.14159265358979323846

#define VENTANA_ANCHO 1000
#define VENTANA_ALTO 800

#define JUEGO_FPS 100
#define JUEGO_DT (1.0/JUEGO_FPS) 		// Define un instante de tiempo de actualizacion para la posicion y velocidad
#define JUEGO_COMBUSTIBLE_INICIAL 9999
#define JUEGO_COMBUSTIBLE_RADIANES 1 	// Consumo de combustible por radian rotado
#define JUEGO_COMBUSTIBLE_POT_X_SEG 1	// Consumo de combustible por segundo a
										// a multiplicar por la potencia en ese instante

#define G 5

#define NAVE_ROTACION_PASO (PI/20)
#define NAVE_MAX_POTENCIA (3*G)

#define NAVE_X_INICIAL 100
#define NAVE_Y_INICIAL VENTANA_ALTO-100
#define NAVE_VX_INICIAL 100
#define NAVE_VY_INICIAL 0.0
#define NAVE_ANGULO_INICIAL (PI/2)
#define NAVE_POTENCIA_INICIAL 0

#define PUNTAJE_ATERRIZAJE_BUENO 50
#define PUNTAJE_ATERRIZAJE_VIOLENTO 15
#define PUNTAJE_DESTRUCCION 5
#define JUEGO_COMBUSTIBLE_DESCUENTO_DESTRUCION 250

#define PANTALLA_POS_REFERENCIA_X_IZQ 10
#define PANTALLA_POS_REFERENCIA_X_DER 700
#define PANTALLA_POS_REFERENCIA_Y 20

#define MAX_CAD 40

#endif // _CONFIG_H_
