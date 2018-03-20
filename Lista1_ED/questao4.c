#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()

void main(){
    
    //Anunciacao do vetor dinamico e da variavel 'i'
    int i, j, troca, vetor[10], *vetorD = (int *)malloc(10 * sizeof(int));

    //inicializacao da semente aleatoria para gerar valores 
    //aleatorios na funcao rand
    srand(time(NULL));

    for(i = 0; i < 10; i++){
        *(vetor + i) = rand() % 10;
    }

    for(i = 0;  i < 10; i++){
        *(vetorD + i) = *(vetor + i);
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if( *(vetorD + i) < *(vetorD + j) ){
                troca = *(vetorD + j);
                *(vetorD + j) = *(vetorD + i);
                *(vetorD + i) = troca;
            } 
        }
    }

    printf("\n\n");

    for(i = 0; i < 10; i++){
        printf("%d ", *(vetorD + i) );
    }

    printf("\n\n");

}