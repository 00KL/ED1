#include "hash.h"

//Tipo q representa cada palavra
typedef struct palavra{
    char conteudo[MAXPAL];
    int cont;
    palavra* prox; //tratamento de colisao
} palavra;



int gera_indice(char* c){
    int indice = 0, i;

    for(i = 0; c[i] != '\0'; i++ ){
        indice += c[i];
    }

    return indice%MAXTAB;
}

int le_palavra(FILE* entrada, char* c){
    int caracter = 0;
    while(!feof(entrada) ){
        c[caracter] = fgetc(entrada);

        if(c[caracter] == ' '){
            c[caracter] = '\0';
            return 1;

        }else if(feof(entrada)){
            //Ultima palavra do texto estava apresentando
            // '\n' lixo
            c[caracter-1] = '\0';
            return 1;
        }

        caracter++;
    }

    return 0;
}

void inicializa_hash(hash tab){
    int i;
    for(i=0; i<MAXTAB; i++)
        tab[i] = NULL;
}

void print_pessoa(palavra* p){
    printf("conteudo: %s ", p->conteudo);
    printf("Contador: %d\n", p->cont);
}

palavra *acessa(hash tab, char* c){
    palavra* p;
    int indice = gera_indice(c);

    //caso a posicao que possuia a chave gerada ja esteja preenchida
    //e preciso checar se a palavra nela contida equivale a palavra
    //q quer ser adicionada. Caso a palavra q quer ser acrescentada
    //ja esteja na tabela tal posição e retornada. Caso a posicao que
    //esteja preenchida por tal chave contenha outra palavra é preciso
    //checar a palavra que é apontada.
    for(p=tab[indice]; p!=NULL; p=p->prox){
        if(strcmp(p->conteudo,c) == 0){
            p->cont++;
            print_pessoa(p);
            return p;
        }
    }

    //Se a posição na tabela cuja chave foi checada não contem nenhuma
    //palavra ou as palavras apontadas por tal posição tampoco apresentam
    //a palavra buscada é preciso criar uma nova palavra
    p = (palavra*)malloc(sizeof(palavra));
    strcpy(p->conteudo, c);
    p->cont = 1;
    //ao acrescentar uma nova palavra é preciso que ela aponte para
    //tad[indice].No caso de ela ser um tratamento de conflito
    //ela deve ser a nova palavra no indice[indice], por isso a palavra
    //que ocupava essa posição anteriormente deve ser apontada pela nova
    //palavra para q n se perca a referencia
    p->prox = tab[indice];
    tab[indice] = p;
    //print_pessoa(p);
    return p;

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
