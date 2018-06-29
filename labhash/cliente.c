#include "hash.h"

int main(int argc, char **argv){
    FILE *entrada = fopen(argv[1], "r");
    char c[MAXPAL];
    hash tab;

    inicializa_hash(tab);

    while(le_palavra(entrada, c)){
        //Coloca palavra na tabela caso ela n esteja
        //Soma 1 a ocorrencia da palavra se ela ja existir
        //Coloca numa lista encadeada as palavras de mesma
        //chave de acesso
        acessa(tab, c);
    }

    imprime_crescente(tab);


    free_palavras(tab);
    fclose(entrada);
    return 0;
}
