#include "abb.h"

arv* cria_vazia(){

    return NULL;
}

int arvore_vazia(arv* arvore){
    if(arvore == NULL){
        return 1;
    }

    return 0;
}

arv* insere(arv* arvore, int x){
    //caso a arvore esteja vazia é importante
    //setar o valor do camo info da raiz
    if(arvore_vazia(arvore)){
        arvore = (arv*)malloc(sizeof(arv));

        arvore->esq = NULL;
        arvore->dir = NULL;
        arvore->info = x;
        printf("%d \n", arvore->info);

        return arvore;
    }

    else{
        //Caso o valor a ser inserido seja menor q a raiz
        //ele deve ser inserido a esquerda
        if(arvore->info > x){


            //caso n haja filhos a esquerda um novo deve ser
            //criado e o novo valor inserido
            if(arvore->esq == NULL){
                arv* novo = (arv*)malloc(sizeof(arv));

                novo->esq = NULL;
                novo->dir = NULL;
                novo->info = x;


                arvore->esq = novo;


                return arvore;
            }

            //caso haja um filho a esquerda o novo valor
            //funcao e executada considerando o no a esquerda da
            //raiz original como nova raiz numa recursão
            else{
                arvore->esq = insere(arvore->esq, x);

                return arvore;
            }
        }

        //Caso o valor a ser inserido seja maior q a raiz
        //ele deve ser inserido a direita
        if(arvore->info < x){

            if(arvore->dir == NULL){
                arv* novo = (arv*)malloc(sizeof(arv));

                novo->esq = NULL;
                novo->dir = NULL;
                novo->info = x;

                arvore->dir = novo;

                return arvore;
            }

            else{
                arvore->dir = insere(arvore->dir, x);

                return arvore;
            }
        }

    }

}

void imprime_crescente(arv* arvore){
    if(arvore_vazia(arvore)){
        printf("(VAZIO");
    }
    else{
        printf("(%d ", arvore->info);

        imprime_crescente(arvore->esq);
        printf(")   ");

        imprime_crescente(arvore->dir);
        printf(")%d", arvore->info);
    }
}

/*
arv* busca(arv* arvore, inr x){
    if(arvore_vazia(arvore)){
        if(arvore->info)
    }
}*/
