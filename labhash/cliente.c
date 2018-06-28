#include "hash.h"

int main(int argc, char **argv){
    FILE *entrada = fopen(argv[1], "r");
    char c[MAXPAL];
    hash tab;
    palavra *p;

    inicializa_hash(tab);
    //int caracter = 0, indice;

    //char* hash[101] = {'\0'};
    //hash = inicializa_hash(hash);

    while(le_palavra(entrada, c)){
        //print para test
        p = acessa(tab, c);
    
    }

    fclose(entrada);
    return 0;
}

/*    while(!feof(entrada) ){
        c[caracter] = fgetc(entrada);



        if(c[caracter] == ' '){
            c[caracter] = '\0';
            indice = gera_indice(c);

            //print para test
            if(hash[indice] == '\0'){
                //coloca na hash
                hash[gera_indice(c)] = c;
                printf("%s||%d\n", c, indice);
            }else{
                printf("%s||%d REPETIDO\n", c, indice);
            }




            //faz c apontar para outro expaço de
            //memoria para receber nova palavra
            c = (char*)malloc(sizeof(char)*50);
            caracter = -1;

        }else if(feof(entrada)){
            //Ultima palavra do texto estava apresentando
            // '\n' lixo
            c[caracter-1] = '\0';

            //print para test
            printf("%s||%d\n", c, gera_indice(c));

            //coloca na hash
            hash[gera_indice(c)] = c;

        }
        caracter++;

    }

    //Caso a posição da lista n esteja preenchida da segmetation foult
    if(hash[2] == '\0'){
        printf("test\n\n");
    }

    */
