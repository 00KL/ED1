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

int tamanho_hash(hash tab){
    int i, total = 0;
    palavra* p;

    for(i = 0; i < MAXTAB; i++){
        for(p = tab[i]; p != NULL; p = p->prox){
            total++;
        }
    }

    return total;
}

palavra** inicia_vet(hash tab, int TAM_HASH){
    palavra** vet = (palavra**)malloc(TAM_HASH*sizeof(palavra*));
    int i, aux = 0;
    palavra* p;
    for(i = 0; i < MAXTAB; i++){
        for(p = tab[i]; p != NULL; p = p->prox){
            vet[aux] = p;
            aux++;
        }
    }

    return vet;
}

int compara_palavras(const void* p1, const void* p2){
    palavra** x = (palavra **)p1;
    palavra** y = (palavra **)p2;

    if( (*x)->cont > (*y)->cont) return 1;
    else if( (*x)->cont < (*y)->cont) return 0;
    else return strcmp( (*x)->conteudo, (*y)->conteudo);
}

void imprime_crescente(palavra** tab){
    palavra **vet;
    int TAM_HASH, i;

    TAM_HASH = tamanho_hash(tab);
    printf("%d\n\n", TAM_HASH);

    vet = inicia_vet(tab, TAM_HASH);
    qsort(vet, TAM_HASH, sizeof(palavra*), compara_palavras);

    for(i = 0; i <= TAM_HASH; i++){
        printf("%s -> %d \n", vet[i]->conteudo, vet[i]->cont );
    }

    free(vet);
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
