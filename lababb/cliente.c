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

    
    return 0;
}
