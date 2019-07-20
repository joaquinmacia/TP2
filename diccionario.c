#include "diccionario.h"
#include "caracteres.h"
#include <stdio.h>

const char juego_tipografia_ascii[TIPOGRAFIA_MAX_ELEMENTOS] = {

	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z',
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'>',
	'<',
	'^',
	'v',
	' ',

};

const size_t juego_tipografia_longitud[TIPOGRAFIA_MAX_ELEMENTOS] = {

	7,
	12,
	4,
	7,
	7,
	6,
	7,
	6,
	6,
	4,
	6,
	3,
	5,
	4,
	5,
	5,
	9,
	7,
	6,
	4,
	4,
	3,
	5,
	5,
	5,
	4,
	5,
	2,
	6,
	7,
	5,
	6,
	5,
	3,
	7,
	5,
	5,
	5,
	5,
	5,
	1,

};

const matriz_coordenadas_t juego_tipografia_matriz[TIPOGRAFIA_MAX_ELEMENTOS] = {

	caracter_a,
	caracter_b,
	caracter_c,
	caracter_d,
	caracter_e,
	caracter_f,
	caracter_g,
	caracter_h,
	caracter_i,
	caracter_j,
	caracter_k,
	caracter_l,
	caracter_m,
	caracter_n,
	caracter_o,
	caracter_p,
	caracter_q,
	caracter_r,
	caracter_s,
	caracter_t,
	caracter_u,
	caracter_v,
	caracter_w,
	caracter_x,
	caracter_y,
	caracter_z,
	caracter_0,
	caracter_1,
	caracter_2,
	caracter_3,
	caracter_4,
	caracter_5,
	caracter_6,
	caracter_7,
	caracter_8,
	caracter_9,
	caracter_derecha,
	caracter_izquierda,
	caracter_arriba,
	caracter_abajo,
	caracter_espacio,

};

matriz_coordenadas_t matriz_coordenadas_obtener(char ascii, size_t *matriz_tam){

	size_t i;

	for(i = 0; i < TIPOGRAFIA_MAX_ELEMENTOS; i++){
		if(juego_tipografia_ascii[i] == ascii){
			*matriz_tam = juego_tipografia_longitud[i];
			return juego_tipografia_matriz[i];
		}
	}

	return NULL;
}
