
#include "listagen.h"

struct listagen{
    void* info;
    struct listagen* prox;
};

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

ListaGen* inicializa_ListaGen(){
    ListaGen* l = (ListaGen*)malloc( sizeof(ListaGen) );
    l->info = NULL;
    l->prox = NULL;

    return l;
}

ListaGen* insere_generica(ListaGen* l,  void* p){
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->info = p;
    novo->prox = l;

    return l;
}
