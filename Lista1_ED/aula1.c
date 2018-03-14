#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.14

//Abreviasao das funcoes
void  calc_esfera  (float  r,  float *area, float *volume);
void main();

void main(){
    float area, volume;
    float r;
    int escolha;

    scanf("%d", &escolha);
    printf("algo\n");
    scanf("%f", &r);
    printf("\n\nalgo");

    
   
    calc_esfera(r, &area, &volume);

   

    printf("Area: %f.2 \n Volume: %f.2", area, volume);
          

}

void  calc_esfera  (float  r,  float *area, float *volume){
    printf("algo");
    *area = 4.0*pi*( pow(r,2) );
    printf("algo");
    *volume = ( 4.0*pi*( pow(r,3) ) ) / 3;
}