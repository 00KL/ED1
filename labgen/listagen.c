
#include "listagen.h"

struct listagen{
    void* info;
    struct listagen* prox;
};

void* Percorre(ListaGen* l , void* (*callback)(void*, void*), void* dado){
    ListaGen* p;
    void* r = NULL;

    for(p=l; p!=NULL; p=p->prox){
        r = callback(p->info, dado);
        if(r){
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
