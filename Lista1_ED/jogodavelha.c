#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    
    char **jogo = (char **)malloc(3  * sizeof(char *));

    int i, j, x, y, k;

    for(i = 0; i < 3; i++){
        jogo[i] = (char *)malloc(3 * sizeof(char));
        for(j = 0; j < 3; j++){
            jogo[i][j] = '*';
        }
    }

    for(k = 0; k < 9; k++){

        if(k%2 == 0){
            printf("Jogador 1:");
            scanf("%d %d", &x, &y);
            jogo[x - 1][y - 1] = 'X';
            if()
        }
        else{
            printf("Jogador 2:");
            scanf("%d %d", &x, &y);
            jogo[x - 1][y - 1] = '0';
        }

        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                printf("%c ", jogo[i][j]);
            }
            printf("\n");
        }
        


    }

    
}