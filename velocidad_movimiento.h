#ifndef _VELOCIDAD_MOVIMIENTO_H_
#define _VELOCIDAD_MOVIMIENTO_H_
#include <stdio.h>

double computar_velocidad (double vi, double a, double dt);
/* La funcion recibe una velocidad inicial, una aceleracion y un diferencial de tiempo
y devuelve la velocidad un instante despues de acuerdo al diferencial suministrado. */

double computar_posicion (double pi, double vi, double dt);
/* La funcion recibe una posicion inicial, una velocidad y un diferencial de tiempo
y devuelve la posicion un instante despues de acuerdo al diferencial suministrado. */


#endif // _VELOCIDAD_MOVIMIENTO_H_