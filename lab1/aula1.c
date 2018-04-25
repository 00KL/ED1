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
int **inverte2 (int n, int* vet);

//Vetor q acumula os numeros de forma crescente questao 4
//int **algo;


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

    //Questao 4
    int *vetornormal, **vetCres;
    int tamanhon;

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

        case 4:
                scanf("%d", &tamanhon);

                vetornormal = (int *)malloc(tamanhon * sizeof(int));
    
                for(int i = 0; i < tamanhon ; i++){
                    scanf("%d", (vetornormal + i));
                }

                vetCres = inverte2 (tamanhon, vetornormal);

                for(int i = 0; i < tamanhon ; i++){
                    printf("%d ", *( *(vetCres) + i ) );
                }

                printf("\n\n");

                free(vetornormal);
                free(vetCres);

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

int **inverte2 (int n, int *vet){

    int troca, i;

    int **vetCres = (int **)malloc(n * sizeof(int **) );


    for(i = 0; i < n; i++){
        *(vetCres + i) = vet + i;
    }
    
    for(int i = 0; i < n - 1; i++){
        
        for(int j = 0; j < n - 1; j++){
            if( *(*vetCres + j) > *(*vetCres + j + 1)){
            troca = *(*vetCres + j);
            *(*vetCres + j) = *(*vetCres + j + 1);
            *(*vetCres + j + 1) = troca;
            }
        }
    }

    return vetCres;
}