#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv{
    char info;
    Arv *esq;
    Arv *dir;
};

//Cria uma �rvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma �rvore com a informa��o do n� raiz c, e
//com sub�rvore esquerda e e sub�rvore direita d
Arv* arv_cria (char c, Arv* e, Arv* d){
    Arv *arvore = (Arv*)malloc(sizeof(Arv));

    arvore->info = c;
    arvore->esq = e;
    arvore->dir = d;

    return arvore;
}

//libera o espa�o de mem�ria ocupado pela �rvore a
Arv* arv_libera (Arv* a);

//retorna true se a �rvore estiver vazia e false
//caso contr�rio
int arv_vazia (Arv* a){
    if(a == NULL){
        return 1;
    }
    return 0;
}

//indica a ocorr�ncia (1) ou n�o (0) do caracter c
int arv_pertence (Arv* a, char c){
    if(!arv_vazia(a)){
        if(a->info == c){
            return 1;
        }

        if( arv_pertence(a->esq, c) || arv_pertence(a->dir, c) ){
            return 1;
        }
    }
    return 0;
}

//imprime as informa��es dos n�s da �rvore
void arv_imprime (Arv* a){
    if(!arv_vazia(a)){
        printf("%c ",a->info);

        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

//indica a ocorr�ncia (1) ou n�o (0) do caracter c
int arv_pertence_filho (Arv* a, char c){
    if(!arv_vazia(a)){
        if(a->info == c){
            return 1;
        }
    }
    return 0;
}

//retorna o pai de um dado no
Arv* arv_pai (Arv* a, char c){
    if(!arv_vazia(a)){

        if( arv_pertence_filho(a->esq, c) || arv_pertence_filho(a->dir, c) ){
            return a;
        }

        Arv* esquerda = arv_pai(a->esq, c);
        if(esquerda != NULL){
            return esquerda;
        }

        Arv* direita = arv_pai(a->dir, c);
        if(direita != NULL){
            return direita;
        }

    }

    return NULL;
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias (Arv* a, char c);

//retorna o campo informacao de um dado no
char info (Arv* a){
    return a->info;
}
