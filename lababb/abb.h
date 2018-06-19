#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
}arv;


arv* busca(arv*, int);
void retira(arv*, int);
void libera(arv*);

//pronta
arv* cria_vazia();
void imprime_crescente(arv*);
arv* insere(arv*, int );
