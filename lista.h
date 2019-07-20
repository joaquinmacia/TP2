#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo nodo_t;
typedef struct lista lista_t;

nodo_t* crear_nodo(void* d);
lista_t* lista_crear();
void lista_destruir(lista_t* l, void(*destruir_dato)(void* d));
bool lista_es_vacia(const lista_t* l);
bool lista_insertar_comienzo(lista_t* l, void *dato);
bool lista_insertar_final(lista_t* l, void* dato);
void* lista_extraer_primero(lista_t* l);
void* lista_extraer_ultimo(lista_t* l);
void* lista_buscar(const lista_t* l, const void* dato, int (*cmp)(const void* a, const void* b));
void lista_mapear(lista_t* l, void* (*f)(void* dato));
lista_t* lista_filtrar(lista_t* l, bool (*f)(void* dato, void* extra), void* extra);



#endif //_LISTA_H_
