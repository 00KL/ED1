#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char **jogo = (char **)malloc(3  * sizeof(char *));

    int i, j, x, y, k, aux;

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
            x -= 1;
            y -= 1;
            aux = x + y;
            jogo[x][y] = 'X';
        }
        else{
            printf("Jogador 2:");
            scanf("%d %d", &x, &y);
            x -= 1;
            y -= 1;
            aux = x + y;
            jogo[x][y] = '0';
        }

        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                printf("%c ", jogo[i][j]);
            }
            printf("\n");
        }
        
        if(k >= 5){
            //Caso o 2 2 seja o numero digitado
            if(x == 1 && y == 1){
                //printf("%c %c %c\n\n", jogo[x][0], jogo[x][1], jogo[x][2] );
                if(jogo[x][0] == jogo[x][1] && jogo[x][1] == jogo[x][2] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }

                else if(jogo[0][y] == jogo[1][y] && jogo[1][y] == jogo[2][y] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }

                else if(jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }

                else if(jogo[2][0] == jogo[1][1] && jogo[1][1] == jogo[0][2] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }
                
            }

            //Caso o a posicao digitada seja 0 1 ou 1 1 ou 1 3 ou 2 2
            else if(aux == 3 || aux == 1){

                 if(jogo[x][0] == jogo[x][1] && jogo[x][1] == jogo[x][2] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }

                else if(jogo[0][y] == jogo[1][y] && jogo[1][y] == jogo[2][y] ){
                    if(jogo[x][y] == 'X'){
                        printf("O jogador 1 ganhou.\n\n");
                    }else{
                        printf("O jogador 2 ganhou.\n\n");
                    }

                    return 0;
                }
            }

            //Caso a posicao digitada seja uma das quinas da matriz
            else if (aux == 0 || aux == 4 || aux == 2){

                    if(jogo[x][0] == jogo[x][1] && jogo[x][1] == jogo[x][2] ){
                        if(jogo[x][y] == 'X'){
                            printf("O jogador 1 ganhou.\n\n");
                        }else{
                            printf("O jogador 2 ganhou.\n\n");
                        }

                        return 0;
                    }

                    else if(jogo[0][y] == jogo[1][y] && jogo[1][y] == jogo[2][y] ){
                        if(jogo[x][y] == 'X'){
                            printf("O jogador 1 ganhou.\n\n");
                        }else{
                            printf("O jogador 2 ganhou.\n\n");
                        }

                        return 0;
                    }

                    else if(aux == 2 && jogo[2][0] == jogo[1][1] && jogo[1][1] == jogo[0][2] ){
                        if(jogo[x][y] == 'X'){
                            printf("O jogador 1 ganhou.\n\n");
                        }else{
                            printf("O jogador 2 ganhou.\n\n");
                        }

                        return 0;
                    }

                    else if(aux == 4 && jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] ){ 
                        if(jogo[x][y] == 'X'){
                            printf("O jogador 1 ganhou.\n\n");
                        }else{
                            printf("O jogador 2 ganhou.\n\n");
                        }

                        return 0;
                    }

                     else if(aux == 0 && jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] ){ 
                        if(jogo[x][y] == 'X'){
                            printf("O jogador 1 ganhou.\n\n");
                        }else{
                            printf("O jogador 2 ganhou.\n\n");
                        }

                        return 0;
                    }
                    

            }

        }

    }

    printf("Deu Velha\n\n");

    return 0;
    
}