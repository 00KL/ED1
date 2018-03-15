#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14

//Abreviasao das funcoes
void  main();
void  calc_esfera  (float  r,  float *area, float *volume);
int   negativos (int n, float* vet);
void  inverte (int n, int* vet);


void main(){
    int escolha;
    
    //Questao 1
    float area, volume;
    float r;

    //Questao 2
    int n, resultado; 
    float *vet;

    //Questao 3
    int num;
    int *vetor;

    scanf("%d", &escolha);
    switch(escolha){
        case 1:
                scanf("%f", &r);
                calc_esfera(r, &area, &volume);
                printf("Area: %.2f \nVolume: %.2f \n\n", area, volume);
                break;

        case 2:
                scanf("%d", &n);

                vet = (float *)malloc(n * sizeof(float));
                
                for(int i = 0; i < n; i++){
                    scanf("%f", (vet + i) );

                }
                
                resultado = negativos(n, vet);
                printf("\nResultado: %d\n\n", resultado);

                free(vet);
                break;

        case 3:
                scanf("%d", &num);

                vetor = (int *)malloc(num * sizeof(int));
                
                for(int i = 0; i < num; i++){
                    scanf("%d", (vetor + i) );
                }

                inverte(num, vetor);

                for(int i = 0; i < num; i++){
                    printf("%d ", *(vetor + i) );
                }

                printf("\n\n");

                free(vetor);
                break;            
    }

    
}

void  calc_esfera  (float  r,  float *area, float *volume){
    *area = pow(r,2)*4*3.14;
    *volume = ( 4.0*pi*( pow(r,3) ) ) / 3;
}

int negativos (int n, float *vet){
    int resultado = 0;
    for(int i = 0; i < n; i++){
        if( *(vet+i) < 0){
            resultado++;
        }
    }
    return resultado;
}

void inverte (int num, int *vetor){
    int troca = 0;
    for(int i = 0; i < num/2; i++){
        troca = *(vetor + i);
        *(vetor + i) = *(vetor + num - 1 - i);
        *(vetor + num - 1 - i) = troca;
    }
}