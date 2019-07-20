#include "lista.h"
#include <stdlib.h>


struct nodo{
	struct nodo* sig;
	void* dato;
};

struct lista{
	struct nodo* prim;
};

//Funciones:

nodo_t* crear_nodo(void* d){

	nodo_t* nodo = malloc(sizeof(nodo_t));
	if(nodo == NULL)
		return NULL;

	nodo->sig = NULL;
	nodo->dato = d;

	return nodo;

}

lista_t* lista_crear(){

	lista_t* l = malloc(sizeof(lista_t));
	if (l == NULL)
		return NULL;

	l->prim = NULL;
	return l;

}

void lista_destruir(lista_t* l, void(*destruir_dato)(void* d)){

	nodo_t* aux = l->prim;

	while(aux != NULL){
		nodo_t* sig = aux->sig;
		destruir_dato(aux->dato);

		free(aux);

		aux = sig;
	}

	free(l);
}

bool lista_es_vacia(const lista_t* l){

	if(l->prim == NULL)
		return true;

	return false;

}

bool lista_insertar_comienzo(lista_t* l, void *dato){

	nodo_t* nodo_nuevo = crear_nodo(dato);
	if(nodo_nuevo == NULL)
		return false;

	nodo_t* aux = l->prim;

	l->prim = nodo_nuevo;

	nodo_nuevo->sig = aux;

	// Otra alternativa:
	// nodo_nuevo->sig = l->prim;
	// l->prim = nodo_nuevo;

	return true;

}

bool lista_insertar_final(lista_t* l, void* dato){

	nodo_t* nodo_nuevo = crear_nodo(dato);
	if(nodo_nuevo == NULL)
		return false;

	//Si la lista esta vacia inserto al principio
	if(l->prim == NULL){
		l->prim = nodo_nuevo;
		return true;
	}

	//Si la lista no esta vacia recorro on un aux hasta llegar al final
	//y lo inserto ahi.
	nodo_t* aux;
	aux = l->prim;

	while(aux->sig != NULL)
		aux = aux->sig;

	aux->sig = nodo_nuevo;

}

void* lista_extraer_primero(lista_t* l){

	if(lista_es_vacia(l))
		return NULL;

	nodo_t* aux;

	aux = l->prim;
	l->prim = l->prim->sig;
	//Otra forma : l->prim = aux->sig;

	void* aux_dato = aux->dato;
	free(aux);

	return aux_dato;

}

void* lista_extraer_ultimo(lista_t* l){

	//Si la lista esta vacia no hago nada.
	if(lista_es_vacia(l))
		return NULL;

	nodo_t* aux;
	aux = l->prim;

	void* aux_dato;

	while(aux->sig != NULL)
		aux = aux->sig;

	aux_dato = aux->dato;

	free(aux);

	return aux_dato;

}

void* lista_buscar(const lista_t* l, const void* dato, int (*cmp)(const void* a, const void* b)){

	if(lista_es_vacia(l))
		return NULL;

	nodo_t* aux;
	aux = l->prim;

	while(aux->sig != NULL){
		if(cmp(dato, aux->dato) == 0)
			return aux->dato;

		aux = aux->sig;
	}

	return NULL;
}


// Aplica la funcion f() a cada uno de los elementos de la lista.
// Asumimos lista no nula/vacia?.
void lista_mapear(lista_t* l, void* (*f)(void* dato)){

	if(lista_es_vacia(l))
		return;

	nodo_t* aux;
	aux = l->prim;

	while(aux != NULL){
		f(aux->dato);
			//que hago?
		aux = aux->sig;
	}


}

// Devolver nueva lista con todos los elementos de l donde f devuelva true
// Extrayendo los elementos de l.
lista_t* lista_filtrar(lista_t* l, bool (*f)(void* dato, void* extra), void* extra){

	if(lista_es_vacia(l))
		return NULL;

	lista_t* d = lista_crear();

	nodo_t* act_l = l->prim;

	while(d->prim == NULL)
		if(f(l->prim->dato, extra)){
			//insertar y mover lprim.
			//OJO que insertar en el primero da la nueva lista es un caso de borde.

		}

}
