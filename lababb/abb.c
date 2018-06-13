#include "abb.h"

arv* cria_vazia(){

    return NULL;
}

int arvore_vazia(arv* arvore){
    if(arvore == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insere(arv* arvore, int x){
    //caso a arvore esteja vazia é importante
    //setar o valor do camo info da raiz
    if(arvore_vazia(arvore)){
        arvore = (arv*)malloc(sizeof(arv));

        arvore->esq = NULL;
        arvore->dir = NULL;
        arvore->info = x;
        printf("%d \n", x);
    }

    else{
        //Caso o valor a ser inserido seja menor q a raiz
        //ele deve ser inserido a esquerda
        if(arvore->info > x){

            //caso n haja a filhos a esquerda um novo deve ser
            //criado e o novo valor inserido
            if(arvore->esq == NULL){
                arv* novo = cria_vazia();
                novo->info = x;

                arvore->esq = novo;
            }

            //caso haja um filho a esquerda deve um recursão da
            //funcao e executada considerando o no a esquerda da
            //raiz original como nova raiz
            else{
                insere(arvore->esq, x);
            }
        }

        //Caso o valor a ser inserido seja menor q a raiz
        //ele deve ser inserido a direita
        if(arvore->info < x){

            if(arvore->dir == NULL){
                arv* novo = cria_vazia();
                novo->info = x;

                arvore->dir = novo;
            }

            else{
                insere(arvore->dir, x);
            }
        }

    }

}

void imprime_crescente(arv* arvore){
    if(arvore_vazia(arvore)){
        printf("< >");
    }
    else{
        printf("<%d ", arvore->info);

        imprime_crescente(arvore->esq);
        printf(">");

        imprime_crescente(arvore->dir);
        printf("> >");
    }
}

/*
arv* busca(arv* arvore, inr x){
    if(arvore_vazia(arvore)){
        if(arvore->info)
    }
}*/
