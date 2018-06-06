#include <stdio.h>
#include <stdlib.h>

typedef struct listagen ListaGen;

ListaGen* insere_generica(ListaGen* , void*);

void* percorre(ListaGen*, void* (*)(void*, void*), void*);

ListaGen* inicializa_ListaGen();
