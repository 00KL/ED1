#include <stdio.h>
#include <stdlib.h>

void main();

void main(){
    int a = 2, b = 3, escolha;
    int *x, *y; //ponteiros

    x = &a; //x esta recemendo o endereco de a
    y = &b;

    scanf("%d", escolha);

    switch(escolha){
        //soma
        case 1: *x + *y;
            break;

        //subtracao
        case 2: *x - *y;
            break;

        //multi
        case 3: *x * *y;
            break;
        
        case 4: *x / *y;
            break;
    }    

}