#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void contido(char letra, int tamanhoPalavra, int *cont, int *erro, char *secreta, char *progresso);

void main(){
    char *secreta = (char *)malloc(50 * sizeof(char));
    char *progresso = (char *)malloc(50 * sizeof(char));

    int erro, acerto, i, tamanhoPalavra, cont = 0;
    char letra, lixo;

    printf("Iniciando Jogo da Forca... \nJogador 1: Digite a palavra secreta:\n");
    scanf("%[^\n]s", secreta);
    system("clear");
    setbuf(stdin, NULL);

    tamanhoPalavra = strlen(secreta);

    for(i = 0; i < tamanhoPalavra; i++){
        *(progresso + i) = '-';
    }

    printf("Jogador 2:\n");
    while( erro < 5 && cont < tamanhoPalavra){

        printf("Digite uma letra: ");
        scanf("%c%c", &letra, &lixo);
        contido(letra, tamanhoPalavra, &cont, &erro, secreta, progresso);

        printf("Palavra:%s", progresso);
        printf("\nERROS %d/5", erro);
        printf("\n\n");
        
    }

    if(erro == 5){
        printf("Voce perdeu, a palavre era: %s\n\n", secreta);
    }else{
        printf("Parabens, voce venceu, a palavra era: %s\n\n", progresso);
    }
}

 void contido(char letra, int tamanhoPalavra, int *cont, int *erro, char *secreta, char *progresso){
    int i , aux = 0;
    for(i = 0; i < tamanhoPalavra; i++){
        if( *(secreta + i) == letra  && *(progresso + i) != toupper(letra) ){
            *(progresso + i) = toupper(letra);//+ 32 pra deixar maiuscula
            *cont = *cont + 1;
            aux++;
        }
    }

    if(aux == 0){
        *erro = *erro + 1;
    }
 }
