#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pontos.h"

struct ponto{
    float x;
    float y;
};

struct cg{
    Ponto p;
    int np;
};

Ponto* cria_Ponto(int x, int y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    return p;
}

ListaGen* inserePonto(ListaGen* l,int x, int y ){

    //Atualiza valor da lista retornando a lista com o novo ponto inserido
    return insere_generica(l, cria_Ponto(x, y));
}

void imprime_lista(ListaGen* lista){
    printf("Lista de pontos na lista:\n");
    percorre(lista,imprime,NULL);
}

int imprime(void* ponto , void* nada){
    //cast para tipo ponto
    Ponto* p = (Ponto*)ponto;

    printf("%.1f %.1f\n", p->x, p->y);
    return 0;
}

int igualdade(void* p, void* q){
    Ponto* p1 = (Ponto*)p;
    Ponto* q1 = (Ponto*)q;

    if(p1->x == q1->x && p1->y == q1->y){
        printf("O %.2f %.2f pertence a lista.\n", q1->x, q1->y);
        return 1;
    }

    return 0;
}

Cg calcCentroGeom(ListaGen* lista){
    Cg cg ;

      cg.p.x = 0;
      cg.p.y = 0;
      cg.np = 0;

    percorre(lista,CentroGeom,&cg);
      cg.p.x /= cg.np;
      cg.p.y /= cg.np;

      return cg;
}

int CentroGeom(void* p, void* dado){
    Ponto* p1 = (Ponto* )p;
    Cg* cg = (Cg*)dado;

    cg->p.x += p1->x;
    cg->p.y += p1->y;

    cg->np++;

    return 0;
}

int main () {
  ListaGen* lista = inicializa_ListaGen();

  //Insere pontos na lista
  lista = inserePonto (lista,0,0);
  lista = inserePonto (lista,1.5,3);
  lista = inserePonto (lista,4,5);
  lista = inserePonto (lista,2,6);

  //Imprime a lista
  imprime_lista(lista);

  //Testa se o ponto esta na lista
  Ponto* ponto1 = cria_Ponto(0, 0);
  Ponto* ponto2 = cria_Ponto(8, 12);
  Ponto* ponto3 = cria_Ponto(3, 0);

  if(percorre(lista, igualdade, ponto1) == 0){
      printf("O %.1f %.1f não pertence a lista.\n", ponto1->x, ponto1->y);
  }
  if(percorre(lista, igualdade, ponto2) == 0){
      printf("O %.1f %.1f não pertence a lista.\n", ponto2->x, ponto2->y);
  }
  if(percorre(lista, igualdade, ponto3) == 0){
      printf("O %.1f %.1f não pertence a lista.\n", ponto3->x, ponto3->y);
  }

  //Calcular Centro Geometrico
  Cg cg = calcCentroGeom(lista);
  printf("CentroGeometrico: x: %.1f y: %.1f\n",cg.p.x,cg.p.y);

  return 0;
}
