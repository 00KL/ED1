
#include "listagen.h"

struct listagen{
    void* info;
    struct listagen* prox;
};

void* listavazia(ListaGen* l){
    if(!l->info){
        return NULL;
    }

    return l;
}

ListaGen* inicializa_ListaGen(){
    ListaGen* l = (ListaGen*)malloc( sizeof(ListaGen) );
    l->info = NULL;
    l->prox = NULL;

    return l;
}

ListaGen* insere_generica(ListaGen* l,  void* p){
    if(l->info == NULL){
        l->info = p;

        return l;
    }
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->info = p;
    novo->prox = l;

    return novo;
}

int percorre(ListaGen* l , int (*callback)(void*, void*), void* dado){
    ListaGen* p;
    int r = 0;

    for(p=l; p!=NULL; p=p->prox){

        r = callback(p->info, dado);
        if(r != 0){
            return r;
        }
    }

    return r;
}
