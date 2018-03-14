#include <stdio.h>
#include <stdlib.h>

//previa das funcoes
void troca(char *);
int contagem(char *);
void main();

//funcao q ira encontrar o tamanho da string
int contagem(char *string){
    
    int i = 0;
    char fim;
    
    for(i ; fim != '\0' ; i++){
        fim = *(string + i);
    }

    return i;
}

//ira inverter a string
void troca(char *string){

    int tamanho = contagem(string) - 1;//O - 1 é para correcao do tamanho,
                                       //pois a ultima casa da string é '/0'
                                       //q n deve ser invertida.
                                       
    char troca;

    for(int i = 0 ; i < ( tamanho/2 ) ; i++){
        troca = *(string + i);
        *(string + i) = *(string + tamanho - 1 - i);//A contagem se inicia no 0, logo
                                                    //é preciso subtrair 1 do tamanho da 
                                                    //string para q a inversao se inicie
                                                    //da casa onde esta o ultimo caracter,
                                                    //caso contrario seria invertido o
                                                    //caracter '/0' com o primeiro da string
                                                    //o q n e desejado.
    
        *(string + tamanho - 1 - i) = troca;
    }

    //printf("%s \n", string);
}

void main(){
    char *string;
    
    string = (char*)malloc(1000 * sizeof(char));

    scanf("%s", string);

    troca(string);

    printf("%s \n", string);

}