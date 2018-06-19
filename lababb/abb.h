#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
}arv;




void libera(arv*);

//pronta
arv* cria_vazia();
void imprime_crescente(arv*);
arv* insere(arv*, int );
int busca(arv*, int);
arv* retira(arv*, int);
arv* retira_aux(arv* , int );//auxliar
