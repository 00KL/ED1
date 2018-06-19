#include "abb.h"

//arvore test <6 <2 <1 < > < > > <4 <3 < > < > > < > > <8 < > < > > >

int main(){
    arv* arvore = cria_vazia();

    arvore = insere(arvore, 6);
    arvore = insere(arvore, 2);
    arvore = insere(arvore, 1);
    arvore = insere(arvore, 4);
    arvore = insere(arvore, 3);
    arvore = insere(arvore, 8);

    imprime_crescente(arvore);
    printf("\n\n");

    if(busca(arvore, 6)){
        printf("6 esta na arvore.\n");
    }else{
        printf("6 nao esta na arvore.\n");
    }

    if(busca(arvore, 14)){
        printf("14 esta na arvore.\n");
    }else{
        printf("14 nao esta na arvore.\n");
    }

    arvore = retira(arvore, 6);

    arvore = retira(arvore, 3);

    arvore = retira(arvore, 8);

    arvore = retira(arvore, 2);

    libera(arvore);

    return 0;
}
