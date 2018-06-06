#include "pontos.h"

struct ponto{
    int x;
    int y;
};

struct cg{
    Ponto p;
    int np;
};



int igualdade(void * p, void* q){
    Ponto* p1 = (Ponto*)p;
    Ponto* q1 = (Ponto*)q;

    if(p1->x == q1->x && p1->y == q1->y){
        return 1;
    }

    return 0;
}

int CentroGeom(void* p, void* dado){
    Ponto* p1 = (Ponto* )p;
    Cg* cg = (Cg*)dado;

    cg->p.x += p1->x;
    cg->p.y += p1->y;

    cg->np++;
    return 0;
}
