#include "pilha.h"
#include "fila.h"
/*gcc pilha.o fila.o progfila.o -o lab4.o
    antes é necessario compilar tudo separadamente com gcc -c*/

fila *cria_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->p1 = cria_pilha();
    f->p2 = cria_pilha();

    return f;
}

void insere(pessoa* p, Fila *f){
    push(p, f->p1);
}

Pessoa retira(Fila *f){
    Pessoa* ṕ;

    copia_pilha(f->p1, f->p2);

    p = pop(f->p2);

    copia_pilha(f->p2, f->p1);

    return p;
}

void copia_pilha(Pilha *p1, Pilha *p2){
    while(!vazia_pilha(p1)){
        push(pop(p1), p2);
    }
}

imprime_fila(Fila *f){
    
    copia_pilha(f->p1, f->p2);

    while(!vazia_pilha(f->p2)){
        printf("%s \n", f->p2->pessoa[f->p2->topo]->nome);
        printf("%d \n", f->p2->pessoa[f->p2->topo]->idade);
        printf("%s \n\n", f->p2->pessoa[f->p2->topo]->endereco);

        push(pop(f->p2), f->p1);
    }

}

int Vazia_fila(Fila *f){
    return vazia_pilha(f->p1);
}

