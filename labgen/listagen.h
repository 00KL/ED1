#include <stdio.h>
#include <stdlib.h>

typedef struct listagen ListaGen;

ListaGen* insere_generica(ListaGen* , void*);

int percorre(ListaGen* , int (*callback)(void*, void*), void*);

ListaGen* inicializa_ListaGen();

void* listavazia(ListaGen* );

void libera_lista(ListaGen*);
