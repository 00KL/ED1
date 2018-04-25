#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    int i,  *vetor = (int *)malloc(10 * sizeof(int));

    for(i = 0; i<10; i++){
        scanf("%d", vetor + i );
    } 

    printf("\n\n");

    for(i = 0; i < 10; i++){
        printf("%d ", *(vetor + i));
    }

    printf("\n\n");

    free(vetor);
}