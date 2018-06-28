#include "hash.h"

typedef char* palavra;

typedef struct texto{
    palavra conteudo;
}texto;


int gera_indice(palavra c){
    int indice = 0, i;

    for(i = 0; c[i] != '\0'; i++ ){
        indice += c[i]/33;
        indice += c[i]%33;
    }

    if(indice < 0) indice *= -1;

    if(indice > 101) indice /= 10;

    return indice;
}

// texto insere_palavra(texto hash, palavra c){
//     hash[gera_indice(c)].conteudo = c;
//
//     return hash;
// }

// palavra* insere_palavra(palavra c, texto* hash, int *aux){
//     c[&aux] = '\0';
//
//
//
//     free(c);
//     c = (char*)malloc(sizeof(char)*50);
//     aux = -1;
// }

// texto* inicializa_hash(texto* hash){
//     hash = (texto*)malloc(sizeof(texto)*101);
//     return hash;
// }
