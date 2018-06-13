#include "abb.h"

//arvore test <6 <2 <1 < > < > > <4 <3 < > < > > < > > <8 < > < > > >

int main(){
    arv* arvore = cria_vazia();

    insere(arvore, 6);
    insere(arvore, 2);
    insere(arvore, 1);
    insere(arvore, 4);
    insere(arvore, 3);
    insere(arvore, 8);

    imprime_crescente(arvore);
    printf("\n\n");
    return 0;
}
