#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pontos.h"

struct ponto{
    int x;
    int y;
};

struct cg{
    Ponto p;
    int np;
};

void inserePonto(ListaGen* l,int x, int y ){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    //Atualiza valor da lista retornando a lista com o novo ponto inserido
    l = insere_generica(l, p);
}

int imprime(void* ponto , void* nada){
    //cast para tipo ponto
    Ponto* p = (Ponto*)ponto;

    printf("%d %d\n", p->x, p->y);
    return 0;
}
int igualdade(void * p, void* q){
    Ponto* p1 = (Ponto*)p;
    Ponto* q1 = (Ponto*)q;

    if(p1->x == q1->x && p1->y == q1->y){
        return 1;
    }

    return 0;
}

// int CentroGeom(void* p, void* dado){
//     Ponto* p1 = (Ponto* )p;
//     Cg* cg = (Cg*)dado;
//
//     cg->p.x += p1->x;
//     cg->p.y += p1->y;
//
//     cg->np++;
//
//     return 0;
// }

int main () {
  ListaGen* lista = inicializa_ListaGen();

  inserePonto (lista,0,0);
  inserePonto (lista,1.5,3);
  inserePonto (lista,4,5);
  inserePonto (lista,2,6);

  percorre(lista,imprime,NULL);
  return 0;

  CG cg ;

    cg.p.x = 0;
    cg.p.y = 0;
    cg.np = 0;

  percorre(lista,CentroGeom,&cg);
    cg.p.x /= cg.np;
    cg.p.y /= cg.np;

    printf("CentroGeometrico: x: %d y: %d\n",cg.p.x,cg.p.y);

  return 0;
}
